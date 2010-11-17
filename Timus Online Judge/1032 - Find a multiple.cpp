#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,A[10000],used[10000];
    scanf("%d",&N);
    
    memset(used,-1,sizeof(used));
    
    for(int i = 0;i<N;++i) scanf("%d",&A[i]);
    
    int sum = 0;
    used[0] = 0;
    
    for(int i = 0;i<N;++i){
        sum += A[i];
        
        if(used[sum%N]!=-1){
            printf("%d\n",i-used[sum%N]+1);
            for(int j = used[sum%N];j<=i;++j)
                printf("%d\n",A[j]);
            break;
        }else{
            used[sum%N] = i+1;
        }
    }
    
    return 0;
}
