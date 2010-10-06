#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int dp[2][501][501][2];

void readInt(int &n){
    int sign = 1;
    char c;
    bool found = false;
    n = 0;
    
    while(true){
    	c = getc(stdin);
    	
        switch(c){
            case ' ':
                if(found) goto jump;
                break;
            case '\n':
                if(found) goto jump;
                break;
            default:
                if(c>='0' && c<='9'){
                    n = n*10+c-'0';
                    found = true;
                }else goto jump;
                break;
        }
    }
    
    jump:
        n *= sign;
}

int main(){
    int T,M,F,R,C,INF = INT_MAX/2;
    int cap[500],p[500];
    
    scanf("%d",&T);
    
    while(T--){
        readInt(M); readInt(F); readInt(R); readInt(C);
        
        for(int i = 0;i<R;++i){
            readInt(cap[i]);
            readInt(p[i]);
        }
        
        for(int m = 0;m<=M;++m)
            for(int f = 0;f<=F;++f)
                for(int c = 0;c<2;++c)
                    dp[0][m][f][c] = dp[1][m][f][c] = INF;
        
        dp[0][0][0][0] = 0;
        
        for(int r = 0,prev = 0,cur = 1;r<R;++r){
            for(int m = 0;m<=M;++m){
                for(int f = 0;f<=F;++f){
                    for(int c = 0;c<2;++c){
                        int &ret = dp[cur][m][f][c];
                        ret = dp[prev][m][f][c];
                        
                        if(m>0){
                            int aux = p[r]+dp[prev][m-min(cap[r],m)][f][c];
                            if(aux<ret) ret = aux;
                        }
                        
                        if(f>0){
                            int aux = p[r]+dp[prev][m][f-min(cap[r],f)][c];
                            if(aux<ret) ret = aux;
                        }
                        
                        if(c==1 && cap[r]>=2){
                            int aux = p[r]+dp[prev][m][f][0];
                            if(aux<ret) ret = aux;
                        }
                    }
                }
            }
            
            prev ^= 1;
            cur ^= 1;
        }
        
        int ans = dp[R&1][M][F][0];
        
        if(C>0){
            int aux = dp[R&1][M-1][F-1][1];
            if(aux<ans) ans = aux;
        }
        
        if(ans<INF) printf("%d\n",ans);
        else printf("Impossible\n");
    }
    
    return 0;
}
