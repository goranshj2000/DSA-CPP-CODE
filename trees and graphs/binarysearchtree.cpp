#include<iostream>

using namespace std;

class Node{
    public:
    Node * lchild;
    Node * rchild;
    int data;
};

class bst{
    public:
    Node * root;
    bst(){root=nullptr;}
    

    void insertnode(int val);
    Node * searchnode(int key);
    void inorder(Node *p);
};

void bst::insertnode(int val){
    Node* p=new Node;
    p->data=val;p->lchild=p->rchild=nullptr;
    Node*t=root;
    Node* s;
    
    if(!root){root=p;}
    else{
        while(t){
            if(val==t->data) return;

            else if(val>t->data) {s=t; t=t->rchild;}

            else {s=t; t=t->lchild;}

        }
        (val<s->data)?s->lchild=p:s->rchild=p;

    }
    return;
}

Node* bst::searchnode(int key){
    Node* t=root;
    while(t){
        if(t->data==key){return t;}
        else if(t->data>key){ t=t->lchild;}
        else {t=t->rchild;}
    }
    return t;
}

void bst::inorder(Node * p){
    if(p!=nullptr){
        inorder(p->lchild);
        cout<<" "<<p->data;
        inorder(p->rchild);
    }
}

int main(){
    cout<<"yo";
    bst b;
    Node*t=b.searchnode(30);
    if(!t) cout<<"\n null";
    b.insertnode(10);
    b.insertnode(20);
    b.insertnode(30);
    b.insertnode(15);
    b.insertnode(45);
    b.inorder(b.root);
}