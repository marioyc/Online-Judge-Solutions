#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int N,L,U,a[100000],take_max[1000001],take_min[1000001];
    
    while(scanf("%d %d %d",&N,&L,&U)==3){
        for(int i = 0;i<N;++i) scanf("%d",&a[i]);
        
        if(L>U){
            puts("0");
            continue;
        }
        
        int ans = 0,len = 0;
        priority_queue<int> QMAX,QMIN;
        
        memset(take_min,0,sizeof(take_min));
        memset(take_max,0,sizeof(take_max));
        
        for(int i = 0;i<N;++i){
            while(!QMIN.empty() && take_min[-QMIN.top()]){
                --take_min[-QMIN.top()];
                QMIN.pop();
            }
            
            while(!QMAX.empty() && take_max[QMAX.top()]){
                --take_max[QMAX.top()];
                QMAX.pop();
            }
            
            while(i+len<N){
                if(len>0){
                    int mn = min(a[i+len],-QMIN.top());
                    int mx = max(a[i+len],QMAX.top());
                    if(mx-mn>U) break;
                }
                
                QMAX.push(a[i+len]);
                QMIN.push(-a[i+len]);
                ++len;
            }
            
            if(len>0 && QMAX.top()+QMIN.top()>=L) ans = max(ans,len);
            ++take_max[a[i]]; ++take_min[a[i]];
            if(len>0) --len;
        }
        
        printf("%d\n",ans);
    }    
    
    return 0;
}
