#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define MAXN 2000

int main(){
    ios::sync_with_stdio(0);
    
    int T,N;
    
    cin >> T;
    
    int A[MAXN],B[MAXN],in[MAXN],ans[MAXN];
    vector<int> L[MAXN];
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N;
        
        for(int i = 0;i < N;++i) cin >> A[i];
        for(int i = 0;i < N;++i) cin >> B[i];
        for(int i = 0;i < N;++i) L[i].clear();
        memset(in,0,sizeof in);
        
        for(int i = 0;i < N;++i){
            int lastA = 0,lastB = N;
            
            for(int j = 0;j < i;++j){
                if(A[j] >= A[i]){
                    L[i].push_back(j);
                    ++in[j];
                }else if(A[j] == A[i] - 1){
                    lastA = j;
                }
            }
            
            if(A[i] > 1){
                L[lastA].push_back(i);
                ++in[i];
            }
            
            for(int j = N - 1;j > i;--j){
                if(B[j] >= B[i]){
                    L[i].push_back(j);
                    ++in[j];
                }else if(B[j] == B[i] - 1){
                    lastB = j;
                }
            }
            
            if(B[i] > 1){
                L[lastB].push_back(i);
                ++in[i];
            }
        }
        
        priority_queue<int> Q;
        int pos = 1;
        
        for(int i = 0;i < N;++i)
            if(in[i] == 0)
                Q.push(-i);
        
        while(!Q.empty()){
            int cur = -Q.top();
            Q.pop();
            ans[cur] = pos++;
            
            for(int i = L[cur].size() - 1,to;i >= 0;--i){
                to = L[cur][i];
                --in[to];
                if(in[to] == 0) Q.push(-to);
            }
        }
        
        cout << "Case #" << tc << ":";
        for(int i = 0;i < N;++i) cout << " " << ans[i];
        cout << '\n';
    }
    
    return 0;
}
