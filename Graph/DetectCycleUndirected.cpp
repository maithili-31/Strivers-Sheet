#include<bits/stdc++.h>
using namespace std;

// DFS:
vector<int> v;
vector<int> parent;

bool DFS(int node,vector<int> adj[]){
    v[node] = 1;
    // cout<<node<<" ";
    for(auto x : adj[node]){
        parent[x] = node;
        if(!v[x]){
            if(DFS(x,adj) == true){
                return true;
            }
        }
        else{
            if(parent[x] != node){
                return true;
            }
        }
    }
    return false;
}

// BFS:
bool BFS(int node,vector<int> adj[]){
    queue<int> q;
    q.push(node);
    v[node] = 1;
    while(!q.empty()){
        int u = q.front();
        // cout<<u<<" ";
        q.pop();
        for (auto x : adj[node])
        {
            parent[x] = node;
            if (!v[x])
            {
                v[x] = 1;
                q.push(x);
            }
            else
            {
                if (parent[x] != node)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int m,n;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i =0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b); //if directed then only one statement
        adj[b].push_back(a); //if undirected then add both statements
        v.assign(n,0);
        parent.assign(n,-1);
        // cout<<DFS(0,adj);
        cout<<BFS(0,adj);
        // BFS(0,adj);
    }
    return 0;
}