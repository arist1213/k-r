#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

char pattern1[] = "ot"; /* pattern to search for */
char pattern2[] = "ould"; /* pattern to search for */

int main() {

	char line[MAXLINE];
	int found = 0;
	int index;

	while(getLine(line, MAXLINE) > 0) {
		if ((index = strindex(line, pattern1)) >= 0) {
			printf("strindex:   %s found at %d\n", line, index);
			found++;
		}
		if ((index = strrindex(line, pattern2)) >= 0) {
			printf("strrindex:  %s found at %d\n", line, index);
			found++;
		}
	}

	return found;
}

/* getLine: get line into s, return length */
int getLine(char s[], int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c!='\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i,j,k;

	for (i = 0; s[i]!='\0'; i++) {
		for (j = i, k = 0; t[k]!='\0' && s[j]==t[k]; j++, k++) 
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}

/* strindex: search from backwards, return index of t in s, -1 if none */
int strrindex(char s[], char t[]) {
	int i,j,k;
	int ls = strlen(s);

	for (i = ls-1; i>=0; i--) {
		for (j = i, k = 0; t[k]!='\0' && s[j]==t[k]; j++, k++) 
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}
