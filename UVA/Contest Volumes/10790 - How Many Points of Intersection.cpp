#include <cstdio>

using namespace std;

int main(){
    int tc = 1,a,b;
    
    while(true){
        scanf("%d %d",&a,&b);
        if(a == 0) break;
        printf("Case %d: %lld\n",tc++,(long long)a * (a - 1) / 2 * b * (b - 1) / 2);
    }
    
    return 0;
}
