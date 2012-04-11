#include <cstdio>

using namespace std;

int main(){
    int N;
    
    while(scanf("%d",&N) == 1){
        if(N & (N - 1)) puts("NO");
        else puts("YES");
    }
    
    return 0;
}
