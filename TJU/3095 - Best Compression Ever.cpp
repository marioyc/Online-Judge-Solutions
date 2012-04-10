#include <cstdio>

using namespace std;

int main(){
    long long N;
    int b;
    
    scanf("%lld %d",&N,&b);
    
    puts((1LL << (b + 1)) - 1 >= N? "yes" : "no");
    
    return 0;
}
