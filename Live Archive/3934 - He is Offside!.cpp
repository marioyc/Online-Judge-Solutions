#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int A,D,x1[11],x2[11];
    
    while(true){
        scanf("%d %d",&A,&D);
        if(A==0) break;
        
        for(int i = 0;i<A;++i) scanf("%d",&x1[i]);
        for(int i = 0;i<D;++i) scanf("%d",&x2[i]);
        
        sort(x1,x1+A);
        sort(x2,x2+D);
        
        if(x1[0]<x2[1]) puts("Y");
        else puts("N");
    }
    
    return 0;
}
