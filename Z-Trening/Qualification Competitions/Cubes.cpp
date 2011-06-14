#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

bool isPrime[1000001];
vector<int> p;

int main(){
    memset(isPrime,true,sizeof(isPrime));
    
    for(int i = 2;i <= 1000000;++i){
        if(isPrime[i]){
            p.push_back(i);
            
            if(i <= 1000)
                for(int j = i*i;j <= 1000000;j += i)
                    isPrime[j] = false;
        }
    }
    
    int n,sz = p.size();
    long long x;
    
    scanf("%d",&n);
    
    while(n--){
        scanf("%lld",&x);
        
        bool check = false;
        
        for(int j = 0;j < sz && p[j] < x;++j)
            if(x % p[j] == 0)
                check = true;
        
        puts(check? "DA" : "NE");
    }
    
    return 0;
}
