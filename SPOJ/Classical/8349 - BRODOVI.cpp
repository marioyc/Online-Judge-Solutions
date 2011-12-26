#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int a[N];
    
    for(int i = 0;i < N;++i){
        scanf("%d",&a[i]);
        --a[i];
    }
    
    bool done[N];
    
    memset(done,false,sizeof done);
    
    int ans = 0;
    
    for(int i = 1;i < N;++i){
        if(!done[i]){
            for(int j = i,k = a[i];j < N;j++){
                if(a[j] == k){
                    done[j] = true;
                    k += a[i];
                }
            }
            
            ++ans;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
