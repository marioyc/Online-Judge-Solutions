#include <algorithm>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> min_rotation(vector<int> &s){
    int N = s.size(),ans = 0,p = 1,len = 0;
    
    while(p < N && ans + len + 1 < N){
        if(s[ans + len] == s[(p + len) % N]) ++len;
        else if(s[ans + len] < s[(p + len) % N]){
            p = p + len + 1;
            len = 0;
        }else{
            ans = max(ans + len + 1,p);
            p = ans + 1;
            len = 0;
        }
    }
    
    vector<int> ret;
    
    for(int i = 0;i < N;++i)
        ret.push_back(s[(ans + i) % N]);
    
    return ret;
}

vector<int> A2,B,rotB;
int N,M;
map< vector<int>, int >cont;

int solution(const vector< vector<int> > &A, int P) {
    N = A.size();
    M = A[0].size();
    if(M == 1) return N * (N - 1) / 2;
    
    for(int i = 0;i < N;++i){
        A2 = vector<int>(A[i]);
        sort(A2.begin(),A2.end());
        B.clear();
        for(int j = 0;j + 1 < M;++j)
            B.push_back(A2[j + 1] - A2[j]);
        B.push_back(P - A2[M - 1] + A2[0]);
        rotB = min_rotation(B);
        cont[rotB] += 1;
    }
    
    int ans = 0;
    
    for(map< vector<int>, int > :: iterator it = cont.begin();it != cont.end();++it)
        ans += (it->second) * (it->second - 1) / 2;
        
    return ans;
}
