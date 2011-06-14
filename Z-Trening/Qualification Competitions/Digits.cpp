#include <cstdio>

using namespace std;

int sum_digits(int n){
    int ret = 0;
    
    while(n != 0){
        ret += n % 10;
        n /= 10;
    }
    
    return ret;
}

int main(){
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    int ans = 0;
    
    for(int i = 0;i <= N;++i)
        if(sum_digits(i) == K)
            ++ans;
    
    printf("%d\n",ans);
    
    return 0;
}
