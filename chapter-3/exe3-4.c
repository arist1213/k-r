#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 1024

void reverse(char s[]) {
    int c, i, j;
    for(i=0, j=strlen(s)-1; i<j; i++,j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* converts the integer n into a base b character representation in the string s */
void itob(int n, char s[], int b) {
    int i, sign, re;
    char c;
    if ((sign=n) < 0)
        n = -n;
    i = 0;

    do {
        re = n%b;
        if (b == 16) {
            if (re >= 10) {
                switch(re) {
                    case 10: c = 'a'; break;
                    case 11: c = 'b'; break;
                    case 12: c = 'c'; break;
                    case 13: c = 'd'; break;
                    case 14: c = 'e'; break;
                    case 15: c = 'f'; break;
                }
                s[i++] = c;
            } else {
                s[i++] = re + '0';
            }
        } else {
            s[i++] = re + '0';
        }
    } while ((n/=b) > 0);

    if (sign<0) 
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main(void) {
    int test[] = {
        1,
        123,
        1234,
        12345,
        123456,
        1234567,
        -100,
        -200,
        -300
    };

    size_t nums = sizeof test / sizeof test[0];
    size_t i = 0;
    char out8[MAX_BUFFER];
    char out16[MAX_BUFFER];

    printf("%10s %10s %10s\n", "decimal", "oct", "hex");
    for(i=0; i<nums; i++) {
        itob(test[i], out8, 8);
        itob(test[i], out16, 16);
        printf("%10d %10s %10s\n", test[i], out8, out16);
    } 

    return 0;
}