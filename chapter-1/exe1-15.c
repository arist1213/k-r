#include <stdio.h>

#define LOWER 0
#define UPPER 200
#define STEP 20
float fahrToCesi(int);

int main() {
    int fahr;
    for(fahr = LOWER; fahr <= UPPER; fahr=fahr+STEP)
        printf("%3d %6.1f\n", fahr, fahrToCesi(fahr));
    return 0;
}

float fahrToCesi(int fahr) {
    return (5.0/9.0)*(fahr-32);
}
