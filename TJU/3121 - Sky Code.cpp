#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_ID 10000

int main(){
    bool sq_free[MAX_ID+1],odd[MAX_ID+1];
    vector<int> L;
    
    sq_free[0] = false;
    sq_free[1] = true;
    odd[1] = false;
    
    for(int i = 2;i<=MAX_ID;++i){
        int aux = i;
        
        sq_free[i] = true;
        odd[i] = true; // si es primo
        
        for(int j = 2;j*j<=i;++j){
            if(i%j==0){
                odd[i] = odd[i/j] ^ odd[j];
                if(i%(j*j)==0) sq_free[i] = false;
            }
        }
        
        if(sq_free[i]) L.push_back(i);
    }
    
    int M = L.size();
    int N,a,rep[MAX_ID+1],cont[MAX_ID+1];
    
    while(scanf("%d",&N)==1){
        memset(rep,0,sizeof(rep));
        
        for(int i = 0;i<N;++i){
            scanf("%d",&a);
            ++rep[a];
        }
        
        memset(cont,0,sizeof(cont));
        
        for(int i = 2;i<=MAX_ID;++i)
            for(int j = i;j<=MAX_ID;j += i)
                cont[i] += rep[j];
        
        long long ans = (long long)N*(N-1)*(N-2)*(N-3)/24;
        
        for(int i = 0;i<M;++i){
            int d = L[i], aux = cont[d];
            long long num = (long long)aux*(aux-1)*(aux-2)*(aux-3)/24;
            
            if(odd[d]) ans -= num;
            else ans += num;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
