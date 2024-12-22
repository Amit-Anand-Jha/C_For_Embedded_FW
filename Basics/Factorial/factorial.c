#include<stdio.h>
#include "../../Common_Defs/inc/common_defs.h"

int main()
{
	int n,val;

	TRACE_HIGH("Namaste !  This code will print Factorial Value of the number you will enter below");
	
	TRACE_HIGH("Please enter the numbee");
	
	scanf("%d",&n);
	
	if(n<0)
	{
		TRACE_HIGH("Factorial value does not exist for negative numbers");
	}
	else if(n==0)
	{
		TRACE_HIGH("Well, weirldy 0!=1");
	}
	else
	{
		TRACE_HIGH("The value of factorial of %d is",n);
	
		val=factorial(n);
	}
	return 0;
}

int factorial(int n)
{	
	int k,count=n;
	while(count!=0)
	{
		k=n*factorial(n-1);
		count=count-1;
	}
	TRACE_HIGH("%d,k");

	return k;
}
