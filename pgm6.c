#include <stdio.h>

int main()
{
    int i=0,j=0,k=0,x=0,y=0,z=0,a=0,b=0,c=0,m=0,n=0,p=0,q=0;

    printf("Enter no of rows of sparse matrix 1: ");
    scanf("%d",&x);

    printf("Enter no of columns of sparse matrix 1: ");
    scanf("%d",&y);

    printf("Enter no of non-zero elements of sparse matrix 1: ");
    scanf("%d",&z);

    printf("Enter no of rows of sparse matrix 2: ");
    scanf("%d",&a);

    printf("Enter no of columns of sparse matrix 2: ");
    scanf("%d",&b);

    printf("Enter no of non-zero elements of sparse matrix 2: ");
    scanf("%d",&c);

    if(x!=a || y!=b)
    {
        printf("Addition not possible.");
        return 0;
    }

    int sm1[z+1][3];
    int sm2[c+1][3];
    int sm3[z+c+1][3];

    sm1[0][0]=x;
    sm1[0][1]=y;
    sm1[0][2]=z;

    sm2[0][0]=a;
    sm2[0][1]=b;
    sm2[0][2]=c;

    for(i=1;i<=z;i++)
    {
        printf("Enter row of non-zero element of sparse matrix 1: ");
        scanf("%d",&sm1[i][0]);

        printf("Enter column of non-zero element of sparse matrix 1: ");
        scanf("%d",&sm1[i][1]);

        printf("Enter value of non-zero element of sparse matrix 1: ");
        scanf("%d",&sm1[i][2]);
    }

    for(i=1;i<=c;i++)
    {
        printf("Enter row of non-zero element of sparse matrix 2: ");
        scanf("%d",&sm2[i][0]);

        printf("Enter column of non-zero element of sparse matrix 2: ");
        scanf("%d",&sm2[i][1]);

        printf("Enter value of non-zero element of sparse matrix 2: ");
        scanf("%d",&sm2[i][2]);
    }

    i=1;
    j=1;
    k=1;

    while(i<=z && j<=c)
    {
        if(sm1[i][0]==sm2[j][0] && sm1[i][1]==sm2[j][1])
        {
            if(sm1[i][2]+sm2[j][2]!=0)
            {
                sm3[k][0]=sm1[i][0];
                sm3[k][1]=sm1[i][1];
                sm3[k][2]=sm1[i][2]+sm2[j][2];
                k++;
            }
            i++;
            j++;
        }
        else if(sm1[i][0]<sm2[j][0] ||
               (sm1[i][0]==sm2[j][0] && sm1[i][1]<sm2[j][1]))
        {
            sm3[k][0]=sm1[i][0];
            sm3[k][1]=sm1[i][1];
            sm3[k][2]=sm1[i][2];
            i++;
            k++;
        }
        else
        {
            sm3[k][0]=sm2[j][0];
            sm3[k][1]=sm2[j][1];
            sm3[k][2]=sm2[j][2];
            j++;
            k++;
        }
    }

    while(i<=z)
    {
        sm3[k][0]=sm1[i][0];
        sm3[k][1]=sm1[i][1];
        sm3[k][2]=sm1[i][2];
        i++;
        k++;
    }

    while(j<=c)
    {
        sm3[k][0]=sm2[j][0];
        sm3[k][1]=sm2[j][1];
        sm3[k][2]=sm2[j][2];
        j++;
        k++;
    }

    sm3[0][0]=x;
    sm3[0][1]=y;
    sm3[0][2]=k-1;

    printf("\nResultant Sparse Matrix:\n");
    printf("Row\tCol\tValue\n");

    for(i=0;i<k;i++)
    {
        printf("%d\t%d\t%d\n",sm3[i][0],sm3[i][1],sm3[i][2]);
    }

    return 0;
}
