// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
void bfs(int src,vector<vector<int>> &adjlist,vector<int>&parent,vector<int>&dis,vector<bool>&visited){
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int neighbour:adjlist[curr]){
            if(!visited[neighbour])
            visited[neighbour]=true,parent[neighbour]=curr,dis[neighbour]=dis[curr]+1,q.push(neighbour);
        }
        
    }
    
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    cout<<"Enter the vertices and edges:";
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adjlist(V);
    vector<int> dis(V,0),parent(V,-1);
    vector<bool> visited(V,false);
    cout<<"Enter the edges:"<<endl;
    int u,v;
    for(int i=0;i<E;i++){
      //  cout<<V<<E<<endl;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    //    cout<<"enddeddd"<<endl;
    }
    int components=1;
    cout<<"hii"<<endl;
    int start;
    cout<<"Enter source:";
    cin>>start;
    bfs(start,adjlist,parent,dis,visited);
    
    for(int i=0;i<V;i++){
        cout<<"hiei"<<endl;
        if(!visited[i]){
            cout<<"gji"<<i<<endl;
            bfs(i,adjlist,parent,dis,visited);
            components++;
        }
    }
    for(int i=0;i<V;i++){
        cout<<i<<":"<<parent[i]<<":"<<dis[i]<<endl;
    }
    cout<<"components"<<components;
    int target;
    cout<<"Enter the target:";
    cin>>target;
    stack<int> path;
    //shortest path
   do{
        path.push(target);
        target=parent[target];
    } while(target!=-1);
    if(path.top()!=start){
        cout<<"no path"<<endl;
    }
    else{
        while(!path.empty()){
            cout<<path.top()<<endl;
            path.pop();
        }
    }
    
    return 0;
    
    
}
