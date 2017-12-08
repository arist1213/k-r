#include <stdio.h>
#include <time.h>

#define MAX_ELEMENT 2000000
#define MAX_ITER_TIME 10000000 /* 查找次数*/

/* two tests */
int binarySearch1(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (v[mid] < x)
            low = mid + 1;
        else
            return mid;
    }

    return -1;
}

/* one test */
int binarySearch2(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n;
    /* 在区间[low, high)查找x */
    while (low < high - 1) {
        mid = (low + high) >> 1; // 以mid为中心
        // 比较后查找 [low, mid) 或 [mid, high)
        if (x < v[mid])
            high = mid;
        else
            low = mid;
    } //出口时, high = low + 1, 查找区间仅剩 v[low] - [low, high)
    return v[low] == x ? low : -1;
}

int main(int argc, char *argv[]) {
    int testdata[MAX_ELEMENT];
    int i;
    int index;
    clock_t time_taken;
    int n = 1; // 查找当前元素，测试查找时间效率
    
    printf("search element %d in %d sizes for %d times.\n", n, MAX_ELEMENT, MAX_ITER_TIME);

    for ( i = 0; i < MAX_ELEMENT; ++i )
        testdata[i] = i;

    for(i=0, time_taken = clock(); i < MAX_ITER_TIME; i++)
        binarySearch1(n, testdata, MAX_ELEMENT);

    time_taken = clock() - time_taken;
    printf("binarySearch1 took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);

    for(i=0, time_taken = clock(); i < MAX_ITER_TIME; i++) 
        binarySearch2(n, testdata, MAX_ELEMENT);

    time_taken = clock() - time_taken;
    printf("binarySearch2 took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
    return 0;
}