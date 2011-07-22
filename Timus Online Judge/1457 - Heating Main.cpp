#include <cstdio>

using namespace std;

int main(){
    int N,sum = 0;
    
    scanf("%d",&N);
    
    for(int i = 0,P;i < N;++i){
        scanf("%d",&P);
        sum += P;
    }
    
    printf("%.10f\n",(double)sum / N);
    
    return 0;
}
