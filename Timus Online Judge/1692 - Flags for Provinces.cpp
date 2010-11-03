#include <cstdio>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    
    int lo = 1,hi = n,mi;
    
    while(lo!=hi){
        mi = (lo+hi+1)>>1;
        
        if(mi*(mi-1)/2>n) hi = mi-1;
        else lo = mi;
    }
    
    int k = lo;
    printf("%d\n",k);
    
    int M[100][100],cur = 1;
    
    for(int i = 0;i<k;++i) for(int j = i+1;j<k;++j){
        M[i][j] = M[j][i] = cur;
        ++cur;
    }
    
    for(int i = 0;i<k;++i){
        printf("%d",k-1);
        for(int j = 0;j<k;++j)
            if(j!=i) printf(" %d",M[i][j]);
        printf("\n");
    }
    
    return 0;
}
