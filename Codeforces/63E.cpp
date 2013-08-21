#include <cstdio>
#include <cstring>

using namespace std;

int memo[(1 << 19)];
char M[5][6];
int id[5][5];
int dr[] = {0,1,1};
int dc[] = {1,0,1};

int win(int mask){
    int &ret = memo[mask];
    
    if(ret == -1){
        ret = 0;
        
        for(int r = 0;r < 5;++r){
            for(int c = 0;c < 5;++c){
                if(M[r][c] == 'O'){
                    for(int i = 0;i < 3;++i){
                        int r2 = r,c2 = c,mask2 = (1 << id[r][c]);
                        
                        if((mask & mask2) == 0 && win(mask | mask2) == 0)
                            ret = 1;
                        
                        for(int j = 0;j < 4;++j){
                            r2 += dr[i]; c2 += dc[i];
                            
                            if(r2 < 5 && c2 < 5 && M[r2][c2] == 'O'){
                                mask2 ^= (1 << id[r2][c2]);
                                
                                if((mask & mask2) == 0 && win(mask | mask2) == 0)
                                    ret = 1;
                            }else break;
                        }
                    }
                }
            }
        }
    }
    
    return ret;
}

int main(){
    memset(M,'.',sizeof M);
    
    for(int i = 0;i < 3;++i) scanf("%s",M[0] + i);
    for(int i = 0;i < 4;++i) scanf("%s",M[1] + i);
    for(int i = 0;i < 5;++i) scanf("%s",M[2] + i);
    for(int i = 0;i < 4;++i) scanf("%s",M[3] + (1 + i));
    for(int i = 0;i < 3;++i) scanf("%s",M[4] + (2 + i));
    
    id[0][0] = 0; id[0][1] = 1; id[0][2] = 2;
    id[1][0] = 3; id[1][1] = 4; id[1][2] = 5; id[1][3] = 6;
    id[2][0] = 7; id[2][1] = 8; id[2][2] = 9; id[2][3] = 10; id[2][4] = 11;
    id[3][1] = 12; id[3][2] = 13; id[3][3] = 14; id[3][4] = 15;
    id[4][2] = 16; id[4][3] = 17; id[4][4] = 18;
    
    memset(memo,-1,sizeof memo);
    
    printf("%s\n",win(0)? "Karlsson" : "Lillebror");
    
    return 0;
}
