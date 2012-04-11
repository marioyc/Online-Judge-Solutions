#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int S,N;
    
    scanf("%d %d",&S,&N);
    
    int mn = 0,sum = 0;
    bool ok = true;
    
    for(int i = 1,x;i <= S;++i){
        scanf("%d",&x);
        
        sum += x;
        
        if(sum - i - mn > N) ok = false;
        
        mn = min(mn,sum - i);
    }
    
    puts(ok? "YES" : "NO");
    
    return 0;
}
