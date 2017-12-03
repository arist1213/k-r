#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* prints its input each word per line */
int main() {
    int c,  state; 
    state = OUT;

    while((c = getchar()) != EOF) {  
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) 
                printf("\n");
            state = OUT;  
        } else {
            putchar(c);
            if (state == OUT) {
                state = IN;
            }
        }
    }

    return 0;
}
