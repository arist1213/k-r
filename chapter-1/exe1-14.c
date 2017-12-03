#include <stdio.h>

#define SIZE 128 /* ascii */

/* print a histogram of different characters in its input */
int main() {
    int c, i, j; 
    count = 0; /* 单词长度计数器 */
    int nlen[SIZE]; /* 统计SIZE个字符长度的单词的直方图，超过SIZE，按ZIE-1算 */

    max = 0; /* 追踪长的单词 */
    for(i = 0; i < SIZE; ++i)
        nlen[i] = 0;

    while((c = getchar()) != EOF) {  
        ++nlen[c]; 
    }
 
    // print bar histogram 
    for (i = 0; i < SIZE; ++i) {
        printf("%c ", i);
        for (j = 0; j < nlen[i]; ++j) 
            printf("*");
        printf("\n");
    }
    return 0;
}
