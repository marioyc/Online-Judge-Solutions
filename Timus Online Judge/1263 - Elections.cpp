#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    
    int cont[10000];
    memset(cont,0,sizeof(cont));
    
    for(int i = 0,x;i<M;++i){
        scanf("%d",&x);
        ++cont[--x];
    }
    
    for(int i = 0;i<N;++i)
        printf("%.2lf%c\n",cont[i]*100.0/M,'%');
    
    return 0;
}
