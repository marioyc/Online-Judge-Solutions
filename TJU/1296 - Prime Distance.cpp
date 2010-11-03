#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#include <iostream>

using namespace std;

int p[1000001];
bool isPrime[1000001];

int main(){
    int ans1,ans2,N;
    bool sieve[46341];
    vector<int> prime_list;
    
    memset(sieve,true,sizeof(sieve));
    
    for(int i=2;i<=46340;++i){
        if(sieve[i]){
            prime_list.push_back(i);
            if(i<=215) for(int j=i*i;j<=46340;j+=i) sieve[j] = false;
        }
    }
    
    int P = prime_list.size(),L,U;
    
    while(scanf("%d %d",&L,&U)==2){
        fill(isPrime,isPrime+(U-L+1),true);
        
        for(int i=0;i<P && prime_list[i]<=U;++i){
            int n = prime_list[i];
            for(long long j=max(2LL,((long long)L+n-1)/n);j<=U/n;++j) isPrime[j*n-L] = false;
        }
        
        if(L==1) isPrime[0] = false;
        
        N = 0;
        for(int i=U;i>=L;--i) if(isPrime[i-L]) p[N++] = i;
        for(int i=N/2-1;i>=0;--i) swap(p[i],p[N-1-i]);
        
        ans1 = ans2 = -1;
        
        for(int i=0;i+1<N;++i){
            if(ans1==-1 || p[i+1]-p[i]<p[ans1+1]-p[ans1]) ans1 = i;
            if(ans2==-1 || p[i+1]-p[i]>p[ans2+1]-p[ans2]) ans2 = i;
        }
        
        if(ans1==-1) printf("There are no adjacent primes.\n");
        else printf("%d,%d are closest, %d,%d are most distant.\n",p[ans1],p[ans1+1],p[ans2],p[ans2+1]);
    }
    
    return 0;
}
