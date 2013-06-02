#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define MOD 1000002013
#define MAXM 1000

int N,M;

long long f(int s, int e){
    return (long long)(e - s) * (2 * N + s - e + 1) / 2 % MOD;
}

pair<int, int> op[MAXM],cl[MAXM];

int main(){
    ios::sync_with_stdio(0);
    
    int T;
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N >> M;
        long long ans = 0;
        
        for(int i = 0,o,e,p;i < M;++i){
            cin >> o >> e >> p;
            op[i] = make_pair(o,p);
            cl[i] = make_pair(e,p);
            ans = (ans + p * f(o,e)) % MOD;
        }
        
        sort(op,op + M);
        sort(cl,cl + M);
        
        stack< pair<int, int> > S;
        
        for(int i = 0,j = 0;i < M || j < M;){
            int cur = N + 1;
            if(i < M) cur = min(cur,op[i].first);
            if(j < M) cur = min(cur,cl[j].first);
            
            while(i < M && op[i].first == cur){
                S.push(op[i]);
                ++i;
            }
            
            while(j < M && cl[j].first == cur){
                while(cl[j].second){
                    pair<int, int> take = S.top();
                    S.pop();
                    
                    int P = min(cl[j].second,take.second);
                    cl[j].second -= P;
                    take.second -= P;
                    ans = (ans - P * f(take.first,cur)) % MOD;
                    
                    if(take.second) S.push(take);
                }
                ++j;
            }
        }
        
        if(ans < 0) ans += MOD;
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    
    return 0;
}
