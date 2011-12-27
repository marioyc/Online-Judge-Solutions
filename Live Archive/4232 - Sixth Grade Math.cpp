#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,a,b;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&a,&b);
        
        printf("%d %d %d\n",tc,a / __gcd(a,b) * b,__gcd(a,b));
    }
    
    return 0;
}
