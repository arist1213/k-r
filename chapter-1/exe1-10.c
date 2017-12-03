#include <stdio.h>

/* copy its input to it's output 
 * replacing each string of one or more blanks by a single blank; 
 * replacing each tab by \t, each backspace by \b and each backslash by \\
 * make them visible*/

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main() {
    int c; 
    int state;
    state = OUT;

    while((c = getchar()) != EOF) {
   
        if (c == ' ' || c == '\t' || c == '\b' || c == '\\') {
          
            if (c == ' ') {
                putchar(' ');
            } else if (c == '\t') {
                printf("\\t");
            } else if (c == '\b') {
                printf("\\b");
            } else if (c == '\\') {
                printf("\\\\");
            }

            if (c == ' ' && state == OUT) {
                state = IN;
            }
         
        } else {

            state = IN;
            putchar(c);

        }

    }
    return 0;
}
