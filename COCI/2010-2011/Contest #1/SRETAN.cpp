#include <cstdio>

using namespace std;

int numOfDigits(int K){
    int aux = 0;
    
    for(int i = 1;i<29;++i){
        aux |= (1<<i);
        if(aux>=K) return i;
    }
    
    return 29;
}

int main(){
    int K;
    scanf("%d",&K);
    
    int D = numOfDigits(K);
    for(int i = 1;i<D;++i) K -= (1<<i);
    
    for(int i = 0;i<D;++i){
        if(K<=(1<<(D-i-1))) putchar('4');
        else{
            putchar('7');
            K -= (1<<(D-i-1));
        }
    }
    
    putchar('\n');
    
    return 0;
}
