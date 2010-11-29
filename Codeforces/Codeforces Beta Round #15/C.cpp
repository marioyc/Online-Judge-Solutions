#include <cstdio>

using namespace std;

long long f(long long x){
    if(x%4==0) return x;
    if(x%4==1) return 1;
    if(x%4==2) return x+1;
    return 0;
}

int main(){
    int N;
    scanf("%d",&N);
    
    long long nim = 0,x,m;
    
    for(int i = 0;i<N;++i){
        scanf("%I64lld %I64lld",&x,&m);
        nim ^= f(x+m-1)^f(x-1);
    }
    
    if(nim) puts("tolik");
    else puts("bolik");
    
    return 0;
}
