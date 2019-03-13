//AUTHOR : SALONI TYAGI
//BFS : BREATH FIRST SEARCH , COMPLEXITY : (V+E)
//Check if Ith vertix can be visited from the 1st node.

#include <iostream>
#include <vector>
#include <string.h>
#include<queue>

using namespace std;

int visited[5000];
vector<int> adj[5001];

int main()
{

    int node, no_of_edges, city, u, v , ele ;
    cin >> node >> no_of_edges >> city;

    for (int i = 0; i < no_of_edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int>q ;
    q.push(1) ;
    
    while(!q.empty()) {
        ele = q.front() ;
        q.pop() ;

        visited[ele] = 1 ;
        for(int i = 0 ; i < adj[ele].size() ; i++) {
            if(visited[adj[ele][i]] == 0) {
                q.push(adj[ele][i]) ;
            }
        }
    }

    if (visited[city] == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}