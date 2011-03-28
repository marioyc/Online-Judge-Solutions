#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int memo[100][256],L;
char s[101],s2[101],sz,MAX_LEN,cont;
set<string> ans;
set<string> :: iterator it;

int solve(int pos, int last){
    if(pos == L) return 0;
    
    int &ret = memo[pos][last];
    
    if(ret == -1){
        ret = solve(pos+1,last);
        if(s[pos] >= last) ret = max(ret,1 + solve(pos+1,s[pos]));
    }
    
    return ret;
}

void generate(int pos, int last){
    if(pos < L){
        if(sz + solve(pos+1,last) == MAX_LEN) generate(pos+1,last);
        if(s[pos] >= last && sz + 1 + solve(pos+1,s[pos]) == MAX_LEN){
            s2[sz] = s[pos]; ++sz;
            generate(pos+1,s[pos]);
            --sz;
        }
    }else if(sz == MAX_LEN){
        ans.insert(string(s2));
    }
}

int main(){
    int T;
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        L = strlen(s);
        
        memset(s2,0,sizeof(s2));
        memset(memo,-1,sizeof(memo));
        
        MAX_LEN = solve(0,0);
        sz = 0;
        
        ans.clear();
        generate(0,0);
        
        for(it = ans.begin();it != ans.end();++it) puts((*it).c_str());
        puts("");
    }
    
    return 0;
}
