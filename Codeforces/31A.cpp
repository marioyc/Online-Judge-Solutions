#include <cstdio>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    int a[n];
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            for(int k = 0;k < n;++k){
                if(j != i && k != i && k != j && a[i] == a[j] + a[k]){
                    printf("%d %d %d\n",i + 1,j + 1,k + 1);
                    return 0;
                }
            }
        }
    }
    
    printf("-1\n");
    
    return 0;
}
