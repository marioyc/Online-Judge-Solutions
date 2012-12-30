#include <cstdio>
#include <cstring>

using namespace std;

char s[11];
int cont[26][26];

int main(){
    int N,L;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%s",s);
        if(i == 0) L = strlen(s);
        ++cont[ s[0] - 'A' ][ s[L - 1] - 'A' ];
    }
    
    long long ans = 0;
    
    for(int i = 0;i < 26;++i){
        for(int j = 0;j < 26;++j){
            for(int i2 = 0;i2 < 26;++i2){
                for(int j2 = 0;j2 < 26;++j2){
                    int n = cont[i][j],m = cont[i2][j2];
                    --cont[i][j];
                    --cont[i2][j2];
                    
                    if(cont[i][j] >= 0 && cont[i2][j2] >= 0){
                        long long aux = (long long)n * ((i == i2 && j == j2)? n - 1 : m);
                        
                        if(cont[i][i2] > 0){
                            aux *= cont[i][i2];
                            --cont[i][i2];
                            
                            aux *= cont[j][j2];
                            ans += aux;
                            
                            ++cont[i][i2];
                        }
                    }
                    
                    ++cont[i][j];
                    ++cont[i2][j2];
                }
            }
        }
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
