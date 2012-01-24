#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int sz[7163],enemies[7163][3];
    
    for(int i = 0;i < N;++i){
        scanf("%d",&sz[i]);
        
        for(int j = 0;j < sz[i];++j){
            scanf("%d",&enemies[i][j]);
            --enemies[i][j];
        }
    }
    
    int group[7163];
    memset(group,0,sizeof group);
    
    bool found = true;
    
    while(found){
        found = false;
        
        for(int i = 0,cont;i < N;++i){
            cont = 0;
            
            for(int j = 0;j < sz[i];++j)
                if(group[enemies[i][j]] == group[i])
                    ++cont;
            
            if(cont > 1){
                found = true;
                group[i] ^= 1;
            }
        }
    }
    
    int cont = 0,g = 0;
    
    for(int i = 0;i < N;++i)
        if(group[i] == 0)
            ++cont;
    
    if(cont > N - cont) g = 1, cont = N - cont;
    if(cont == N - cont) g = group[0];
    
    printf("%d\n",cont);
    
    for(int i = 0,j = 0;i < N;++i){
        if(group[i] == g){
            ++j;
            printf("%d%c",i + 1,j == cont? '\n' : ' ');
        }
    }
    
    return 0;
}
