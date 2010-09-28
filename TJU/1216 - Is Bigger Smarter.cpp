#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct E{
    int n,W,S;
    
    E(int i, int w, int s){
        n=i;
        W=w;
        S=s;
    }
    
    bool operator < (E X) const{
        if(W!=X.W) return W<X.W;
        return S>X.S;
    }
};

int main(){    
    vector<E> v;
    
    int w,s,n=0;
    
    while(scanf("%d %d",&w,&s)==2) v.push_back(E(n++,w,s));
    
    sort(v.begin(),v.end());
    
    int dp[n],next[n],ans=0,pos;
    
    for(int i=n-1;i>=0;i--){
        dp[i]=1;
        next[i]=-1;
        
        for(int j=i+1;j<n;j++)
            if(v[i].W!=v[j].W && v[i].S>v[j].S && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                next[i]=j;
        }
        
        if(dp[i]>ans){
            ans=dp[i];
            pos=i;
        }
    }
    
    printf("%d\n",ans);
    
    while(pos!=-1){
        printf("%d\n",v[pos].n+1);
        pos=next[pos];
    }
    
    return 0;
}
