#include <cstdio>

using namespace std;

int main(){
    double sum = 0,x;
    
    for(int i = 0;i<12;++i){
        scanf("%lf",&x);
        sum += x;
    }
    
    printf("$%.2f\n",sum/12);
    
    return 0;
}
