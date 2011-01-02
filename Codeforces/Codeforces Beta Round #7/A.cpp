#include <cstdio>

using namespace std;

char M[8][9];

int solve(){
    bool all = true;
    
    for(int i = 0;i<8;++i)
        for(int j = 0;j<8;++j)
            if(M[i][j]=='W')
                all = false;
    
    if(all) return 8;
    
    int ans = 0;
    
    for(int i = 0;i<8;++i){
        all = true;
        
        for(int j = 0;j<8;++j)
            if(M[i][j]=='W')
                all = false;
        
        if(all) ++ans;
        
        all = true;
        
        for(int j = 0;j<8;++j)
            if(M[j][i]=='W')
                all = false;
        
        if(all) ++ans;
    }
    
    return ans;
}

int main(){
    for(int i = 0;i<8;++i) scanf("%s",M[i]);
    
    printf("%d\n",solve());
    
    return 0;
}
