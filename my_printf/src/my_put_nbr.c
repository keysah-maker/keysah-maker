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
#include <math.h>
#include "my.h"

int  my_put_nbr(int nb)
{
    int z = 0;
    //int i = nb;
    int d = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb *-1;
    }
    while (nb/d >= 10) {
        d *= 10;
    }
    while (d >= 1 ) {
        z = nb / d;
        z = z + 48;
        my_putchar(z);
        nb = nb % d;
        d = d / 10;
    }
    return (0);
}
