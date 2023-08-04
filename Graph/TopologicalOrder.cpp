#include<bits/stdc++.h>
using namespace std;

// DFS:
// vector<int> v;
// vector<int> DFS(int V,vector<int> adj[]){
//     for(int i =0; i<V ; i++){
//         for(auto x: adj[i]){
//             if(!v[x]){
//                 DFS()
//             }
//         }
//     }
//     for(auto x : adj[node]){
//         if(!v[x]){
//             DFS(x,adj);
//         }
//     }

//     v[node] = 1;
// }

// BFS:
vector<int> BFS(int V,vector<int> adj[]){
    vector<int> indegree(V,0);
    for(int i =0; i<V ; i++){
        for(auto x: adj[i]){
            indegree[x]++;
        }
    }

    
    queue<int> q;
    for(int i = 0 ; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int u = q.front();
        // cout<<u<<" ";
        q.pop();
        topo.push_back(u);
        for(auto x : adj[u]){
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    return topo;
}

int main(){
    int m,n; //m=edges , n=nodes
    cin>>n>>m;
    vector<int>adj[n];
    for(int i =0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b); //if directed then only one statement
        // adj[b].push_back(a); //if undirected then add both statements
        BFS(n,adj);
        // v.assign(n,0);
        // DFS(n,adj);
    }
    return 0;
}