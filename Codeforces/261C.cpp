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

int sz;
int n2[50];
long long memo[50][51][2];


long long solve(int pos, int nb, int eq){
    if(nb < 0) return 0;
    if(pos == -1){
        if(nb == 0) return 1;
        return 0;
    }

    long long &ret = memo[pos][nb][eq];
    
    if(ret == -1){
        ret = 0;
        
        int mxD = 1;
        if(eq) mxD = n2[pos];
        
        for(int i = 0;i <= mxD;++i)
            ret += solve(pos - 1,i == 1? nb - 1:nb,i != n2[pos]? 0 : eq);
    }
    
    return ret;    
}

int main(){
    ios::sync_with_stdio(0);
    
    long long n,t;
    
    cin >> n >> t;
    ++n;
    
    long long aux = 1;
    int lg = -1;
    
    for(int i = 0;i <= 39;++i,aux *= 2)
        if(aux == t) lg = i;
    
    if(lg == -1){
        printf("0\n");
        return 0;
    }
    
    int nb = lg + 1;
    sz = 0;
    
    for(int i = 0;i < 50;++i){
        n2[sz++] = n % 2;
        n /= 2;
    }
    
    memset(memo,-1,sizeof memo);
    cout << solve(sz - 1,nb,1) + (t == 1? -1:0) << endl;
    
    return 0;
}
