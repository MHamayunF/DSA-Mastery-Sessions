#include<iostream>
using namespace std;

int binarySearch(int array[], int size, int value) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid =  end / 2;

        if (array[mid] == value) {
            return mid;
        } else if (array[mid] < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int value, size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int array[size];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << "Enter the value to search: " << endl;
    cin >> value;

    int result = binarySearch(array, size, value);

    if (result != -1) {
        cout << "Value is found at index " << result << endl;
    } else {
        cout << "Value not found in the array" << endl;
    }

    return 0;
}

