#include <cstring>

int solution(vector<int> &A) {
    int N = A.size();
    int cont[N];
    
    memset(cont,0,sizeof cont);
    
    for(int i = 0;i < N;++i){
        if(A[i] > N || cont[ A[i] - 1] > 0) return 0;
        ++cont[ A[i] - 1];
    }
    
    return 1;
}
