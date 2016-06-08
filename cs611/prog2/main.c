/*
    main driver for grading program 2, cs611 Spring 2001

    The program simply calls the routine DoubleAdd with
    a series of contant parameters. The parameters
    and the result are displayed in both float and hex
    formats.

    DoubleAdd is emulating IEEE 64-bit floating point addition
    using only integer operations.

    This program must be ran on a machine where sizeof(long) == 8.

    Author: Phil Hatcher

*/

#include <signal.h>

/* following union is used to pass/return a double as an long to DoubleAdd */
typedef union {
    double d;
    long l;
} DOUB_LONG;

/* prototypes follow */
int DoubleAdd (long, long);

void Display (DOUB_LONG, DOUB_LONG, DOUB_LONG);

void TestHex(long a, long b);

void TestDouble(double a, double b);

int IsNaN(long val);

int IsZero(long val);

/* set the following to 1 to see all cases displayed */
#define ALWAYS_PRINT 0

main()
{
    /* Alpha/OSF (at least) requires us to request that SIGFPE be ignored */

    signal(SIGFPE, SIG_IGN);
	
    /* First, some easy ones */

    printf("\nEasy Ones\n");

    TestDouble(1.0, 2.0);

    TestDouble(5.0, 2.0);

    TestHex(0x4010000000000000L, 0x400000000000001EL);

    TestHex(0x4030000000000000L, 0x400E200000000000L);

    /* How about negative inputs? */

    printf("\nNegative Inputs\n");

    TestDouble(3.0, -1.0);

    TestHex(0x430000000000000FL, 0xC00E000000000000L);

    TestHex(0xC00E00000000000FL, 0x430000000000000FL);

    TestDouble(-1.0, -2.0);

    TestHex(0xC30000000000000FL, 0x400E000000000000L);

    /* How about normalization? */

    printf("\nNormalization\n");

    TestDouble(1.0, 1.0);

    TestHex(0x400000000000000FL, 0xC000000000000000L);

    /* How about rounding? */

    printf("\nRounding - 1 bit\n");

    TestHex(0x4010000000000000L, 0x4000000000000000L);    /* 1 bit shift */

    TestHex(0x4010000000000000L, 0x4000000000000001L);

    TestHex(0x4010000000000001L, 0x4000000000000000L);

    TestHex(0x4010000000000001L, 0x4000000000000001L);

    printf("\nRounding - 2 bit\n");

    TestHex(0x4020000000000000L, 0x4000000000000000L);    /* 2 bit shift */

    TestHex(0x4020000000000000L, 0x4000000000000001L);

    TestHex(0x4020000000000000L, 0x4000000000000002L);

    TestHex(0x4020000000000000L, 0x4000000000000003L);

    TestHex(0x4020000000000001L, 0x4000000000000000L);

    TestHex(0x4020000000000001L, 0x4000000000000001L);

    TestHex(0x4020000000000001L, 0x4000000000000002L);

    TestHex(0x4020000000000001L, 0x4000000000000003L);

    printf("\nRounding - 3 bit\n");

    TestHex(0x4030000000000000L, 0x4000000000000000L);    /* 3 bit shift */

    TestHex(0x4030000000000000L, 0x4000000000000001L);

    TestHex(0x4030000000000000L, 0x4000000000000002L);

    TestHex(0x4030000000000000L, 0x4000000000000003L);

    TestHex(0x4030000000000000L, 0x4000000000000004L);

    TestHex(0x4030000000000000L, 0x4000000000000005L);

    TestHex(0x4030000000000000L, 0x4000000000000006L);

    TestHex(0x4030000000000000L, 0x4000000000000007L);

    TestHex(0x4030000000000001L, 0x4000000000000000L);

    TestHex(0x4030000000000001L, 0x4000000000000001L);

    TestHex(0x4030000000000001L, 0x4000000000000002L);

    TestHex(0x4030000000000001L, 0x4000000000000003L);

    TestHex(0x4030000000000001L, 0x4000000000000004L);

    TestHex(0x4030000000000001L, 0x4000000000000005L);

    TestHex(0x4030000000000001L, 0x4000000000000006L);

    TestHex(0x4030000000000001L, 0x4000000000000007L);

    printf("\nRounding - 4 bit\n");

    TestHex(0x4040000000000000L, 0x4000000000000000L);    /* 4 bit shift */

    TestHex(0x4040000000000000L, 0x4000000000000001L);

    TestHex(0x4040000000000000L, 0x4000000000000002L);

    TestHex(0x4040000000000000L, 0x4000000000000003L);

    TestHex(0x4040000000000000L, 0x4000000000000004L);

    TestHex(0x4040000000000000L, 0x4000000000000005L);

    TestHex(0x4040000000000000L, 0x4000000000000006L);

    TestHex(0x4040000000000000L, 0x4000000000000007L);

    TestHex(0x4040000000000000L, 0x4000000000000008L);

    TestHex(0x4040000000000000L, 0x4000000000000009L);

    TestHex(0x4040000000000000L, 0x400000000000000AL);

    TestHex(0x4040000000000000L, 0x400000000000000BL);

    TestHex(0x4040000000000000L, 0x400000000000000CL);

    TestHex(0x4040000000000000L, 0x400000000000000DL);

    TestHex(0x4040000000000000L, 0x400000000000000EL);

    TestHex(0x4040000000000000L, 0x400000000000000FL);

    TestHex(0x4040000000000001L, 0x4000000000000000L);

    TestHex(0x4040000000000001L, 0x4000000000000001L);

    TestHex(0x4040000000000001L, 0x4000000000000002L);

    TestHex(0x4040000000000001L, 0x4000000000000003L);

    TestHex(0x4040000000000001L, 0x4000000000000004L);

    TestHex(0x4040000000000001L, 0x4000000000000005L);

    TestHex(0x4040000000000001L, 0x4000000000000006L);

    TestHex(0x4040000000000001L, 0x4000000000000007L);

    TestHex(0x4040000000000001L, 0x4000000000000008L);

    TestHex(0x4040000000000001L, 0x4000000000000009L);

    TestHex(0x4040000000000001L, 0x400000000000000AL);

    TestHex(0x4040000000000001L, 0x400000000000000BL);

    TestHex(0x4040000000000001L, 0x400000000000000CL);

    TestHex(0x4040000000000001L, 0x400000000000000DL);

    TestHex(0x4040000000000001L, 0x400000000000000EL);

    TestHex(0x4040000000000001L, 0x400000000000000FL);

    printf("\nRounding - sticky bit, etc\n");

    TestHex(0x40A0000000000000L, 0x4000000000000201L);   /* test sticky bit */

    TestHex(0x4007FFFFFFFFFFFFL, 0x4340000000000000L);   /* again */

    TestHex(0x4040000000000001L, 0x4000000000000005L);   /* subtract w/sticky */

    TestHex(0x40AFF80000000000L, 0x400FFFFFFFFFFFFFL);   /* rounding causes 
                                                            re-normalization */

    TestHex(0x40AC000000000000L, 0x4004000000000005L);   /* round or normalize
                                                            result first? */

    /* How about zero, NaN, infinity? */

    printf("\nSpecial Cases - overflow\n");

    TestHex(0x7FE0000000000000L, 0x7FE0000000000000L);   /* overflow to
                                                            +infinity */

    TestHex(0xFFE0000000000000L, 0xFFE0000000000000L);   /* overflow to
                                                            -infinity */

    printf("\nSpecial Cases - NaN in\n");

    TestHex(0x7FF0000000000001L, 0x3FF0000000000000L);   /* NaN plus 1 */

    TestHex(0x3FF0000000000000L, 0x7FF1000000000000L);   /* 1 plus NaN */

    printf("\nSpecial Cases - NaN out\n");

    TestHex(0x7FF0000000000000L, 0xFFF0000000000000L);   /* +Infinity plus
                                                            -Infinity */

    printf("\nSpecial Cases - Infinity in\n");

    TestHex(0x7FF0000000000000L, 0x3FF0000000000000L);   /* +Infinity plus 1 */

    TestHex(0x7FF0000000000000L, 0xBFF0000000000000L);   /* +Infinity plus -1 */
    
    TestHex(0xFFF0000000000000L, 0x3FF0000000000000L);   /* -Infinity plus 1 */
    
    TestHex(0xFFF0000000000000L, 0xBFF0000000000000L);   /* -Infinity plus -1 */

    printf("\nSpecial Cases - zero\n");

    TestDouble(0.0, 1.0);

    TestDouble(1.0, -1.0);

    printf("\nDone.\n");
}

