#include <stdio.h>

#define MAX_BUFFER 1024

// assume s is big enough
void escape(char s[], char t[]) {
    int i, j;
    i = 0;
    j = 0;
    while(t[i]!='\0') {
        switch (t[i]) {
            case '\\': 
                s[j++] = '\\';
                s[j] = '\\';
                break;
            case '\n': 
                s[j++] = '\\';
                s[j] = 'n';
                break;
            case '\t': 
                s[j++] = '\\'; 
                s[j] = 't'; 
                break;
            case '\v': 
                s[j++] = '\\'; 
                s[j] = 'v'; 
                break;
            case '\a': 
                s[j++] = '\\'; 
                s[j] = 'a'; 
                break;
            case '\r': 
                s[j++] = '\\'; 
                s[j] = 'r'; 
                break;
            case '\b': 
                s[j++] = '\\'; 
                s[j] = 'b'; 
                break;
            default:
                s[j] = t[i];
            break;
        }
        i++;
        j++;
    }

}

void unescape(char s[], char t[]) {
    int i, j;
    i = 0;
    j = 0;
    while(t[i]!='\0') {
        if (t[i] == '\\') {

            switch(t[++i]) {
                case 'n': s[j] = '\n'; break;
                case 't': s[j] = '\t'; break;
                case 'b': s[j] = '\b'; break;
                case 'r': s[j] = '\r'; break;
                case 'a': s[j] = '\a'; break;
                case 'v': s[j] = '\v'; break;
                case '\\': s[j] = '\\'; break;
                default: 
                    s[j] = t[i];   
                break;
            }

        } else {
            s[j] = t[i];
        }
        i++;
        j++;
    }

    s[j] = t[i]; // copy \0 character
}

int main() {
    char f[] = "\tThis \bis\n how it's \twork \tthere, with some\vstrange escape \rwhich I never used before.";
    char t[MAX_BUFFER];
    char u[MAX_BUFFER];

    escape(t, f);
    printf("original:   %s\n", f);
    printf("escape:     %s\n", t);
    unescape(u, t);
    printf("unescape:   %s\n", u);

    return 0;
}