// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
void dijstra(int V,vector<vector<pair<int,int>>>adjlist,int src){
    vector<int> dis(V,INT_MAX);
    dis[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto &[v,weight]:adjlist[u]){
            if(dis[u]+weight<dis[v]){
                dis[v]=dis[u]+weight;
                pq.push({dis[v],v});
            }
        }
        
    }
    for(int i=0;i<V;i++){
        cout<<i<<":"<<dis[i]<<endl;
    }
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
int V=9,E=14;
vector<vector<pair<int,int>>> adjlist(V);
cout<<"Enter the edges and weight:"<<endl;
int u,v,w;
for(int i=0;i<E;i++){
    cin>>u>>v>>w;
    adjlist[u].push_back({v,w});
    adjlist[v].push_back({u,w});
    //cout<<i<<endl;
}

dijstra(V,adjlist,0);








    return 0;
}
