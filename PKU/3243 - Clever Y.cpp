#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

int pow(long long a, int b, int c){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % c;
        a = a * a % c;
        b >>= 1;
    }
    
    return ret;
}

int r;
pair<int, int> baby[31622],giant[31622];

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    int x,z,m;
    
    while(true){
        scanf("%d %d %d",&x,&m,&z);
        if(x == 0) break;
        
        z %= m;
        
        if(m == 1 || z == 1) puts("0");
        else{
            int ans = -1;
            
            if(pow(x,31,m) == 0){
                long long aux = 1;
                
                for(int i = 0;i < 32;++i){
                    if(aux == z){
                        ans = i;
                        break;
                    }
                    
                    aux = x * aux % m;
                }
            }else{
                r = (int)floor(sqrt(m));
                int max_val = (m + r - 1) / r;
                long long p = z;
                
                for(int i = 0;i < r;++i){
                    baby[i] = make_pair(p % m,i);
                    p = p * x % m;
                }
                
                sort(baby,baby + r,cmp);
                
                int aux = pow(x,r,m);
                p = aux;
                
                for(int i = 0,e = r;i < max_val;++i, e += r){
                    giant[i] = make_pair(p,e);
                    p = p * aux % m;
                }
                
                sort(giant,giant + max_val);
                
                for(int i = 0,j = 0;i < max_val && j < r;++i){
                    while(j < r && baby[j].first < giant[i].first) ++j;
                    
                    if(j < r && baby[j].first == giant[i].first)
                        if(ans == -1 || giant[i].second - baby[j].second < ans)
                            ans = giant[i].second - baby[j].second;
                }
            }
            
            if(ans == -1) puts("No Solution");
            else printf("%d\n",ans);
            
        }
    }
    
    return 0;
}
