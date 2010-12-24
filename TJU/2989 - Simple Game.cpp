#include <cstdio>

using namespace std;

int main(){
    bool win[(1<<4)][(1<<4)][(1<<4)][(1<<4)];
    win[0][0][0][0] = false;
    
    for(int mask1 = 0;mask1<(1<<4);++mask1) for(int mask2 = 0;mask2<(1<<4);++mask2)
    for(int mask3 = 0;mask3<(1<<4);++mask3) for(int mask4 = 0;mask4<(1<<4);++mask4){
        bool &res = win[mask1][mask2][mask3][mask4];
        res = false;
        
        if(mask1!=0 && !win[0][mask2][mask3][mask4]) res = true;
        if(mask2!=0 && !win[mask1][0][mask3][mask4]) res = true;
        if(mask3!=0 && !win[mask1][mask2][0][mask4]) res = true;
        if(mask4!=0 && !win[mask1][mask2][mask3][0]) res = true;
        
        for(int i = 0;i<4;++i)
            if(((mask1 | mask2 | mask3 | mask4) & (1<<i))!=0 && !win[mask1 & ~(1<<i)][mask2 & ~(1<<i)][mask3 & ~(1<<i)][mask4 & ~(1<<i)])
                res = true;
    }
    
    int T,mask[4];
    scanf("%d",&T);
    
    while(T--){
        for(int i = 0,b;i<4;++i){
            mask[i] = 0;
            for(int j = 0;j<4;++j){
                scanf("%d",&b);
                if(b==1) mask[i] |= (1<<j);
            }
        }
        
        if(win[mask[0]][mask[1]][mask[2]][mask[3]]) puts("yes");
        else puts("no");
    }
    
    return 0;
}
