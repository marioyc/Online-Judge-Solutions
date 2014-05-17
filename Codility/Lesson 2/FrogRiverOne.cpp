#include <cstring>

int solution(int X, vector<int> &A) {
    int N = A.size(),cont[X + 1];
    
    memset(cont,0,sizeof cont);
    
    for(int i = 0,have = 0;i < N;++i){
        if(cont[ A[i] ] == 0){
            ++cont[ A[i] ];
            ++have;
        }
        
        if(have == X) return i;
    }
    
    return -1;
}
