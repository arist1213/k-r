#include <stdio.h>
#include <ctype.h>

#define MAX_BUFFER 1024

/* expands shorthand notation like a-z in the stirng into the 
equivalent complete list abc...xyz */
void expand(char s1[], char s2[]) {
    int i, j, k, from, to;
    i = k = from = to = 0;
 
    if (s1[i] == '-') /* add leading */
        s2[i++] = '-';
    /* 
        a-b-c abc
        0-9 0123456789
        a-c abc
        a-z abcdef...xyz        
        a-Z abcd..xyzABCD...XYZ
        a-zA-Z 0-9  
    */

    while (s1[i]!='\0') {

        if (s1[i+1] == '-' && s1[i+2] != '\0') { 
            from = s1[i];
            to = s1[i+2];
            // [from, to]
            if (isalpha(from) && isalpha(to)) {
                if ((
                        (islower(from) && islower(to)) 
                        || (isupper(from) && isupper(to))
                    ) 
                    && from < to) {                
                    for(j = from; j <= to; j++)
                        s2[k++] = j;
                } else if (islower(from) && isupper(to)) {
                    // illeagal

                    // for(j = from; j <= 'z'; j++)
                    //     s2[k++] = j;
                    // for(j = 'A'; j <= to; j++)
                    //     s2[k++] = j;
                }

            } else if (isdigit(from) && isdigit(to) && from < to) {
                for(j = from; j <= to; j++)
                        s2[k++] = j;
            }
        }

        i+=3;
    }

    s2[k] = s1[i]; // end
}


int main(void) {
    char *sh[] = {
        "-a-e",
        "a-c",
        "a-d",
        "a-z",
        "A-S",
        "A-Z",
        "a-zA-Z",
        "a-Z",
        "0-9",
        "a-sA-S0-8",
    };

    size_t nums = sizeof sh / sizeof sh[0];
    size_t i = 0;
    char out[MAX_BUFFER];

    for(i=0; i<nums; i++) {
        printf("shorthand: %s\n", sh[i]);
        expand(sh[i], out);
        printf("expand: %s\n", out);        
    } 

    return 0;
}