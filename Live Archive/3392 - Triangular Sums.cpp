#include <cstdio>

using namespace std;

int main(){
    int ans[301];
    
    ans[0] = 0;
    for(int i = 1;i<=300;++i) ans[i] = ans[i-1]+i*((i+1)*(i+2)/2);
    
    int T,N;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d",&N);
        printf("%d %d %d\n",tc,N,ans[N]);
    }
    
    return 0;
}
