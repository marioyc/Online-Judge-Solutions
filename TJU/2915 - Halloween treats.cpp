#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int a[100000];
    int sum[100001];
    int mod[100000];
    int c,n;
    
    while(1){
        scanf("%d %d",&c,&n);
        
        if(c==0 && n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        
        memset(mod,-1,sizeof(mod));
        
        sum[0]=0;
        mod[0]=0;
        
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i-1];
            
            if(mod[sum[i]%c]!=-1){
                for(int j=mod[sum[i]%c]+1;j<=i;j++){
                    cout<<j;
                    if(j!=i) cout<<" ";
                }
                cout<<endl;
                break;
            }
            mod[sum[i]%c]=i;
        }
    }
    
    return 0;
}
