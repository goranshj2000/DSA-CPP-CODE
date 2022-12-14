#include<iostream>
#include<vector>
#include<queue>

#define pb push_back

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<bool> visited2;

void edge(int u, int w){
    g[u].pb(w);
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()){
        int a=q.front();
        cout<<a<<" ";
        
        q.pop();

        for(int i=0;i<g[a].size();i++){
            if(!visited[g[a][i]]){
                q.push(g[a][i]);
                visited[g[a][i]]=true;
            }
        }        
    }
}

//doesnt work on disconnected graphs
void dfs(int u){
    
    
    cout<<u<<" ";
    visited2[u]=true;
    
    for(int i=0;i<g[u].size();i++){
        if(!visited2[g[u][i]]) dfs(g[u][i]);
        
    }
}

int main(){
    int v, e;
    cin>>v>>e;
    visited.assign(v,false);
    visited2.assign(v,false);
    g.assign(v,vector<int>());

    for(int i=0;i<e;i++){
        int a,b;cin>>a>>b;
        edge(a,b);
    }

    bfs(0);
    cout<<endl;
    dfs(0);
    return 0;

}