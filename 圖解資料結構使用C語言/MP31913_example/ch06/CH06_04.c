#include <stdio.h>
#include <stdlib.h>

struct tree
{  int data;
   struct tree *left,*right;
};
typedef struct tree node;
typedef node *btree;

btree creat_tree(btree,int);
void inorder(btree ptr)       /*���Ǩ��X�Ƶ{��*/
{  
  if(ptr!=NULL)
     {  
      inorder(ptr->left);
      printf("[%2d] ",ptr->data);
      inorder(ptr->right);
      }
}
void postorder(btree ptr)/*��Ǩ��X*/
{  
     if (ptr != NULL)
     {  
      postorder(ptr->left);
      postorder(ptr->right);
      printf("[%2d] ",ptr->data);
      }
}
void preorder(btree ptr)/*�e�Ǩ��X*/
{  
  if (ptr != NULL)
  {  
   printf("[%2d] ",ptr->data);
   preorder(ptr->left);
   preorder(ptr->right);
   }
}
int main()
{  
	int i,data[]={7,4,1,5,16,8,11,12,15,9,2};
	btree ptr=NULL;
	btree root=NULL;
	
	for(i=0;i<11;i++)
	  ptr=creat_tree(ptr,data[i]);       /*�إߤG����*/
	
	
    printf("=======================================================\n");
    printf("���Ǧ����X���G�G\n");
    inorder(ptr);   /*���Ǩ��X*/
    printf("\n");
    printf("=======================================================\n");
    printf("��Ǧ����X���G�G\n");
    postorder(ptr);   /*���Ǩ��X*/
    printf("\n");
    printf("=======================================================\n");
    printf("�e�Ǧ����X���G�G\n");
    preorder(ptr);   /*���Ǩ��X*/
    printf("\n");
	
    system("pause");
	return 0;
}
btree creat_tree(btree root,int val)    /*�إߤG������*/
{  
	btree newnode,current,backup;
	newnode=(btree)malloc(sizeof(node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
	{  
		root=newnode;
		return root;
	}
	else
	{  
		for(current=root;current!=NULL;)
		{  
			backup=current;
			if(current->data > val)
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root;
}

