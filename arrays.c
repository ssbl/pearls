#include <assert.h>
#include <stdio.h>
#include <string.h>

int
endswith(char *str, char *substr)
{
    int len = strlen(str), sublen = strlen(substr);

    if (len < sublen)
        return 0;

    for (int pos = 1; pos <= sublen; pos++)
        if (*(substr + sublen - pos) != *(str + len - pos))
            return 0;
    return 1;
}

char *
concat(char **parts)
{
    static char s[128];

    memset(s, 0, 128);
    for (int i = 0; parts[i]; i++)
        strcat(s, parts[i]);

    return s;
}

char *
add_hyphens(char *word, char **parts)
{
    int i, partix, partnum = 0, retix = 0;
    static char ret[128];

    memset(ret, 0, 128);
    for (i = 0, partix = 0; parts[partnum] && word[i]; i++) {
        if (parts[partnum][partix] == '\0') {
            ret[retix++] = '-';
            partix = 0;
            partnum += 1;
        }

        ret[retix++] = word[i];
        if (word[i] == parts[partnum][partix])
            partix += 1;
    }

    ret[retix] = 0;
    return ret;
}

char *
hyphenate(char *word, char **rules[])
{
    char *hyphenated = NULL;

    for (int i = 0; rules[i]; i++) {
        if (endswith(word, concat(rules[i]))) {
            hyphenated = add_hyphens(word, rules[i]);
            break;
        }
    }

    return hyphenated;
}

int
main(void)
{
    char **parts[4];
    char *rule1[64] = { "n", "tic" };
    char *rule2[64] = { "h", "nic" };

    parts[0] = rule1;
    parts[1] = rule2;
    printf("%s\n", hyphenate("ethnic", parts));
    return 0;
}
