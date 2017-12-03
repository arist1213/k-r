#include <stdio.h>

/* revert the chracter string */
void reverse(char s[], int n);

int main() {    
    int i;
    char line[] = {'h','e','l','l','o'}; 
    printf("%s\n", line);
    reverse(line, 5);
    printf("%s\n", line);
}

void reverse(char s[], int n) {
    int k;
    char t;
    k = 0;
    while (k <= n) {
        t = s[k];
        s[k++] = s[--n];
        s[n] = t;
    } 
}
