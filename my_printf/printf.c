#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include "my.h"

int my_put_base(char *base, unsigned int nb)
{                                                                                                        char *result = malloc(sizeof(char) * 25);
  int k = 0;

  while (nb != 0) {
    result[k] = base[nb % my_strlen(base)];
    nb = nb / my_strlen(base);
    k = k + 1;                                                                                          }
  result = my_revstr(result);                                                                             result[25] = '\0';
  my_putstr(result);
  return (0);
}

int my_put_nbri(unsigned int nb)
{
  unsigned int z = 0;
  //unsigned int i = nb;
  unsigned int d = 1;
  
  if (nb <= 0) {
    my_putchar('-');
    nb = nb *-1;
  }
  while (nb/d >= 10) {
    d *= 10;
  }
  while (d >= 1 ) {
    z = nb / d;
    z = z + 48;                                                                                             my_putchar(z);
    nb = nb % d;
    d = d / 10;                                                                                         }
  return (0);
}

void flag_step_one(char *s, va_list ap, int d)
{
  switch (s[d+1])
    {
    case 's':
      my_putstr(va_arg(ap, char*));
      break;
    case 'c':
      my_putchar(va_arg(ap, int));
      break;
    case 'i':
      my_put_nbr(va_arg(ap, int));
      break;
    case 'd':
      my_put_nbr(va_arg(ap, int));
      break;
    }
}

void flag_step_two(char *s, va_list ap, int d)
{
  switch (s[d+1])
    {
    case 'u':
      my_put_nbri(va_arg(ap, unsigned int));
      break;
    case 'o':
      my_put_base("01234567", va_arg(ap, unsigned int));
      break;
    case 'x':
      my_put_base("0123456789abcdef", va_arg(ap, unsigned int));
      break;
    case 'X':
      my_put_base("0123456789ABCDEF", va_arg(ap, unsigned int));
      break;
    case '%':
      my_putchar('%');
      break;
    }
}

int my_printf(char *s, ...)
{                                                                                                           va_list ap;                                                                                             int d = 0;
  va_start(ap, s);                                                                                        while (s[d] != '\0') {                                                                                      if (s[d] == '%') {
      flag_step_one(s, ap, d);
      flag_step_two(s, ap, d);
      d = d + 1;
    } else {
      my_putchar(s[d]);                                                                                   }
    d = d + 1;                                                                                          }
  va_end(ap);
  return (0);
}
