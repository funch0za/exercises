#include <unistd.h>
#include <stdio.h>

int main() {
  int fd[2];
  if (pipe(fd) == -1) {
    puts("error");
  }
}
