#include <cstdio>

using namespace std;

char a[1000000];
int N,min;

int main(){
    scanf("%d",&N);
    
    for(int i = 0,x,y; i<N;++i){
        scanf("%d %d",&x,&y);
        a[i] = x+y;
    }
    
    for(int i = N-1;i>0;--i){
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
    
    for (int i = 0;i<N;++i) printf("%d",a[i]);
    
    return 0;
}
