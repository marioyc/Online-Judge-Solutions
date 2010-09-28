#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct device{
    int B,P;
    
    device(){}
    
    bool operator < (device X)const{
        return B<X.B;
    }
}D[100][100];

int main(){
    int T,n,m[100],pos[100],L[100*100],M,minP[100][100],chosen,P;
    double ans;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        M = 0;
        
        for(int i=0;i<n;++i){
            scanf("%d",&m[i]);
            for(int j=0;j<m[i];++j){
                scanf("%d %d",&D[i][j].B,&D[i][j].P);
                L[M+j] = D[i][j].B;
            }
            M += m[i];
            sort(D[i],D[i]+m[i]);
        }
        
        for(int i=0;i<n;++i){
            minP[i][m[i]-1] = D[i][m[i]-1].P;
            for(int j=m[i]-2;j>=0;--j) minP[i][j] = min(minP[i][j+1],D[i][j].P);
        }
        
        sort(L,L+M);
        memset(pos,0,sizeof(pos));
        ans = 0;
        
        for(int i=0;i<M;++i){
            if(i>0 && L[i]==L[i-1]) continue;
            
            chosen = P = 0;
            
            for(int j=0;j<n;++j){
                while(pos[j]<m[j] && D[j][pos[j]].B<L[i]) ++pos[j];
                
                if(pos[j]<m[j]){
                    P += minP[j][pos[j]];
                    ++chosen;
                }
            }
            
            if(chosen<n) break;
            
            ans = max(ans,L[i]*1.0/P);
        }
        
        printf("%.3lf\n",ans);
    }
    
    return 0;
}
