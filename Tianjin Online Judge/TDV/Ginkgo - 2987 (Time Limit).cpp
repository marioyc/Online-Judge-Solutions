#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T, L,n,D,max_sum;
    
    int dp[10000];
    int X[10000];
    int H[10000];
    
    scanf("%d",&T);
    
    for(int caso=0;caso<T;caso++){
        scanf("%d %d %d",&L,&n,&D);
        
        for(int i=0;i<n;i++) scanf("%d %d", &X[i], &H[i]);
        
        max_sum=-1;
        
        for(int i=0;i<n;i++){
            dp[i]=H[i];
            
            for(int j=0;j<i;j++)
                if(X[i]-X[j]>D)
                    dp[i]=max(dp[i],dp[j]+H[i]);
            
            max_sum=max(dp[i],max_sum);
        }
        
        printf("%d\n",max_sum); 
    }
    
    return 0;
}
