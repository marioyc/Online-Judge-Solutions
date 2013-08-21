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

#define MAXN 500000

struct lady{
    int B,I,R;
    
    lady(){}
    
    bool operator < (lady X)const{
        return B < X.B;
    }
}L[MAXN];

vector<int> allI;
int bit[MAXN];

void update(int idx, int val){
    for(int x = idx;x <= MAXN;x += x & -x)
        bit[x] = max(bit[x],val);
}

int query(int idx){
    int ret = -1;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret = max(ret,bit[x]);
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    for(int i = 0;i < N;++i) cin >> L[i].B;
    for(int i = 0;i < N;++i) cin >> L[i].I;
    for(int i = 0;i < N;++i) cin >> L[i].R;
    for(int i = 0;i < N;++i) allI.push_back(L[i].I);
    sort(allI.begin(),allI.end());
    sort(L,L + N);
    
    memset(bit,-1,sizeof bit);
    int ans = 0;
    
    for(int i = N - 1;i >= 0;){
        int e = i;
        
        while(e >= 0 && L[e].B == L[i].B) --e;
        
        for(int j = e + 1;j <= i;++j){
            int pos = lower_bound(allI.begin(),allI.end(),L[j].I) - allI.begin();
            pos = N - pos;
            
            int bestR = query(pos - 1);
            
            if(L[j].R < bestR) ++ans;
        }
        
        for(int j = e + 1;j <= i;++j){
            int pos = lower_bound(allI.begin(),allI.end(),L[j].I) - allI.begin();
            pos = N - pos;
            
            update(pos,L[j].R);
        }
        
        i = e;
    }
    
    cout << ans << '\n';
    
    return 0;
}
