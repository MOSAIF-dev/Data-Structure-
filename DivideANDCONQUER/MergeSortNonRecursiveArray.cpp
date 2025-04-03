#include<iostream>
using namespace std;

// What is the logic behind merging the array?
// We compare half of the array with the other half.
// We take the smallest element from the first half and the smallest element from the second half.
// We compare them and put the smallest one in the first position of the array.
// We repeat the same process until we find the smallest element in the array.

class Merge_Sort_Same_Array {
private:
    int *Original_Array;
    int size;

public:
    // Constructor to initialize the array and its size
    Merge_Sort_Same_Array(int Size) {
        size = Size;
        Original_Array = new int[size];  // Dynamically allocate memory for the array
    }

    // Recursive MergeSort function
    void MergeSort(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            MergeSort(low, mid);      // Recursively sort the first half
            MergeSort(mid + 1, high); // Recursively sort the second half
            Merge(low, mid, high);    // Merge the two sorted halves
        }
    }

    // In-place Merge function to merge two sorted subarrays
    void Merge(int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        
        // Loop to merge the two sorted halves
        while (i <= mid && j <= high) {
            if (Original_Array[i] <= Original_Array[j]) {
                i++;
            } else {
                // Swap the elements to merge in-place
                int temp = Original_Array[j];
                // Shift all elements in the left part to the right by one position
                for (int k = j; k > i; k--) {
                    Original_Array[k] = Original_Array[k - 1];
                }
                // Place the saved value at the correct position
                Original_Array[i] = temp;
                
                // Move the pointers
                i++;
                j++;
                mid++;  // Adjust mid since the array has shifted
            }
        }
    }

    // Function to input elements into the array
    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> Original_Array[i];
        }
    }

    // Function to display the sorted array
    void display() {
        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << Original_Array[i] << " ";
        }
        cout << endl;
    }

    
};

int main() {
    int num;
    cout << "Enter the number of elements: ";
    cin >> num;

    // Create an object of Merge_Sort_Same_Array
    Merge_Sort_Same_Array obj(num);

    // Input elements
    obj.input();

    // Perform MergeSort
    obj.MergeSort(0, num - 1);

    // Display the sorted array
    obj.display();

    return 0;
}


//   Is this code give a good Time-Complexity and Space-Complexity?  To compare the previous one MergeSort.cpp ?

//  ANS : NO , this code is not give  a good Time -Complexity bcz ....

//  T(n) = {2T(N/2) + n^2  }, bcz T(n/2) is to for first half of array and T(n/2) is for second half of array and n^2 is for.
// Conquring Cost for merging the Array is O(n^2) .

//  Overall             T(n) = {2T(n/2) +n^2 , n>1
//                               1, n<=1 }

//  Just Apply the Master Theorem where a = 2 and b = 2 , and f(n) = n^2 . after comaparing ,  It follows the Case 3 

//    Case 3 - f(n) = n.log a (b) and after it compare the Neccecasry Condition 

//              af(n/2)<=c.f(n) where c<1 


//  Finaly answer is Time Complexity = θ(n^2) .
//  Space Complexity = θ(1) . , bcz we are not using any extra Array so , it only works on the same array .






//                  THE END OF CODE 
//                  MO SAIF BABA , 231227