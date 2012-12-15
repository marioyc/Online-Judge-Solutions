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

int main(){
    ios::sync_with_stdio(0);
    
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    char s[21];
    int len[N];
    
    for(int i = 0;i < N;++i){
        scanf("%s",s);
        len[i] = strlen(s);
    }
    
    int cont[21];
    memset(cont,0,sizeof cont);
    
    ++cont[ len[0] ];
    
    long long ans = 0;
    
    for(int i = 0,s = 0,e = 0;i < N;++i){
        if(i - s > K){
            --cont[ len[s] ];
            ++s;
        }
        
        while(e + 1 < N && e + 1 - i <= K){
            ++cont[ len[e + 1] ];
            ++e;
        }
        
        ans += cont[ len[i] ] - 1;
    }
    
    printf("%lld\n",ans / 2);
    
    return 0;
}
