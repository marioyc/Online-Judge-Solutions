#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    int a[N],b[M];
    
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    for(int i=0;i<M;i++) scanf("%d",&b[i]);
    
    sort(a,a+N);
    sort(b,b+M);
    
    int cont=N;
    
    for(int i=0,j=0;i<M;i++){
        while(j<N && a[j]<=b[i]) j++;
        
        if(j==N) break;
        
        cont++; j++;
    }
    
    printf("%d\n",cont);
    
    return 0;
}
