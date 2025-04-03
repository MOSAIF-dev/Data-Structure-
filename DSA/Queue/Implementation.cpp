#include<iostream>
using namespace std;

class queue{
    private:
        int *arr;
        int size;
        int front;
        int rear;
    public:
        queue(int capacity){
            size = capacity;
            arr = new int[size];
            front = rear = -1;
        }

    void enqueue(int data){
        if(rear == size-1){
            cout<<"Queue Overflow";
            return ;
        }
        if(front==-1 ){
            front=0;   
        }
            arr[++rear] = data;
        
    }


    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    

void dequeue(){
    if(front==-1 || front>rear){
        cout<<"Queue Underflow";
    }
    cout<<"Deleted Elements from the Queue is: "<<arr[front]<<endl;
    front++;
    if(rear<front){
        front=rear=-1;
    }
}
};
int main(){
    int n;
    cout<<"Enter how many size of your queue ?";
    cin>>n;
    queue q1(n);
    int ele;
    for(int i=0;i<n;i++){
        cout << "Enter Element for position " << i + 1 << ": ";
        cin>>ele;
        q1.enqueue(ele);
    }
    cout<<"Elements before deleting from the Queue ";
    q1.display();
    cout<<"Elements after deleting from the Queue "<<endl;
    q1.dequeue();
    q1.display();
    return 0;
}