#include<iostream>
#include<queue>
#include<list>

using namespace std;

class graph{
    public:
    int n;
    list<int> *adj; //list of lists || list of pointers to lists
    

    graph(int size){
        n=size;
        adj=new list<int> [n];
    }

    void add_edge(int u , int w);

    void BFS(int k);

    void print_adj_matrix();
};

void graph::add_edge(int u, int w){
    adj[u].push_back(w);
}

void graph::print_adj_matrix(){
    cout<<"\n";
    for(int i=0;i<n;i++){
        vector<int> a(n,0);
        list<int>::iterator it=adj[i].begin();
        while(it!=adj[i].end()){
            a[*it]=1;
            it++;
        }
        for(int j=0;j<n;j++){
            cout<<a[j]<<" ";
        }

        
    }
}

int main(){
    graph goro(3);
    goro.add_edge(1,2);
    //goro.print_adj_matrix();
    return 0;
}
