#include <stdio.h>
#include <stdlib.h>
struct Node {
       int value;
       int left_Thread;
       int right_Thread;
       struct Node *left_Node;
       struct Node *right_Node;
};
typedef struct Node ThreadNode;
typedef ThreadNode *ThreadBinaryTree;
ThreadBinaryTree rootNode;
/*�N���w���ȥ[�J��G���޽u��*/ 
void Add_Node_To_Tree(int value) {
     ThreadBinaryTree newnode;
     ThreadBinaryTree previous;
      newnode=(ThreadBinaryTree)malloc(sizeof(ThreadNode));
      newnode->value=value;
      newnode->left_Thread=0;
      newnode->right_Thread=0;
      newnode->left_Node=NULL;
      newnode->right_Node=NULL;
      ThreadBinaryTree current;
      ThreadBinaryTree parent;
      previous=(ThreadBinaryTree)malloc(sizeof(ThreadNode));
      previous->value=value;
      previous->left_Thread=0;
      previous->right_Thread=0;
      previous->left_Node=NULL;
      previous->right_Node=NULL;
      int pos;
      /*�]�w�޽u�G���𪺶}�Y�`�I*/
      if(rootNode==NULL) {
         rootNode=newnode;
         rootNode->left_Node=rootNode;
         rootNode->right_Node=NULL;
         rootNode->left_Thread=0;
         rootNode->right_Thread=1;
         return;
      }
      /*�]�w�}�Y�`�I�ҫ����`�I*/
      current=rootNode->right_Node;
      if(current==NULL){
         rootNode->right_Node=newnode;
         newnode->left_Node=rootNode;
         newnode->right_Node=rootNode;
         return ;
      }
      parent=rootNode; /*���`�I�O�}�Y�`�I*/
      pos=0; /*�]�w�G���𤤪���i��V*/
      while(current!=NULL) {
         if(current->value>value) {
            if(pos!=-1) {
               pos=-1;
               previous=parent;
            }
            parent=current;
            if(current->left_Thread==1)
               current=current->left_Node;
            else
               current=NULL;
         }
         else {
            if(pos!=1) {
               pos=1;
               previous=parent;
            }
            parent=current;
            if(current->right_Thread==1)
               current=current->right_Node;
            else
               current=NULL;
         }
      }
      if(parent->value>value) {
         parent->left_Thread=1;
         parent->left_Node=newnode;
         newnode->left_Node=previous;
         newnode->right_Node=parent;
      }
      else {
         parent->right_Thread=1;
         parent->right_Node=newnode;
         newnode->left_Node=parent;
         newnode->right_Node=previous;
      }
      return ;
   }
/*�޽u�G���𤤧Ǩ��X*/
   void trace() {
      ThreadBinaryTree tempNode;
      tempNode=rootNode;
      do {
         if(tempNode->right_Thread==0)
            tempNode=tempNode->right_Node;
         else
         {
            tempNode=tempNode->right_Node;
            while(tempNode->left_Thread!=0)
               tempNode=tempNode->left_Node;
         }
         if(tempNode!=rootNode)
            printf("[%d]\n",tempNode->value);
      } while(tempNode!=rootNode);
   } 
int main(void)
{
      int i=0;
      int array_size=11;
      printf("�޽u�G����g�إ߫�,�H���ǰl�ܯ঳�ƧǪ��ĪG\n");
      printf("�Ĥ@�ӼƦr���޽u�G���𪺶}�Y�`�I,���C�J�Ƨ�\n");
      int data1[]={0,10,20,30,100,399,453,43,237,373,655};
      for(i=0;i<array_size;i++)
         Add_Node_To_Tree(data1[i]);
      printf("====================================\n");
      printf("�d�� 1 \n");
      printf("�Ʀr�Ѥp��j���ƧǶ��ǵ��G��: \n");
      trace();
      int data2[]={0,101,118,87,12,765,65};
      rootNode=NULL;/*�N�޽u�G���𪺾���k�s*/
      array_size=7;/*��2�ӽd�Ҫ��}�C���׬�7*/
      for(i=0;i<array_size;i++)
         Add_Node_To_Tree(data2[i]);    
      printf("====================================\n");
      printf("�d�� 2 \n");
      printf("�Ʀr�Ѥp��j���ƧǶ��ǵ��G��: \n");
      trace();
      printf("\n");
  	system("pause");
	return 0;
}
