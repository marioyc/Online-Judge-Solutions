#include <cstdio>
#include <cstring>

using namespace std;

char num[10];
int L,memo[10][2];

int solve(int pos, int all){
    if(pos == L) return 1;
    
    int &ret = memo[pos][all];
    
    if(ret == -1){
        ret = 0;
        
        int mxD = num[pos] - '0';
        if(all) mxD = 9;
        
        for(int i = 0;i <= mxD;++i)
            if(i != 4) ret += solve(pos + 1,i < mxD? 1 : all);
    }
    
    return ret;
}

int main(){
    while(true){
        scanf("%s",num);
        if(num[0] == '0') break;
        
        L = strlen(num);
        
        memset(memo,-1,sizeof memo);
        
        printf("%s: %d\n",num,solve(0,0) - 1);
    }
    
    return 0;
}
