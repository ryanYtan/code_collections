#include <stdio.h>
#include <stdlib.h>

long search(long *a, long i, long j, long q)
{
    if (i > j) {
        return -1;
    }

    long mid = i + (j - i) / 2;
    if (a[mid] == q) {
        return mid;
    }

    if (a[i] <= a[j]) {
        if (q < a[mid]) {
            return search(a, i, mid - 1, q);
        }
        return search(a, mid + 1, j, q);
    }

    if (a[i] <= a[mid] && a[mid] >= a[j]) {
        if (a[mid] < q || q < a[i]) {
            return search(a, mid + 1, j, q);
        }
        return search(a, i, mid - 1, q);
    }

    if (q < a[mid] || a[j] < q) {
        return search(a, i, mid - 1, q);
    }
    return search(a, mid + 1, j, q);
}

int main()
{
    long n, q;
    scanf("%ld", &n);
    long *a = calloc(n, sizeof(*a));
    for (long i = 0; i < n; i++) {
        scanf("%ld", &a[i]);
    }
    scanf("%ld", &q);

    long index = search(a, 0, n - 1, q);
    if (index == -1) {
        printf("not found\n");
    } else {
        printf("%ld\n", index);
    }

    free(a);
}
