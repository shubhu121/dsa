#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int n)
{
    int *A, i;

    A = (int *)malloc(n * sizeof(int));
    A[0] = 1 + rand() % 10;
    for (i = 1; i < n; ++i)
        A[i] = (rand() % 2) ? A[i - 1] : A[i - 1] + 1 + (rand() % 3);
    return A;
}

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%5d ", A[i]);
        if (i % 12 == 11)
            printf("\n");
    }
    if (i % 12)
        printf("\n");
}

/**** FOR STUDENTS WHOSE PC NUMBERS ARE NEITHER EVEN NOR ODD ****/
/* Function that returns the number of elements in A that are < x.
 * The binary search algorithm is modified. The search range is [L,R].
 * In the loop, we maintain the invariance that A[L-1] < x and A[R] >= x.
 * The binary search loop stops when L = R. By the invariance, we then have
 * A[L-1] < x <= A[L]. That is, L stores the index of the first element
 * in A that is larger than or equal to x. This L is the desired count.
 */
int ltCount(int *A, int n, int x)
{
    int L, R, M;

    if (A[0] >= x)
        return 0;
    if (A[n - 1] < x)
        return n;
    L = 1;
    R = n - 1;
    while (L < R)
    {
        M = (L + R) / 2;
        if (A[M] >= x)
            R = M;
        else
            L = M + 1;
    }
    return L;
}

/**** FOR STUDENTS WITH ODD PC NUMBERS ****/
/* Function that returns the number of elements in A that are <= x.
 * The binary search algorithm is modified. The search range is [L,R].
 * In the loop, we maintain the invariance that A[L-1] <= x and A[R] > x.
 * The binary search loop stops when L = R. By the invariance, we then have
 * A[L-1] <= x < A[L]. That is, L stores the index of the first element
 * in A that is larger than x. This L is the desired count.
 */
int leCount(int *A, int n, int x)
{
    int L, R, M;

    if (A[0] > x)
        return 0;
    if (A[n - 1] <= x)
        return n;
    L = 1;
    R = n - 1;
    while (L < R)
    {
        M = (L + R) / 2;
        if (A[M] > x)
            R = M;
        else
            L = M + 1;
    }
    return L;
}

/**** FOR STUDENTS WITH EVEN PC NUMBERS ****/
/* Function that returns the index of the first occurrence of x in A.
 * The binary search algorithm is modified. The search range is [L,R].
 * In the loop, we maintain the invariance that A[L-1] < x and A[R] >= x.
 * The binary search loop stops when L = R. By the invariance, we then have
 * A[L-1] < x <= A[L]. That is, L stores the index of the first element
 * in A that is larger than or equal to x. Then check whether A[L] = x.
 */
int firstOcc(int *A, int n, int x)
{
    int L, R, M;

    if (A[0] == x)
        return 0;
    if (A[0] > x)
        return -1;
    if (A[n - 1] < x)
        return -1;
    L = 1;
    R = n - 1;
    while (L < R)
    {
        M = (L + R) / 2;
        if (A[M] >= x)
            R = M;
        else
            L = M + 1;
    }
    return (A[L] == x) ? L : -1;
}

int main(int argc, char *argv[])
{
    int n, *A, c1, c2, x;

    srand((unsigned int)time(NULL));
    if (argc > 1)
        n = atoi(argv[1]);
    else
    {
        printf("n = ");
        scanf("%d", &n);
    }
    A = createArray(n);
    printArray(A, n);
    while (1)
    {
        printf("\nx = ");
        scanf("%d", &x);
        if (x <= 0)
            break;

        printf("\n*** For students with ODD PC numbers:\n");
        c1 = leCount(A, n, x - 1);
        c2 = leCount(A, n, x);
        printf("    Number of elements less than %d is %d\n", x, c1);
        printf("    Number of elements less than or equal to %d is %d\n", x, c2);
        printf("    Number of occurrences of %d is %d\n", x, c2 - c1);

        printf("\n*** For students with EVEN PC numbers:\n");
        c1 = firstOcc(A, n, x);
        printf("    Index of the first occurrence of %d is %d\n", x, c1);
        if (c1 == -1)
        {
            printf("    Number of occurrences of %d is %d\n", x, 0);
        }
        else
        {
            c2 = firstOcc(A, n, x + 1);
            if (c2 == -1)
                c2 = firstOcc(A, n, x + 2);
            if (c2 == -1)
                c2 = firstOcc(A, n, x + 3);
            if (c2 == -1)
                c2 = n;
            printf("    Number of occurrences of %d is %d\n", x, c2 - c1);
        }

        printf("\n*** For the rest of the students:\n");
        c1 = ltCount(A, n, x);
        c2 = ltCount(A, n, x + 1);
        printf("    Number of elements less than %d is %d\n", x, c1);
        printf("    Number of elements less than or equal to %d is %d\n", x, c2);
        printf("    Number of occurrences of %d is %d\n", x, c2 - c1);
    }
    free(A);
    exit(0);
}