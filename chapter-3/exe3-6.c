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
/* convert n to characters in s, padding blank spaces in left if need. modify p64 itoa */
void itoa(int n, char s[], int pad) {
    int i, sign;
    if ((sign=n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n%10 + '0';    /* get next digit 获取个位上的数字 */
    } while ((n/=10) > 0);
    
    if (sign < 0)
        s[i++] = '-';
    
    /* 如果需要，在左边填充空格*/
    if (i < pad) {
        do {
            s[i++] = ' ';        
        } while (i<pad);
    }
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
    
    int pad = 12;

    size_t nums = sizeof test / sizeof test[0];
    size_t i = 0;
    char out[MAX_BUFFER];

    for(i=0; i<nums; i++) {
        itoa(test[i], out, pad);
        printf("%s\n", out);
    } 

    return 0;
}