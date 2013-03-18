#include <cstdio>

using namespace std;

#define MAXN 100000

int l[MAXN],r[MAXN];

int main(){
    int N,Q;
    
    while(true){
        scanf("%d %d",&N,&Q);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i){
            l[i] = i - 1;
            r[i] = i + 1;
        }
        
        for(int i = 0,x,y;i < Q;++i){
            scanf("%d %d",&x,&y);
            --x; --y;
            
            int lx = l[x],ry = r[y];
            
            if(lx != -1){
                printf("%d ",lx + 1);
                r[lx] = ry;
            }else printf("* ");
            
            if(ry != N){
                printf("%d\n",ry + 1);
                l[ry] = lx;
            }else printf("*\n");
        }
        
        puts("-");
    }
    
    return 0;
}
