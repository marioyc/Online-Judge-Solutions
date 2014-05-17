int solution(vector<int> &A) {
    int N = A.size(),aux = 0;
    
    for(int i = 0;i < N;++i)
        aux ^= (A[i] ^ (i + 1));
    aux ^= (N + 1);
    
    return aux;
}
