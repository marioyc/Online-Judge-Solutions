#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

string s[23],pos[23];
int a[23],M[23][23];

int ans,aux,cont1,cont2,cont3,cont4;

void search(int n, int mask){
    if(__builtin_popcount(mask) == 11){
        ans = max(ans,aux);
        return;
    }
    
    if(n == 23) return;
    
    if(cont1 + cont2 + cont3 + cont4 + 22 - n >= 11)
        search(n + 1,mask);
    
    if(pos[n][0] == 'g') ++cont1;
    if(pos[n][0] == 'd') ++cont2;
    if(pos[n][0] == 'm') ++cont3;
    if(pos[n][0] == 's') ++cont4;
    
    if(cont1 <= 1 && cont2 <= 4 && cont3 <= 4 && cont4 <= 2 && cont1 + cont2 + cont3 + cont4 + 22 - n >= 11){
        aux += a[n];
        
        for(int i = 0;i < n;++i)
            if(mask >> i & 1)
                aux += M[n][i];
        
        search(n + 1,mask | (1 << n));
        
        aux -= a[n];
        
        for(int i = 0;i < n;++i)
            if(mask >> i & 1)
                aux -= M[n][i];
    }
    
    if(pos[n][0] == 'g') --cont1;
    if(pos[n][0] == 'd') --cont2;
    if(pos[n][0] == 'm') --cont3;
    if(pos[n][0] == 's') --cont4;
}

map<string, int> id;
int ne;
string u,v;

int main(){
    ios::sync_with_stdio(0);
    
    while(cin >> s[0] >> a[0] >> pos[0]){
        id.clear();
        id[ s[0] ] = 0;
        
        for(int i = 1;i < 23;++i){
            cin >> s[i] >> a[i] >> pos[i];
            id[ s[i] ] = i;
        }
        
        cin >> ne;
        memset(M,0,sizeof M);
        
        for(int i = 0,idu,idv,w;i < ne;++i){
            cin >> u >> v >> w;
            idu = id[u];
            idv = id[v];
            M[idu][idv] += w;
            M[idv][idu] += w;
        }
        
        cont1 = cont2 = cont3 = cont4 = aux = 0;
        ans = -1000000000;
        search(0,0);
        
        if(ans == -1000000000) cout << "impossible\n";
        else cout << ans << endl;
    }
    
    return 0;
}
