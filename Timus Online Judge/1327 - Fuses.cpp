#include <cstdio>

using namespace std;

int main(){
    int A,B;
    scanf("%d %d",&A,&B);
    
    if(A%2==0) ++A;
    if(B%2==0) --B;
    
    printf("%d\n",(B-A)/2+1);
    
    return 0;
}
