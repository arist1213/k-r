#include <stdio.h>
#include <string.h>

void reverse(char s[], int i, int j) {
    char c;
    if (i < j) {        
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverse(s, ++i, --j);
    }
}

int main(void)
{
    char s[] = "Hamlet, son to the former, and nephew to the present king.";
    
    printf("%s %d\n", s, (int) strlen(s)-1);
    reverse(s, 0, (int) strlen(s) - 1);
    printf("%s\n", s); 
    
    return 0;
}

