#include <stdio.h>
int main()
{
    int i = 0, j = 0, k = 1;
    int x1 = 0, y1 = 0, z1 = 0, x2 = 0, y2 = 0, z2 = 0;
    printf("Enter no of rows of matrix 1: ");
    scanf("%d", &x1);
    printf("Enter no of columns of matrix 1: ");
    scanf("%d", &y1);
    printf("Enter no of non-zero elements of matrix 1: ");
    scanf("%d", &z1);
    printf("Enter no of rows of matrix 2: ");
    scanf("%d", &x2);
    printf("Enter no of columns of matrix 2: ");
    scanf("%d", &y2);
    printf("Enter no of non-zero elements of matrix 2: ");
    scanf("%d", &z2);
    if (x1 != x2 || y1 != y2)
    {
        printf("Matrix addition is not possible.\n");
        return 0;
    }
    int S1[z1 + 1][3], S2[z2 + 1][3], S3[z1 + z2 + 1][3];
    S1[0][0] = x1;
    S1[0][1] = y1;
    S1[0][2] = z1;
    S2[0][0] = x2;
    S2[0][1] = y2;
    S2[0][2] = z2;
    for (i = 1; i <= z1; i++)
    {
        printf("Enter row of non-zero element of matrix 1: ");
        scanf("%d", &S1[i][0]);
        printf("Enter column of non-zero element of matrix 1: ");
        scanf("%d", &S1[i][1]);
        printf("Enter non-zero element of matrix 1: ");
        scanf("%d", &S1[i][2]);
    }
    for (i = 1; i <= z2; i++)
    {
        printf("Enter row of non-zero element of matrix 2: ");
        scanf("%d", &S2[i][0]);
        printf("Enter column of non-zero element of matrix 2: ");
        scanf("%d", &S2[i][1]);
        printf("Enter non-zero element of matrix 2: ");
        scanf("%d", &S2[i][2]);
    }
    printf("\nMatrix 1 (3-Tuple form):\n");
    for (i = 0; i <= z1; i++)
    {
        printf("(%d, %d, %d)", S1[i][0], S1[i][1], S1[i][2]);
        if (i < z1) printf(", ");
    }
    printf("\n\nMatrix 2 (3-Tuple form):\n");
    for (i = 0; i <= z2; i++)
    {
        printf("(%d, %d, %d)", S2[i][0], S2[i][1], S2[i][2]);
        if (i < z2) printf(", ");
    }
    printf("\n\n--- Intermediate Addition Steps ---\n");
    S3[0][0] = x1;
    S3[0][1] = y1;
    i = 1;
    j = 1;
    k = 1;
    while (i <= z1 && j <= z2)
    {
        if (S1[i][0] == S2[j][0] && S1[i][1] == S2[j][1])
        {
            S3[k][0] = S1[i][0];
            S3[k][1] = S1[i][1];
            S3[k][2] = S1[i][2] + S2[j][2];
            printf("Step %d: Added elements at (%d, %d) -> %d + %d = %d\n", k, S1[i][0], S1[i][1], S1[i][2], S2[j][2], S3[k][2]);
            i++;
            j++;
            k++;
        }
        else if (S1[i][0] < S2[j][0] || (S1[i][0] == S2[j][0] && S1[i][1] < S2[j][1]))
        {
            S3[k][0] = S1[i][0];
            S3[k][1] = S1[i][1];
            S3[k][2] = S1[i][2];
            printf("Step %d: Copied element from Matrix 1 at (%d, %d) -> %d\n", k, S1[i][0], S1[i][1], S1[i][2]);
            i++;
            k++;
        }
        else
        {
            S3[k][0] = S2[j][0];
            S3[k][1] = S2[j][1];
            S3[k][2] = S2[j][2];
            printf("Step %d: Copied element from Matrix 2 at (%d, %d) -> %d\n", k, S2[j][0], S2[j][1], S2[j][2]);
            j++;
            k++;
        }
    }
    while (i <= z1)
    {
        S3[k][0] = S1[i][0];
        S3[k][1] = S1[i][1];
        S3[k][2] = S1[i][2];
        printf("Step %d: Copied remaining element from Matrix 1 at (%d, %d) -> %d\n", k, S1[i][0], S1[i][1], S1[i][2]);
        i++;
        k++;
    }
    while (j <= z2)
    {
        S3[k][0] = S2[j][0];
        S3[k][1] = S2[j][1];
        S3[k][2] = S2[j][2];
        printf("Step %d: Copied remaining element from Matrix 2 at (%d, %d) -> %d\n", k, S2[j][0], S2[j][1], S2[j][2]);
        j++;
        k++;
    }
    S3[0][2] = k - 1;
    printf("\nResultant Matrix 3 (3-Tuple form):\n");
    for (i = 0; i < k; i++)
    {
        printf("(%d, %d, %d)", S3[i][0], S3[i][1], S3[i][2]);
        if (i < k - 1) printf(", ");
    }
    printf("\n");
    return 0;
}
