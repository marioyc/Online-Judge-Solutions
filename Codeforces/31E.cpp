#include <cstdio>
#include <cstring>

using namespace std;

int n;
char s[37];
long long memo[19][19];
bool choose[19][19];
long long pot10[18];

long long solve(int have1, int have2){
    if(have1 == n && have2 == n) return 0;
    long long &ret = memo[have1][have2];
    
    if(ret == -1){
        ret = -2;
        
        if(have1 < n){
            long long aux = (s[have1 + have2] - '0') * pot10[n - 1 - have1] + solve(have1 + 1,have2);
            
            if(aux > ret){
                ret = aux;
                choose[have1][have2] = false;
            }
        }
        
        if(have2 < n){
            long long aux = (s[have1 + have2] - '0') * pot10[n - 1 - have2] + solve(have1,have2 + 1);
            
            if(aux > ret){
                ret = aux;
                choose[have1][have2] = true;
            }
        }
    }
    
    return ret;
}

int main(){
    scanf("%d %s",&n,s);
    
    memset(memo,-1,sizeof memo);
    
    pot10[0] = 1;
    for(int i = 1;i < 18;++i)
        pot10[i] = pot10[i - 1] * 10;
    
    long long aux = solve(0,0);
    
    int have1 = 0,have2 = 0;
    
    while(have1 < n || have2 < n){
        if(choose[have1][have2]) putchar('M'),++have2;
        else putchar('H'),++have1;
    }
    
    putchar('\n');
    
    return 0;
}
