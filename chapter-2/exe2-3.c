#include <stdio.h>
#include <math.h>
#include <ctype.h>

/* converts a string of hexadecimal digits (including an optional 0x or 0X) into 
its equivalent integer value. */

// todo check if this string is a valid hex string
int htoi(char s[]) {
    int i, j, n, total, r;
    char t;
    i = j = n = total = r = 0;

    if (s[0] == '0')
        j = 2;
    while(s[i++]!='\0')
        n++;

    n -= j;
    n -= 1;
    //printf("n %d\n", n);

    for(i = j; s[i]!='\0'; i++, n--) {  

        if (isdigit(s[i])) {            
            total += pow(16, n) * (s[i] - '0');
            //printf("s[%d] %c -> %d n->%d\n", i, s[i], (s[i] - '0'), n);            
        } else if (isalpha(s[i])){
            t = tolower(s[i]);
            if (t == 'a') {
                r = 10;
            } else if (t == 'b') {
                r = 11;
            } else if (t == 'c') {
                r = 12;
            } else if (t == 'd') {
                r = 13;
            } else if (t == 'e') {
                r = 14;
            } else if (t == 'f') {
                r = 15;
            }
            total += pow(16, n) * r;
        }

    }

    return total;
}  

int main(int argc, char *argv[]) {
    //char s[] = "0x12345";
    // 0x12345
    // 16^4*1 16^3*2 16^2*3 16^1*4 16^0*5
    // 74565
    printf("%s\n", argv[1]);
    printf("%d\n", htoi(argv[1]));
    return 0;
}