#include <cstdio>
#include <cstring>

using namespace std;


int main(){
    int R,C,L;
    char s[401];
    bool used[20][20];
    
    while(true){
        scanf("%d %d",&R,&C);
        if(R==0 && C==0) break;
        
        scanf("%s",s);
        L = strlen(s);
        
        for(int i = 0;i<L;++i){
            s[i] -= 7;
            if(s[i]<0) s[i] += 126;
        }
        
        memset(used,false,sizeof(used));
        
        int  N = R*C,r = 0,c = 0,dr = 0,dc = 1,tmp,r2,c2;
        
        for(int i = 0;i<N;++i){
            used[r][c] = true;
            putchar(s[r*C+c]);
            
            for(int k = 0;k<4;++k){
                r2 = r+dr; c2 = c+dc;
                
                if(r2>=0 && r2<R && c2>=0 && c2<C && !used[r2][c2]){
                    r = r2, c = c2;
                    break;
                }else{
                    tmp = dr;
                    dr = dc;
                    dc = -tmp;
                    r2 = r+dr; c2 = c+dc;
                    
                    if(r2>=0 && r2<R && c2>=0 && c2<C && !used[r2][c2]){
                        r = r2, c = c2;
                        break;
                    }
                }
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}
