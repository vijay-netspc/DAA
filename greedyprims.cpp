// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
void prims(int V,vector<bool>&visited,vector<int>&parent,vector<vector<pair<int ,int>>> &adjlist){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //important
    vector<int> key(V,INT_MAX);
    vector<bool> inmst(V,false);
    pq.push({0,0});
    key[0]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        if(inmst[u])
            continue;
        inmst[u]=true;
        for(auto &[v,weight]:adjlist[u]){
            if(!inmst[v]&&weight<key[v]){
                key[v]=weight;
                parent[v]=u;
                pq.push({key[v],v});
                }
        }
    }
    for(int i=0;i<V;i++)
        cout<<i<<":"<<parent[i]<<endl;
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    int V,E;
    cout<<"Enter the Edges and vertices:";
    cin>>V>>E;
    vector<vector < pair<int,int>>> adjlist(V);
    vector<int> parent(V,-1);
    vector<bool> visited(V,false);
    cout<<"Enter the edges and weights:"<<endl;
    int u,v,w;
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
        //cout<<E<<i<<endl;
    }
    //cout<<"hii"<<endl;
    prims(V,visited,parent,adjlist);
    
    return 0;
}
