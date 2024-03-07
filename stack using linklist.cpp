
#include<iostream>
using namespace std;
struct link_list{
	int data;
	link_list* next;
};
class stack{
	private:
		link_list* top;
	public:
		stack()
		{
			top=NULL;
		}
		void push(int data)
		{
			if(top==NULL)
			{
				top=new link_list;
				top->data=data;
				top->next=NULL;
				return;
			}
			else
			{
				link_list* present=top;
				while(present->next!=NULL)
				{
					present=present->next;
				}
				link_list* temp=new link_list;
				present->next=temp;
				temp->data=data;
				temp->next=NULL;
			}
		}
		int pop()
		{
			link_list* present=top;
			if(top==NULL)
			{
				cout<<"Stack is empty"<<endl;
				return NULL;
			}
			link_list* previous=present;
			while(present->next!=NULL)
			{
				previous=present;
				present=present->next;
			}
			previous->next=NULL;
			int data=present->data;
			delete present;
			return data;
		}
		int Top()
		{
			if(top==NULL)
			{
			cout<<"Stack is empty"<<endl;
			return NULL;
		}
		return top->data;
		}
		bool empty()
		{
		if(top==NULL)
			return 1;
		else
			return 0;
		}
		void show()
		
		{
			link_list* present=top;
			if(top==NULL)
			{
				cout<<"Stack is empty"<<endl;
				return;
			}
			link_list* previous=present;
			while(present!=NULL)
			{
				cout<<present->data<<" ";
				present=present->next;
			}
			cout<<endl;
		}
};
int main()
{
	stack stk;
	stk.push(2);
	stk.push(3);
	stk.push(4);
	cout<<"Stack before push is "<<endl;
	stk.show();
	stk.pop();
	cout<<"stack after pop is "<<endl;
	stk.show();
	cout<<"top element "<<stk.Top()<<endl;
	cout<<"empty function "<<stk.empty()<<endl;
	
	
	return 0;
}
