#include <iostream>
using namespace std;

int queue[100], size = 100, front = -1, rear = -1;

bool is_empty() {
   return front == -1;
}

void enqueue() {
   int val;
   if (rear == size - 1)
      cout << "Queue Overflow" << endl;
   else {
      if (front == -1)
         front = 0;
      cout << "Enter the element to insert into the queue: " << endl;
      cin >> val;
      rear++;
      queue[rear] = val;
   }
}

void dequeue() {
   if (is_empty()) {
      cout << "Queue Underflow" << endl;
   } else {
      cout << "Element removed from the queue: " << queue[front] << endl;
      if (front == rear) {
         front = rear = -1;  
      } else {
         front++;
      }
   }
}

void display() {
   if (is_empty())
      cout << "Queue is empty" << endl;
   else {
      cout << "Queue elements are: ";
      for (int i = front; i <= rear; i++)
         cout << queue[i] << " ";
      cout << endl;
   }
}

int main() {
   int choice;
   cout << "1) Insert element into the queue" << endl;
   cout << "2) Delete element from the queue" << endl;
   cout << "3) Display all the elements of the queue" << endl;
   cout << "4) Check if the queue is empty" << endl;
   cout << "5) Exit" << endl;

   do {
      cout << "Enter your choice: " << endl;
      cin >> choice;
      switch (choice) {
         case 1: enqueue();
         break;
         case 2: dequeue();
         break;
         case 3: display();
         break;
         case 4: cout << "Queue is " << (is_empty() ? "empty" : "not empty") << endl;
         break;
         case 5: cout << " terminated" << endl;
         break;
         default: cout << "Invalid choice" << endl;
      }
   } while (choice != 5);
   return 0;
}

