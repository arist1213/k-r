#include <stdio.h>

/* from K&R */
int getline(char s[], int lim) {
    
    int c,i;
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n') {
        s[i]='\n';
        i++;
    }
    
    s[i] = '\0';
    return i;
    
}

/* from K&R */
int getline2(char s[], int lim) {
    
    int c,i;
    for (i = 0; i < lim-1; ++i) {
        if ((c=getchar()) == EOF) 
            break;
        else if (c == '\n') 
            break;
        s[i]=c;
    }
        
    
    if (c == '\n') {
        s[i]='\n';
        i++;
    }
    
    s[i] = '\0';
    return i;
    
}

int main() {

}