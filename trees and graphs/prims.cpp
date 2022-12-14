#include<iostream>
#include<vector>

using namespace std;

#define I INT_MAX

int cost [][8] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };

int near[]={I,I,I,I,I,I,I,I};

int t[2][6]; //t[2][|V|-1]

int main(){
    int u,w;
    int n=7, min=I;
    //step1: initialization
    //take min cost from the matrix
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(cost[i][j]<min) {
                min=cost[i][j];
                u=i;w=j;
            }
        }
    }
    t[0][0]=u;
    t[1][0]=w;
    near[u]=0;near[w]=0;
    //initialize near array: for each vertex check minimum edge 
    for(int i=1;i<=n;i++){
        if(near[i]!=0){
            if(cost[i][u]<cost[i][w]) near[i]=u;
            else near[i]=w;
        }
    }

    //step2: start looping
    //find next edge
    for(int i=1;i<n-1;i++){
        min=I;
        int k;
        for(int j=1;j<=n;j++){
            if(near[j]!=0&&cost[j][near[j]]<min){
                min=cost[j][near[j]];
                k=j;
            }
        }
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
    //update near array if a particular index is closer to K thand the current value;

        for(int i=1;i<=n;i++){
            if(near[i]!=0&&cost[i][k]<cost[i][near[i]]){
                near[i]=k;
            }
        }
    }

    //printing the MST
    for(int i=0;i<=n;i++){
        cout<<t[0][i]<<" "<<t[1][i]<<endl;
    }

    return 0;
}
