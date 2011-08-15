#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int V,H;
    
    while(true){
        scanf("%d %d",&V,&H);
        if(V == -1) break;
        
        printf("%.6f\n",V / 9.8 * sqrt(2 * 9.8 * H + V * V));
    }
    
    return 0;
}
