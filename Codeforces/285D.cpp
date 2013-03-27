#include <cstdio>

using namespace std;

int n;
bool found[16];
int cont = 0;

void search(int pos, int mask){
    if(pos == -1) ++cont;
    else{
        for(int i = 0;i < n;++i){
            if(mask >> i & 1){
                int aux = (pos + i) % n;
                if(!found[aux]){
                    found[aux] = true;
                    search(pos - 1,mask ^ (1 << i));
                    found[aux] = false;
                }
            }
        }
    }
}

int precalc[] = {1,0,3,0,15,0,133,0,2025,0,37851,0,1030367,0,36362925,0};

#define MOD 1000000007

int main(){
    scanf("%d",&n);
    
    //search(n - 1,(1 << n) - 1);
    
    //printf("%d\n",cont);
    
    long long ans = precalc[n - 1];
    
    for(int i = 1;i <= n;++i)
        ans = (ans * i) % MOD;
    
    printf("%I64d\n",ans);
    
    return 0;
}
