#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int n,m,p[80],p2[31][80];
    char s[81],x[81];
    
    while(true){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) break;
        
        for(int i=0;i<n;++i){
            scanf("%d",&p[i]);
            --p[i];
        }
        
        fgets(s,81,stdin);
        
        memset(s,0,sizeof(s));
        for(int i=0;i<n;++i) s[i] = getchar();
        
        for(int i=0;i<n;++i) p2[0][i] = p[i];
        
        for(int i=1;i<=30;++i)
            for(int j=0;j<n;++j)
                p2[i][j] = p2[i-1][p2[i-1][j]];
        
        for(int i=30;i>=0;--i){
            if((m & (1<<i))==0) continue;
            
            for(int j=0;j<n;++j) x[p2[i][j]] = s[j];
            for(int j=0;j<n;++j) s[j] = x[j];
        }
        
        puts(s);
    }
    
    return 0;
}
