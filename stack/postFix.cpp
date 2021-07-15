#include<iostream>
#include<cstring>
using namespace std;
#define MAX 50
class STACK
{
	char stack[MAX];
	int top;
	public:
		STACK()
		{
			top=-1;
		}
		int isEmpty()
		{
			if(top==-1)
			{
				return 0;
			}
			else
				return 1; 
		}
		int isFull()
		{
			if(top==MAX-1)
			{
				cout<<"\nStack is Full ";
				return 0;
			}
			else
				return 1; 
		}
		void push(char element)
		{
			top++;
			stack[top]=element;
		}
		char pop()
		{
			return stack[top--];
		}
		char topElement()
		{
			return stack[top];
		}
			
};

int isOperator(char symbol)
{
	if(symbol=='+')
		return 2;
	else if(symbol=='-')
		return 1;
	else if(symbol=='*')
		return 3;
	else if(symbol=='/')
		return 4;
	else if (symbol=='%')
		return 5;
	else 
		return 0;
}
void infixToPrefix(char inFixExpression[30],char preFixExpression[30])
{
	STACK s;
	int y,count=0,infixLength,x,flag=0;
	strrev(inFixExpression);
	infixLength=strlen(inFixExpression);
	for(int i=0;i<infixLength;i++)
	{
		flag=0;
		x=isOperator(inFixExpression[i]);
		if(x!=0)
		{
			flag=1;
			if(s.isEmpty()==0)
				{
					s.push(inFixExpression[i]);
				}
			else
			{
				y=isOperator(s.topElement());
				while(1)
				{
					y=isOperator(s.topElement());
					if(y<=x)
					{
						s.push(inFixExpression[i]);
						break;
					}
					else
					{
						if(s.isEmpty()==0)
							break;
						preFixExpression[count++]=s.pop();
					}
				} 
			}
		}
		else if(flag==0)
		{
			preFixExpression[count++]=inFixExpression[i];
		}
	}
		while(s.isEmpty())
			preFixExpression[count++]=s.pop();
		strrev(preFixExpression);
		
		cout<<"\n";
		cout<<preFixExpression;
}

void infixToPostfix(char inFixExpression[30],char postFixExpression[30])
{
	int i,j,count=0,op,top;
	STACK post;
	strrev(inFixExpression);
	int length=strlen(inFixExpression);
	for(i=0;i<length;i++)
	{
		op=isOperator(inFixExpression[i]);
		if(op!=0)
		{
			if(!post.isEmpty())
			{
				post.push(inFixExpression[i]);
			}
			else
			{
				while(1)
				{
					top=isOperator(post.topElement());
					if(op>top)
					{
						post.push(inFixExpression[i]);
						break;
					}
					else
					{
						if(!post.isEmpty())
							break;
						postFixExpression[count++]=post.pop();
					}
				}
			}
		}
		else
		{
			postFixExpression[count++]=inFixExpression[i];
		}
		
	}
	
	
	while(post.isEmpty())
		postFixExpression[count++]=post.pop();
	
	cout<<"\nPost Fix Expression : ";
	cout<<postFixExpression;
	
	
	
	
	
}

int main()
{
	STACK s;
	char postFixExpression[30];
	char inFixExpression[30];
	char preFixExpression[30];
	cout<<"\nEnter INFIX EXPRESSION ";
	cin>>inFixExpression;
	infixToPrefix(inFixExpression,preFixExpression);
	infixToPostfix(inFixExpression,postFixExpression);






}
