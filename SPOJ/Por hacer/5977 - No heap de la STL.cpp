#include <cstdio>
#include <queue>

using namespace std;

#define MOD 1000000007

int main(){
    int T,n,x,y,c;
    long long a,b,ans;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%lld %lld %d %d",&a,&b,&c,&n);
        
        priority_queue<int> A,B;
        
        A.push(1);
        x = ans = 1;
        
        for(int i=1;i<n;++i){
            x = (int)((a*x+b*(i+1)+c)%MOD);
            ans += x;
            
            if(i%2==0){
                y = -B.top();
                B.pop();
            }else{
                y = A.top();
                A.pop();
            }
            
            if(x<=y){
                A.push(x);
                B.push(-y);
            }else{
                A.push(y);
                B.push(-x);
            }
            
            x = A.top();
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
