#include <string.h>
#include <stdio.h>

/* Pictures of zero, largest positive and largest negative numbers. */
static const char *pat = "┌───┐\n"
                         "│   │\n"
                         "└───┘\n"
                         "├─┴─┤\n"
                         "┤   ├\n"
                         "├─┬─┤\n"
                         "┌┬┬┬┐\n"
                         "├   ┤\n"
                         "└┴┴┴┘\n";

/* Precomputed number of digits in a picture and byte size of it. */
#define SZD 8
#define SZP 42

/* Trits description in order from low to high values. */
struct ds
{
    int pos, len, exp, val;
} digit[SZD] = {
    {32, 3},
    {26, 6},
    {16, 8},
    {0, 6},
    {6, 3},
    {9, 7},
    {21, 5},
    {35, 7}
};

/* A number to convert and signed one to keep if it was negative. */
static int src = 0, inv = 1;

/* A buffer for the result. */
static char res[SZP + 1];

/* Use it like 'echo -42 | ./b3k' */
int main(int q, char *argv[])
{
    scanf("%d", &src);

    /* Split the value into its modulus and signed multiplier. */
    if (src < 0)
        src *= inv = -1;

    int r;

    digit[0].exp = 1;
    digit[0].val = 0;
    for (r = 1; r < SZD; ++r)
    {
        digit[r].exp = digit[r - 1].exp * 3;
        digit[r].val = 0;
    }

    /* Truncate to the largest allowed positive. */
    int t = 3 * digit[SZD - 1].exp / 2;
    r = 3 * p->exp / 2;
    if (src > t)
        src = t;
    else
        t = src;

    /* Like 'echo "obase=3; $src" | bc'. */
    do
    {
        for (r = SZD - 1; t < digit[r].exp;)
        {
            r--;
        }
        t -= digit[r].exp;
        digit[r].val++;
    } while (t != 0);

    /* Convert to the balanced form. */
    for (r = 0; r < SZD; r++)
    {
        if (t != 0)
            digit[r].val++;

        t = digit[r].val == 2;

        if (t != 0)
            digit[r].val = -1;

        digit[r].val *= inv;
    }

    /* Restore the sign. */
    src *= inv;

    /* Show the result. */
    int pos;
    for (r = 0; r < SZD; r++)
    {
        pos = digit[r].pos;
        if (digit[r].val == -1)
            pos = pos + 2 * SZP;

        if (digit[r].val == 1)
            pos = pos + SZP;

        strncpy(res + digit[r].pos,
                pat + pos,
                digit[r].len);
    }

    printf("%s", res);

    return 0;
}
