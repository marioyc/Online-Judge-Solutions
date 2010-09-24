#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_N 10000
#define S 6

int main(){
    int T,n,val[MAX_N][S],best[MAX_N][S],total[MAX_N][S],ans;
    int back[] = {5,3,4,1,2,0};
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        for(int i=0;i<n;++i) for(int j=0;j<S;++j) scanf("%d",&val[i][j]);
        
        for(int i=0;i<n;++i) for(int j=0;j<S;++j){
            best[i][j] = -1;
            for(int k=0;k<S;++k)
                if(k!=j && k!=back[j] && val[i][k]>best[i][j]) best[i][j] = val[i][k];
        }
        
        for(int j=0;j<S;++j) total[0][j] = best[0][j];
        
        for(int i=1;i<n;++i) for(int j=0;j<S;++j) for(int k=0;k<S;++k)
            if(val[i][j]==val[i-1][k]) total[i][j] = total[i-1][back[k]]+best[i][j];
        
        ans = -1;
        for(int j=0;j<S;++j) if(total[n-1][j]>ans) ans = total[n-1][j];
        printf("%d\n",ans);
    }
    
    return 0;
}
