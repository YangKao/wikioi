#include <stdio.h>
int main()
{
	int a,sum;
	double b;
	scanf("%lf%d",&b,&a);
	sum = a*b/10;
	a = sum%10;
	if(a>=5) 
	{
		sum = sum + 10 - a;
		printf ("%d",sum);
	}
	else
	{
		sum = sum - a;
		printf ("%d",sum);
	}
	return 0;
}