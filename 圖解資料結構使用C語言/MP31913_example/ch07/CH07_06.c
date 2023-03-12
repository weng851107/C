#include <stdio.h>
#include <stdlib.h>
#define VERTS	6                /*�ϧγ��I��*/

struct edge                      /*�䪺���c�ŧi*/
{  
	int from,to;
	int find,val;
	struct edge* next;
};
typedef struct edge node;
typedef node* mst;
int v[VERTS+1];
mst findmincost(mst head)                 /*�j�M�����̤p����*/
{
	int minval=100;
	mst ptr,retptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->val<minval&&ptr->find==0)
		{                                  /*���pptr->val���Ȥp��minval*/
			minval=ptr->val;			   /*�N��ptr->val�]���̤p��*/
			retptr=ptr;                    /*�åB��ptr�����U��*/
		}
		ptr=ptr->next;
	}
	retptr->find=1;                        /*�Nretptr�]���w��쪺��*/
	return retptr;                         /*�Ǧ^retptr*/
}
void mintree(mst head)                     /*�̤p�����X�i����*/
{
	mst ptr,mceptr;
	int i,result=0;
	ptr=head;

	for(i=0;i<=VERTS;i++)
		v[i]=0;

	while(ptr!=NULL)
	{
		mceptr=findmincost(head);
		v[mceptr->from]++;
		v[mceptr->to]++;
		if(v[mceptr->from]>1&&v[mceptr->to]>1)
		{
			v[mceptr->from]--;
			v[mceptr->to]--;
			result=1;
		}
		else
			result=0;
		if(result==0)
			printf("�_�l���I [%d] -> �פ�I [%d] -> ���|���� [%d]\n",mceptr->from,mceptr->to,mceptr->val);
		ptr=ptr->next;
	}
}

int main()
{  
	int data[10][3]={{1,2,6},{1,6,12},{1,5,10},{2,3,3},    /*������}�C*/
                    {2,4,5},{2,6,8},{3,4,7},{4,6,11},
					{4,5,9},{5,6,16}};
	int i,j;
	mst head,ptr,newnode;
	head=NULL;
	
	for(i=0;i<10;i++)                    /*�إ߹ϧΦ�C*/
	{  
		for(j=1;j<=VERTS;j++)
		{  
			if(data[i][0]==j)
			{  
				newnode=(mst)malloc(sizeof(node));
				newnode->from=data[i][0];
				newnode->to=data[i][1];
				newnode->val=data[i][2];
				newnode->find=0;
				newnode->next=NULL;
				if(head==NULL)
				{  
					head=newnode;
					head->next=NULL;
					ptr=head;
				}   
				else
				{  
					ptr->next=newnode;
					ptr=ptr->next;
				}
			}
		}
	}
	
	printf("-------------------------------------------------\n");
	printf("�إ̤߳p�����X�i��G\n");
	printf("-------------------------------------------------\n");
	mintree(head);                        /*�إ̤߳p�����X�i��*/
	system("pause");
	return 0;
}
