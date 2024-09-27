#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
  printf("pid = %d\n", getpid());
  fork(); 
  execle("/bin/cat", "/bin/cat", "task2.c", 0, envp);
  printf("Error on program start\n");
  exit(-1);
  return 0;
}
