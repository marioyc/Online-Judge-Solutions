#include <cstdio>

using namespace std;

int main(){
    int n,m,x;
    scanf("%d %d %d",&n,&m,&x);
    
    for(int i = 1;i<x;++i){
        if(n<2 || m<2){
            printf("0\n");
            return 0;
        }
        n -= 2;
        m -= 2;
    }
    printf("n = %d\n",n);
    int ans = (m+1)/2+(n>2? (n-2)/2*2 : 0)+(n>=2? (n%2==0? m/2 : (m+1)/2) : 0);
    printf("%d %d %d\n",(m+1)/2,(n>2? (n-2)/2*2 : 0),(n>=2? (n%2==0? m/2 : (m+1)/2) : 0));
    printf("%d\n",ans);
    
    return 0;
}
