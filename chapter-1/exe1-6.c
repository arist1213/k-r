#include <stdio.h>

int main() {
    int c;
    int flag;
    flag = getchar() != EOF;
    // control + d = 0
    printf("flag: %d", flag);
}
