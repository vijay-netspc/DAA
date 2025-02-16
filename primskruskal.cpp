// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge{
    int u,v,weight;
};

bool compare(Edge a, Edge b){
    return a.weight<b.weight;
}

class DSU{
    vector<int> rank,parent;
  
  public:
  DSU(int V){
      parent.resize(V);
      rank.assign(V,0);
      for(int i=0;i<V;i++)
        parent[i]=i;
  }  
  
  int find(int x){
      if(parent[x]!=x)
        parent[x]=find(parent[x]);
      return parent[x];
  }
  void union_set(int a,int b){
      int rootx=find(a),rooty=find(b);
      if(rootx!=rooty){
      if(rank[rootx]<rank[rooty])
        parent[rootx]=rooty;
      else if(rank[rootx]>rank[rooty])
        parent[rooty]=rootx;
      else{
          parent[rootx]=rooty;
          rank[rooty]++;
      }
  }
  }
};

void kruskal(int V,vector<Edge> &edges){
    sort(edges.begin(),edges.end(),compare);
    DSU dsu(V);
    vector<Edge> mst;
    int mst_cost=0;
    for(auto &edge:edges){
        if(dsu.find(edge.u)!=dsu.find(edge.v)){
            dsu.union_set(edge.u,edge.v);
            mst.push_back(edge);
            mst_cost+=edge.weight;
        }
    }
    for(auto &edge:mst)
        cout<<edge.u<<":"<<edge.v<<endl;
    cout<<"The cost:"<<mst_cost<<endl;
    
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    int V=9,E=14;
    vector<Edge> edges(E);
    cout<<"Enter the edges and weight:\n";
    //int u,v,w;
    for(int i=0;i<E;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].weight;
    
        
    }
       kruskal(V,edges); 
    return 0;
}
