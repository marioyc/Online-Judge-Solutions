#include <iostream>

using namespace std;

#define min(a,b) a<b? a:b
#define max(a,b) a>b? a:b

int n,N;
int M[8][8];
int memo[(1<<8)][(1<<8)];

int solve(int mask_r, int mask_c){
    if(mask_r==N && mask_c==N) return 0;
    
    
    if(memo[mask_r][mask_c]!=8001) return memo[mask_r][mask_c];
    
    int mx=-8001;
    
    for(int i=0;i<n;i++){
        if(mask_r & (1<<i)) continue;
        
        int mn=8001;
        
        for(int j=0;j<n;j++){
           if(mask_c & (1<<j)) continue;
           
           mn=min(mn,M[i][j]+solve(mask_r | (1<<i), mask_c | (1<<j)));
        }
        
        mx=max(mx,mn);
    }
    
    memo[mask_r][mask_c]=mx;
    
    return mx;
}

int main(){    
    int T;
    
    cin>>T;
    
    for(int tc=1;tc<=T;tc++){
        cin>>n;
        N=(1<<n)-1;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) cin>>M[i][j];
        
        for(int i=N;i>=0;i--) fill(memo[i],memo[i]+(1<<n),8001);
        
        cout<<solve(0,0)<<endl;
    }
    
    return 0;
}
