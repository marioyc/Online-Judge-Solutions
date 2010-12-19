#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int R,C;
bool board[10][10];

bool checkKing(int r, int c){
    if(r>0 && c>0 && board[r-1][c-1]) return true;
    if(c>0 && board[r][c-1]) return true;
    if(r+1<R && c>0 && board[r+1][c-1]) return true;
    if(r>0 && board[r-1][c]) return true;
    if(r+1<R && board[r+1][c]) return true;
    if(r>0 && c+1<C && board[r-1][c+1]) return true;
    if(c+1<C && board[r][c+1]) return true;
    if(r+1<R && c+1<C && board[r+1][c+1]) return true;
    return false;
}

bool checkQueen(int r, int c){
    for(int i = max(r,c);i>=1;--i){
        if(r>=i && c>=i && board[r-i][c-i]) return true;
        if(c>=i && board[r][c-i]) return true;
        if(r+i<R && c>=i && board[r+i][c-i]) return true;
        if(r>=i && board[r-i][c]) return true;
        if(r+i<R && board[r+i][c]) return true;
        if(r>=i && c+i<C && board[r-i][c+i]) return true;
        if(c+i<C && board[r][c+i]) return true;
        if(r+i<R && c+i<C && board[r+i][c+i]) return true;
    }
    
    return false;
}

bool checkBishop(int r, int c){
    for(int i = max(r,c);i>=1;--i){
        if(r>=i && c>=i && board[r-i][c-i]) return true;
        if(r+i<R && c>=i && board[r+i][c-i]) return true;
        if(r>=i && c+i<C && board[r-i][c+i]) return true;
        if(r+i<R && c+i<C && board[r+i][c+i]) return true;
    }
    
    return false;
}

bool checkRook(int r, int c){
    for(int i = max(r,c);i>=1;--i){
        if(c>=i && board[r][c-i]) return true;
        if(r>=i && board[r-i][c]) return true;
        if(r+i<R && board[r+i][c]) return true;
        if(c+i<C && board[r][c+i]) return true;
    }
    
    return false;
}

int dr[] = {-2,-2,-1,-1,1,1,2,2};
int dc[] = {-1,1,-2,2,-2,2,-1,1};

bool checkKnight(int r, int c){
    for(int i = 0;i<8;++i){
        int r2 = r+dr[i],c2 = c+dc[i];
        
        if(r2>=0 && r2<R && c2>=0 && c2<C && board[r2][c2])
            return true;
    }    
    
    return false;
}

int main(){
    char M[10][21],s[6];
    int r[15],c[15],type[15],cont;
    
    while(scanf("%s",s)==1){
        scanf("%d\n%d\n",&C,&R);
        for(int i = 0;i<R;++i) fgets(M[i],21,stdin);
        scanf("%s",s);
        
        cont = 0;
        
        for(int i = 0;i<R;++i) for(int j = 0;j<C;++j){
            if(M[i][2*j]!='E'){
                r[cont] = i;
                c[cont] = j;
                type[cont] = M[i][2*j];
                ++cont;
            }
        }
        
        int ans = cont-1;
        
        if(cont>0){
            for(int mask = 1;mask<(1<<cont);++mask){
                if(__builtin_popcount(mask)>cont-ans){
                    memset(board,false,sizeof(board));
                    
                    for(int i = 0;i<cont;++i)
                        if(mask & (1<<i))
                            board[r[i]][c[i]] = true;
                    
                    bool found = false;
                    
                    for(int i = 0;i<cont;++i){
                        if(mask & (1<<i)){
                            if(type[i]=='K') found = (found || checkKing(r[i],c[i]));
                            else if(type[i]=='Q') found = (found || checkQueen(r[i],c[i]));
                            else if(type[i]=='B') found = (found || checkBishop(r[i],c[i]));
                            else if(type[i]=='R') found = (found || checkRook(r[i],c[i]));
                            else found = (found || checkKnight(r[i],c[i]));
                        }
                    }
                    
                    if(!found) ans = cont-__builtin_popcount(mask);
                }
            }
        }else ans = 0;
        
        printf("Minimum Number of Pieces to be removed: %d\n",ans);
    }
    
    return 0;
}
