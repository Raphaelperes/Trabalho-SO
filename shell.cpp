#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_SIZE_LINE 512 // max size for commands

void flush_in () { 
  int ch;
  while((ch = fgetc(stdin)) != EOF && ch != '\n' ) {} 
}

int main () {
  char **command, *token, key[100], receptor[100] = {};
  int command_position_vector[30];
  int count1, count2 = 0;
  pid_t child_process;
  int size_matrix;
  int i, j;

  do { 
    printf("->> ");
    count1 = 0;
    count2 = 0; 
    scanf("%[^\n]s", receptor); // stores the entire line command in the variable "receptor"
    flush_in();

    while (count1 <= strlen(receptor)) {
      if (strcmp(key, "quit") == 0) return 1;

      if (strcmp(key, " quit") == 0) return 1;

      if (strcmp(key, " quit ") == 0) return 1;
    
      if ((receptor[count1] == ',') || (count1 == strlen(receptor))) {
        token = strtok(key, " "); // save the input using space like separator
        command = (char**) calloc(MAX_SIZE_LINE*sizeof(char*), 1); //matrix of commands
    
        i = 0; // token counter
        j = 1; // block counter
        command_position_vector[0] = 0;

        while (token != NULL) {
          command[i] = (char*) calloc(strlen(token)*sizeof(char*), 1);
          
          // finding pipes . . .
          if (strcmp(token, "|") == 0) {
            command_position_vector[j] = i+1;
            command[i] = NULL; // the pipe must be null for execvp() stop the running of command
            j++;
          } else {
            strcpy(command[i], token);
          }

          i++; // next command
          size_matrix++;
          token = strtok(NULL, " "); // take next token from "key"
        }
    
        int fd[j][2];
    
        for (i = 0; i < j; i++) {
          pipe(fd[i]);
        }
    
        for (i = 0; i < j; i++) { // j stores the necessaries forks()
          child = fork();

          if (child == 0) {
            int FILE_IN, FILE_OUT; // files for redirect I/O
            int index = command_position_vector[i]; // index of command
            int to_point = index; // to point for the element of current command

            while (command[to_point] != NULL) {
              if (strcmp(command[to_point], ">") == 0) {
                FILE_OUT = open(command[to_point+1], O_CREAT | O_RDWR | O_TRUNC, 0644);
                dup2(FILE_OUT, STDOUT_FILENO);
                command[to_point] = NULL;
              } else if (strcmp(command[to_point], ">>") == 0) {
                FILE_OUT = open(command[to_point+1], O_CREAT | O_RDWR | O_APPEND, 0644);
                dup2(FILE_OUT, STDOUT_FILENO);
                command[to_point] = NULL;
              } else if (strcmp(command[to_point], "<") == 0) {
                FILE_IN = open(command[to_point+1], O_RDONLY, 0644);
                dup2(FILE_IN, STDIN_FILENO);
                command[to_point] = NULL;
              }
              to_point++;
            }

            if (i != 0) {
              close(fd[i-1][1]);
              dup2(fd[i-1][0], STDIN_FILENO);
              close(fd[i-1][0]);
            }

            if (i != j-1) {
              close(fd[i][0]);
              dup2(fd[i][1], STDOUT_FILENO);
              close(fd[i][1]);
            }

            execvp(command[index], &command[index]);
            close(fd[i-1][0]);
          } else if (child > 0) {
            close(fd[i-1][0]);
            close(fd[i-1][1]);
            waitpid(-1, NULL, 0);
          } else{
            printf("Occurred an error on creating child processes. Try again\n");
          }
        }

        count2 = 0;
        strncpy(key, "", 100); // clear key
      } else {
        key[count2] = receptor[count1];
        count2++;			
      }
          
      count1++;
    }
  } while (1 != 2); // infinite loop ultil "quit" command

  return 0;
}
