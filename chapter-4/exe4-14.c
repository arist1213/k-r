#include <stdio.h>
#define swap(t,x,y) {t t##__; t##__ = x; x = y; y = t##__;}

int main(void)
{
    int x = 1;
    int y = 2;
    printf("x: %d, y: %d\n", x, y);
    swap(int, x, y);
    printf("x: %d, y: %d\n", x, y);

    float x1 = 1.1;
    float y1 = 1.2;
    printf("x1: %g, y1: %g\n", x1, y1);
    swap(float, x1, y1);
    printf("x1: %g, y1: %g\n", x1, y1);

    return 0;
}

