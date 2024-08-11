#include <stdio.h>

enum { N = 10 };

int binsearch_1(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int binsearch_2(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n;
  while (low < high - 1) {
    mid = (low + high) / 2;
    // fprintf(stderr, "%d %d %d\n", mid, low, high);
    if (x < v[mid]) {
      high = mid;
    } else {
      low = mid;
    }
  }

  mid = low;
  if (v[mid] != x) {
    mid = -1;
  }

  return mid;
}

int main(void) {
  int a[N] = {1, 5, 10, 23, 44, 56, 99, 102, 103, 342};

  for (int i = -400; i <= 400; ++i) {
    int res1 = binsearch_1(i, a, N);
    int res2 = binsearch_2(i, a, N);

    if (res1 != res2) {
      puts("ERROR");
      printf("i : %d\n1 : %d\n2 : %d\n", i, res1, res2);
    }
  }
}
