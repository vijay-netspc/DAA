// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
int V,E,count=0;
vector<vector<int>> adjlist;
vector<int> parent,discovery,finish;
vector<bool>visited;

void classify_edge(int u,int v){
    cout<<u<<"->"<<v;
    if(!visited[v])
        cout<<":Tree-edge\n";
    else if(finish[v]==0&&discovery[u]>discovery[v])
        cout<<":Backward edge\n";
    else if(discovery[u]<discovery[v])
        cout<<":Forward"<<"edge\n";
    else
        cout<<":cross edge\n";
}
void dfs(int u){
    visited[u]=true;
    discovery[u]=count++;
    for(int v:adjlist[u]){
       if(!visited[v]){
           parent[v]=u;
           classify_edge(u,v);
           dfs(v);
       } 
       else{
           classify_edge(u,v);
       }
        
    }
    finish[u]=count++;
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    cout<<"Enter the edges and vertices:";
    cin>>V>>E;
    adjlist.resize(V);
    parent.assign(V,-1);
    discovery.assign(V,0);
    visited.assign(V,false);
    finish.assign(V,0);
    //DFS
    
    cout<<"Enter the edges:\n";
    int u,v;
    for(int i=0;i<E;i++)
    {    cin>>u>>v;
        adjlist[u].push_back(v);
    
        
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i);
        }
        
    }
    for(int i=0;i<V;i++)
        cout<<i<<":"<<discovery[i]<<":"<<finish[i]<<endl;
    return 0;
}
