#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) 
	{
		data=val;
		next=NULL;
	}
};

class LinkList {
public:
    Node* head;

    LinkList() : head(NULL) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int linearSearch(int value) {
        Node* current = head;
        int index = 0;
        while (current != NULL) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
};

int main() {
    int value, size, result;
    LinkList linkedList;

    cout << "Enter the elements of the linked list: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> value;
        linkedList.add(value);
    }

	cout<<"enter value you want to search"<<endl;
	cin>>value;

    result = linkedList.linearSearch(value);

    if (result != -1) {
        cout << "Element " << value << " found at index " << result << endl;
    } else {
        cout << "Element " << value << " not found in the linked list" << endl;
    }


    }



