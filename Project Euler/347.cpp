#include <iostream>
#include <cstring>
#include <set>
#include <map>

using namespace std;

const int MAXN = 10000000;
bool p[MAXN + 1];
int f[MAXN + 1];

int main(){
    memset(p,true,sizeof p);
    
    for(int i = 2;i <= MAXN;++i){
        if(p[i]){
            f[i] = i;
            
            if(i <= MAXN / i)
                for(int j = i*i;j <= MAXN;j += i){
                    p[j] = false;
                    f[j] = i;
                }
        }
    }
    
    set< pair<int, int> > S;
    long long ans = 0;
    
    for(int i = MAXN;i >= 2;--i){
        int aux = i;
        int p1 = f[aux];
        
        while(aux % p1 == 0) aux /= p1;
        
        if(aux == 1) continue;
        
        int p2 = f[aux];
        
        while(aux % p2 == 0) aux /= p2;
        
        if(aux != 1) continue;
        
        if(p1 < p2) swap(p1,p2);
        
        if(S.find(make_pair(p1,p2)) == S.end()){
            S.insert(make_pair(p1,p2));
            ans += i;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
