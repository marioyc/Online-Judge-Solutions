#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,R,C,K;
    char M[200][200];
    
    scanf("%d",&T);
    
    int ans1 = 0,ans2 = 0;
    
    while(T--){
        scanf("%d %d %d",&C,&R,&K);
        
        for(int i = 0;i < R;++i)
            scanf("%s",M[i]);
        
        bool done = false;
        
        for(int i = 0;i < R && !done;++i){
            for(int j = 0;j < C && !done;++j){
                if(M[i][j] != '.'){
                    int cont = 0,aux;
                    
                    if(i + K <= R){
                        aux = 0;
                        
                        for(int k = 0;k < K && M[i + k][j] == M[i][j];++k)
                            ++aux;
                        
                        cont = max(cont,aux);
                    }
                    
                    if(j + K <= C){
                        aux = 0;
                        
                        for(int k = 0;k < K && M[i][j + k] == M[i][j];++k)
                            ++aux;
                        
                        cont = max(cont,aux);
                    }
                    
                    if(i + K <= R && j + K <= C){
                        aux = 0;
                        
                        for(int k = 0;k < K && M[i + k][j + k] == M[i][j];++k)
                            ++aux;
                        
                        cont = max(cont,aux);
                    }
                    
                    if(i + K <= R && j >= K - 1){
                        aux = 0;
                        
                        for(int k = 0;k < K && M[i + k][j - k] == M[i][j];++k)
                            ++aux;
                        
                        cont = max(cont,aux);
                    }
                    
                    if(cont >= K){
                        done = true;
                        
                        if(M[i][j] == 'x') ++ans1;
                        else ++ans2;
                    }
                }
            }
        }
    }
    
    printf("%d:%d\n",ans1,ans2);
    
    return 0;
}
