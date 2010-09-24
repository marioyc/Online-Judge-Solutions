#include<cstdio>
#define min(a,b) a<b? a : b
#define max(a,b) a>b? a : b

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,N,aux,ind;
    int A[7][7];
    int C[7];
    int ans;
    
    while(1){
        scanf("%d",&n);
        if(n==-1) break;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
        
        N=1;        
        for(int i=0;i<n-1;i++) N*=n;
        
        ans=(1<<30);
        
        for(int i=0;i<N;i++){            
            for(int j=0;j<n;j++) C[j]=A[0][j];
            
            aux=i;
            for(int j=1;j<n;j++){
                ind=aux%n;
                for(int k=0;k<n;k++) C[k]+=A[j][(k+ind)%n];
                
                aux/=n;
            }
            
            aux=C[0];
            for(int j=1;j<n;j++) aux=max(aux,C[j]);
            
            ans=min(ans,aux);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
