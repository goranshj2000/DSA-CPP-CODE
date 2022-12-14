#include<iostream>
#include "Queue.h"

using namespace std;


class Tree{
    public:
    Node *root;
    Tree(){root=NULL;}
    void createTree();
    void preorder(Node* p);
    void inorder(Node* p);
    void postorder(Node *p);
    void levelorder(Node *p);
    int height(Node *p);
};

void Tree::createTree(){
    Node*p,*t;
    int x;
    Queue q(10);
    cout<<"\nenter root value";
    cin>>x;
    root=new Node; root->data=x; root->lchild=nullptr; root->rchild=nullptr;
    q.enqueue(root);

    while(!q.isEmpty()){
        p=q.dequeue();
        cout<<"\nEnter left child of"<<p->data<<": " ; cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;t->lchild=nullptr;t->rchild=nullptr;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"\nEnter Right child of"<<p->data<<": "; cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;t->lchild=nullptr;t->rchild=nullptr;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node* p){
    if(p){
        cout<<"\t"<<p->data;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node* p){
    if(p){
        inorder(p->lchild);
        cout<<"\t"<<p->data;
        inorder(p->rchild);
    }
}

void Tree::postorder(Node* p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<"\t"<<p->data;
    }
}

void Tree::levelorder(Node *p){
    Queue d(20);
    d.enqueue(p);
    cout<<p->data<<" ";
    while(!d.isEmpty()){
        p=d.dequeue();

        if(p->lchild){
            cout<<p->lchild->data<<" ";
            d.enqueue(p->lchild);
        }
        if(p->rchild){
            cout<<p->rchild->data<<" ";
            d.enqueue(p->rchild);
        }        
    }
}

int Tree::height(Node *p){      //draw to check how this one works
    if(p==nullptr) return 0;
    int x=0,y=0;
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y) return x+1;
    else return y+1;

}

int main(){
    Tree goro;
    goro.createTree();    
    goro.preorder(goro.root); cout<<"\n";
    goro.inorder(goro.root);cout<<"\n";
    goro.postorder(goro.root);cout<<"\n";
    goro.levelorder(goro.root);cout<<"\n";
    cout<<goro.height(goro.root);
}