#include <stdio.h>
/* Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. 
        Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? 
 */
#define MAX_BUFFER 1024
#define SPACE (char)' '
#define TAB (char)'\t'

/* K&R's getline() function from p29 
    ps:getline() has been declarated in /usr/include/stdio.h with clang compiler at macpro system */

int getLine(char s[], int lim) {

    int c,i;
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i]='\n';
        i++;
    }

    s[i] = '\0';
    return i;

}

int calculateNumberOfSpace(int offset, int tabSize) {
    return tabSize - (offset % tabSize);
}

int main() {    
    char Buffer[MAX_BUFFER];
    int tabSize = 5;

    int i,j,k;

    while( getLine(Buffer, MAX_BUFFER) > 0) {
    
        for (i = 0; Buffer[i] != '\0'; ++i) {
            if (Buffer[i] == TAB) {
                j = calculateNumberOfSpace(i, tabSize);
                for (k = 0; k < j; ++k) {
                    putchar(SPACE);
                }
            } else {
                putchar(Buffer[i]);
            }             
        }
        
    }    

    return 0;
}




