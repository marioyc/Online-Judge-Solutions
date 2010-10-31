#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    
    int H[50][50];
    
    for(int i = 0;i<M;++i)
        for(int j = 0;j<N;++j)
            scanf("%d",&H[i][j]);
    
    bool used[50][50];
    memset(used,false,sizeof(used));
    
    int row[1000],col[1000];
    double R[1000];
    
    for(int i = 0;i<K;++i){
        scanf("%d %d %lf",&row[i],&col[i],&R[i]);
        --row[i]; --col[i];
        used[row[i]][col[i]] = true;
    }
    
    long long ans = 0;
    double eps = 1e-6;
    
    for(int i = 0;i<M;++i) for(int j = 0;j<N;++j){
        if(used[i][j]) continue;
        
        bool possible = true;
        double max_h = 1000000,min_h = H[i][j];
        
        for(int k = 0;k<K && possible;++k){
            long long diff = (long long)(i-row[k])*(i-row[k])+(long long)(j-col[k])*(j-col[k]);
            
            if(diff<=R[k]*R[k]+eps){
                double aux = sqrt(R[k]*R[k]-diff);
                max_h = min(max_h,H[row[k]][col[k]]+aux);
                min_h = max(min_h,H[row[k]][col[k]]-aux);
            }else possible = false;
        }
        
        if(possible) ans += max(0,(int)floor(max_h)-(int)ceil(min_h)+1);
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
