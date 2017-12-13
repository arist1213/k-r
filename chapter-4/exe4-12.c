#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

/* printd: print n in decimal */
void printd(int n) 
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }

    if (n/10)
      printd(n/10);

    putchar(n % 10 + '0');
}


/* itoa: convert an integer into a string, recursion */
int itoa(int n, char s[])
{
    int i =  0;
    if (n / 10)
        i = itoa(n/10, s);
    else if (n < 0) 
        s[i++] = '-';        

    s[i++] = abs(n % 10) + '0';
    s[i] = '\0';

    return i;
}

/* reverse Polish calculator */

int main(void)
{
    char s[MAX_SIZE];
    int size = 9;
    int i;

    int test[] = {
        12,
        123,
        1234,
        12345,
        123456,
        -1,
        -12,
        -123,
        -1234
    };
    
    for (i = 0; i < size; i++) {
        printd(test[i]);
        printf("\n");
    }

    for (i = 0; i < size; i++) {
        
        itoa(test[i], s);
        printf("%s\n", s);
      
    }
    return 0;
}

