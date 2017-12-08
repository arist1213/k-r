#include <stdio.h>


void lower(char s[]) {
    int i;
    while (s[i]!='\0') {
        s[i] = (s[i]>'A' && s[i]<'Z') ? s[i]+'a'-'A': s[i];
        i++;
    }
}

int main(int argc, char *argv[]) {
    printf("%s\n", argv[1]);
    lower(argv[1]);
    printf("%s\n", argv[1]);
    return 0;
}