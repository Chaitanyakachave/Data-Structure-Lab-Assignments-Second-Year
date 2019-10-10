#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

struct fdetail
{
	char name[30];
	unsigned long phone_no;
};


class Friend
{
	int total_no=0,mid,high,low=0;
	fdetail F[50];
	public:
	void search_friend()
	{
		char name[30];
		int tmp,flag=0,i;
		cout<<"Enter friend's name to search: ";
		cin.ignore();
		cin.getline(name,30);
		if(total_no==0)
		{
			cout<<"\n!!! No details found. !!!\n\n";
			cout<<"Enter 1 to add details else 0: ";
			cin>>tmp;
			if(tmp==1)
			{
				cout<<"\nEnter friends name: ";
				cin.ignore();
				cin.getline(F[total_no].name,30);
				cout<<"Enter friends number: ";
				cin>>F[total_no++].phone_no;
				high=total_no;
			}
			else
			{
				cout<<"\n\n Process terminated..\n"<<endl;
			}
			
		}
		else
		{
			while(low<high)
			{
				mid=(low+high)/2;
				if(strcmp(return_name(mid),name)==0)
				{
					cout<<"\n\n!!! Friends details found. !!!\n\n"<<endl;
					cout<<"Name: "<<F[mid].name<<endl;
					cout<<"Phone number: "<<F[mid].phone_no<<endl;
					flag=1;
					break;
				}
				else if(strcmp(return_name(mid),name)>0)
				{
					high=mid;
				}
				else if(strcmp(return_name(mid),name)<0)
				{
					low=mid+1;
				}
			}
			if(flag==0)
			{
				cout<<"\n\n!!! No details found. !!!\n\n";
				cout<<"Enter 1 to add details else 0: ";
				cin>>tmp;
				if(tmp==1)
				{
					for(i=total_no-1;i>=0;i--)
					{
						if(strcmp(name,return_name(i))>0)
						{
							cout<<"\nEnter friends name: ";
							cin.getline(F[total_no].name,30);
							cout<<"Enter friends number: ";
							cin>>F[total_no++].phone_no;
							high=total_no;
							break;
						}
					}
					
				}
				else
				{
					cout<<"\n\n Process terminated..\n"<<endl;
				}
			}
		}	
	}
	char* return_name(int index)
	{
		return F[index].name;
	}
	void display_list()
	{
		int i;
		cout<<internal<<setw(20)<<"NAME"<<internal<<setw(20)<<"PHONE NUMBER"<<endl;
		for(i=0;i<total_no;i++)
		{
			cout<<internal<<setw(20)<<F[i].name<<internal<<setw(20)<<F[i].phone_no<<endl;
		}
	}
};

int main()
{
	int ch;
	Friend F1;
	while(true)
	{
		cout<<"\n\nMENU: \n\n";
		cout<<"1] Search friends name in list\n";
		cout<<"2] Display List\n";
		cout<<"3] Exit\n";
		cout<<"\nEnter Choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				F1.search_friend();
				break;
			case 2:
				F1.display_list();
				break;
			case 3:
				exit(0);
		}
	}
}
