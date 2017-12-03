#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
#define SIZE 15 /*最大单词长度*/
/* print a histogram of the lengths of words in its input */

int main() {
    int c, i, j, state, count, max; 
    state = OUT;
    count = 0; /* 单词长度计数器 */
    int nlen[SIZE]; /* 统计SIZE个字符长度的单词的直方图，超过SIZE，按ZIE-1算 */

    max = 0; /* 追踪长的单词 */
    for(i = 0; i < SIZE; ++i)
        nlen[i] = 0;

    while((c = getchar()) != EOF) {  
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) { 
                if (count >= SIZE) count = SIZE - 1;
                ++nlen[count];
                count = 0; /* 计数器归零 */
            }
            state = OUT;  
        } else {
            ++count;
            if (state == OUT) {
                state = IN;
            }
        }
    }
 
    // print bar histogram 
    for (i = 0; i < SIZE; ++i) {
        //printf("%2d ", i);
        for (j = 0; j < nlen[i]; ++j) 
            printf("*");
        printf("\n");
        // track max number of words length
        if (nlen[i] > max)
            max = nlen[i];
    }
    // print vertical histogram 
    // max = max >= SIZE ? max : SIZE; 
    for (j = max - 1; j >= 0; --j) {
        for (i = 0; i < SIZE; ++i) {
            if (nlen[i] > j) printf(" * ");
            else printf("   ");
        }
        printf("\n");
    }
    return 0;
}
