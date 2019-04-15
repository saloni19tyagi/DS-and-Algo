#include<iostream>
#include<set>
#include<vector>
#include<climits>
#include<string.h>

 using namespace std ;

 int main() {
     int ver, edge ,  u , v ,w , a ,b  ;
     cin >> ver >> edge ;

     vector<pair<int, int> >adj[ver+1] ;
     multiset<pair<int, int> >s ;

     int dist[ver+1] ;
     int visited[ver+1] ;
     memset(visited , 0 , sizeof(visited)) ;
     for(int i = 0 ; i <= ver ; i++)
       dist[i] = 1000000000 ;

     for(int i = 0 ; i < edge ; i++){
         cin >> u >> v >> w ;
         adj[u].push_back(make_pair(v, w)) ;
        // adj[v].push_back(make_pair(u , w)) ;
     }
     
     dist[1] = 0 ;

     s.insert(make_pair(0, 1)) ;

     while(!s.empty()) {
         pair<int, int> p = *s.begin() ;
         s.erase(s.begin()) ;

         int x = p.second , weight = p.first ;

         if(visited[x] == 1)
           continue ;
         visited[x] = 1 ;
         for(int  i = 0 ; i < adj[x].size() ; i++) {
              int p = adj[x][i].first , q = adj[x][i].second ;
             if(dist[p] > dist[x] + q) {
                 dist[p] = dist[x] + q ;
	             s.insert(make_pair(dist[p] , p)) ;
             }
         }
     }

     
     for(int i = 2 ; i <= ver ; i++) {
        cout << dist[i] << " " ;
     }
 }
