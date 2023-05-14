#include <stdio.h>

void draw_square(long row, long width)
{
    	if (row == 0 || row == width - 1) {
    	    	for (long i = 0; i < width; i++) {
    	    	    	printf("#");
    	    	}
    	    	return;
    	}
    	if (row == 1 || row == width - 2) {
    	    	printf("#");
    	    	for (long i = 1; i < width - 1; i++) {
    	    	    	printf(" ");
    	    	}
    	    	printf("#");
    	    	return;
    	}
    	printf("# ");
    	draw_square(row - 2, width - 4);
    	printf(" #");
}

int main()
{
    	long n;
    	scanf("%ld", &n);

    	for (long i = 0; i < n; i++) {
    	    	draw_square(i, n);
    	    	printf("\n");
    	}
}
