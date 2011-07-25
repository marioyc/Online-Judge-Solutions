#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1000000;

struct Bignum{
    vector<int> v;
    int d;
    
    Bignum(int n){
        v.push_back(n);
        d = 1;
    }
    
    void norm(){
        for(int i = 0;i+1 < d;++i){
            v[i+1] += v[i] / MOD;
            v[i] %= MOD;
        }
        
        while(v[d-1] >= MOD){
            v.push_back(v[d-1] / MOD);
            v[d-1] %= MOD;
            ++d;
        }
    }
    
    void add(Bignum X){
        if(X.d > d){
            d = X.d;
            v.resize(X.d,0);
        }
        
        for(int i = 0;i < X.d;++i) v[i] += X.v[i];
        norm();
    }
    
    void multiply(int n){
        for(int i = 0;i < d;++i) v[i] *= n;
        norm();
    }
    
    void print(){
        printf("%d",v[d-1]);
        for(int i = d-2;i >= 0;--i) printf("%06d",v[i]);
        printf("\n");
    }
};

int main(){
    int N;
    
    scanf("%d",&N);
    
    Bignum ans(0),aux(N);
    
    for(int i = 2;i <= N;++i){
        aux.multiply(N - i + 1);
        ans.add(aux);
    }
    
    ans.print();
    
    return 0;
}
