#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int V,n,E;
int M[10][10];
int a[10],b[10];
map< vector<int> , int > best;

void generate(int pos, int sz){
    if(sz > 1){
        for(int i = 0;i < sz;++i)
            b[i] = a[i];
        
        int ans = 100000;
        
        do{
            int aux = 0;
            
            for(int i = 1;i < sz;++i)
                aux += M[ b[i - 1] ][ b[i] ];
            
            ans = min(ans,aux);
        }while(next_permutation(b + 1,b + sz));
        
        best[ vector<int>(b + 1,b + sz) ] = ans;
    }
    
    for(int i = pos;i < V;++i){
        a[sz] = i;
        generate(i + 1,sz + 1);
    }
}

vector<int> watch[4];
int ans;

void solve(int pos){
    if(pos == V){
        int aux = 0;
        
        for(int i = 0;i < n;++i)
            if(!watch[i].empty())
                aux = max(aux,best[ watch[i] ]);
        
        ans = min(ans,aux);
        
        return;
    }
    
    for(int i = 0;i < min(n,pos);++i){
        watch[i].push_back(pos);
        solve(pos + 1);
        watch[i].pop_back();
    }
}

int main(){
    char s[3];
    
    while(true){
        scanf("%d",&V);
        
        if(V == 0) break;
        
        scanf("%d %d",&n,&E);
        
        n = min(n,V - 1);
        
        for(int i = 0;i < V;++i){
            M[i][i] = 0;
            
            for(int j = i + 1;j < V;++j)
                M[i][j] = M[j][i] = 10;
        }
        
        for(int i = 0;i < E;++i){
            scanf("%s",s);
            
            int u = s[0] - 'A',v = s[1] - 'A';
            M[u][v] = M[v][u] = 1;
        }
        
        for(int k = 0;k < V;++k)
            for(int i = 0;i < V;++i)
                for(int j = 0;j < V;++j)
                    M[i][j] = min(M[i][j],M[i][k] + M[k][j]);
        
        a[0] = 0;
        best.clear();
        
        generate(1,1);
        
        ans = 100000;
        
        solve(1);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
