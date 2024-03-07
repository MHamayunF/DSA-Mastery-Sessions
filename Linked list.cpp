#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
	
		node(int value)
		{
			data=value;
			next=NULL;
		}
};

void inhead(node* &head,int value)
{
	node* n=new node(value);
	n->next=head;
	head=n;	
}

void intail(node* &head,int value)
{
	node* n=new node(value);
	node* temp=head;
	if(head==NULL)
	{
		head=n;
		return;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
		
	}
	temp->next=n;
}
void todelete(node* &head,int value)
{
	if(head==NULL)
	{
		return;
	}
	if(head->data==value)
	{
		node* temp=head;
		head=head->next;
		delete temp;
		return;
	}
	node* present=head;
	while(present->next!=NULL)
	{
		if(present->next->data==value)
		{
			node* temp=present->next;
			present->next=temp->next;
			delete temp;
			
		}
		present=present->next;
	}
}

void totraverse(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
		
	}
	cout<<"NULL"<<endl;
}

void insert_at_pos(node* &head,int value,int position)
{
	node* n=new node(value);
	if(position==0)
	{
		n->next=head;
		head=n;
		return;
	}
	node* temp=head;
	int num=0;
	while(temp!=NULL && num>position-1)
	{
		temp=temp->next;
		num++;
	}
	if(temp==NULL)
	{
		cout<<"invalid position";
		delete n;
		return;
	}
	n->next=temp->next;
	temp->next=n;
}

bool search(node* head,int key)
{
	node* temp=head;
	while(temp!=NULL)
	{
	
		if(temp->data==key)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}

void shorting(node* &head)
{
	node *i,*j;
	for(i=head;i!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(i->data>j->data)
			{
				int temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
}
void display(node* &head)
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<" NULL"<<endl;
}

int main()
{
	int condition, num;
	cout<<"press 1 to Insert a node at the beginning of the linked list."<<endl;
	cout<<"press 2 to Insert a node at the end of the linked list."<<endl;
	cout<<"Press 3 to Insert a node at a given position in the linked list."<<endl;
	cout<<"Press 4 to Delete a node from the linked list."<<endl;
	cout<<"Press 5 to Print the elements of the linked list."<<endl;
	cout<<"Press 6 to Search a specific node in the linked list."<<endl;
	cout<<"Press 7 to Traverse."<<endl;
	cout<<"Press 8 to Sorting."<<endl;

	node* head=NULL;
	do
	{
		cin>>condition;
	if(condition==1)
	{
		int value;
		cout<<"Enter value to insert at head"<<endl;
		cin>>value;
		inhead(head,value);
	}
	else if(condition==2)
	{
		int value;
		cout<<"Enter value to insert at tail"<<endl;
		cin>>value;
		intail(head,value);
	}
	else if(condition==3)
	{
		int value, position;
		cout<<"Enter value you want to insert "<<endl;
		cin>>value;
		cout<<"Enter position at where you want to enter "<<endl;
		cin>>position;
		insert_at_pos(head,value,position);	
	}
	else if(condition==4)
	{
		int value;
		cout<<"Enter value you want to delete"<<endl;
		cin>>value;
		todelete(head,value);	
	}
	else if(condition==5)
	{
		display(head);
	}
	else if(condition==6)
	{
		int key;
		cout<<"Enter key to search the node"<<endl;
		cin>>key;
		if(search(head,key))
		{
			cout<<"Key is available in list "<<endl;
		}
		else
		cout<<"Key is not available in list "<<endl;
	}
	else if(condition==7)
	{
		totraverse(head);
	}
	else if(condition==8)
	{
		shorting(head);
		display(head);
	}
	cout<<"Do you want to cont...(if yes enter 1 otherwise press 0)"<<endl;
	cin>>num;
	cout<<"Enter the condition from above list to perform specific operation"<<endl;
	
	}
	while(num!=0);

	return 0;
	
}
