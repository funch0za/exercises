#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
  puts("argv:");
  for (int i = 0; i < argc; ++i) {
    puts(argv[i]);
  }
  puts("\nenvp:");
  for (int i = 0; envp[i] != NULL; ++i) {
    puts(envp[i]);
  }
}
