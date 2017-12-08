#include <stdio.h>
#include <stdlib.h>

/* count 1 bits in x */
int bitcount(unsigned x) {
    int b;
    for(b = 0; x != 0; x>>=1)
        if (x & 01)
            b++;
    return b;
}

/* 
fast version of count bits
x&=(x-1) 
1. 当x是奇数 x-1 == x&(x-1) 效果相同
2. 当x是偶数 会清除最右边的1-bit

python
n = 50
def b(x):
    '{0:b}'.format(x)
while n > 0:
    '%2d %10s %2d %10s'%(n, b(n), (n)&(n-1), b((n)&(n-1)))
    n = n - 2

'50     110010 48     110000'
'48     110000 32     100000'
'46     101110 44     101100'
'44     101100 40     101000'
'42     101010 40     101000'
'40     101000 32     100000'
'38     100110 36     100100'
'36     100100 32     100000'
'34     100010 32     100000'
'32     100000  0          0'
'30      11110 28      11100'
'28      11100 24      11000'
'26      11010 24      11000'
'24      11000 16      10000'
'22      10110 20      10100'
'20      10100 16      10000'
'18      10010 16      10000'
'16      10000  0          0'
'14       1110 12       1100'
'12       1100  8       1000'
'10       1010  8       1000'
' 8       1000  0          0'
' 6        110  4        100'
' 4        100  0          0'
' 2         10  0          0'

 */
int bitcount2(unsigned x) {
    int b;
    for(b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}

int main(int argc, char *argv[]) {
    unsigned x = strtol(argv[1], NULL, 10);
    printf("%d\n", x);
    printf("%d\n", bitcount(x));
    printf("%d\n", bitcount2(x));
    return 0;
}