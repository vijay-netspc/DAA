#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E, countTime = 0;
vector<vector<int>> adjlist;
vector<int> parent, discovery, finish, indegree, topoSort;
vector<bool> visited;
bool hasCycle = false;

// Function to classify edges
void classify_edge(int u, int v) {
    cout << u << " -> " << v;
    if (!visited[v]) {
        cout << ": Tree Edge\n";
    } 
    else if (discovery[v] < discovery[u] && finish[v] == 0) { 
        cout << ": Backward Edge (Cycle Detected)\n"; 
        hasCycle = true; // Backward edge means cycle
    } 
    else if (discovery[u] < discovery[v]) {
        cout << ": Forward Edge\n";
    } 
    else {
        cout << ": Cross Edge\n";
    }
}

// DFS function for edge classification and topological sorting
void dfs(int u) {
    visited[u] = true;
    discovery[u] = countTime++;

    for (int v : adjlist[u]) {
        if (!visited[v]) {
            parent[v] = u;
            classify_edge(u, v);
            dfs(v);
        } else {
            classify_edge(u, v);
        }
    }

    finish[u] = countTime++;
    topoSort.push_back(u); // Topological Sorting (DFS method)
}

// Topological Sorting using Indegree (Kahn’s Algorithm)
void topoSortIndegree() {
    vector<int> result;
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) 
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adjlist[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    cout << "\nTopological Sort (Indegree Method): ";
    if (result.size() != V) {
        cout << "Cycle Detected! No Topological Order\n";
    } else {
        for (int v : result) cout << v << " ";
        cout << endl;
    }
}

int main() {
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    adjlist.resize(V);
    parent.assign(V, -1);
    discovery.assign(V, 0);
    finish.assign(V, 0);
    visited.assign(V, false);
    indegree.assign(V, 0);

    cout << "Enter the edges (u v):\n";
    int u, v;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adjlist[u].push_back(v);
        indegree[v]++; // For Kahn’s Algorithm
    }

    // DFS for edge classification and topological sorting
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print Discovery & Finish Time
    cout << "\nVertex : Discovery Time : Finish Time\n";
    for (int i = 0; i < V; i++)
        cout << i << " : " << discovery[i] << " : " << finish[i] << endl;

    // Topological Sorting using DFS
    if (hasCycle) {
        cout << "\nCycle Detected! No Topological Order\n";
    } else {
        cout << "\nTopological Sort (DFS Method): ";
        for (int i = topoSort.size() - 1; i >= 0; i--) {
            cout << topoSort[i] << " ";
        }
        cout << endl;
    }

    // Perform Topological Sort using Indegree
    topoSortIndegree();

    return 0;
}
