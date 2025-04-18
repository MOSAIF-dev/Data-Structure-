
//  We have unsorted array first we have to sort them then we have to find the median of the array.
// Wr are using the quick sort to sorting the array .

//  Class Definition ..

#include<iostream>
// #include "QuickSort.cpp"
using namespace std;

class Array {
private:
    int *arr;
    int size;

public:
    Array(int Size) {
        size = Size;
        arr = new int[size];
    }

    

    void QuickSort(int low, int high) {
        if (low < high) {
            int pivot = Partition(arr, low, high);
            QuickSort(low, pivot - 1);
            QuickSort(pivot + 1, high);
          
        }
    }

    int Partition(int arr[], int low, int high) {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;

        do {
            while (i <= high && arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }

            if (i < j) {
                swap(arr[i], arr[j]);
            }

        } while (i < j);

        swap(arr[low], arr[j]);
        return j;
    }

    // Def for finding the median of an array of integers

    int Median()
    {
        cout<<arr[size/2];
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << (i + 1) << ": ";
            cin >> arr[i];
        }
    }

    void display() {
        cout << "******** Array Elements ********" << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int num;
    cout << "Enter the size of the array: ";
    cin >> num;

    if (num <= 0) {
        cout << "Invalid array size. Exiting program." << endl;
        return 0;
    }

    Array obj(num);
    obj.input();
    obj.QuickSort(0, num - 1);
    obj.display();
    obj.Median();

    return 0;
}





