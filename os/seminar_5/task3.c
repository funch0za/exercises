#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <sys/types.h>
#include <unistd.h>

#define N 14

int main() {
  int pipefd[2];
  if (pipe(pipefd) < 0) {
    puts("Can\'t create pipe\n");
    exit(EXIT_FAILURE);
  } else {
    puts("Pipe is created\n");
  }

  size_t size;
  switch (fork()) {
    case -1:
      puts("Can\'t fork child");
      exit(EXIT_FAILURE);
      break;
    case 0:
      puts("Child");
      close(pipefd[1]);
      
      char str[N];
      size = read(pipefd[0], str, N);

      if (size != N) {
        puts("Can\t read string");
        exit(EXIT_FAILURE);
      }

      puts(str);
      close(pipefd[1]);
      printf("Child exit");
      break;
    default:
      puts("Parent");
      close(pipefd[0]);
      size = write(pipefd[1], "Hello, world!", N);

      if (size != N) {
        puts("Can\'t write all string");
        exit(EXIT_FAILURE);
      }
      close(pipefd[1]);

      puts("Parent exit");
      break;
  }

  return EXIT_SUCCESS;
}
