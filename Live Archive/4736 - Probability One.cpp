#include <cstdio>

using namespace std;

int main(){
    int tc = 1,n0;
    
    while(true){
        scanf("%d",&n0);
        if(n0==0) break;
        
        int ans = ((3*n0+1)>>1)/3;
        
        printf("%d. %s %d\n",tc++,(n0 & 1)? "odd" : "even",ans);
    }
    
    return 0;
}
