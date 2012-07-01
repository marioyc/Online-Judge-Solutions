#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int parent[20000];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

map<string, int> M;

int main(){
    int N;
    char s[20001][51],s1[51],s2[51];
    int L[20001];
    
    N = 0;
    
    while(true){
        scanf("%s",s[N]);
        L[N] = strlen(s[N]);
        M[ s[N] ] = N;
        
        if(L[N] == 2 && s[N][0] == '-' && s[N][1] == '-') break;
        
        ++N;
    }
    
    for(int i = 0;i < N;++i)
        parent[i] = i;
    
    for(int i = 0;i < N;++i){
        for(int j = i + 1;j < N;++j){
            if(L[i] == L[j]){
                int cont = 0;
                
                for(int k = 0;k < L[i];++k)
                    if(s[i][k] != s[j][k]) ++cont;
                
                if(cont == 1) Union(i,j);
            }
        }
    }
    
    while(scanf("%s %s",s1,s2) == 2){
        if(M.find(s1) != M.end() && M.find(s2) != M.end() && Find(M[s1]) == Find(M[s2])) puts("Yes");
        else puts("No");
    }
    
    return 0;
}
