//AUTHOR : SALONI TYAGI
//DFS : DEPTH FIRST SEARCH , COMPLEXITY : (V+E) 
//Check if Ith vertix can be visited from the 1st node.

#include<iostream>
#include<vector>
#include<string.h>

using namespace std ;

int visited[5000] ;
vector<int>adj[5001] ;

void dfs(int source) {
    visited[source] = 1 ;
    for(int i = 0 ; i < adj[source].size() ; i++) {
        if(visited[adj[source][i]] == 0) {
            dfs(adj[source][i]) ;
        }
    }
}
int main() {

    int node , no_of_edges ,city , u , v;
    cin >> node >> no_of_edges >> city ;

    for (int i = 0 ; i < no_of_edges ; i++)
    {
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u) ;
    }
    
    memset(visited, 0, sizeof(visited));
    dfs(1);

    if(visited[city] == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}
