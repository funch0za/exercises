#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...) {
  va_list ap;
  char *p, *sval;
  char cval;
  int ival;
  double dval;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }

    switch (*++p) {
      case 'd':
        ival = va_arg(ap, int);
        printf("%d", ival); // ?
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf("%f", dval);
      case 's':
        for (sval = va_arg(ap, char *); *sval; sval++) {
          putchar(*sval);
        }
        break;
      case 'c':
        sval = va_arg(ap, char *);
        putchar(*sval);
      default:
        putchar(*sval);
        break;
    }
  }

  va_end(ap);
}
