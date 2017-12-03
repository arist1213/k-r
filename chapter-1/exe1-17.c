#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define UP 60 /* print lines beyond this number */
int getLine(char line[], int maxline);

/* print all input lines are longer than 80 characters */
int main() {

    int i, len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0)
        if (len > UP) {
            printf("%s", line);
            /* clear line */
            while (len>0)
                line[len--] = ' ';
        }
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim) {
    int c,i;
    // 最大只会获取 lim 长度的文本
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0'; /* end of line */
    return i;
}

