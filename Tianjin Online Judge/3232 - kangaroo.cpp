#include <cstdio>

using namespace std;

#define max(a,b) a>b? a:b

int main(){
    int A,B,C;
    
    scanf("%d %d %d",&A,&B,&C);
    
    printf("%d\n",max(B-A-1,C-B-1));
    
    return 0;
}
