#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    bool adj[(1<<12)][9][9];
    memset(adj,false,sizeof(adj));
    
    for(int mask = 0;mask<(1<<12);++mask){
        for(int i = 0,r,x;i<6;++i){
            if((mask & (1<<i))==0){
                r = i/2;
                x = 3*r+(i&1);
                adj[mask][x][x+1] = adj[mask][x+1][x] = true;
            }
        }
        
        for(int i = 6,c,x;i<12;++i){
            if((mask & (1<<i))==0){
                c = (i-6)/2;
                x = 3*(i&1)+c;
                adj[mask][x][x+3] = adj[mask][x+3][x] = true;
            }
        }
        
        for(int k = 0;k<9;++k)
            for(int i = 0;i<9;++i)
                for(int j = 0;j<9;++j)
                    adj[mask][i][j] = (adj[mask][i][j] || (adj[mask][i][k] && adj[mask][k][j]));
    }    
    
    int tc = 1,T,S,C,R;
    bool win[(1<<12)];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&S,&C,&R);
        --S; --C;
        int grid = (1<<12)-1;
        
        for(int i = 0,x1,y1,x2,y2,id;i<R;++i){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            
            if(x1==x2){
                if(y1>y2) swap(y1,y2);
                id = 2*y1+x1-1;
            }
            
            if(y1==y2){
                if(x1>x2) swap(x1,x2);
                id = 2*x1+y1+5;
            }
            
            grid &= ~(1<<id);
        }
        
        printf("Case %d: ",tc++);
        
        if(adj[grid][S][C]) puts("No Cheese!");
        else{
            for(int mask = 0;mask<=grid;++mask){
                win[mask] = false;
                
                if(!adj[mask][S][C])
                    for(int i = 0;i<12;++i)
                        if((mask & (1<<i))!=0 && !win[mask & ~(1<<i)])
                            win[mask] = true;
            }
            
            if(win[grid]) puts("SOHA");
            else puts("TARA");
        }
    }
    
    return 0;
}
