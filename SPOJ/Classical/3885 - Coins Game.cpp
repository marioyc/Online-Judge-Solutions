#include <cstdio>
#include <algorithm>

using namespace std;

bool win[1000001];

int main(){
    int K,L,m;
    scanf("%d %d %d",&K,&L,&m);
    
    int maxN = 0,N[m];
    
    for(int i = 0;i < m;++i){
        scanf("%d",&N[i]);
        maxN = max(maxN,N[i]);
    }
    
    win[0] = false;
    
    for(int i = 1;i <= maxN;++i){
        win[i] = !win[i-1];
        if(i >= K && !win[i-K]) win[i] = true;
        if(i >= L && !win[i-L]) win[i] = true;
    }
    
    for(int i = 0;i < m;++i){
        if(win[N[i]]) putchar('A');
        else putchar('B');
    }
    
    putchar('\n');
    
    return 0;
}
