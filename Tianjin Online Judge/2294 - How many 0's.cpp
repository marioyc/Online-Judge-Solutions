#include <cstdio>

using namespace std;

long long count(long long &x){
    if(x<0) return 0;
    
    long long cont=1,y=1;
    
    while(x/y!=0){
        if((x/y)%10==0) cont+=x%y+1+(x-10*y)/(10*y)*y;
        else cont+=x/(10*y)*y;
        
        y*=10;
    }
    
    return cont;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    long long m,n;
    
    while(1){
        scanf("%lld %lld",&m,&n);
        if(m<0) break;
        
        m--;        
        printf("%lld\n",count(n)-count(m));
    }
    
    return 0;
}
