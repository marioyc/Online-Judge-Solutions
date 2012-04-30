#include <cstdio>

using namespace std;

int main(){
    int N,sum = 0,a;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%d",&a);
        sum += a;
    }
    
    printf("%d\n",sum / N);
    
    return 0;
}
