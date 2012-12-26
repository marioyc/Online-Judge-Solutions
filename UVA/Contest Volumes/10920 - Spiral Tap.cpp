#include <cstdio>
#include <map>

using namespace std;

pair<int,int> solve(int P, int K){
    long long aux = (long long)K * K;
    int K2 = K / 2;
    
    if(P > aux - K) return make_pair(P - aux + K2,K2);
    
    aux -= K - 1;
    
    if(P > aux - K) return make_pair(-K2,P - aux + K2);
    
    aux -= K - 1;
    
    if(P > aux - K) return make_pair(aux - P - K2,-K2);
    
    aux -= K - 1;
    
    return make_pair(K2,aux - P - K2);
}

int main(){
    int N;
    long long P;
    
    while(true){
        scanf("%d %lld",&N,&P);
        if(N == 0) break;
        
        int K = N;
        
        while(K > 1 && (long long)(K - 2) * (K - 2) >= P) K -= 2;
        
        pair<int,int> ret = solve(P,K);
        
        ret.first = N / 2 + 1 + ret.first;
        ret.second = N / 2 + 1 + ret.second;
        
        printf("Line = %d, column = %d.\n",ret.first,ret.second);
    }
    
    return 0;
}
