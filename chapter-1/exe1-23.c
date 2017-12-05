#include <stdio.h>
/* 

    remove all c program comments
    no nested comments

*/
#define MAX_BUFFER 1024

#define bool int
#define true 1
#define false 0

#define IN 1    // in comments
#define OUT 2   // out comments

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

bool isCommentBegin(char s[], int i) {
    return s[i] == '/' && s[i+1] == '*';
}

bool isDoubleSlashes(char s[], int i) {
    return s[i] == '/' && s[i+1] == '/';
}

bool isCommentEnd(char s[], int i) {
    return s[i] == '*' && s[i+1] == '/';
}

bool isBlankLine(char s[]) {
    int i;
    i = 0;
    while (s[i]!='\0') {
        if (s[i] != '\n' && s[i] != ' ') return false;
        i++;
    }
    return true;
}

void removeComments(char Buffer[], int idx, int offset) {
    int j,n;
    if (Buffer[offset] == '\n' || Buffer[offset] == '\0') {
        Buffer[idx] = '\n';
        Buffer[idx+1] = '\0';
    } else {
        for (j = idx, n=0; j < offset; j++, n++) 
            Buffer[j] = Buffer[offset+n];   
    }
}

void removeCommentsOfSize(char Buffer[], int idx, int offset, int size) {
    int j,n;
    if (Buffer[offset] == '\n' || Buffer[offset] == '\0') {
        Buffer[idx] = '\n';
        Buffer[idx+1] = '\0';
    } else {
        for (j = idx, n=0; j < size && Buffer[j] != '\0'; j++, n++) 
            Buffer[j] = Buffer[offset+n];   
    }
}

int main() {    
    char Buffer[MAX_BUFFER]; 
    int i, k, state, len;    

    state = OUT; /* if in a comment state - default out */

    while( (len=getLine(Buffer, MAX_BUFFER)) > 0 ) {
        i = 0;
        while(Buffer[i]!='\0') {

            if (state == IN && isCommentEnd(Buffer, i)) { // multiple comments found here                            
                // condition
                // */ int b = 0;
                state = OUT;                
                /* remove character from 0 to i+2 */
                removeCommentsOfSize(Buffer, 0, i+2, len);
                i = 0; /* important restart to scan comment flag */

            } else if (state == OUT && isCommentBegin(Buffer, i)) { // deal with simple /* comment */
                // no nested comments like /* comments  /* nested comments*/ */
                state = IN;
                // find end comment flag
                k = i + 2;
                while (Buffer[k] != '\0') {
                    if (isCommentEnd(Buffer, k)) {
                        state = OUT;
                        break;
                    }
                    k++;
                }     

                // we found the end comment flag
                if (state == OUT) {
                    removeComments(Buffer, i, k+2); 
                } else { // multiple comments end with /*
                    // ignore the rest chracters of tihs line
                    Buffer[i] = '\n';
                    Buffer[i+1] = '\0';
                    printf("%s", Buffer);
                    break;
                }

            } else if (isDoubleSlashes(Buffer, i)) { // deal with //
                // simple remove the rest of this line
                Buffer[i] = '\n';
                Buffer[i+1] = '\0';
                break;
            }

            i++; 
        } 

        if (state == IN) continue; /* multiple comments not finish yet */
        // output this line if not blanks
        if (!isBlankLine(Buffer)) printf("%s", Buffer);
    }    
    
    return 0;
}






