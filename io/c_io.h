/**
 * c_io.h
 */
#define IOE_SUCCESS 0   /* General success case */
#define IOE_FAILURE 1   /* General failure case */
#define IOE_RANGE 2     /* Number out-of-bounds */
#define IOE_INVAL 3     /* Unexpected input format */

char *read_word();
char *read_line();
int read_long(long*);
int read_int(int*);
int read_double(double*);
