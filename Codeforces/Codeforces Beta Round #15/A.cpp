#include <cstdio>
#include <algorithm>

using namespace std;

struct house{
    int x,l;
    
    house(){}
    
    bool operator < (house H)const{
        return x<H.x;
    }
}h[1000];

int main(){
    int N,L;
    scanf("%d %d",&N,&L);
    
    for(int i = 0;i<N;++i){
        scanf("%d %d",&h[i].x,&h[i].l);
        h[i].x <<= 1;
    }
    
    sort(h,h+N);
    
    int ans = 2;
    
    for(int i = 0;i+1<N;++i){
        int dx = h[i+1].x-h[i].x-h[i+1].l-h[i].l;
        
        if(dx==2*L) ++ans;
        else if(dx>=2*L) ans += 2;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
