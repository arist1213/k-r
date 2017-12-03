#include <stdio.h>

/* copy its input to it's output 
 * replacing each string of one or more blanks by a single blank; */

#define IN 1
#define OUT 0

int main() {
    int c; 
    int state;
    state = OUT;

    while((c = getchar()) != EOF) {
        
        if (c != ' ') {
            putchar(c);
            state = IN;
        } else {
            if (state == OUT) {
                putchar(' ');
            }
            state = IN;
        }
    }
    return 0;
}
