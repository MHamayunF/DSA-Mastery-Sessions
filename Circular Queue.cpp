#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class MyCircularQueue {
    stack<int> MyStackForQueue;
    queue<int> MyQueueForPoppedElements;

private:
    int* MyArray;
    int MyTotalSize;
    int MySize;
    int MyFront;
    int MyRear;

public:
    MyCircularQueue(int TotalSize) {
        this->MyTotalSize = TotalSize;
        MyArray = new int[TotalSize];
        MySize = 0;
        MyFront = -1;
        MyRear = -1;
    }

    bool IsEmpty() {
        return MySize == 0;
    }

    bool IsFull() {
        return MySize == MyTotalSize;
    }

    int QueueSize() {
        return MySize;
    }

    void Insert(int Value) {
        if (IsFull()) {
            cout << "Queue is full, We Cannot insert " << Value << endl;
            return;
        }

        if (IsEmpty()) {
            MyFront = MyRear = 0;
        } else {
            MyRear = (MyRear + 1) % MyTotalSize;
        }

        MyArray[MyRear] = Value;
        MySize++;
        cout << "Value is " << Value << " Inserted into the circular queue" << endl;
    }

    void Remove() {
        if (IsEmpty()) {
            cout << "Queue is empty,We Cannot remove." << endl;
            return;
        }

        int RemovedValue = MyArray[MyFront];

        if (MyFront == MyRear) {
            MyFront = MyRear = -1;
        } else {
            MyFront = (MyFront + 1) % MyTotalSize;
        }
        MySize--;
        cout << "Value is " << RemovedValue << " Removed from the circular queue" << endl;
    }

    int Peek() {
        if (IsEmpty()) {
            cout << "Queue is empty,We Cannot peek." << endl;
            return -1;
        }
        return MyArray[MyFront];
    }

    void Display() {
        if (IsEmpty()) {
            cout << "Queue is empty, We cannot display anything." << endl;
            return;
        }

        int Current = MyFront;
        cout << "Circular Queue elements is: ";
        do {
            cout << MyArray[Current] << " ";
            Current = (Current + 1) % MyTotalSize;
        } while (Current != (MyRear + 1) % MyTotalSize);

        cout << endl;
    }

    void PushQueueToStack() {
        int Current = MyFront;
        do {
            MyStackForQueue.push(MyArray[Current]);
            Current = (Current + 1) % MyTotalSize;
        } while (Current != (MyRear + 1) % MyTotalSize);
    }

    void PopStackElements() {
        int Current = MyFront;
        do {
            int Value = MyStackForQueue.top();
            MyStackForQueue.pop();
            MyQueueForPoppedElements.push(Value);
            Current = (Current + 1) % MyTotalSize;
        } while (Current != (MyRear + 1) % MyTotalSize);
    }

    void DisplayReversedQueue() {
        if (MyQueueForPoppedElements.empty()) {
            cout << "Reversed Queue is empty, We cannot display anything." << endl;
            return;
        }

        cout << "Reversed Queue elements are: ";
        while (!MyQueueForPoppedElements.empty()) {
            cout << MyQueueForPoppedElements.front() << " ";
            MyQueueForPoppedElements.pop();
        }
        cout << endl;
    }
};

int main() {
    MyCircularQueue MyQueue(5);

    MyQueue.Insert(5);
    MyQueue.Insert(7);
    MyQueue.Insert(10);
    MyQueue.Insert(1);
    cout << endl;
    MyQueue.Display();
    cout << endl;
    MyQueue.Remove();
    MyQueue.Remove();
    MyQueue.Remove();
    cout << endl;
    MyQueue.Display();
    cout << endl;

    MyQueue.Insert(10);
    MyQueue.Insert(15);
    MyQueue.Insert(20);
    MyQueue.Insert(30);
    cout << endl;
    MyQueue.Display();
    cout << endl;

    cout << "Insert element which invokes the wraparound feature." << endl;
    MyQueue.Remove();
    MyQueue.Insert(50);
    MyQueue.Display();
    cout << endl;
    MyQueue.PushQueueToStack();
    MyQueue.PopStackElements();
    MyQueue.DisplayReversedQueue();

    return 0;
}

