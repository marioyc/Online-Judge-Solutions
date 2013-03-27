#include <cstdio>

using namespace std;

int main(){
    printf("302\n");
    printf("0 500000\n");
    
    for(int i = 300,pos = 454850;i >= 1;--i){
        printf("%d %d\n",pos + i,i);
        pos += 2 * i;
    }
    
    printf("1000000 600000\n");
}
