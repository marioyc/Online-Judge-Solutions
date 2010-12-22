#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,a[1000],b[1000];
int memo[1000][1000];

int solve(int pos1, int pos2){
    if(pos1==n) return 0;
    
    int &ret = memo[pos1][pos2];
    
    if(ret==-1){
        ret = solve(pos1+1,pos2)-200;
        
        if(a[pos1]==b[pos2]) ret = max(ret,solve(pos1+1,pos2+1));
        if(a[pos1]>b[pos2]) ret = solve(pos1+1,pos2+1)+200;
    }
    
    return ret;
}

int main(){
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i = 0;i<n;++i) scanf("%d",&a[i]);
        for(int i = 0;i<n;++i) scanf("%d",&b[i]);
        
        sort(a,a+n);
        sort(b,b+n);
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,0));
    }
    
    return 0;
}
