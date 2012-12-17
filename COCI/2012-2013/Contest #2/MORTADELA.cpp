#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,X,Y;
    
    scanf("%d %d %d",&X,&Y,&N);
    
    double ans = 1000.0 * X / Y;
    
    for(int i = 0;i < N;++i){
        scanf("%d %d",&X,&Y);
        ans = min(ans,1000.0 * X / Y);
    }
    
    printf("%.2f\n",ans);
    
    return 0;
}
