#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int n;
    char s[200][31];
    int x[200],y[200],z[200];
    
    cin >> n;
    
    for(int i = 0;i < n;++i)
        cin >> s[i] >> x[i] >> y[i] >> z[i];
    
    bool M[200][200];
    memset(M,false,sizeof M);
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            int cont = 0;
            
            if(x[i] > x[j]) ++cont;
            if(y[i] > y[j]) ++cont;
            if(z[i] > z[j]) ++cont;
            if(cont >= 2) M[i][j] = true;
        }
    }
    
    bool visited[200];
    
    for(int i = 0;i < n;++i){
        queue<int> Q;
        Q.push(i);
        
        memset(visited,false,sizeof visited);
        visited[i] = true;
        
        int cont = 0;
        
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            ++cont;
            
            for(int j = 0;j < n;++j){
                if(M[cur][j] && !visited[j]){
                    Q.push(j);
                    visited[j] = true;
                }
            }
        }
        
        if(cont == n) cout << s[i] << '\n';
    }
    
    return 0;
}
