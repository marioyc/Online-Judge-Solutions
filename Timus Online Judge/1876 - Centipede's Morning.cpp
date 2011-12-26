#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A,B;
int memo[101][101];

int solve(int a, int b){
    if(a >= 40 && b >= 40) return 0;
    
    int &ret = memo[a][b];
    
    if(ret == -1){
        if(a >= 40){
            if(A > a) ret = max(ret,2 + solve(a + 1,b));
            ret = max(ret,1 + solve(a,b + 1));
        }else{
            ret = max(ret,1 + solve(a + 1,b));
            if(B > b) ret = max(ret,2 + solve(a,b + 1));
        }
    }
    
    return ret;
}

int main(){
    scanf("%d %d",&A,&B);
    
    memset(memo,-1,sizeof memo);
    
    printf("%d\n",solve(0,0));
    
    return 0;
}
