#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    int T,N,take_min[3001],take_max[3001];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        priority_queue<int> Qmin,Qmax;
        
        memset(take_min,0,sizeof(take_min));
        memset(take_max,0,sizeof(take_max));
        
        for(int i = 0,x;i < N;++i){
            scanf("%d",&x);
            Qmin.push(-x);
            Qmax.push(x);
        }
        
        int ans = 0;
        
        while(true){
            int A,B;
            
            while(true){
                A = Qmax.top();
                Qmax.pop();
                
                if(take_max[A] == 0) break;
                else --take_max[A];
            }
            
            while(true){
                B = -Qmin.top();
                Qmin.pop();
                
                if(take_min[B] == 0) break;
                else --take_min[B];
            }
            
            if(A == B) break;
            
            if(A == B + 1){
                ans = -1;
                break;
            }
            
            ++ans;
            
            int x = (A - B + 1) / 2;
            int A2 = B + x;
            int B2 = A - x;
            
            Qmax.push(A2);
            Qmax.push(B2);
            
            Qmin.push(-A2);
            Qmin.push(-B2);
            
            ++take_max[B];
            ++take_min[A];
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
