#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int n,m;
int a[100],b[100];
vector<int> L[100];

bool check(int x, int y, int x2, int y2){
    if(x > y) swap(x,y);
    if(x2 > y2) swap(x2,y2);
    
    if(x < x2 && x2 < y && !(x <= y2 && y2 <= y)) return false;
    if(x < y2 && y2 < y && !(x <= x2 && x2 <= y)) return false;
    
    return true;
}

int c[100];
bool ok = true;

void dfs(int cur, int curc){
    if(c[cur] != -1) return;
    c[cur] = curc;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(c[to] == -1) dfs(to,curc ^ 1);
        else if(c[to] == curc) ok = false;
    }
}

int main(){
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i < m;++i)
        scanf("%d %d",&a[i],&b[i]);
    
    for(int i = 0;i < m;++i){
        for(int j = i + 1;j < m;++j){
            if(!check(a[i],b[i],a[j],b[j])){
                L[i].push_back(j);
                L[j].push_back(i);
            }
        }
    }
    
    memset(c,-1,sizeof c);
    
    for(int i = 0;i < m;++i)
        dfs(i,0);
    
    if(!ok) puts("Impossible");
    else{
        for(int i = 0;i < m;++i)
            printf("%c",c[i] == 0? 'i' : 'o');
        printf("\n");
    }
    
    return 0;
}
