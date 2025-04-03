#include <iostream>
#include <list>
using namespace std;

// Function to process every second element and print it with +1 added
void fun1(list<int>::iterator p1) {
    if (p1 == nullptr) {
        return;
    }
    
    // Process the current element by adding 1 and printing it
    cout << (*p1 + 1) << " ";
    
    // Move the iterator two steps ahead
    advance(p1, 2);
    
    // Recursively call fun1 with the updated iterator
    if (p1 != nullptr) {
        fun1(p1);
    }
}

int main() {
    list<int> mylist;
    
    // Adding elements to the list
    mylist.push_back(6);
    mylist.push_back(4);
    mylist.push_back(3);
    mylist.push_back(1);
    mylist.push_back(2);
    mylist.push_back(7);
    
    // Call fun1 with the iterator to the beginning of the list
    fun1(mylist.begin());

    return 0;
}
