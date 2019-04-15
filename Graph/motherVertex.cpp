//Author : Saloni Tyagi
//Mother Vertex : It is that vertex , from which all the other vertices can be reached.
//Concept used : DFS , Complexity : V*(V+E) ;

#include<iostream>
#include<vector>
#include<string.h>

using namespace std ;

vector<int>adj[200] ;
bool visited[202] ;
void dfs(int source){
    visited[source] =1 ;
    for(int i =0 ; i < adj[source].size() ; i++){
        if(visited[adj[source][i]] ==0){
            dfs(adj[source][i]) ;
        }
    }
}

int main() {

    int ver , edges , ans = 0 , count = 0 , a , b;
    cin >> ver >> edges ;

    while(edges--) {
        cin >> a >> b ;
        adj[a].push_back(b) ;
    }

    for(int i = 1 ; i <= ver ; i++) {
        memset(visited , 0 , sizeof(visited)) ;
        dfs(1) ;
        count = 0 ;
        for(int j = 1 ; j <= ver ; j++) {
            if(visited[j] == 1) {
                count++ ;
            }
        }
        if(count == ver) {
            ans = i ;
            break ;
        }
    }

    cout << ans << "\n" ;
}