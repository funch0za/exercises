#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  printf("uid = %u\tgid = %u\n", getuid(), getgid()); 
}
