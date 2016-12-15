#include <stdio.h>

int
search(int vec[], int low, int high, int k)
{
    int mid, lo = low, hi = high;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (k > vec[mid])
            lo = mid + 1;
        else if (k < vec[mid])
            hi = mid - 1;
        else if (k == vec[mid])
            return k;
        else
            return -1;
    }

    return -1;
}

int
main(void)
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

    if (search(a, 0, 7, 5) != -1)
        puts("found k");
    return 0;
}
