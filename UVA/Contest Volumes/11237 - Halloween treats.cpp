#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int a[100000];
    int sum[100001];
    int mod[100000];
    int c,n;
    
    while(1){
        scanf("%d %d",&c,&n);
        
        if(c==0 && n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        
        fill(mod,mod+c,-1);
        
        sum[0]=0;
        mod[0]=0;
        
        for(int i=1;i<=n;i++){
            sum[i]=(sum[i-1]+a[i-1])%c;
            
            if(mod[sum[i]]!=-1){
                for(int j=mod[sum[i]]+1;j<=i;j++){
                    printf("%d",j);
                    if(j!=i) printf(" ");
                }
                printf("\n");
                break;
            }
            mod[sum[i]]=i;
        }
    }
    
    return 0;
}
