#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct node
{
    char job[30];
    node* next=NULL;
};
class job_queue
{
	char job[50][30];
	int front=-1,rear=0,j;
	public:
	void add_job()
	{
		if(!is_full())
		{
			for(j=front;j>=0;j--)
			{
				strcpy(job[j+1],job[j]);
			}
			cout<<"Enter Job: ";
			cin.ignore();
			cin.getline(job[rear],30);
			front++;
		}
		else
		{
			cout<<"Queue is full"<<endl;
		}

	}
	void delete_job()
	{
		if(!is_empty())
		{
			job[front--][0]='\0';
			//front--;
			cout<<"Job has been deleted."<<endl;
		}
		else
		{
			cout<<"Queue is empty."<<endl;
		}
	}
	int is_full()
	{
		if(front==49)
			return 1;
		else
			return 0;
	}
	int is_empty()
	{
		if(front==-1)
			return 1;
		else
			return 0;
	}
	void display_job_list()
	{
		if(!is_empty())
		{
			for(j=front;j>=0;j--)
				cout<<job[j]<<endl;
		}
		else
		{
			cout<<"Queue is empty."<<endl;
		}

	}
};
int main()
{
	int ch;
	job_queue Q;
	while(true)
	{
		cout<<"\n\nMENU\n\n";
		cout<<"1] Add job to queue\n2] Delete job from queue\n3] Display job list\n4] Exit\n\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				Q.add_job();
				break;
			}
			case 2:
			{
				Q.delete_job();
				break;
			}
			case 3:
			{
				Q.display_job_list();
				break;
			}
			case 4:
			{
				exit(0);
			}
		}
	}

}
