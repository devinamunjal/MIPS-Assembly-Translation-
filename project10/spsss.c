/*I pledge by my honor that I did not receive or give assistance
  on this assignment
  dmunjal
  section:0201
  119016480*/
#include "spsss.h"
#include "safe-fork.h"
#include "split.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
/*this function will read and store, in a linkedlist, 
  one list of commands from one external file,
  and another list of commands from another file
  the first list consists of UNIX commands 
  intended to compile a student project on our
  hypothetical submit server. The second list is
  commands for running the tests of the student project.*/
Spsss_commands read_spsss_commands(const char compile_cmds[],
                                   const char test_cmds[]){
  Spsss_commands commands_list;
  FILE *file = fopen(compile_cmds, "r");
  FILE *tfile = fopen(test_cmds, "r");
  char tline[LINE_MAX];
  char line[LINE_MAX];
  char *c_com;
  char *t_com;
  /* int tc_null = 0; 
     int count = 0; */
  Node *temp;
  Node *curr = NULL;
  if (compile_cmds == NULL || test_cmds == NULL ||
      open(compile_cmds, O_RDONLY) == -1) {
    exit(1);
  }
  /*checks to ensure file can be opened */
  if(file == NULL){
    fprintf(stderr, "failure opening file");
    exit(1);
  }
  /*checking and reading line(s) until NULL */
  while(fgets(line, LINE_MAX, file) != NULL){
    /*allocate mem for node */
    temp = malloc(sizeof(Node));
    if(temp == NULL)
      exit(1);
    line[strcspn(line, "\n")] = '\0';
    c_com = malloc(strlen(line) + 1);
    if(c_com == NULL)
      exit(1);
    strcpy(c_com, line);
    
    fgets(tline, LINE_MAX, tfile);
    tline[strcspn(tline, "\n")] = '\0';
    t_com = malloc(strlen(tline) + 1);
    if(t_com == NULL){
       exit(1);
     }
    strcpy(t_com, tline);
    
  
    /*sets compile_cmd and test_cmd in temp node */
    temp -> compile_commands = c_com;
    temp -> test_commands = t_com;
    temp -> next = NULL;

    /*adds temp to Spsss_commands */
    /*if head empty */
    if(curr == NULL){
      commands_list.head = temp;
      curr = commands_list.head;
    }
    else{
      curr -> next = temp;
      curr = temp;
    }
  }
  fclose(file);
  fclose(tfile);
  return commands_list;
}
void clear_spsss_commands(Spsss_commands *const commands){
  Node *curr;
  Node *temp;
  if(commands == NULL || commands->head == NULL){
    return;
  }
  curr = commands->head;
  /*free all of the nodes in the list */
  while(curr != NULL){
    temp = curr -> next;
    free(curr -> compile_commands);
    free(curr -> test_commands);
    free(curr);
    curr = temp;
  }
  commands->head = NULL;
    
}
static char** setup_redirection(char *command[]) {
  int fd;
  int ofd;
  char *file;
  int x = 0;
  while(command[x] != NULL){
    if (strcmp(command[x], "<") == 0) {
      file = malloc(strlen(command[x+1]) + 1);
      if(file == NULL){
	fprintf(stderr, "mem allocation error");
	exit(1);
      }
      strcpy(file, command[x+1]);
      command[x+1] = NULL;
      free(command[x]);
      fd = open(file, O_RDONLY);
      if (fd == -1) {
	fprintf(stderr,"error opening input file");
        exit(1);
      }
      dup2(fd, STDIN_FILENO);
      close(fd);
    }
    if (strcmp(command[x], ">") == 0) {
      file = malloc(strlen(command[x+1]) + 1);
      if(file == NULL){
	fprintf(stderr, "mem allocation error");
	exit(1);
      }
      strcpy(file, command[x+1]);
      command[x+1] = NULL;
      free(command[x]);
      ofd = open(file, FILE_FLAGS, FILE_MODE);
      if(ofd == -1) {
	fprintf(stderr,"error opening output file");
	exit(1);
      }
      dup2(ofd, STDOUT_FILENO);
      close(ofd);
    }
    x++;
  }
  return command;
}
int compile_program(Spsss_commands commands){
  /*creating pipe */
  pid_t pid;
  /*char *argv[4]; */
  int status;
  Node *curr;
  char **compile_command;
  curr= commands.head;
  while(curr != NULL){
    pid= safe_fork();
    if(pid > 0){
      waitpid(pid, &status, 0);
      if(!WIFEXITED(status) || WEXITSTATUS(status) != 0){
        return FAILED_COMPILATION;
      }
    }
    /*child proccess */
    else if(pid == 0){
      compile_command = split(curr->compile_commands);
      compile_command = setup_redirection(compile_command);
      execvp(compile_command[0], compile_command);
    }
    else{
      fprintf(stderr, "error forking");
      exit(1);
    }
    curr = curr -> next;
  }
  
  return SUCCESSFUL_COMPILATION;
}
int test_program(Spsss_commands commands){
  pid_t pid;
  int status;
  Node *curr;
  int count = 0;
  char **test_command;
  curr= commands.head;
  if(curr -> test_commands == NULL)
    return 0;
  while(curr != NULL){
    pid= safe_fork();
    if(pid > 0){
      waitpid(pid, &status, 0);
      if(WIFEXITED(status) && WEXITSTATUS(status) == 0){
        count++;
      }
    }
    /*child proccess */
    else if(pid == 0){
      test_command = split(curr->test_commands);
      test_command = setup_redirection(test_command);
      execvp(test_command[0], test_command);
    }
    else{
      fprintf(stderr, "error forking");
      exit(1);
    }
    curr = curr -> next;
  }
  
  return count;
}
