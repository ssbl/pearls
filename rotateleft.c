#include <stdio.h>

#define NMAX 50000000

void
rotate_tmp(int vector[], int len, int places)
{
    int ptr = 0, tmp, nleft = places;

    while (nleft > 0) {
        tmp = vector[ptr];

        for (int i = places + ptr; i < len; i += places)
            vector[i - places] = vector[i];

        vector[len - places + ptr] = tmp;
        ptr += 1;
        nleft -= 1;
    }
}

void
reverse(int vector[], int len, int left, int right)
{
    int tmp, leftptr = left, rightptr = right;

    while (leftptr < rightptr) {
        tmp = vector[leftptr];
        vector[leftptr] = vector[rightptr];
        vector[rightptr] = tmp;

        leftptr += 1;
        rightptr -= 1;
    }
}

void
rotate_reverse(int vector[], int len, int places)
{
    reverse(vector, len, 0, places - 1);
    reverse(vector, len, places, len - 1);
    reverse(vector, len, 0, len - 1);
}

int *
sample_vector()
{
    static int v[NMAX];

    for (int i = 0; i < NMAX; i++)
        v[i] = i;

    return v;
}

void
print_vector(int vector[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", vector[i]);
    printf("\n");
}

int
main(void)
{
    int len = NMAX;
    int *sample = sample_vector();

    rotate_tmp(sample, len, 6000000);
}
