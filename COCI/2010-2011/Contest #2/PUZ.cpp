#include <cstdio>

using namespace std;

int main(){
    int A,B,V;
    scanf("%d %d %d",&A,&B,&V);
    
    int ans = 1;
    V -= A;
    
    ans += (V+A-B-1)/(A-B);
    
    printf("%d\n",ans);
    
    return 0;
}
