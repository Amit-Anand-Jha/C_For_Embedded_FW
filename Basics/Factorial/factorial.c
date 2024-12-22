#include<stdio.h>

int main()
{
	int n,val;

	printf("\n\nNamaste !\n\nThis code will print Factorial Value of the number you will enter below\n\n");
	
	printf("\n\nPlease enter the number\n\n");
	
	scanf("%d",&n);
	
	if(n<0)
	{
		printf("\n\nFactorial value does not exist for negative numbers\n\n");
	}
	else if(n==0)
	{
		printf("\n\nWell, weirldy 0!=1\n\n");
	}
	else
	{
		printf("\n\nThe value of factorial of %d is\n",n);
	
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
	printf("\n%d,k");

	return k;
}
