// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    int V,E;
    cout<<"Enter the number of vertices and Edges: ";
    cin>>V>>E;
    vector<vector<int>> adjmatrix(V,vector<int>(V,0));
    cout<<"Enter the edges(u,v):"<<endl;
    int u,v;
    for(int i=0;i<E;i++){
        cin>>u>>v;
         adjmatrix[u][v]=1;
         //adjmatrix[v][u]=1;
    }
    cout<<"Adj matrix"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<int> in(V,0),out(V,0);
    for(int i=0;i<V;i++){
        cout<<i<<":";
        for(int j=0;j<V;j++){
            if(adjmatrix[i][j]){
                cout<<j;
                in[j]++;
                out[i]++;
                
            }
        }
        cout<<endl;
    }
    for(int i=0;i<V;i++){
        cout<<i<<":"<<in[i]<<":"<<out[i]<<endl;
    }
    
    return 0;
}
