#include <cstdio>

using namespace std;

int Q[1000006];

int main(){
    int total = 1000006,head = 0,tail = 0,cur,nxt;
    int dig[] = {0,1,2,5,6,8,9},inv[] = {0,1,2,-1,-1,5,9,-1,8,6};
    
    for(int i = 1;i<7;++i){
        Q[tail] = dig[i];
        ++tail;
    }
    
    while(tail<total){
        cur = Q[head];
        ++head;
        
        for(int i = 0;i<7;++i){
            nxt = cur*10+dig[i];
            Q[tail] = nxt; ++tail;
        }
    }
    
    int K;
    
    while(scanf("%d",&K)==1){
        int x = Q[K-1];
        
        while(x!=0){
            putchar('0'+inv[x%10]);
            x /= 10;
        }
        
        putchar('\n');
    }
    
    return 0;
}
