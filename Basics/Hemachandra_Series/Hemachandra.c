#include<stdio.h>
#include "../Common_Defs/inc/common_defs.h"

int main()
{
	int n;

	TRACE_HIGH("Namaste ! This code will print Hemachandra Series");
	
	TRACE_HIGH("Please enter the number of terms you want to see");
	
	scanf("%d",&n);
	
	if(n<0)
	{
		TRACE_HIGH("\n\nNumber of terms can't be negative\n\n");
	}
	else if(n==0)
	{
		TRACE_HIGH("\n\nYou wanted to see no term, so scoot!\n\n");
	}
	else
	{
		TRACE_HIGH("\n\nThe first %d terms of Hemachamdra Series are\n",n);
	
		hema(n);
	}
	return 0;
}

int hema(int n)
{	
	int a1=1,a2=1,a3,i=0;
	
	if(n==1)
	{
		TRACE_HIGH("%d ",a1);
	}
	else if (n==2)
	{
		TRACE_HIGH("%d , %d ",a1,a2);
	}
	else
	{
		TRACE_HIGH("%d , %d , ",a1,a2);
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
