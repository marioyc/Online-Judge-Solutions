#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXL 1010000
#define MAXN 10000
#define B 261

char s[MAXL];
int pos[MAXN],len[MAXN];
unsigned long long H[MAXL + 1],powB[MAXL + 1];

vector<int> L[MAXN];
int memo[MAXN];

int solve(int cur){
    int &ret = memo[cur];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = L[cur].size() - 1;i >= 0;--i)
            ret = max(ret,1 + solve(L[cur][i]));
    }
    
    return ret;
}

unsigned long long get_hash(int l, int r){
    return H[r + 1] - H[l] * powB[r - l + 1];
}

bool check(int x, int y){
    int &lx = len[x],&px = pos[x],&ly = len[y],&py = pos[y];
    unsigned long long hx = get_hash(px,px + lx - 1);
    
    for(int i = 0;i + lx <= ly;++i)
        if(get_hash(py + i,py + i + lx - 1) == hx)
            return true;
    
    return false;
}

int main(){
    powB[0] = 1;
    
    for(int i = 1;i <= MAXL;++i)
        powB[i] = powB[i - 1] * B;
    
    int n;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        int p = 0;
        
        for(int i = 0;i < n;++i){
            scanf("%s",s + p);
            len[i] = strlen(s + p);
            pos[i] = p;
            p += len[i] + 1;
        }
        
        H[0] = 0;
        
        for(int i = 0;i < p;++i)
            H[i + 1] = s[i] + H[i] * B;
        
        for(int i = 0;i < n;++i){
            L[i].clear();
            
            for(int j = 0;j < n;++j)
                if(len[i] < len[j] && check(i,j))
                    L[i].push_back(j);
        }
        
        memset(memo,-1,sizeof memo);
        int ans = 0;
        
        for(int i = 0;i < n;++i)
            ans = max(ans,1 + solve(i));
        
        printf("%d\n",ans);
    }
    
    return 0;
}
