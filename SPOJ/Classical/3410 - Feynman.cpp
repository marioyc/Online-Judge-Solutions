#include <cstdio>

using namespace std;

int main(){
    int n;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        printf("%d\n",n*(n+1)/2*(2*n+1)/3);
    }
}
