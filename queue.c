#include<stdio.h>
#include<stdlib.h>

struct queue
{
        int data;
        struct queue *next;
};

void insertq(struct queue**,struct queue**,struct queue**,int);
void display(struct queue**,struct queue *,struct queue *);
int delete(struct queue**,struct queue**,struct queue**);

void main()
{

        int b;

        struct queue *mq=NULL;

        struct queue *f=NULL;

        struct queue *r=NULL;

        insertq(&mq,&f,&r,10);

        insertq(&mq,&f,&r,20);

        insertq(&mq,&f,&r,30);

        insertq(&mq,&f,&r,40);

 //       display(&mq);

        //printf("\n");

       b=delete(&mq,&f,&r);
       b=delete(&mq,&f,&r);

     //printf("value=%d\n",b);

       display(&mq,f,r);

}


void insertq(struct queue**p,struct queue**f,struct queue**r,int val)

{

        if((*f)==NULL)
        {

	      (*p)=(struct queue*)malloc(sizeof(struct queue));

	      (*f)=(*r)=(*p);

	      (*r)->data=val;

	      (*r)->next=NULL;

	      return;

        }

        (*r)->next=(struct queue*)malloc(sizeof(struct queue));

        (*r)->next->data=val;

        (*r)->next->next=NULL;

        (*r)=(*r)->next;

}


void display(struct queue **p,struct queue *f,struct queue *r)
{ 

	printf("Front  : %p\n",f);
	printf("Rear   : %p\n",r);
        if((*p)==NULL)

        {

	      printf("\nno nodes in queues\n");

        }


        else
        {
	      while((*p)!=NULL)
	      {
		    printf("\n Addr: %p  %d\n",*p,(*p)->data);

		    (*p)=(*p)->next;
	      }
        }
}


int delete(struct queue **p,struct queue**f,struct queue **r)

{

        int val;

        struct queue *dn;


        if((*p)==NULL)
        {

	      printf("queue is empty\n");

	      return 0;

        }

        if((*f)==(*r))
        {
	      val=(*f)->data;

	      free(*p);


	      (*f)=NULL;

	      (*r)=NULL;

	      (*p)=NULL;

	      return val;

        }

        val=(*f)->data;

        dn=(*f);

        (*f)=(*f)->next;

         (*p)=(*f);

        free(dn);

        return val;

}
