#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int T,N,M;
    char s[4];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        priority_queue<int> Q1,Q2;
        
        for(int i = 0,x;i<N;++i){
            scanf("%d",&x);
            Q2.push(-x);
        }
        
        for(int i = 0,x;i<(N+1)/2;++i){
            x = -Q2.top();
            Q2.pop();
            Q1.push(x);
        }
        
        scanf("%d",&M);
        
        for(int q = 0,y = Q1.top();q<M;++q){
            scanf("%s",s);
            
            if(s[0]=='m'){
                printf("%d\n",y);
            }else{
                int x;
                scanf("%d",&x);
                ++N;
                
                if(x<y){
                    Q1.push(x);
                    
                    if((N & 1)==0){
                        x = Q1.top();
                        Q1.pop();
                        Q2.push(-x);
                    }
                }else{
                    Q2.push(-x);
                    
                    if(N & 1){
                        x = -Q2.top();
                        Q2.pop();
                        Q1.push(x);
                    }
                }
                
                y = Q1.top();
            }
        }
    }
    
    return 0;
}
