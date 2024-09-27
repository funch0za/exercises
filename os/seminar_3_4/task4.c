#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
  pid_t pid = fork();
  if (pid == 0) {
    execle("/bin/cat", "/bin/cat", "task4.c", 0, envp);
  } else {
    execle("/bin/pwd", "/bin/pwd", 0, envp);
  }
}
