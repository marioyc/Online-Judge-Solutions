#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N1,C1,N2,T,C2,N3,K,mm,ss,total = 0;
    
    scanf("%d %d %d %d %d %d %d",&N1,&C1,&N2,&T,&C2,&N3,&K);
    
    while(K--){
        scanf("%d:%d",&mm,&ss);
        if(mm == 0 && ss <= 6) continue;
        
        total += mm;
        if(ss != 0) ++total;
    }
    
    printf("Basic:     %d\n",N1 + C1 * total);
    printf("Combined:  %d\n",N2 + C2 * max(0,total - T));
    printf("Unlimited: %d\n",N3);
    
    return 0;
}
