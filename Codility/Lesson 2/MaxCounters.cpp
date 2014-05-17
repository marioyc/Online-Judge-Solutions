#include <cstring>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> &A) {
    int M = A.size();
    int cont[N + 1],last[N + 1],prev = 0,cur = 0,q2 = 0;
    memset(cont,0,sizeof cont);
    memset(last,0,sizeof last);
    
    for(int i = 0;i < M;++i){
        if(A[i] == N + 1){
            ++q2;
            prev = cur;
        }else{
            if(last[ A[i] ] != q2){
                cont[ A[i] ] = prev;
                last[ A[i] ] = q2;
            }
            
            ++cont[ A[i] ];
            cur = max(cur,cont[ A[i] ]);
        }
    }
    
    vector<int> ret;
    
    for(int i = 1;i <= N;++i){
        if(last[i] != q2) ret.push_back(prev);
        else ret.push_back(cont[i]);
    }
    
    return ret;
}
