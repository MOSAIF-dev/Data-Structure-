#include<iostream>
using namespace std;

class Array {
public:
    int* arr;
    int size;
    int currentSize;

    Array(int Size) {
        size = Size;
        arr = new int[size];
        currentSize = 0;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cout << "Enter your " << (i + 1) << " index value: ";
            cin >> arr[i];
            heapifyUp(currentSize);  
            currentSize++;
        }
    }

    void heapifyUp(int i) {
        
        while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void display() {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array arr(12);
    arr.input();
    arr.display();
    return 0;
}


//  Baba Logic kya h ?

// Logic For this code in simple ways : Follows some terminologies to Build the Max heap 

//  MaxHeap kya h ? 
//  Ans:-           In the MaxHeap the root node is biggere to their children  and must be Complete Binary Tree
//  Complete Binary Tree Def: Every Level must be loaded with 0 or 2 child till (l-1)th level the last level must be loaded left to right .

// Something about MaxHeap , First we have to know Tree is nothing but it is the set of Elements in the Array where we make operations on the Array 
//  like Insertion , Deletion , Searching , Sorting(Heap Sort) etc .
//  While Insert Any Type of node we have to look the parents is it(parents) is greater or not to their child .
//  If Parents is initialy greater then no need to swap otherwise swap both the Elements .
//  Like This we go till Bottom and comapre each other and swap . 

//  What About Time Complexity ?

//  In the MaxHeap  :

//  MaxHeap is build by Two method   [i]- Top Down Approches [ii]- Bottom Up Approches .

//  So this algo is Buttom up approches why ?

//  Answer :  In the Buttom Up approches first half Element is Non-leaf Node and second half is leaf node only , so we iterate only first half Element only  (mid-1) to 0 .
//  Note :-  While we findting the Time complexity of the Tree we have first knowledge about finding the Height of the Tree .

//  H = 1*2^0 + 2*2^1 + 2*2^2 + ........... + h*2^h .



//  SO , while we finding the Hight we get (h*2^h) where n is the number of nodes in the Tree .

//  So taking log both the side and finaly TC = (n.logn).


//                                              MO SAIF 
//                                              231227
//                                              4th Sem , 2nd Year 
//                                              CSE , BSc(hons)
//                                              University Of Delhi .