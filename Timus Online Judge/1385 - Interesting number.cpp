#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    if(N==1) printf("14");
    else if(N==2) printf("155");
    else{
        printf("1575");
        for(int i = 3;i<N;++i) putchar('0');
    }
    
    return 0;
}
