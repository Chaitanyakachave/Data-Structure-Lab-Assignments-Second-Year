#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class stack
{
	int top=-1,x,i;
	char a[100];
	public:
	void push(char b)
	{
		x=isfull();
		if(x==1)
		{
		    top++;
			a[top]=b;
		}
		else
		{
			cout<<"Stack is full..\n";
		}
	}
	char pop()
	{
        x=isempty();
		if(x==1)
		{
			return(a[top]);
			a[top]=NULL;
			top--;
		}
		else
		{
			cout<<"Stack is empty..\n";
		}
	}
	int isempty()
	{
		if(top==-1)
			return 0;
		else
			return 1;
	}
	int isfull()
	{
		if(top==30)
			return 0;
		else
			return 1;
	}
	void display()
	{
	    for(i=0;i<=top;i++)
        {
           cout<<" "<<a[i];
        }
	}
	void compare(stack &R)
	{
	    int flag=0;
	    for(i=0;i<=top;i++)
        {
            if(a[i]!=R.a[i])
            {
                flag=-1;
                break;
            }
        }
        if(flag==0)
            cout<<"String is palindrome..."<<endl;
        else
            cout<<"string is not palindrome..."<<endl;
	}
};
int main()
{
	char str[100];
	int l,i=0;
	stack S,R;
	cout<<"Enter string : ";
	cin.getline(str,30);
	for(i=0;str[i]!=NULL;i++)
	{
	    if(str[i]!=32)
            S.push(str[i]);
	}
	S.display();
	i--;
	for(;i>=0;i--)
    {
        if(str[i]!=32)
            R.push(str[i]);
    }
    cout<<"\n";
    R.display();
    cout<<"\n";
    S.compare(R);
}
