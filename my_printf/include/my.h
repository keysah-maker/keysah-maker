#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_put_nbr(int nb);
int my_printf(char *s, ...);
char *my_revstr(char *str);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_base(char *base, unsigned int nb);
int  my_put_nbri(unsigned int nb);
//void flag(char *s, va_list ap, int d);
//void flag_two(char *s, va_list ap, int d);
void flag_step_one(char *s, va_list ap, int d);
void flag_step_two(char *s, va_list ap, int d);

#endif
