/* �Hfor�j��p�� n! */
#include<stdio.h>
#include<stdlib.h>

int main()
{ 
	int i,j,n,sum = 1;
	printf("�п�Jn="); 
	scanf("%d",&n);
	
	for(i=0;i<=n;i++)	 /* 0~4���h */
	{  
		for(j=i;j>0;j--) /* n!=n*(n-1)*(n-2)*...*1 */
		sum *= j;		 /* sum=sum*j */
		printf("%d!=%3d\n",i,sum);
		sum	= 1;
	}
	system("pause");
	return 0;
}
