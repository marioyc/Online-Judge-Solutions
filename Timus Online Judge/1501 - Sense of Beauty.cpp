#include <cstdio>
#include <cstring>

using namespace std;

int N;
char s1[1001],s2[1001];
bool done[1001][1001][2],memo[1001][1001][2];

bool solve(int n, int m, int next){
    if(n==N && m==N) return true;
    
    bool &ret = memo[n][m][next];
    
    if(!done[n][m][next]){
        ret = false;
        
        if((n+m) & 1){
            if(n<N && s1[n]=='0'+next && solve(n+1,m,1-next)) ret = true;
            if(m<N && s2[m]=='0'+next && solve(n,m+1,1-next)) ret = true;
        }else{
            if(n<N && solve(n+1,m,s1[n]=='0'? 1 : 0)) ret = true;
            if(m<N && solve(n,m+1,s2[m]=='0'? 1 : 0)) ret = true;
        }
        
        done[n][m][next] = true;
    }
    
    return ret;
}

int main(){
    scanf("%d",&N);
    scanf("%s %s",s1,s2);
    
    memset(done,false,sizeof(done));
    
    if(solve(0,0,0) || solve(0,0,1)){
        int n = 0,m = 0,next = (solve(0,0,0)? 0 : 1);
        
        while(n!=N || m!=N){
            if((n+m) & 1){
                if(n<N && s1[n]=='0'+next && solve(n+1,m,1-next)){
                    putchar('1');
                    next = 1-next;
                    ++n;
                }else{
                    putchar('2');
                    next = 1-next;
                    ++m;
                }
            }else{
                if(n<N && solve(n+1,m,s1[n]=='0'? 1 : 0)){
                    putchar('1');
                    next = (s1[n]=='0'? 1 : 0);
                    ++n;
                }else{
                    putchar('2');
                    next = (s2[m]=='0'? 1 : 0);
                    ++m;
                }
            }
        }
        
        putchar('\n');
    }else{
        puts("Impossible");
    }
    
    return 0;
}
