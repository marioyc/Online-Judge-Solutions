#include <cstdio>

using namespace std;

int main(){
    int N,a[10000],ans,L,lo,hi,mi;
    int sum[10001];
    bool found;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        
        sum[0]=0;
        for(int i=0;i<N;i++) sum[i+1]=sum[i]+a[i];
        
        ans=-1;
        
        for(int i=N;i>=3 && ans==-1;i--){
            if(sum[N]%i!=0) continue;
            L=sum[N]/i;
            found=false;
            
            for(int j=0;j<N && sum[j]<L && !found;j++){
                found=true;
                
                for(int k=0,s=j;k<i-1 && found;k++){
                    lo=s+1;hi=N;
                    
                    while(lo!=hi){
                        mi=(lo+hi)>>1;
                        
                        if(sum[mi]-sum[s]<L) lo=mi+1;
                        else hi=mi;
                    }
                    
                    if(sum[lo]-sum[s]==L) s=lo;
                    else found=false;
                }
                
            }
            
            if(found) ans=N-i;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
