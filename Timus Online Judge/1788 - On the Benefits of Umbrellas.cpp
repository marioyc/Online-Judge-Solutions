#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m,g[100],b[100];;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i < n;++i) scanf("%d",&g[i]);
    for(int i = 0;i < m;++i) scanf("%d",&b[i]);
    
    int ans = -1;
    
    sort(g,g + n);
    sort(b,b + m);
    
    for(int i = min(n,m);i >= 0;--i){
        int aux = 0;
        
        for(int j = 0;j < n-i;++j) aux += g[j];
        for(int j = 0;j < m-i;++j) aux += i * b[j];
        
        if(ans == -1 || aux < ans) ans = aux;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
