#include <stdio.h>

/* count blanks, tabs, and newlines in input; */
int main() {
    int c, nl, nb, nt;
    nl = 0;
    nb = 0;
    nt = 0;
    while((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt; 
    }
    printf("blanks: %d, lines: %d, tabs: %d\n", nb, nl, nt);
    return 0;
}