/* Test given hex specification for float values */
void TestHex(long a, long b)
{
    DOUB_LONG param1, param2, result, check;

    param1.l = a;
    param2.l = b;
    check.d = param1.d + param2.d;
    result.l = DoubleAdd (param1.l, param2.l);
#if ALWAYS_PRINT
 printf("\n");
 Display(param1, param2, result);
#endif
    if (result.l != check.l && !(IsNaN(result.l) && IsNaN(check.l)) &&
                               !(IsZero(result.l) && IsZero(check.l)))
    {
        printf("\nFailed! Answer should be %e (%08lx).\n", check.d, check.l);
        Display(param1, param2, result);
        printf("\n");
    }
}

/* Test given float values */
void TestDouble(double a, double b)
{
    DOUB_LONG param1, param2, result, check;

    param1.d = a;
    param2.d = b;
    check.d = param1.d + param2.d;
    result.l = DoubleAdd (param1.l, param2.l);
#if ALWAYS_PRINT
 printf("\n");
 Display(param1, param2, result);
#endif
    if (result.l != check.l && !(IsNaN(result.l) && IsNaN(check.l)) &&
                               !(IsZero(result.l) && IsZero(check.l)))
    {
        printf("\nFailed! Answer should be %e (%08lx).\n", check.d, check.l);
        Display(param1, param2, result);
        printf("\n");
    }
}

/* Displays DOUB_LONG unions in both double and hex formats.*/
void Display(DOUB_LONG param1, DOUB_LONG param2, DOUB_LONG result)
{
    printf("%e (%08lx) plus %e (%08lx) is %e (%08lx)\n",
        param1.d, param1.l,
        param2.d, param2.l,
        result.d, result.l
    );
}


/* check if the bit pattern specifies a floating point NaN */
int IsNaN(long val)
{
    long exp_all_ones = ((val & 0x7ff0000000000000L) == 0x7ff0000000000000L);
    long signif_not_all_zeroes = (val & 0x000fffffffffffffL);
    return exp_all_ones && signif_not_all_zeroes;
}

/* check if the bit pattern specifies a floating point zero */
/* NOTE: treats denormalized numbers as zero */
int IsZero(long val)
{
    return !(val & 0x7ff0000000000000L);
}

