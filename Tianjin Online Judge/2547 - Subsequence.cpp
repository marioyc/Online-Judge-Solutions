#include <cstdio>

using namespace std;

int main(){
    int T,N,S,a[100000],sum[100001],lo,hi,mi,ans;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&N,&S);
        
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        
        sum[0]=0;
        for(int i=0;i<N;i++) sum[i+1]=sum[i]+a[i];
        
        ans=0;
        for(int i=0;i<N;i++){
            lo=i; hi=N-1;
            
            while(lo!=hi){
                mi=(lo+hi)>>1;
                
                if(sum[mi+1]-sum[i]>=S) hi=mi;
                else lo=mi+1;
            }
            
            if(sum[hi+1]-sum[i]<S) continue;
            
            if(ans==0) ans=hi-i+1;
            else ans<?=hi-i+1;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
