#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 27000

void
bitmap_set(int val, uint8_t bitmap[])
{
    int loc = val / 8;
    int bit = val % 8;

    bitmap[loc] |= 1 << bit;
}

int
bitmap_isset(int val, uint8_t bitmap[])
{
    int loc = val / 8, bit = val % 8;

    return bitmap[loc] & (1 << bit);
}

int *
rand_ints(int len)
{
    int val, lastval = 0;
    static int ret[NMAX];
    uint8_t bitmap[NMAX / 8] = {0};

    for (int i = 0; i < len; i++) {
        val = rand() % NMAX;
        if (!bitmap_isset(val, bitmap)) {
            bitmap_set(val, bitmap);
        } else {
            for (val = lastval; val < NMAX; val++) {
                if (!bitmap_isset(val, bitmap)) {
                    bitmap_set(val, bitmap);
                    lastval = val;
                    break;
                }
            }
        }
        ret[i] = val;
    }

    return ret;
}

void
bitmapsort(int data[], int len)
{
    uint8_t bitmap[NMAX / 8] = {0};

    for (int i = 0; i < len; i++)
        bitmap_set(data[i], bitmap);

    for (int i = 0, index = 0; i < NMAX; i++)
        if (bitmap_isset(i, bitmap))
            data[index++] = i;
}

int
issorted(int data[], int len)
{
    for (int i = 0; i < len - 1; i++)
        if (data[i] > data[i + 1])
            return 0;
    return 1;
}

int
main(void)
{
    int len = rand() % NMAX;
    int *data = rand_ints(len);
    int *sorted;

    assert(!issorted(data, len));
    bitmapsort(data, len);
    assert(issorted(data, len));

    return 0;
}
