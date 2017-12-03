#include <stdio.h>

#define IN 1
#define OUT 2
#define MAXLINE 1000 /* maximum input line size */
int getLine(char line[], int maxline);

/* remove trailing blanks and tabs from each line of input, and delete entirely blank lines */
int main() {
    int i, len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        printf("len: %d -> ", len); 
        if (len > 1) {
            for(i = 0; i < len; ++i)
                printf("%c ", line[i]);
            printf("\n");
            //printf("%s", line);
        } else {
            line[0] = ' '; // remove \n
        }
    }
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim) {
    int c,i,k,state;
    state = OUT;
    k = 0; /* track no trailing blanks and no tab character length */
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
        if (c==' ' || c=='\t') {
           if (state == IN)
               s[k++] = ' ';
           state = OUT; 
        } else {
            if (state == OUT)
                state = IN;
            s[k++] = c;
        }
    }
    if (c == '\n') {
        s[k++] = c;
    }
    s[k] = '\0'; /* end of line */
    return k;
}

