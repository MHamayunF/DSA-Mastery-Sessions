#include <iostream>
#include <string>

using namespace std;

const int TableSize = 10;

class Student {
	public:
		int studentId;
		string studentName;

		Student() {
			studentId = 0;
			studentName = "";
		}

		Student(int _id, const string& _name) {
			studentId = _id;
			studentName = _name;
		}
};

class Node {
	public:
		Student studentData;
		Node* nextNode;

		Node(Student _student) {
			studentData = _student;
			nextNode = NULL;
		}
};

class HashTable {
	private:
		Node* hashTable[TableSize];

	public:
		HashTable() {
			for (int i = 0; i < TableSize; ++i) {
				hashTable[i] = NULL;
			}
		}

		int hashFunction(int key) {
			return key % TableSize;
		}

		void addStudent(const Student& student) {
			if (student.studentId < 0) {
				cout << "Invalid id Please enter a non-negative id"<<endl;
				return;
			}

			int index = hashFunction(student.studentId);

			Node* newNode = new Node(student);
			newNode->nextNode = hashTable[index];
			hashTable[index] = newNode;
		}

		Node* findStudent(int id) {
			int index = hashFunction(id);
			Node* current = hashTable[index];

			while (current != NULL) {
				if (current->studentData.studentId == id) {
					return current;
				}
				current = current->nextNode;
			}

			return NULL;
		}

		void removeStudent(int id) {
			int index = hashFunction(id);
			Node* current = hashTable[index];
			Node* previous = NULL;

			while (current != NULL) {
				if (current->studentData.studentId == id) {
					if (previous == NULL) {
						hashTable[index] = current->nextNode;
					} else {
						previous->nextNode = current->nextNode;
					}

					delete current;
					cout << "Student record removed successfully!"<<endl;
					return;
				}

				previous = current;
				current = current->nextNode;
			}

			cout << "Student not found"<<endl;
		}

		void displayStudents() {
			for (int i = 0; i < TableSize; ++i) {
				Node* current = hashTable[i];

				while (current != NULL) {
					cout << "ID: " << current->studentData.studentId << ", Name: " << current->studentData.studentName << endl;
					current = current->nextNode;
				}
			}
		}
};

int main() {
	HashTable studentHashTable;

	while (true) {
		cout << "***************************************"<<endl;
		cout << "Enter your choice:"<<endl;
		cout << "1. Add a new student record"<<endl;
		cout << "2. Search for a student by ID"<<endl;
		cout << "3. Remove a student record"<<endl;
		cout << "4. Display the entire list of students"<<endl;
		cout << "5. Exit the program"<<endl;
		cout << "***************************************"<<endl;

		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1: {
				int id;
				string name;
				cout << "Enter student ID: ";
				cin >> id;
				cout << "Enter student name: ";
				cin >> name;

				Student newStudent(id, name);
				studentHashTable.addStudent(newStudent);

				cout << "Student record added successfully!"<<endl;
				break;
			}
			case 2: {
				int id;
				cout << "Enter student ID to search: ";
				cin >> id;

				Node* result = studentHashTable.findStudent(id);
				if (result !=NULL) {
					cout << "Student found! ID: "<<result->studentData.studentId<<", Name: "<<result->studentData.studentName<< endl;
				} else {
					cout << "Student not found"<<endl;
				}
				break;
			}
			case 3: {
				int id;
				cout << "Enter student ID to remove: ";
				cin >> id;

				studentHashTable.removeStudent(id);
				break;
			}
			case 4:
				studentHashTable.displayStudents();
				break;
			case 5:
				cout << "Exiting the program"<<endl;
				return 0;
			default:
				cout << "Invalid choice. Please enter a valid option."<<endl;
		}
	}
	return 0;
}

