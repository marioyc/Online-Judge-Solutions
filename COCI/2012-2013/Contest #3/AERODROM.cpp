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

#define MAXN 100000

int T[MAXN];

int main(){
    ios::sync_with_stdio(0);
    
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    int maxT = 0;
    
    for(int i = 0;i < N;++i){
        scanf("%d",&T[i]);
        maxT = max(maxT,T[i]);
    }
    
    long long lo = 1,hi = (long long)maxT * M,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        long long cont = 0;
        
        for(int i = 0;i < N;++i)
            cont = min((long long)M,cont + mi / T[i]);
        
        if(cont < M) lo = mi + 1;
        else hi = mi;
    }
    
    printf("%lld\n",lo);
    
    return 0;
}
