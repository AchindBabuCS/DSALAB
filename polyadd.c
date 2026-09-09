#include <stdio.h>
struct Polynomial{
	int coef;
	int exp;
};
int main()
{
	int i=0,j=0,k=0,n1=0,n2=0,n3=0;
	printf("Enter no of elements of Polynomial 1: ");
	scanf("%d",&n1);
	printf("Enter no of elements of Polynomial 2: ");
	scanf("%d",&n2);
	struct Polynomial p1[n1];
	struct Polynomial p2[n2];
	if(n1>n2)
	{
		n3=n1;
	}
	else
	{
		n3=n2;
	}
	struct Polynomial p3[n3];
	for(i=0;i<n1;i++)
	{
		printf("Enter coefficient of element of Polynomial 1: ");
		scanf("%d",&p1[i].coef);
		printf("Enter exponent of element of Polynomial 1: ");
		scanf("%d",&p1[i].exp);
	}
	for(i=0;i<n2;i++)
	{
		printf("Enter coefficient of element of Polynomial 2: ");
		scanf("%d",&p2[i].coef);
		printf("Enter exponent of element of Polynomial 2: ");
		scanf("%d",&p2[i].exp);
	}
	i=0;
	j=0;
	k=0;
	while(i<n1 && j<n2)
	{
		if(p1[i].exp==p2[j].exp)
		{
			p3[k].coef=p1[i].coef+p2[j].coef;
			p3[k].exp=p1[i].exp;
			i++;
			j++;
		}
		else if(p1[i].exp>p2[j].exp)
		{
			p3[k].coef=p1[i].coef;
			p3[k].exp=p1[i].exp;
			i++;
		}
		else
		{
			p3[k].coef=p2[j].coef;
			p3[k].exp=p2[j].exp;
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		p3[k].coef=p1[i].coef;
		p3[k].exp=p1[i].exp;
		i++;
		k++;
	}
	while(j<n2)
	{
		p3[k].coef=p2[j].coef;
		p3[k].exp=p2[j].exp;
		j++;
		k++;
	}
	for(i=0;i<k;i++)
	{
		if(p3[i].exp==0)
		{
			printf("%d",p3[i].coef);
			break;
		}
		else
		{
			printf("%dx^%d + ",p3[i].coef,p3[i].exp);
		}
	}
	return 0;
}
