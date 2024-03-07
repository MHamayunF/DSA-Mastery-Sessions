#include<iostream>
using namespace std;
class stack{
	private:
		int top,size;
		int *array;
	public:
		stack(int s)
		{
			size=s;
			top=-1;
			array=new int[size];
		}
	void push(int data)
	{
		if(top==size-1)
		{
			cout<<"stack is full"<<endl;
			return;
		}
		else
		{
			array[++top]=data;
		}
	}
	int pop()
	{
		if(top==-1)
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			int temp=array[top--];
		}
	}
	int Top()
	{
		if(top==-1)
		{
			cout<<"Stack is empty"<<endl;
		}
		return array[top];
	}
	bool empty()
	{
		if(top==-1)
			return true;
		else
			false;
	}
	void show()
	{
		int t=top;
		
		if(t==-1)
		{
			cout<<"Stack is empty"<<endl;
			return;
		}
		while(t!=-1)
		{
			cout<<array[t]<<" ";
			t--;
		}
		
	}
};
int main()
{
	stack stk(5);
	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout<<"Stack is ";
	stk.show();
	cout<<endl;
	stk.pop();
	cout<<"Stack after pop is "<<endl;
	stk.show();
	cout<<endl;
	cout<<stk.Top();
	cout<<endl;
	cout<<stk.empty();
	return 0;
}
