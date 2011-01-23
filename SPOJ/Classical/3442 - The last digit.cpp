#include <cstdio>
using namespace std;
int pow(int a, int b){
    if(b==0) return 1;
    int ret = pow(a,b/2);
    ret *= ret;
    if(b&1) ret *= a;
    return ret%10;
}
int main(){
    int T,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        printf("%d\n",pow(a%10,b));
    }
    return 0;
}
