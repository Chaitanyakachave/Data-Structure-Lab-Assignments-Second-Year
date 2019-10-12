#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
using namespace std;
struct club
{
	long int PRN;
	char name[30];
	struct club *link;
}*startA,*secA,*startB,*secB,*tmp,*start,*sec;

void dis(char);
void add_node();
void cn();
void dlt();
int member(char);
void rev(struct club *p,char);
void insert_posi();
void concatenate();
void dis();

int main()
{
	int ch,i;
	startA=new(struct club);
	cout<<"Enter name of president of division A: ";
	cin.getline(startA->name,30);
	cout<<"Enter PRN of president: ";
	cin>>startA->PRN;
	startA->link=new(struct club);
	secA=startA->link;
	cout<<"Enter name of secretary of division A: ";
	cin.ignore();
	cin.getline(startA->link->name,30);
	cout<<"Enter PRN of secretary: ";
	cin>>startA->link->PRN;
	startA->link->link=NULL;
	startB=new(struct club);
	cin.ignore();
	cout<<"Enter name of president of division B: ";
	cin.getline(startB->name,30);
	cout<<"Enter PRN of president: ";
	cin>>startB->PRN;
	startB->link=new(struct club);
	secB=startB->link;
	cout<<"Enter name of secretary of division B: ";
	cin.ignore();
	cin.getline(startB->link->name,30);
	cout<<"Enter PRN of secretary: ";
	cin>>startB->link->PRN;
	startB->link->link=NULL;
	while(1)
	{
	    cout<<"--------------------------------------------------------------------------------\n";
		cout<<"Menu: \n\n";
		cout<<"1.Add member\n2.Add member at particular position\n3.Delete member\n4.Display members\n5.Total members\n6.Members in reverse order\n7.Concatenate two list and print\n8.Exit";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				int n;
				cout<<"Enter how many members you want to add: ";
				cin>>n;
				for(i=1;i<=n;i++)
				{
					add_node();
				}
				break;
			}
			case 2:
            {
                insert_posi();
                break;
            }
			case 3:
            {
                dlt();
                break;
            }
			case 4:
			{
			    char div;
			    cout<<"Enter division: ";
			    cin>>div;
				dis(div);
				break;
			}
			case 5:
            {
                char div;
			    cout<<"Enter division: ";
			    cin>>div;
                cout<<"Total members = "<<member(div)<<endl;
                break;
            }
            case 6:
            {
                char div;
			    cout<<"Enter division: ";
			    cin>>div;
                cout<<"\n"<<setw(15)<<"NAME"<<setw(15)<<"PRN NO"<<setw(15)<<"POST"<<setw(15)<<"DIVISION"<<endl;
                if(div=='a' || div=='A')
                    rev(startA,div);
                else if(div=='b' || div=='B')
                    rev(startB,div);
                break;
            }
            case 7:
            {
                concatenate();
                dis();
                break;
            }
			case 8:
				exit(0);
		}
	}
	return(0);
}
void cn()
{
    struct club *t=startA;
	tmp=new(struct club);
	cout<<"Enter name of student: ";
	cin.ignore();
	cin.getline(tmp->name,30);
	cout<<"Enter PRN of student: ";
	z:
	cin>>tmp->PRN;
	while(t!=NULL)
    {
        if(t->PRN==tmp->PRN)
        {
            cout<<"**** Error: Invalid PRN entered (PRN already exist) ****"<<endl;
            cout<<"Renter PRN of student: ";
            t=startA;
            goto z;
        }
        t=t->link;
    }
    t=startB;
    while(t!=NULL)
    {
        if(t->PRN==tmp->PRN)
        {
            cout<<"**** Error: Invalid PRN entered (PRN already exist) ****"<<endl;
            cout<<"Renter PRN of student: ";
            t=startA;
            goto z;
        }
        t=t->link;
    }
}
void add_node()
{
	struct club *t;
	char div;
	cn();
	cout<<"Enter Division of student: ";
	cin>>div;
	if(div=='A' || div=='a')
	{
	    t=startA;
		if(startA->link==secA)
		{
			startA->link=tmp;
			tmp->link=secA;
		}
		else
		{
			while(t->link!=secA)
			{
				t=t->link;
			}
			t->link=tmp;
			tmp->link=secA;
		}
	}
	else if(div=='B' || div=='b')
	{
	    t=startB;
		if(startB->link==secB)
		{
			startB->link=tmp;
			tmp->link=secB;
		}
		else
		{
			while(t->link!=secB)
			{
				t=t->link;
			}
			t->link=tmp;
			tmp->link=secB;
		}
	}
}
void insert_posi()
{
    struct club *t;
    int ch;
    char div;
    cn();
    cout<<"Enter division of student: ";
    cin>>div;
    cout<<"\n\tAt which position you want to insert new member: \n\t1.At startA\n\t2.At Last\n\t3.At particular position\n\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        {
            if(div=='a' || div=='A')
            {
                tmp->link=startA->link;
                startA->link=tmp;
            }
            else if(div=='b' || div=='B')
            {
                tmp->link=startB->link;
                startB->link=tmp;
            }
            break;
        }
    case 2:
        {
            if(div=='a' || div=='A')
            {
                t=startA;
                if(startA->link==secA)
                {
                    startA->link=tmp;
                    tmp->link=secA;
                }
                else
                {
                    while(t->link!=secA)
                    {
                        t=t->link;
                    }
                    t->link=tmp;
                    tmp->link=secA;
                }
            }
            else if(div=='b' || div=='B')
            {
                t=startB;
                if(startB->link==secB)
                {
                    startB->link=tmp;
                    tmp->link=secB;
                }
                else
                {
                    while(t->link!=secB)
                    {
                        t=t->link;
                    }
                    t->link=tmp;
                    tmp->link=secB;
                }
            }
            break;
        }
    case 3:
        {
            int n;
            if(div=='a' || div=='A')
            {
                t=startA->link;
            }
            else if(div=='b' || div=='B')
            {
                t=startB->link;
            }
                cout<<"Enter position: ";
                x:
                cin>>n;
                if(n<=member(div)-1)
                {
                    for(int i=0;i<n-2;i++)
                    {
                        t=t->link;
                    }
                    tmp->link=t->link;
                    t->link=tmp;
                }
                else
                {
                    cout<<"**** Error: Incorrect position entered ****"<<endl;
                    cout<<"Re-enter position: ";
                    goto x;
                }

        }
    }
    cout<<"**** New member inserted successfully ****"<<endl;

}
void dis(char div)
{
	struct club *t;
	if(div=='a'|| div=='A')
        t=startA;
    else if(div=='b'|| div=='B')
        t=startB;
	cout<<setw(15)<<"NAME"<<setw(15)<<"PRN NO"<<setw(15)<<"POST"<<setw(15)<<"DIVISION"<<endl;
	while(t!=NULL)
	{
		if(t==startA || t==startB)
		{
		    cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"PRESIDENT"<<setw(15)<<div<<endl;
		}
		else if(t==secA || t==secB)
		{
		    cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"SECRETARY"<<setw(15)<<div<<endl;
		}
		else
        {
            cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"MEMBER"<<setw(15)<<div<<endl;
        }
		t=t->link;
	}
}
void dlt()
{
    struct club *t;
    long int temp;
    char div;
    cout<<"Enter PRN of student to delete his/her details: ";
    cin>>temp;
    cout<<"Enter division of student: ";
    cin>>div;
    if(div=='a'|| div=='A')
        t=startA;
    else if(div=='B'|| div=='b')
        t=startB;
    if(startA->PRN==temp || startB->PRN==temp)
    {
        cout<<"\n**** President details deleted successfully ****\n"<<endl;
        if(div=='a'|| div=='A')
        {
            cout<<"Enter name of new president: ";
            cin.ignore();
            cin.getline(startA->name,30);
            cout<<"Enter PRN of new president: ";
            cin>>startA->PRN;
        }
        else if(div=='B'|| div=='b')
        {
            cout<<"Enter name of new president: ";
            cin.ignore();
            cin.getline(startB->name,30);
            cout<<"Enter PRN of new president: ";
            cin>>startB->PRN;
        }
    }
    else if(secA->PRN==temp || secB->PRN==temp)
    {
        if(div=='a'|| div=='A')
        {
            cout<<"\n**** secretary details deleted successfully ****\n"<<endl;
            cout<<"Enter name of new secretary: ";
            cin.ignore();
            cin.getline(secA->name,30);
            cout<<"Enter PRN of new secretary: ";
            cin>>secA->PRN;
        }
        else if(div=='B'|| div=='b')
        {
            cout<<"\n**** secretary details deleted successfully ****\n"<<endl;
            cout<<"Enter name of new secretary: ";
            cin.ignore();
            cin.getline(secB->name,30);
            cout<<"Enter PRN of new secretary: ";
            cin>>secB->PRN;
        }
    }
    else
    {
        while(t->link->PRN!=temp)
        {
            t=t->link;
        }
        tmp=t->link;
        t->link=t->link->link;
        delete(tmp);
        cout<<"\n**** Member details deleted successfully ****\n"<<endl;
    }
}
int member(char div)
{
    struct club *t;
    int i=0;
    if(div=='a' || div=='A')
    {
        t=startA;
        while(t!=NULL)
        {
            t=t->link;
            i++;
        }
        return(i);
    }
    else if(div=='b' || div=='B')
    {
        t=startB;
        while(t!=NULL)
        {
            t=t->link;
            i++;
        }
        return(i);
    }

}
void rev(struct club *t,char div)
{
    if(t->link!=NULL)
    {
        rev(t->link,div);
    }
    if(t==startA || t==startB)
		{
		    cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"PRESIDENT"<<setw(15)<<div<<endl;
		}
		else if(t==secA || t==secB)
		{
		    cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"SECRETARY"<<setw(15)<<div<<endl;
		}
		else
        {
            cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"MEMBER"<<setw(15)<<div<<endl;
        }
}
void concatenate()
{
    struct club *t=startA,*current=start;
    while(t!=NULL)
    {
        if(t==startA)
        {
            start=new(struct club);
            strcpy(start->name,t->name);
            start->PRN=t->PRN;
            current=start;
        }
        else
        {
            current->link=new(struct club);
            strcpy(current->link->name,t->name);
            current->link->PRN=t->PRN;
            current=current->link;
        }
        t=t->link;
    }
    t=startB;
    while(t!=NULL)
    {
        current->link=new(struct club);
        strcpy(current->link->name,t->name);
        current->link->PRN=t->PRN;
        current=current->link;
        if(t==secB)
        {
            sec=current;
        }
        t=t->link;
    }
}
void dis()
{
    struct club *t=start;
    int z=0;
    cout<<setw(15)<<"NAME"<<setw(15)<<"PRN NO"<<setw(15)<<"POST"<<setw(15)<<"DIVISION"<<endl;
    while(t!=NULL)
    {
        if(z==0)
        {
            if(t==start)
            {
                cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"PRESIDENT"<<setw(15)<<"A"<<endl;
            }
            else
            {
                cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"MEMBER"<<setw(15)<<"A"<<endl;
            }
            if(t->PRN==secA->PRN)
            {
                z++;
            }
        }
        else if(z==1)
        {
            if(t==sec)
            {
                cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"SECRETARY"<<setw(15)<<"B"<<endl;
            }
            else
            {
                cout<<setw(15)<<t->name<<setw(15)<<t->PRN<<setw(15)<<"MEMBER"<<setw(15)<<"B"<<endl;
            }
        }
        t=t->link;
    }
}
