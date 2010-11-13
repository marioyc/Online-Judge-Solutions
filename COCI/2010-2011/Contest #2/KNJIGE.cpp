#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int A[N];
    for(int i = 0;i<N;++i) scanf("%d",&A[i]);
    
    int pos = -1;
    for(int i = 0;i<N;++i) if(A[i]==N) pos = i;
    
    int cont = 0;
    for(int i = pos;i>=0;--i) if(A[i]==N-cont) ++cont;
    
    printf("%d\n",N-cont);
    
    return 0;
}
