#include<stdio.h>
#include<stdlib.h>

int bin_search(int*,int);
int main(void)
{  
	int i,j,val=1,num,data[50]={0};
	for (i=0;i<50;i++)
	{  
		data[i]=val;
		val+=(rand()%5+1);
	}
	while(1)
	{  
		num=0;
		printf("�п�J�j�M���(1-150)�A��J-1�����G");
		scanf("%d",&val);
		if(val==-1)
			break;
		num=bin_search(data,val);
		if(num==-1)
			printf("##### �S�����[%3d] #####\n",val);
		else
			printf("�b�� %2d�Ӧ�m��� [%3d]\n",num+1,data[num]);
	}
	printf("��Ƥ��e�G\n");
	for(i=0;i<5;i++)
	{ 
		for(j=0;j<10;j++)
			printf("%3d-%-3d",i*10+j+1,data[i*10+j]);
		printf("\n");
	}
	system("pause");
	return 0;
}
int bin_search(int data[50],int val)
{  
	int low,mid,high;
	low=0;
	high=49;
	printf("�j�M�B�z��......\n");
	while(low<= high && val !=-1)
	{  
		mid=low+((val-data[low])*(high-low)/(data[high]-data[low])); /*�����k����*/
		if (val==data[mid])
			return mid;
		else if (val < data[mid])
		{  
			printf("%d �����m %d[%3d]�Τ����� %d[%3d]�A�䥪�b��\n",val,low+1,data[low],mid+1,data[mid]);
			high=mid-1;	     
		}
		else if(val > data[mid])
		{  
			printf("%d ���󤤶��Ȧ�m %d[%3d] �� %d[%3d]�A��k�b��\n",val,mid+1,data[mid],high+1,data[high]);
			low=mid+1;   	     
		}
	}
	return -1;
}
