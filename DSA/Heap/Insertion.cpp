#include<iostream>
using namespace std;
class MaxHeap{
    int * arr;
    int size;
    int tot_size;
public:
    MaxHeap(int Length){
        arr  = new int[Length];
        size  = 0;
        tot_size = Length;
    }

    // Insertion Steps 1st 

    void Insert(int value){
        if(size==tot_size){
            cout<<"Heap Overflow \n";
            return ;
        }
        arr[size] = value;
        int index = size;
        size++;

        // Compare the function with parent node and swap if required 
        

        while(index>0 && arr[index] > arr[(index-1)/2]){
            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
             

        }

        
    }


    void Deletion(){
        if(size==0){
            cout<<"Heap UnderFlow \n";
            return ;
        }
        cout<<arr[0]<<" Deleted from the Heap \n";
        arr[0] = arr[size-1];
        size--;

    }

    void Heapify(int index){
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;
        if(left<size && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<size && arr[right]>arr[largest]){
            largest = right;
        }
        if(largest!=index){
            swap(arr[index],arr[largest]);
             Heapify(largest);
        }
       

    }
    int display(){
        if(size==0){
            cout<<"Heap Underflow /n";
            return 0;
        }
        
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }

        cout<<endl<<"Values Inserted Successfully ! "<<endl;
    
    }
};


int main(){

    int size;
    cout<<"Enter your MaxHeap Length: ";
    cin>>size;
    MaxHeap h1(size);
    int Ele;
    for(int i=0;i<size;i++){
        cout<<"Push "<<(i+1)<<" Index Value: ";
        cin>>Ele;
        h1.Insert(Ele);
    }


h1.display();




    return 0;
}