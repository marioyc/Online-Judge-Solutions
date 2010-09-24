#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,K,mx,x,sum[1001],aux[1001],a,b,ans;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        fill(aux,aux+1001,0);
        
        mx=ans=0;
        
        for(int i=0;i<N;i++){
            scanf("%d",&K);
            ans+=K;
            
            fill(sum,sum+1001,0);
            
            for(int j=K-1;j>=0;j--){
                scanf("%d",&x);
                sum[x]++;
            }
            
            for(int i=999;i>=0;i--) sum[i]+=sum[i+1];
            
            for(int i=0;i<=1000;i++){
                a=sum[i];
                b=K-a;
                aux[i]+=abs(a-b);
            }
        }
        
        for(int j=0;j<=1000;j++)
            if(aux[j]<ans) ans=aux[j];
        
        printf("%d\n",ans);
    }
    
    return 0;
}
