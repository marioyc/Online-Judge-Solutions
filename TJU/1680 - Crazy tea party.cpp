#include <cstdio>

using namespace std;

int main(){
    int T,n;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        int a = n/2,b = (n+1)/2;
        printf("%d\n",a*(a-1)/2+b*(b-1)/2);
    }
    
    return 0;
}
