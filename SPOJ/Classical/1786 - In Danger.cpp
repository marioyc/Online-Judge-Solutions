#include <cstdio>
#include <map>

using namespace std;

map<int, int> memo;

int solve(int n){
    if(n<=2) return 0;
    if(memo.find(n)!=memo.end()) return memo[n];
    
    int x = n/2;
    
    return memo[n] = 2*((n&1)? ((solve(x+1)+x)%(x+1)) : solve(x));
}

int main(){
    char x,y;
    int d;
    
    while(scanf("%c%ce%d\n",&x,&y,&d)==3){
        int n = (x-'0')*10+(y-'0');
        for(int i = 0;i<d;++i) n *= 10;
        
        if(n==0) break;
        
        printf("%d\n",1+solve(n));
    }
    
    return 0;
}
