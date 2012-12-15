#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define MAXN 3000
#define MAXLEN 3001
#define MOD 1000000007

string a[MAXN];
int len[MAXN];

long long fact[28];

long long solve(int pos, int l, int r){
    long long ret = 1;
    int cont = 0;
    
    if(len[l] == pos){
        ++l;
        ++cont;
    }
    
    for(char c = 'A';c <= 'Z' && l <= r;++c){
        if(a[l][pos] == c){
            int lo = l,hi = r,mi;
            
            while(lo < hi){
                mi = (lo + hi + 1) >> 1;
                
                if(a[mi][pos] == c) lo = mi;
                else hi = mi - 1;
            }
            
            ret = ret * solve(pos + 1,l,lo) % MOD;
            l = lo + 1;
            ++cont;
        }
    }
    
    ret = ret * fact[cont] % MOD;
    
    return ret;
}

char s[MAXLEN];

int main(){
    ios::sync_with_stdio(0);
    
    fact[0] = 1;
    
    for(int i = 1;i <= 27;++i)
        fact[i] = fact[i - 1] * i % MOD;
    
    int N;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%s",s);
        a[i] = string(s);
    }
    
    sort(a,a + N);
    
    for(int i = 0;i < N;++i)
        len[i] = a[i].size();
    
    printf("%lld\n",solve(0,0,N - 1));
    
    return 0;
}
