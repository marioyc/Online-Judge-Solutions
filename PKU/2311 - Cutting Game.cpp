#include <cstdio>
#include <cstring>

using namespace std;

int memo[201][201];

int solve(int w, int h){
    int &ret = memo[w][h];
    
    if(ret == -1){
        ret = 0;
        
        bool have[400];
        memset(have,false,sizeof have);
        
        for(int i = 2;i < w - 1;++i)
            have[solve(i,h) ^ solve(w - i,h)] = true;
        
        for(int i = 2;i < h - 1;++i)
            have[solve(w,i) ^ solve(w,h - i)] = true;
        
        while(have[ret]) ++ret;
    }
    
    return ret;
}

int main(){
    int W,H;
    
    memset(memo,-1,sizeof memo);
    
    while(scanf("%d %d",&W,&H) == 2)
        puts(solve(W,H) == 0? "LOSE" : "WIN");
    
    return 0;
}
