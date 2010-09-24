#include <cstdio>
#include <algorithm>

using namespace std;

int M[1000][1000],gr[1000],memo[1000];

int count(int v){
    if(v==0) return 1;
    if(memo[v]!=-1) return memo[v];
    
    memo[v]=0;
    
    for(int i=gr[v]-1;i>=0;i--) memo[v]+=count(M[v][i]);
    
    return memo[v];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,m,x,ans;
    bool line=false;
    
    while(scanf("%d",&n)==1){
        ans=0;
        
        fill(memo,memo+n,-1);
        fill(gr,gr+n,0);
        
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            if(m==0) ans+=count(i);
            
            for(int j=0;j<m;j++){
                scanf("%d",&x);
                M[x][gr[x]++]=i;
            }
        }
        
        if(line) printf("\n");
        else line=true;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
