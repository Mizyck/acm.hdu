#include<stdio.h>
int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		int x=1,y=0;
		while(x<=a)
		{
			y=y+x;
			++x;
			
		}
		printf("%d\n\n",y);
	}
	return 0;
}
