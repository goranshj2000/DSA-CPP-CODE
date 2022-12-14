#include<iostream>

using namespace std;

class Node{
    public:
    Node * lchild;
    int data;
    Node * rchild;
};

class Queue
{
    private:
        int size;
        int front;
        int rear;
        Node **Q;

    public:
        Queue(int size2){
            front=rear=-1;
            size=size2;
            Q=new Node*[size];
            }
        ~Queue(){
            //delete [] Q;
        }

        void enqueue(Node* x);
        Node* dequeue();
        bool isEmpty();
        bool isFull();
        void display();
};

void Queue::enqueue(Node* x){
    if(rear==size-1) cout<<"\nfull queue";
    else{
        rear++;
        Q[rear]=x;
    }
}

Node* Queue::dequeue(){
    Node* k=nullptr;
    if(front==rear) cout<<"empty queue";
    else{
        front++;
        k=Q[front];
    }
    return k;
}

bool Queue::isEmpty(){
    if(front==rear) return true;
    else return false;
}

bool Queue::isFull(){
    if(rear==size-1) return true;
    else return false;
}

void Queue::display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}