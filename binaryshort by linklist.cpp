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

    LinkList()
    {
    	head=NULL;
	}

    void add(int value)
	 {
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

    int binarySearch(int value) {
        Node* current = head;
        int size = 0;
        while (current != NULL) {
            size++;
            current = current->next;
        }

        int start = 0;
        int end = size - 1;
        current = head;

        while (start <= end) {
            int mid = start + end / 2;
           
            for (int i = 0; i < mid; i++) {
                current = current->next;
            }

            if (current->data == value) {
                return mid;
            } else if (current->data < value) {
                return start = mid + 1;
            } else {
               return end = mid - 1;
            }

            current = head; 
        }

        return -1;
    }
};

int main() {
    int value, size, result;
    LinkList linkedList;

    cout << "Enter the size of linked list: " << endl;
    cin >> size;

    cout << "Enter the elements of the linked list: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> value;
        linkedList.add(value);
    }
	cout<<"enter the value you want to search"<<endl;
	cin>>value;

    result = linkedList.binarySearch(value);

    if (result != -1) {
        cout << "Element " << value << " found at index " << result << endl;
    } else {
        cout << "Element " << value << " not found in the linked list" << endl;
    }

 

    return 0;
}

