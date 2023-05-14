#include <stdio.h>
#include <limits.h>

struct DigitCountResult {
        long digit;
        long count;
        long result;
};

struct DigitCountResult consume(long n)
{
        if (n <= 0) {
                return (struct DigitCountResult) { -1, LONG_MIN, 0 };
        }
        long digit = n % 10;
        long count = 0;
        while (n % 10 == digit) {
                n /= 10;
                count += 1;
        }
        return (struct DigitCountResult) { digit, count, n };
}

void replace(struct DigitCountResult *result, struct DigitCountResult *with)
{
        if (with->count > result->count
                        || (with->count == result->count
                                        && with->digit < result->digit)) {
                result->count = with->count;
                result->digit = with->digit;
        }
}

int main()
{
        long n;
        scanf("%ld", &n);

        long digit = 0;
        long longest_digit_count = -1;

        struct DigitCountResult final = { 0, -1, LONG_MAX };

        while (n > 0) {
                struct DigitCountResult ret = consume(n);
                replace(&final, &ret);
                n = ret.result;
        }
        printf("%ld\n", final.digit);
}
