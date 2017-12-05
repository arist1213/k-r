#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main() {

    // print the variable limit from limit.h
    printf("%s\n", "--- limit.h ---");

    printf("maximum of signed char              %d\n", CHAR_MAX);
    printf("minimum of signed of char           %d\n", SCHAR_MIN);    
    
    printf("maximum of unsigned of char         %d\n", UCHAR_MAX);

    printf("maximum of signed short             %d\n", SHRT_MAX);
    printf("minimum of signed short             %d\n", SHRT_MIN);

    printf("maximum of unsigned short           %d\n", USHRT_MAX);

    printf("maximum of signed int               %d\n", INT_MAX);
    printf("minimum of signed int               %d\n", INT_MIN);

    printf("maximum of unsigned int             %u\n", UINT_MAX);

    printf("maximum of signed long              %ld\n", LONG_MAX);
    printf("minimum of signed long              %ld\n", LONG_MIN);    

    printf("maximum of unsigned long            %lu\n", ULONG_MAX);

    printf("%s\n", "--- Computer ---");
    // computer  
    // char  1 2^8
    printf("maximum of signed char              %d\n", (char) (pow(2, 7) - 1));
    printf("minimum of signed char              %d\n", (char) pow(-2, 7));    

    printf("maximum of unsigned char            %d\n", (short) (pow(2, 8) - 1));

    // short 2 2^16
    printf("maximum of signed short             %d\n", (short) (pow(2, 15) - 1));
    printf("minimum of signed short             %d\n", (short) pow(-2, 15));    

    printf("maximum of unsigned short           %d\n", (int) (pow(2, 16) - 1));

    // int   4 2^32
    printf("maximum of signed int               %d\n", (int) (pow(2, 31) - 1));
    printf("minimum of signed int               %d\n", (int) pow(-2, 31));    

    printf("maximum of unsigned int             %ld\n",(long) (pow(2, 32) - 1));
    // long  8 2^64
    printf("maximum of signed long              %ld\n", (long) (pow(2, 63) - 1));
    printf("minimum of signed long              %ld\n", (long)  pow(-2, 63));    

    printf("maximum of unsigned long            %lu\n", (long) (pow(2, 64) - 1)); // not work
    // double 8 2^64
    
    /*
    output 
--- limit.h ---
maximum of signed char              127
minimum of signed of char           -128
maximum of unsigned of char         255
maximum of signed short             32767
minimum of signed short             -32768
maximum of unsigned short           65535
maximum of signed int               2147483647
minimum of signed int               -2147483648
maximum of unsigned int             4294967295
maximum of signed long              9223372036854775807
minimum of signed long              -9223372036854775808
maximum of unsigned long            18446744073709551615
--- Computer ---
maximum of signed char              127
minimum of signed char              -128
maximum of unsigned char            255
maximum of signed short             32767
minimum of signed short             -32768
maximum of unsigned short           65535
maximum of signed int               2147483647
minimum of signed int               -2147483648
maximum of unsigned int             4294967295
maximum of signed long              -9223372036854775808
minimum of signed long              -9223372036854775808
maximum of unsigned long            9223372036854775808
    */

    return 0;
}