#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MOD 1000000007

vector<int> p,e;
int np;

int get_mask(int x){
    int ret = 0;
    
    for(int i = 0;i < np;++i){
        int aux = 0;
        
        while(x % p[i] == 0){
            x /= p[i];
            ++aux;
        }
        
        if(aux == e[i]) ret |= (1 << i);
    }
    
    return ret;
}

int memo[100][1001][1 << 5];
vector<int> div,use;
int ndiv;

int solve(int pos, int sum, int mask){
    if(sum < 0) return 0;
    if(pos == -1){
        if(sum == 0 && mask == (1 << np) - 1) return 1;
        return 0;
    }
    
    int &ret = memo[pos][sum][mask];
    
    if(ret == -1){
        ret = 0;
        
        for(int i = 0;i < ndiv;++i){
            ret += solve(pos - 1,sum - div[i],mask | use[i]);
            if(ret >= MOD) ret -= MOD;
        }
    }
    
    return ret;
}

int main(){
    int N,M,K;
    
    while(scanf("%d %d %d",&N,&M,&K) == 3){
        p.clear(); e.clear(); np = 0;
        int M2 = M;
        
        for(int i = 2;i <= M2 / i;++i){
            if(M2 % i == 0){
                p.push_back(i); ++np;
                int aux = 0;
                
                while(M2 % i == 0){
                    M2 /= i;
                    ++aux;
                }
                
                e.push_back(aux);
            }
        }
        
        if(M2 != 1){
            p.push_back(M2);
            e.push_back(1);
            ++np;
        }
        
        div.clear(); use.clear(); ndiv = 0;
        
        for(int i = 1;i <= M / i;++i){
            if(M % i == 0){
                div.push_back(i);
                use.push_back(get_mask(i));
                ++ndiv;
                
                if(i != M / i){
                    div.push_back(M / i);
                    use.push_back(get_mask(M / i));
                    ++ndiv;
                }
            }
        }
        
        memset(memo,-1,sizeof memo);
        printf("%d\n",solve(K - 1,N,0));
    }
    
    return 0;
}
