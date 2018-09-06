/*
 ============================================================================
 Name        : Queue-operations.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void insert(int);
void display();
void delete();
struct queue
{
	int data;
	struct queue *link;
};
struct queue *root=NULL;
struct queue *front=NULL;
struct queue *rear=NULL;

int main(void)
{
  insert(100);
  insert(200);
  insert(300);
  insert(400);
  insert(500);
  insert(600);
  insert(700);
  insert(800);
  insert(900);
  display();
  delete();
  display();
  delete();
  display();
return 0;
}
  void insert(int val)
  {
	  struct queue *temp=NULL;
	  struct queue *p=root;

	  temp=(struct queue*)malloc(sizeof(struct queue));
	  front=rear=root;
	  temp->data = val;
	  temp->link=NULL;

	  if(p==NULL)
		  root=temp;
	  else
	  {
		 while(rear->link!=NULL)
			 rear=rear->link;
		 rear->link=temp;
	  }
  }

    void display()
    {
    	 struct queue *temp=root;
    	 while(temp!=NULL)
    	 {
    		 printf("-->%d",temp->data);
    		 temp=temp->link;
    	 }
    	 free(temp);
    }

    void delete()
		{
    	   int val;
    	   struct queue *sn=front;
    	   val = front->data;
    	   root=front->link;
    	   front=root;
    	   free(sn);
    	   printf("\n deleted  element=%d\n",val);

		}

