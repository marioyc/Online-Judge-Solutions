#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct interval{
    int s,e;
    
    interval(){}
    
    bool operator < (interval X)const{
        return s<X.s;
    }
}L[200];

int main(){
    int T,n,e,ans;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        for(int i=0;i<n;++i){
            scanf("%d %d",&L[i].s,&L[i].e);
            if(L[i].s>L[i].e) swap(L[i].s,L[i].e);
            
            L[i].s = (L[i].s+1)/2;
            L[i].e = (L[i].e+1)/2;
        }
        sort(L,L+n);
        
        priority_queue<int> Q;
        Q.push(-L[0].e);
        ans = 1;
        
        for(int i=1;i<n;++i){
            e = -Q.top();
            
            if(L[i].s>e) Q.pop();
            else ++ans;
            
            Q.push(-L[i].e);
        }
        
        printf("%d\n",10*ans);
    }
    
    return 0;
}
