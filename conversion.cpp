#include<iostream>
#include<string.h>
#include<stack>
#include<math.h>
#include<stdlib.h>
using namespace std;

class conver
{
	int top=-1,x,i,k=0,ans;
	char oper[100],expre[100],post[100];
	string op1,op2,post1[100];
	public:
	void push(char b)
	{
		x=isfull();
		if(x==1)
		{
		    top++;
			oper[top]=b;
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
			return(oper[top--]);
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
		if(top==100)
			return 0;
		else
			return 1;
	}
	void display()
	{

    	cout<<post<<endl;

	}
	void get_expre()
	{
		cout<<"Enter Expression: ";
		cin>>expre;
	}
	void in_to_post()
	{

		for(i=0;i<strlen(expre);i++)
		{
			if((expre[i]>='A' && expre[i]<='Z')||(expre[i]>='a' && expre[i]<='z'))
			{
				post[k++]=expre[i];
				post[k]=NULL;
			}
			else if(expre[i]=='+' || expre[i]=='-'|| expre[i]=='*' || expre[i]=='/' || expre[i]=='^')
			{
				if(top==-1)
					push(expre[i]);
				else
				{
					if(get_weight(expre[i])>get_weight(oper[top]))
						push(expre[i]);
					else if(get_weight(expre[i])<=get_weight(oper[top]))
					{
						post[k++]=pop();
						post[k]=NULL;
						push(expre[i]);
					}
				}
			}
			else if(expre[i]=='(' || expre[i]==')')
			{
				if(expre[i]=='(')
					push(expre[i]);
				else
				{
					while(oper[top]!='(')
					{
						post[k++]=pop();
						post[k]=NULL;
					}
					post[k++]=pop();
					post[k]=NULL;
				}
			}
		}
		while(top!=-1)
		{
			post[k++]=pop();
			post[k]=NULL;
		}
		cout<<"Postfix Expression is: ";
		display();

	}
	void in_to_pre()
	{
		k=0;
		for(i=strlen(expre)-1;i>=0;i--)
		{
			if((expre[i]>='A' && expre[i]<='Z')||(expre[i]>='a' && expre[i]<='z'))
			{
				post[k++]=expre[i];
				post[k]=NULL;
			}
			else if(expre[i]=='+' || expre[i]=='-'|| expre[i]=='*' || expre[i]=='/' || expre[i]=='^')
			{
				if(top==-1)
					push(expre[i]);
				else
				{
					if(get_weight(expre[i])>get_weight(oper[top]))
						push(expre[i]);
					else if(get_weight(expre[i])<=get_weight(oper[top]))
					{
						post[k++]=pop();
						post[k]=NULL;
						push(expre[i]);
					}
				}
			}
			else if(expre[i]=='(' || expre[i]==')')
			{
				if(expre[i]=='(')
					push(expre[i]);
				else
				{
					while(oper[top]!='(')
					{
						post[k++]=pop();
						post[k]=NULL;
					}
					post[k++]=pop();
					post[k]=NULL;
				}
			}
		}
		while(top!=-1)
		{
			post[k++]=pop();
			post[k]=NULL;
		}
		cout<<"Prefix expression is: ";
		for(i=strlen(post)-1;i>=0;i--)
		{
			cout<<post[i];
		}
	}
	void post_to_pre()
	{
		k=0;
		for(i=0;i<strlen(expre);i++)
		{
			if((expre[i]>='A' && expre[i]<='Z')||(expre[i]>='a' && expre[i]<='z'))
			{
				post1[k]=expre[i];
				k++;
			}
			else if(expre[i]=='+' || expre[i]=='-'|| expre[i]=='*' || expre[i]=='/' || expre[i]=='^')
			{
				op1=post1[--k];
				op2=post1[--k];
				post1[k]=expre[i]+op2+op1;
				k++;
			}
		}
		cout<<"Prefix Expression is: "<<post1[0];
	}
	void pre_to_post()
	{
		k=0;
		for(i=strlen(expre)-1;i>=0;i--)
		{
			if((expre[i]>='A' && expre[i]<='Z')||(expre[i]>='a' && expre[i]<='z'))
			{
				post1[k]=expre[i];
				k++;
			}
			else if(expre[i]=='+' || expre[i]=='-'|| expre[i]=='*' || expre[i]=='/' || expre[i]=='^')
			{
				op1=post1[--k];
				op2=post1[--k];
				post1[k]=op1+op2+expre[i];
				k++;
			}
		}
		cout<<"Postfix Expression is: "<<post1[0];
	}
	void post_to_in()
	{
		k=0;
		for(i=0;i<strlen(expre);i++)
		{
			if((expre[i]>='A' && expre[i]<='Z')||(expre[i]>='a' && expre[i]<='z'))
			{
				post1[k]=expre[i];
				k++;
			}
			else if(expre[i]=='+' || expre[i]=='-'|| expre[i]=='*' || expre[i]=='/' || expre[i]=='^')
			{
				op1=post1[--k];
				op2=post1[--k];
				post1[k]='('+op2+expre[i]+op1+')';
				k++;
			}
		}
		cout<<"Infix Expression is: "<<post1[0];
	}
	void pre_to_in()
	{
	    k=0;
		for(i=strlen(expre)-1;i>=0;i--)
		{
			if((expre[i]>='A' && expre[i]<='Z')||(expre[i]>='a' && expre[i]<='z'))
			{
				post1[k]=expre[i];
				k++;
			}
			else if(expre[i]=='+' || expre[i]=='-'|| expre[i]=='*' || expre[i]=='/' || expre[i]=='^')
			{
				op1=post1[--k];
				op2=post1[--k];
				post1[k]='('+op1+expre[i]+op2+')';
				k++;
			}
		}
		cout<<"Infix Expression is: "<<post1[0];
	}
	void evaluate_post()
	{
	    k=0;
	    char o1,o2;
	    int c;
		for(i=0;i<strlen(expre);i++)
		{
			if((expre[i]>='A' && expre[i]<='Z')||(expre[i]>='a' && expre[i]<='z'))
			{
			    cout<<"Enter the value of "<<expre[i]<<" : ";
				cin>>c;
				post1[k][0]=c;
				k++;
			}
			else if(expre[i]=='+' || expre[i]=='-'|| expre[i]=='*' || expre[i]=='/' || expre[i]=='^')
			{
				o1=post1[--k][0];
				o2=post1[--k][0];
				if(expre[i]=='+')
                    post1[k][0]=o2+o1;
				else if(expre[i]=='-')
                    post1[k][0]=(o2)-(o1);
                else if(expre[i]=='*')
                    post1[k][0]=(o2)*(o1);
                else if(expre[i]=='/')
                    post1[k][0]=o2/o1;
                else if(expre[i]=='^')
                    post1[k][0]=pow(o2,o1);
				k++;
			}
		}
		cout<<"Answer: "<<(int)post1[0][0];
	}
	void evaluate_pre()
	{
	    k=0;
	    char o1,o2;
	    int c;
		for(i=strlen(expre)-1;i>=0;i--)
		{
			if((expre[i]>='A' && expre[i]<='Z')||(expre[i]>='a' && expre[i]<='z'))
			{
			    cout<<"Enter the value of "<<expre[i]<<" : ";
			    cin>>c;
			    post1[k][0]=c;
				k++;
			}
			else if(expre[i]=='+' || expre[i]=='-'|| expre[i]=='*' || expre[i]=='/' || expre[i]=='^')
			{
				o1=post1[--k][0];
				o2=post1[--k][0];
				if(expre[i]=='+')
                    post1[k][0]=o1+o2;
                else if(expre[i]=='-')
                    post1[k][0]=o1-o2;
                else if(expre[i]=='*')
                    post1[k][0]=o1*o2;
                else if(expre[i]=='/')
                    post1[k][0]=o1/o2;
                else
                    post1[k][0]=pow(o1,o2);
				k++;
			}
		}
		cout<<"Answer: "<<(int)post1[0][0];
	}
	int get_weight(char a)
	{
		switch(a)
		{
			case '^':
				return 3;
			case '/':
				return 2;
			case '*':
				return 2;
			case '+':
				return 1;
			case '-':
				return 1;
			case '(':
				return 0;
		}
	}
};

int main()
{
    int ch;
	conver A;
	while(true)
    {
        cout<<"\n\nMENU\n\n";
        cout<<"1] Convert Infix expression to Postfix\n2] Convert Infix expression to Prefix\n3] Convert Postfix expression to Prefix\n4] Convert Prefix expression to Postfix\n5] Convert Postfix expression to Infix\n6] Convert Prefix expression to Infix\n7] Evaluate Expression\n8] Exit";
        cout<<"\n\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                A.get_expre();
                A.in_to_post();
                break;
            }
        case 2:
            {
                A.get_expre();
                A.in_to_pre();
                break;
            }
        case 3:
            {
                A.get_expre();
                A.post_to_pre();
                break;
            }
        case 4:
            {
                A.get_expre();
                A.pre_to_post();
                break;
            }
        case 5:
            {
                A.get_expre();
                A.post_to_in();
                break;
            }
        case 6:
            {
                A.get_expre();
                A.pre_to_in();
                break;
            }
        case 7:
            {

                int choice;
                cout<<"Which expression you have?"<<endl;
                cout<<"1] Postfix\n2] Prefix"<<endl;
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                case 1:
                    {
                        A.get_expre();
                        A.evaluate_post();
                        break;
                    }
                case 2:
                    {
                        A.get_expre();
                        A.evaluate_pre();
                        break;
                    }
                }
                break;

            }
        case 8:
            {
                exit(0);
            }

        }
    }
}
