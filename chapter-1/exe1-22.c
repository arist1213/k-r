#include <stdio.h>
/* fold very long lines into two or more lines */
#define MAX_BUFFER 100

/* from K&R */
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

/* from K&R */
void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

int main() {    

    char Buffer[MAX_BUFFER];
    char line[MAX_BUFFER];
    int k,len;    

    /* CONDITION 1. has spaces      ...cc  \0   */
    /* CONDITION 2. has no \n       ...cccc\0   */
    /* CONDITION 3. OK              ...cc\n\0   */    
    while( (len = getLine(Buffer, MAX_BUFFER)) > 0 ) {
        
        if (len >= MAX_BUFFER-1) {
            // not found \n character             
            if (Buffer[len-1] == '\n') { // c3
                printf("%s", Buffer);
            } else if (Buffer[len-1] != '\n' && Buffer[len-1] != ' ') { // c2
                printf("%s\n", Buffer);
            } else { // c1
                k = 0;
                while(Buffer[--len] == ' ')
                    k++;
                if (k == 0) {
                    // must error
                } else if (k == 1) { // only one blank
                    Buffer[len+1] = '\n';
                    printf("%s", Buffer);
                } else { // at least two blanks
                    // remove the blanks from index len which not blanks
                    Buffer[len+1] = '\n';
                    Buffer[len+2] = '\0';
                    copy(line, Buffer);
                    printf("%s", line);
                }            
            }

        } else {
            printf("%s", Buffer);
        }        
    }    

    return 0;
}




