#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    char s[4001];
    scanf("%s",s);
    
    int L = strlen(s);
    vector<int> palin[4000];
    
    for(int i = 0;i<L;++i){
        int pos1 = i,pos2 = i;
        
        while(pos1>=0 && pos2<L && s[pos1]==s[pos2]){
            palin[pos1].push_back(pos2);
            --pos1; ++pos2;
        }
        
        pos1 = i; pos2 = i+1;
        
        while(pos1>=0 && pos2<L && s[pos1]==s[pos2]){
            palin[pos1].push_back(pos2);
            --pos1; ++pos2;
        }
    }
    
    int dp[4001],next[4000];
    dp[L] = 0;
    
    for(int i = L-1;i>=0;--i){
        dp[i] = L-i;
        next[i] = i+1;
        
        for(int j = palin[i].size()-1;j>=0;--j){
            if(dp[i]>1+dp[palin[i][j]+1]){
                dp[i] = 1+dp[palin[i][j]+1];
                next[i] = palin[i][j]+1;
            }
        }
    }
    
    printf("%d\n",dp[0]);
    
    int pos = 0;
    
    while(pos!=L){
        if(pos!=0) putchar(' ');
        for(int i = pos;i<next[pos];++i) putchar(s[i]);
        pos = next[pos];
    }
    
    putchar('\n');
    
    return 0;
}
