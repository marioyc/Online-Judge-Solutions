#include <cstdio>

using namespace std;

int f[77];

int main(){
    f[1] = f[2] = 1;
    
    for(int i = 3;i <= 76;++i)
        f[i] = f[i - 2] + f[i - 3];
    
    int n;
    
    while(scanf("%d",&n) == 1)
        printf("%d\n",f[n] + f[n - 1]);
    
    return 0;
}
