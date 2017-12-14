#include <stdio.h>

/* strcat: copies the string t to the end of s */
void strcat(char *s, char *t) 
{
    if (*s) /* if s is empty*/
        while (*++s);   
    while(*s++ = *t++); /* 如果s没有足够的空间，只会复制s允许范围 */
}

int main()
{
    char buf[1024];
    char *s1 = " hello, world";

    strcat(buf, s1);    
    strcat(buf, s1); // s1 没有指向字符串的末尾
    strcat(buf, s1);
    strcat(buf, s1);

    printf("%s\n", buf);
    return 0;
}