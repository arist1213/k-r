#include <stdio.h>
#include <stdlib.h> /* for atof() - in K&R, math.h is referenced - this is an anachronism */
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER 0 /* signal that a number was found */
#define MATH_IDENTIFY 1 /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* extra commands */
void top();
void dup();
void swapt();
void cs();

void doMath(char []);

/* reverse Polish calculator */

int main(void)
{
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF)
  {
    switch(type)
    {
      case NUMBER:
        push(atof(s));
        break;
      case MATH_IDENTIFY:
        doMath(s);
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;      
      case '/':
        op2 = pop();
        if(op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        if (op2)
        	push(fmod(pop(), op2));
        else
        	printf("error: zero modulus\n");	       
        break;

      case '?': top(); break;
      case '@': dup(); break;
      case '$': swapt(); break;
      case '~': cs(); break;

      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }

  return 0;
}

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else
  {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* top: to print top of stack */
void top()
{
	if (sp > 0) {
		printf("top element is %g\n", val[sp-1]);
	} else {
		printf("error: stack empty\n");
	}
}
/* dup: duplicate top element */
void dup()
{
	double d = top();
	push(d);
  push(d);
}
/* swapt: swap top two elements */
void swapt()
{
	double t1 = pop();
	double t2 = pop();
	push(t1);
	push(t2);
}
/* cs: clear stack */
void cs() {
	sp = 0;
}

void doMath(char s[]) 
{
    double op2;
    if (0 == strcmp(s, 'sin')) {
        push(sin(pop()));
    } else if (0 == strcmp(s, 'cos')) {
        push(cos(pop()));
    } else if (0 == strcmp(s, 'exp')) {
        push(exp(pop()));
    } else if (0 == strcmp(s, 'pow')) {
        op2 = pop();
        push(exp(pop(), op2));
    } else {
        printf("%s is not supported math function\n", s);
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
  int i, c;

  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';

  /* is a valid alpha */
  if(isalpha(c))
  {
      i = 0;
      while(isalpha(s[i++] = c))
         c = getch();     
      s[i - 1] = '\0';
      if(c != EOF)
         ungetch(c);
      return MATH_IDENTIFY;
   }

  if(!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if(isdigit(c)) /* collect integer part */
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}