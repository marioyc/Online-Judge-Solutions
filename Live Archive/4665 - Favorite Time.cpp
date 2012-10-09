#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,s[100],e[100];
    int hh,mm;
    int t[200];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        int m = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%d:%d",&hh,&mm);
            s[i] = hh * 60 + mm;
            
            scanf("%d:%d",&hh,&mm);
            e[i] = hh * 60 + mm;
            
            t[m++] = s[i];
            t[m++] = e[i];
        }
        
        sort(t,t + m);
        
        m = unique(t,t + m) - t;
        
        int best = 0;
        int S = 0,E = 0;
        
        for(int i = 0;i < m;++i){
            for(int j = m - 1;j >= i;--j){
                int cont = 0;
                
                for(int k = 0;k < N;++k)
                    if(t[i] >= s[k] && t[i] <= e[k])
                        ++cont;
                
                bool valid = true;
                
                for(int k = t[i];k <= t[j];++k){
                    int aux = 0;
                    
                    for(int x = 0;x < N;++x)
                        if(k >= s[x] && k <= e[x])
                            ++aux;
                    
                    if(aux != cont){
                        valid = false;
                        break;
                    }
                }
                
                if(valid && cont > best){
                    best = cont;
                    S = t[i];
                    E = t[j];
                }
            }
        }
        
        printf("%02d:%02d %02d:%02d\n",S / 60,S % 60,E / 60,E % 60);
    }
    
    return 0;
}
