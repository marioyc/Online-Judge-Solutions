#include <cstdio>
#include <cstring>

using namespace std;

double memo[1001][1001][2];

double solve(int w, int b, int p){
    if(w < 0 || b < 0) return 0;
    double &ret = memo[w][b][p];
    
    if(!(ret == ret)){
        ret = 0;
        
        if(p == 0){
            if(w) ret += (double)w / (w + b);
            if(b) ret += (double)b / (w + b) * solve(w,b - 1,1);
        }else{
            if(b && w + b > 1) ret += (double)b / (w + b) * ((double)(b - 1) / (w + b - 1) * solve(w,b - 2,0) + (double)w / (w + b - 1) * solve(w - 1,b - 1,0));
        }
    }
    
    return ret;
}

int main(){
    int w,b;
    
    scanf("%d %d",&w,&b);
    
    memset(memo,-1,sizeof memo);
    printf("%.9f\n",solve(w,b,0));
    
    return 0;
}
