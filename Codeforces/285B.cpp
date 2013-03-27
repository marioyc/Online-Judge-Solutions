#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,s,t;
    
    scanf("%d %d %d",&n,&s,&t);
    
    int p[n + 1];
    
    for(int i = 1;i <= n;++i)
        scanf("%d",&p[i]);
    
    bool visited[n + 1];
    int pos = s,cont = 0,ans = -1;
    memset(visited,false,sizeof visited);
    
    while(!visited[pos]){
        visited[pos] = true;
        if(pos == t) ans = cont;
        pos = p[pos];
        ++cont;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
