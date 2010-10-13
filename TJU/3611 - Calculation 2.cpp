#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int INV = 500000004;
const int MOD = 1000000007;

int main(){
    bool isPrime[31625];
    vector<int> prime;
    
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    
    prime.push_back(2);
    for(int i = 4;i<31625;i += 2) isPrime[i] = false;
    
    for(int i = 3;i<31625;i += 2){
        if(isPrime[i]){
            prime.push_back(i);
            
            for(int j = i*i;j<31625;j += i)
                isPrime[j] = false;
        }
    }
    
    int N,M = prime.size();
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        long long ans = (long long)N*(N-1)/2;
        int phi = N, aux = N;
        
        for(int i = 0;i<M;++i){
            if(aux%prime[i]==0){
                phi -= phi/prime[i];
                
                while(aux%prime[i]==0)
                    aux /= prime[i];
            }
        }
        
        if(aux!=1) phi -= phi/aux;
        
        ans -= (long long)N*phi/2;
        
        printf("%lld\n",ans%MOD);
    }
    
    return 0;
}
