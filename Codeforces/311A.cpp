#include <cstdio>

using namespace std;

int main(){
    int n,k;
    
    scanf("%d %d",&n,&k);
    
    if(k >= n * (n - 1) / 2) printf("no solution\n");
    else{
        for(int i = 0;i < n;++i)
            printf("0 %d\n",i);
    }
    
    return 0;
}
