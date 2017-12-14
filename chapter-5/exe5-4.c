#include <stdio.h>

int strlen(char *s) 
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p-s;
}

int strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

/* strend:  return 1 if the string t occurs at the end of the string s, and zero otherwise */
int strend(char *s, char *t) 
{
    int slen = 0, tlen = 0, result = 0;

    slen = strlen(s);
    tlen = strlen(t);

    if (tlen == 0 && slen > 0) return result;

    if (tlen <= slen) {
        s += slen - tlen; 
        if (strcmp(s, t) == 0) {
            result = 1;
        }    
    }

    return result;
}

/* strend:  return 1 if the string t occurs at the end of the string s, and zero otherwise */
int __strend(char *s, char *t) 
{
    int slen = 0, tlen = 0;
    // get string len
    while (*t++)
        tlen++;
    while (*s++)
        slen++;     
    if (tlen > slen || (tlen == 0 && slen != 0)) return 0;
    // reset point
    s-=slen+1;
    t-=tlen+1;
    // compare from s+j-i
    s += slen - tlen;
    for (; *s == *t; s++, t++)
        if (*s=='\0')
            return 1;

    return 0;
}

int main()
{
    char *s = "hello, world";
    char *t[] = {
        "",
        "h",
        "d",
        "world",
        "123",
        "456",
        "hello",
        "hello, world",
        "this is long string."
    };
    size_t n = sizeof t / sizeof t[0];
    size_t i;

    for (i = 0; i < n; i++) {
        //strend(s, t[i]);
        printf("%10s\t%10s\t%2d\n", s, t[i], strend(s, t[i]));
    }
    return 0;
}