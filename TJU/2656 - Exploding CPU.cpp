#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long n){
    if(n==2) return true;
    if(n%2==0) return false;
    
    for(int i = 3;i<=n/i;i += 2)
        if(n%i==0)
            return false;
    
    return true;
}

int main(){
    bool prime[44722];
    vector<int> P;
    
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    
    P.push_back(2);
    for(int i = 4;i<=44722;i += 2) prime[i] = false;
    
    for(int i = 3;i<=44721;i += 2){
        if(prime[i]){
            P.push_back(i);
            for(int j = 2*i;j<=44721;j += i) prime[j] = false;
        }
    }
    
    int n = P.size();
    const int LIM = 2000000000;
    
    vector<int> exploit;
    
    for(int i = 0;i+1<n && P[i]<1260;++i){
        for(int j = i+1;j<n;++j){
            if((P[j]-P[i])%(P[i]-1)==0){
                int A = (P[j]-P[i])/(P[i]-1);
                int B = P[i]-A;
                
                long long cur = A*P[j]+B;
                long long acum = P[i]*P[j]*cur;
                
                while(acum<=LIM && isPrime(cur)){
                    exploit.push_back(acum);
                    cur = A*cur+B;
                    acum *= cur;
                }
            }
        }
    }
    
    sort(exploit.begin(),exploit.end());
    
    int m = exploit.size(),T,L,H;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&L,&H);
        
        int lo = 0, hi = m-1,mi;
        
        while(lo!=hi){
            mi = (lo+hi)/2;
            
            if(exploit[mi]>=L) hi = mi;
            else lo = mi+1;
        }
        
        int s = lo;
        
        lo = 0,hi = m-1,mi;
        
        while(lo!=hi){
            mi = (lo+hi+1)/2;
            
            if(exploit[mi]<=H) lo = mi;
            else hi = mi-1;
        }
        
        printf("%d\n",lo-s+1);
    }
    
    return 0;
}
