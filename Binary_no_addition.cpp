#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int b;
	node* back,*next;
};
class binary
{
	node* head=NULL,*curr,*prev;
	int no;

	public:
	void enterno()
	{
		cout<<"Enter binary no: ";
		cin>>no;
		while(no>0)
		{
			curr=new node;
			curr->b=no%10;
			if(head==NULL)
			{
                head=curr;
				curr->next=NULL;
				curr->back=NULL;
			}
			else
			{
				curr->next=head;
				curr->back=NULL;
				head=curr;
				curr->next->back=curr;
			}
			no=no/10;
		}
	}
	void ones_compli()
	{
		struct node *t=head;
		while(t!=NULL)
		{
			if(t->b==0)
				t->b=1;
			else
				t->b=0;
			t=t->next;
		}
	}
	void twos_compli()
	{
		int z=0;
		struct node *t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		while(t!=NULL)
		{
			if(z==0)
			{
				if(t->b==1)
				{
					z++;
				}
			}
			else
			{
				if(t->b==0)
					t->b=1;
				else
					t->b=0;
			}
			t=t->back;
		}
	}
	void addition(binary B1,binary B2)
	{
		struct node *t1=B1.head,*t2=B2.head;
		int carry=0;
		if(t1!=NULL)
        {
            while(t1->next!=NULL)
            {
                t1=t1->next;
            }
        }
        if(t2!=NULL)
        {
            while(t2->next!=NULL)
            {
                t2=t2->next;
            }
        }
		while(t1!=NULL && t2!=NULL)
        {
            if(t1->b==1 && t2->b==0)
            {
                curr=new node;
                if(carry==0)
                    curr->b=1;
                else
                {
                    curr->b=0;
                    carry=1;
                }
            }
            else if(t1->b==1 && t2->b==1)
            {
                curr=new node;
                if(carry==0)
                {
                    curr->b=0;
                    carry=1;
                }
                else
                {
                    curr->b=1;
                    carry=1;
                }
            }
            else if(t1->b==0 && t2->b==1)
            {
                curr=new node;
                if(carry==0)
                    curr->b=1;
                else
                {
                    curr->b=0;
                    carry=1;
                }
            }
            else if(t1->b==0 && t2->b==0)
            {
                curr=new node;
                if(carry==0)
                    curr->b=0;
                else
                {
                    curr->b=1;
                    carry=0;
                }
            }
            if(head==NULL)
            {
                head=curr;
                curr->next=NULL;
            }
            else
            {
                curr->next=head;
                curr->back=NULL;
                head=curr;
                curr->next->back=curr;
            }
            t1=t1->back;
            t2=t2->back;
        }
        while(t1!=NULL)
        {
            curr=new node;
            if(t1->b==0)
            {
                if(carry==0)
                    curr->b=0;
                else
                    curr->b=1;

            }
            else
            {
                if(carry==0)
                    curr->b=1;
                else
                {
                    curr->b=0;
                    carry=1;
                }
            }
            if(head==NULL)
            {
                head=curr;
                curr->next=NULL;
            }
            else
            {
                curr->next=head;
                curr->back=NULL;
                head=curr;
                curr->next->back=curr;
            }
            t1=t1->back;
        }
        while(t2!=NULL)
        {
            curr=new node;
            if(t2->b==0)
            {
                if(carry==0)
                    curr->b=0;
                else
                    curr->b=1;

            }
            else
            {
                if(carry==0)
                    curr->b=1;
                else
                {
                    curr->b=0;
                    carry=1;
                }
            }
            if(head==NULL)
            {
                head=curr;
                curr->next=NULL;
            }
            else
            {
                curr->next=head;
                curr->back=NULL;
                head=curr;
                curr->next->back=curr;
            }
            t2=t2->back;
        }
        if(carry==1)
        {
            curr=new node;
            curr->b=1;
            if(head==NULL)
            {
                head=curr;
                curr->next=NULL;
            }
            else
            {
                curr->next=head;
                curr->back=NULL;
                head=curr;
                curr->next->back=curr;
            }
        }
	}
	void display()
	{
		struct node *t=head;
		while(t!=NULL)
		{
			cout<<t->b;
			t=t->next;
		}
	}
};


int main()
{
	int ch;
	while(1)
	{
		cout<<"\n\nMenu:\n\n";
		cout<<"1. 1's compliment of binary number\n2. 2's compliment of binary number\n3. Addition of two binary numbers\n4. Exit\n\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				binary B1;
				B1.enterno();
				B1.ones_compli();
				B1.display();
				break;
			}
			case 2:
			{
				binary B1;
				B1.enterno();
				B1.twos_compli();
				B1.display();
				break;
			}
			case 3:
			{
				binary B1,B2,B3;
				B1.enterno();
				B2.enterno();
				B3.addition(B1,B2);
				B3.display();
				break;
			}
			case 4:
			{
				exit(0);
			}
			default:
                cout<<"**** INVALID CHOICE ENTERED ****"<<endl;
		}
	}
}
