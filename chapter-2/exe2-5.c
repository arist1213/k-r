#include <stdio.h>

/* returns the first location int the string s1
where any character from the string s2 occurs or -1 if not found*/
// strpos php ?
int any(char s1[], char s2[]) {
    int i,j,k,n,ss;
    ss = i = 0;

    while(s2[ss]!='\0')
        ss++;
    if (ss == 0) return -1;

    while(s1[i]!='\0') {
        // check if s2 match s1 from the first character to last resonable place
        k = i;
        n = 0;
        j = 0;
        while(s2[j]!='\0') 
            if (s2[j++] == s1[k++]) n++;
        if (n==ss) 
            return i; /* found the match, return the first locate of string s2 in s1 */
        ++i;
    }   

    return -1;
}

int main(int argc, char *argv[]) {
    printf("s1: %s\n", argv[1]);
    printf("s2: %s\n", argv[2]);
    printf("any: %d\n", any(argv[1], argv[2]));
    return 0;
}