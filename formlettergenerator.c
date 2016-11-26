#include <stdio.h>

void
generate(char *fmt, char *args[])
{
    int index;
    char *ptr = fmt;

    while (*ptr != '\0') {
        if (*ptr != '$') {
            putchar(*ptr);
        } else if (*(++ptr) == '$') {
            putchar('$');
        } else if (*ptr - '0' >= 0 && *ptr - '0' < 10) {
            index = (int) *ptr - '0';
            printf("%s", args[index]);
        } else {
            fprintf(stderr, "bad schema\n");
            return;
        }
        ptr += 1;
    }
}

int
main(int argc, char *argv[])
{
    char *args[] = { "foo", "quux" };

    generate("hello $0, i'm $1\n", args);
    return 0;
}
