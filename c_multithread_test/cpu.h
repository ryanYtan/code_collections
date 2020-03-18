#include <time.h>

void _function(int n)
{
        int lps = n * 5000;
        double y, z;
        for (int i = 0; i < lps; i++) {
                for (int j = 0; j < 1000; j++) {
                        y = ((double)lps) / (lps - i + 1);
                        z = (y * y * z) * i / (double)lps;
                }
        }
}
