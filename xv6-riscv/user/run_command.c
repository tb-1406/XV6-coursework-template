#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"

void execute_line(char** args) {

  // Use fork() to create a child process. Determine if the process
  // is a parent or a child, and run exec() if it is a child, and
  // run wait() if it is a parent.
  int pid = fork();
  if (pid < 0){
    fprintf(2, "run_command: fork failed\n");
    exit(1);
  }
  wait(0);
  // For guidance, the model solution has 9 lines of code.
}


int main(int argc, char *argv[]) {

  // Two pointers: to a command and to a null terminator.
  char *args[2] = {0};
  // Fixed-size storage for reading in a line of input, and a pointer
  // to a particular character in this storage.
  char buffer[512], *b;
  // Point b to the first character in the line.
  b=buffer;
  // Read characters from the standard input. When we find '\n' that
  // means one line has terminated - execute the command.
  fprintf(2, "Please enter command and press enter (type 'q' to exit):\n");
  while (read(0, b, 1) > 0) {
    // Check the current character in b. If it is not special, move the pointer
    // b to the next character and continue reading. If the command string has
    // been fully entered ('\n' is found in b), execute the command by calling
    // execute_line().
    if (*b == '\n') {
      *b = 0;
      if (buffer[0] == 'q' && buffer[1]==0) exit(0);
      args[0] = buffer;
      execute_line(args);
      fprintf(2, "Please enter command and press enter (type 'q' to exit):\n");
      b = buffer;
      continue;
    }
    b++;
    // For guidance, the model solution has 10 lines of code in this loop.
  }
  exit(0);
}
