#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n,x,y;
    
    scanf("%d",&n);
    
    priority_queue<int> A,B;
    scanf("%d",&x);
    A.push(x);
    printf("%d\n",x);
    
    for(int i=1;i<n;++i){
        scanf("%d",&x);
        
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
        
        printf("%d\n",A.top());
    }
    
    return 0;
}
