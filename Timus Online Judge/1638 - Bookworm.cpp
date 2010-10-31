#include <cstdio>

using namespace std;

int main(){
    int w1,w2,n1,n2;
    scanf("%d %d %d %d",&w1,&w2,&n1,&n2);
    
    if(n1<=n2) printf("%d\n",(n2-n1)*2*w2+(n2-n1-1)*w1);
    else printf("%d\n",(n1-n2)*2*w2+(n1-n2+1)*w1);
    
    return 0;
}
