#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,X,Y;
    
    scanf("%d %d %d",&N,&X,&Y);
    
    int M[N],B[N];
    
    for(int i=0;i<N;i++) scanf("%d %d",&M[i],&B[i]);
    
    sort(M,M+N);
    sort(B,B+N);
    
    int S=0;
    
    for(int i=0;i<N;i++)
        if(M[i]>B[i]) S+=Y*(M[i]-B[i]);
        else S+=X*(B[i]-M[i]);
    
    printf("%d\n",S);
    
    return 0;
}
