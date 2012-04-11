#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    printf("%.10f\n",N * (1 - pow(1 - 1.0 / N,M)));
    
    return 0;
}
