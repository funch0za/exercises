#include <stdio.h>
#include <string.h>

#define MAXN 1000

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fputs("Incorrect arguments", stderr);
    return 1;
  }

  FILE *fp1 = fopen(argv[1], "r");
  FILE *fp2 = fopen(argv[2], "r"); 

  if (fp1 == NULL) {
    fprintf(stderr, "Can't open %s file\n", argv[1]); 
    return 1;
  }
  if (fp2 == NULL) {
    fprintf(stderr, "Can't open %s file\n", argv[2]);
    return 1;
  }

  char s1[MAXN], s2[MAXN];
  while (fgets(s1, MAXN, fp1) != NULL && fgets(s2, MAXN, fp2) != NULL) {
    s1[strlen(s1) - 1] = '\0';
    s2[strlen(s2) - 1] = '\0';
    if (strcmp(s1, s2) != 0) {
      printf("%s : %s\n%s : %s\n", argv[1], s1, argv[2], s2);
      return 0;
    }
  }
  
  char *end1 = fgets(s1, MAXN, fp1);
  char *end2 = fgets(s2, MAXN, fp2);
  
  if (end1 == NULL && end2 != NULL || end1 != NULL && end2 == NULL) {
    s1[strlen(s1) - 1] = '\0';
    s2[strlen(s2) - 1] = '\0';
    printf("%s : %s\n%s : %s\n", argv[1], s1, argv[2], s2);
  }
}
