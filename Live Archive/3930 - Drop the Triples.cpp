#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int pow3[13];

int to_num(vector<int> &v){
    int ret = 0;
    
    for(int i = 0;i < 13;++i)
        ret += v[i] * pow3[i];
    
    return ret;
}

int memo[1594323];

int solve(vector<int> &v){
    int b3 = to_num(v);
    if(b3 == 0) return 0;
    
    int &ret = memo[b3];
    
    if(ret == -1){
        ret = 0;
        
        int last = -1;
        
        for(int i = 12;i >= 0;--i){
            if(v[i] > 0){
                last = i;
                break;
            }
        }
        
        int aux = v[last];
        
        --v[last];
        
        if(v[last] == 0){
			for(int i = 0;i < last;++i){
				if(v[i] > 0){
					--v[i];
					
					for(int j = 0;j <= i;++j){
						if(v[j] > 0 && 1 + i + j > last){
							--v[j];
							
							ret = max(ret,1 + solve(v));
							
							++v[j];
						}
					}
					
					++v[i];
				}
			}
        }else{
            v[last] = 0;
            
            for(int i = 0;i < last;++i){
                if(v[i] > 0){
                    --v[i];
                    
                    ret = max(ret,1 + solve(v));
                    
                    ++v[i];
                }
            }
        }
		
		ret = max(ret,solve(v));
		v[last] = aux;
    }
    
    memo[b3] = ret;
    
    return ret;
}

int main(){
    pow3[0] = 1;
    
    for(int i = 1;i < 13;++i)
        pow3[i] = pow3[i - 1] * 3;
    
    memset(memo,-1,sizeof memo);
    
    int N;
    
    int cont1[13],cont2[13];
    
    while(true){
        scanf("%d",&N);
        
        if(N == 0) break;
        
        memset(cont1,0,sizeof cont1);
        memset(cont2,0,sizeof cont2);
        
        for(int i = 0,x;i < N;++i){
            scanf("%d",&x);
            --x;
            
            if(i & 1) ++cont2[x];
            else ++cont1[x];
        }
        
        int n1 = 0,n2 = 0;
        
        for(int i = 0;i < 13;++i){
            n1 += cont1[i] / 3;
            n2 += cont2[i] / 3;
            cont1[i] %= 3;
            cont2[i] %= 3;
        }
        
        vector<int> v1(cont1,cont1 + 13);
        vector<int> v2(cont2,cont2 + 13);
        
        pair<int, int> p1 = make_pair(n1,solve(v1));
        pair<int, int> p2 = make_pair(n2,solve(v2));
        
        if(p1 > p2) puts("1");
        else if(p1 < p2) puts("2");
        else puts("0");
    }
    
    return 0;
}
