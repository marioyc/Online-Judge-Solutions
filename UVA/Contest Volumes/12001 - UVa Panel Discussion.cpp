#include <cstdio>

using namespace std;

int main(){
    int N,M,cont[50];
    
    while(true){
        scanf("%d %d",&N,&M);
        if(N == 0) break;
        
        for(int i = 0;i < M;++i) cont[i] = 0;
        
        for(int i = 0,x;i < N;++i){
            scanf("%d",&x);
            ++cont[--x];
        }
        
        int ans3 = 0;
        
        for(int i = 0;i < M;++i){
            ans3 += cont[i] * (cont[i] - 1) / 2 * (cont[i] - 2) / 3;
            
            for(int j = i+1;j < M;++j)
                for(int k = j+1;k < M;++k)
                    ans3 += cont[i] * cont[j] * cont[k];
        }
        
        int total = 0;
        long long ans4 = 0,aux;
        
        for(int i = 0;i < M;++i) total += cont[i];
        
        for(int i = 0;i < M;++i){
            if(cont[i] >= 3){
                aux = cont[i] * (cont[i] - 1) / 2 * (cont[i] - 2) / 3;
                ans4 += aux * (total - cont[i]);
                ans4 += aux * (cont[i] - 3) / 4;
            }
        }
        
        for(int i = 0;i < M;++i)
            for(int j = i+1;j < M;++j)
                for(int k = j+1;k < M;++k)
                    for(int l = k+1;l < M;++l)
                        ans4 += cont[i] * cont[j] * cont[k] * cont[l];
        
        for(int i = 0;i < M;++i) for(int j = i+1;j < M;++j) for(int k = j+1;k < M;++k){
            ans4 += cont[i] * (cont[i] - 1) / 2 * cont[j] * cont[k];
            ans4 += cont[i] * cont[j] * (cont[j] - 1) / 2 * cont[k];
            ans4 += cont[i] * cont[j] * cont[k] * (cont[k] - 1) / 2;
        }
        
        printf("%d %lld\n",ans3,ans4);
    }
    
    return 0;
}
