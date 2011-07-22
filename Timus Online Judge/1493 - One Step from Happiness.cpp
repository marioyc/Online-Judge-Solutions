#include <cstdio>

using namespace std;

bool test(int N){
    int s1 = 0,s2 = 0;
    
    for(int i = 0;i < 3;++i){
        s1 += N % 10;
        N /= 10;
    }
    
    for(int i = 0;i < 3;++i){
        s2 += N % 10;
        N /= 10;
    }
    
    return s1 == s2;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    if(test(N+1) || test(N-1)) puts("Yes");
    else puts("No");
    
    return 0;
}
