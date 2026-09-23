#include <stdio.h>

int main()
{
    int i=0,j=0,k=0,x=0,y=0,z=0;

    printf("Enter no of rows: ");
    scanf("%d",&x);

    printf("Enter no of columns: ");
    scanf("%d",&y);

    printf("Enter no of non-zero elements: ");
    scanf("%d",&z);

    int S[z+1][3];

    S[0][0]=x;
    S[0][1]=y;
    S[0][2]=z;

    int TS[z+1][3];

    TS[0][0]=y;
    TS[0][1]=x;
    TS[0][2]=z;

    for(i=1;i<=z;i++)
    {
        printf("Enter row of non-element: ");
        scanf("%d",&S[i][0]);

        printf("Enter column of non-element: ");
        scanf("%d",&S[i][1]);

        printf("Enter non-zero element: ");
        scanf("%d",&S[i][2]);
    }

    printf("\nOriginal Matrix (3-Tuple form):\n");

    for(i=0;i<=z;i++)
    {
        printf("%d %d %d\n",S[i][0],S[i][1],S[i][2]);
    }

    i=0;
    j=0;
    k=1;

    printf("\n--- Intermediate Transpose Steps ---\n");

    for(i=0;i<y;i++)
    {
        for(j=1;j<=z;j++)
        {
            if(S[j][1]==i)
            {
                TS[k][0]=S[j][1];
                TS[k][1]=S[j][0];
                TS[k][2]=S[j][2];

                printf("Step %d: Transposed (%d, %d, %d) -> (%d, %d, %d)\n",
                       k,
                       S[j][0],
                       S[j][1],
                       S[j][2],
                       TS[k][0],
                       TS[k][1],
                       TS[k][2]);

                k++;
            }
        }
    }

    printf("\nTranspose Matrix (3-Tuple form):\n");

    for(i=0;i<=z;i++)
    {
        printf("%d %d %d\n",TS[i][0],TS[i][1],TS[i][2]);
    }

    return 0;
}
