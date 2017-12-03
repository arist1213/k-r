#include <stdio.h>
/* Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing. 
Use the same stops as for detab . When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
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

int calculateNumberOfTabs(int spaces, int tabSize) {
    return  spaces > tabSize ? spaces / tabSize : 0;
}

int calculateNumberOfSpace(int spaces, int tabs, int tabSize) {    
    return tabs > 0 ? spaces % tabSize : spaces;
}

int main() {    
    char Buffer[MAX_BUFFER];
    int tabSize = 5;

    int i,j,k;

    int tabs = 0;
    int spaces = 0;

    while( getLine(Buffer, MAX_BUFFER) > 0 ) {
    
        for (i = 0; Buffer[i] != '\0'; ++i) {
            if (Buffer[i] == SPACE) {
                k = i; // check the 

                /* check if has enough spaces to replace by tab */
                while (Buffer[k++] == SPACE) {
                    ;
                }                

                tabs = calculateNumberOfTabs(k-i-1, tabSize);
                spaces = calculateNumberOfSpace(k-i-1, tabs, tabSize);                

                //printf("tabSize: %d, spaces size: %d, replaces tabs: %d, replaces spaces: %d, found space from index %d to %d\n", tabSize, k-i-1, tabs, spaces, i, k-1);
                for (j = 0; j < tabs; j++)
                    putchar(TAB);            
                for (j = 0; j < spaces; j++)
                    putchar(SPACE);    
            
                i = k - 1; /* move forword */
                putchar(Buffer[i]);

            } else {
                putchar(Buffer[i]);
            }             
        }
        
    }    

    return 0;
}




