#include <iostream>
using namespace std;

void CustomSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int CustomPartitionFirstPivot(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        while (i <= j && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            CustomSwap(arr[i], arr[j]);
        }
    }
    CustomSwap(arr[low], arr[j]);
    return j;
}

void CustomQuickFirstPivot(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = CustomPartitionFirstPivot(arr, low, high);
        CustomQuickFirstPivot(arr, low, pivotIndex - 1);
        CustomQuickFirstPivot(arr, pivotIndex + 1, high);
    }
}

int CustomPartitionMedian(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    CustomSwap(arr[mid], arr[low]);
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        while (i <= j && arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            CustomSwap(arr[i], arr[j]);
        }
    }
    CustomSwap(arr[low], arr[j]);
    return j;
}

void CustomQuickMedian(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = CustomPartitionMedian(arr, low, high);
        CustomQuickMedian(arr, low, pivotIndex - 1);
        CustomQuickMedian(arr, pivotIndex + 1, high);
    }
}

int CustomPartitionLastPivot(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            CustomSwap(arr[i], arr[j]);
        }
    }
    CustomSwap(arr[i + 1], arr[high]);
    return i + 1;
}

void CustomQuickLastPivot(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = CustomPartitionLastPivot(arr, low, high);
        CustomQuickLastPivot(arr, low, pivotIndex - 1);
        CustomQuickLastPivot(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int userChoice;
    int customArray[] = {3, 6, 8, 10, 1, 2, 1};
    int arraySize = sizeof(customArray) / sizeof(customArray[0]);

    cout << "Select Pivot strategy:" << endl;
    cout << "1. First element as Pivot" << endl;
    cout << "2. Median-of-three Pivot" << endl;
    cout << "3. Last element as Pivot" << endl;
    cout << "Enter your choice: ";
    cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        CustomQuickFirstPivot(customArray, 0, arraySize - 1);
        break;
    case 2:
        CustomQuickMedian(customArray, 0, arraySize - 1);
        break;
    case 3:
        CustomQuickLastPivot(customArray, 0, arraySize - 1);
        break;
    default:
        cout << "Invalid choice" << endl;
        return 1;
    }

    cout << "Sorted array:" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << customArray[i] << " ";
    }
    cout << endl;

    return 0;
}

