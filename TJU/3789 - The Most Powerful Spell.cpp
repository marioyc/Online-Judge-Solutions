#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int u[400],v[400];
string w[400];

int main(){
    ios::sync_with_stdio(0);
    
    int n,m,s,e;
    char str[7];
    string dist[40];
    bool visited[40],change,inf;
    
    while(true){
        cin >> n >> m >> s >> e;
        
        if(n == 0) break;
        
        for(int i = 0;i < m;++i)
            cin >> u[i] >> v[i] >> w[i];
        
        memset(visited,0,sizeof visited);
        
        dist[e] = "";
        visited[e] = true;
        change = true;
        inf = false;
        
        for(int it = 0;it <= 6*n && change && !inf;++it){
            change = false;
            
            for(int i = 0;i < m;++i){
                if(visited[ v[i] ]){
                    string aux = w[i] + dist[ v[i] ];
                    
                    if(!visited[ u[i] ] || aux < dist[ u[i] ]){
                        dist[ u[i] ] = aux;
                        change = true;
                        if(it >= n - 1 && u[i] == s) inf = true;
                    }
                    
                    visited[ u[i] ] = true;
                }
            }
        }
        
        if(inf || !visited[s]) cout << "NO\n";
        else cout << dist[s].c_str() << '\n';
    }
    
    return 0;
}
