#include <cstdio>
#include <algorithm>

using namespace std;

int solve(int n, int m){
    if(n > m) swap(n,m);
    if(n == 1) return m;
    if(n == 2) return m / 4 * 4 + (m % 4 == 1? 2 : (m % 4 >= 2? 4 : 0));
    return (n*m + 1) / 2;
}

int main(){
    int N,M,ans;
    
    while(true){
        scanf("%d %d",&N,&M);
        if(N == 0) break;
        
        printf("%d knights may be placed on a %d row %d column board.\n",solve(N,M),N,M);
    }
    
    return 0;
}
