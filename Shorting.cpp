#include <iostream>
#include <ctime>
using namespace std;

struct ListNode
{
    int Value;
    ListNode* Next;
    ListNode(int val) : Value(val), Next(NULL) {}
};

ListNode* GetListTail(ListNode *head)
{
    while (head != NULL && head->Next != NULL)
    {
        head = head->Next;
    }
    return head;
}

ListNode* GetRandomNode(ListNode *head, ListNode *tail)
{
    int Length = 0;
    ListNode* current = head;
    ListNode* result = NULL;
    while (current != NULL)
    {
        Length++;
        if (rand() % Length == 0)
        {
            result = current;
        }
        current = current->Next;
    }
    return result;
}

ListNode* PartitionList(ListNode* head, ListNode *end, ListNode **newHead, ListNode **newEnd)
{
    ListNode* Pivot = GetRandomNode(head, end);
    ListNode* previous = NULL;
    ListNode* current = head;
    ListNode* tail = Pivot;

    while (current != Pivot)
    {
        if (current->Value < Pivot->Value)
        {
            if (*newHead == NULL)
            {
                *newHead = current;
            }
            previous = current;
            current = current->Next;
        }
        else
        {
            if (previous)
            {
                previous->Next = current->Next;
            }
            ListNode *temp = current->Next;
            current->Next = NULL;
            tail->Next = current;
            tail = current;
            current = temp;
        }
    }

    if (*newHead == NULL)
    {
        *newHead = Pivot;
    }
    *newEnd = tail;

    return Pivot;
}

ListNode* QuickSortRecursive(ListNode *head, ListNode *end)
{
    if (!head || head == end)
    {
        return head;
    }

    ListNode* newHead = NULL;
    ListNode* newEnd = NULL;

    ListNode* Pivot = PartitionList(head, end, &newHead, &newEnd);

    if (newHead != Pivot)
    {
        ListNode *temp = newHead;
        while (temp->Next != Pivot)
        {
            temp = temp->Next;
        }
        temp->Next = NULL;

        newHead = QuickSortRecursive(newHead, temp);

        temp = GetListTail(newHead);
        temp->Next = Pivot;
    }

    Pivot->Next = QuickSortRecursive(Pivot->Next, newEnd);

    return newHead;
}

void QuickSortList(ListNode** headRef)
{
    *headRef = QuickSortRecursive(*headRef, GetListTail(*headRef));
}

void AddListNode(ListNode** headRef, int newData)
{
    ListNode *newNode = new ListNode(newData);
    newNode->Next = *headRef;
    *headRef = newNode;
}

void DisplayListNode(ListNode *node)
{
    while (node)
    {
        cout << node->Value << " ";
        node = node->Next;
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    ListNode *listHead = NULL;
    int userChoice, data;

    do
    {
        cout << "1. Add number in list" << endl;
        cout << "2. Sort the list" << endl;
        cout << "3. Print the element of list" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            cout << "Enter number to add in the List: ";
            cin >> data;
            AddListNode(&listHead, data);
            break;
        case 2:
            QuickSortList(&listHead);
            cout << "List sorted successfully." << endl;
            break;
        case 3:
            cout << "Linked List: ";
            DisplayListNode(listHead);
            break;
        case 4:
            cout << "Program terminated" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (userChoice != 4);

    return 0;
}

