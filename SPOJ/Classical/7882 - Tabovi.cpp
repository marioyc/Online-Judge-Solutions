#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int A[N],B[N];
    for(int i = 0;i<N;++i) scanf("%d",&A[i]);
    for(int i = 0;i<N;++i) scanf("%d",&B[i]);
    
    int sum = 0,pos = 0,neg = 0;
    
    for(int i = N-1;i>=0;--i){
        int aux = B[i]-A[i]-sum;
        sum += aux;
        
        if(aux<0) neg -= aux;
        else pos += aux;
    }
    
    printf("%d\n",max(pos,neg));
    
    return 0;
}
