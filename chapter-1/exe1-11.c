#include <stdio.h>

/* count lines, words, and characters in input */

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */


// 1. 测试文件 ./a.out < file
// 2. 还有很多特殊字符"\v..."未考虑进来
int main() {
    int c, nl, nw, nc, state; 
    state = OUT;
    nl = nw = nc = 0;

    while((c = getchar()) != EOF) { 
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;  
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("lines: %d, words: %d, characters: %d", nl, nw, nc);
    return 0;
}
