
#include<stdio.h>

int main()
{
	int n;

	printf("\n\nNamaste !\n\nThis code will print Hemachandra Series\n\n");
	
	printf("\n\nPlease enter the number of terms you want to see\n\n");
	
	scanf("%d",&n);
	
	if(n<0)
	{
		printf("\n\nNumber of terms can't be negative\n\n");
	}
	else if(n==0)
	{
		printf("\n\nYou wanted to see no term, so scoot!\n\n");
	}
	else
	{
		printf("\n\nThe first %d terms of Hemachamdra Series are\n",n);
	
		hema(n);
	}
	return 0;
}

int hema(int n)
{	
	int a1=1,a2=1,a3,i=0;
	
	if(n==1)
	{
		printf("%d \n\n",a1);
	}
	else if (n==2)
	{
		printf("%d , %d \n\n",a1,a2);
	}
	else
	{
		printf("%d , %d , ",a1,a2);
		for(i=0;i<n-2;i++)
		{
			a3=a1+a2;
			printf("%d , ",a3);
			a1=a2;
			a2=a3;
		}
		printf("\n\n");
	}
}
