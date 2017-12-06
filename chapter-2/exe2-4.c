#include <stdio.h>

/* delete each character in s1 that 
        match any character in the string s2 */
void squeeze(char s1[], char s2[]) {
    int i,j,k;
    char t;
    unsigned short isFound;

    for (i = j = 0; s1[i] != '\0'; i++) {
        k = 0;
        t = s1[i];
        isFound = 1;
        // loop each character in s2, not fast
        while (s2[k] != '\0') {
            if (t == s2[k]) {
                // found s1[i] in s2 need remove s1[i]
                isFound = 2;
                break;
            }
            k++;
        }
        if (isFound==1)
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
}

int main(int argc, char *argv[]) {
    printf("s1: %s\n", argv[1]);
    printf("s2: %s\n", argv[2]);

    squeeze(argv[1], argv[2]);

    printf("squeeze: %s\n", argv[1]);
    return 0;
}