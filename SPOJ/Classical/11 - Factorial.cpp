#include <cstdio>

using namespace std;

int main(){    
    int M[12]={5,25,125,625,3125,15625,78125,390625,1953125,9765625,48828125,244140625};
    
    int T,N,cont;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        cont=0;
        
        for(int j=0;j<12;j++) cont+=N/M[j];
        
        printf("%d\n",cont);
    }
    
    return 0;
}
