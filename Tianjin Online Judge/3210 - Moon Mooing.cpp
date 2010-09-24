#include <cstdio>

using namespace std;

long long T[4000001];

int main(){
    int c,N,a1,b1,d1,a2,b2,d2;
    
    scanf("%d %d",&c,&N);
    scanf("%d %d %d",&a1,&b1,&d1);
    scanf("%d %d %d",&a2,&b2,&d2);
    
    T[1]=c;
    int Tsize=1,p1=1,p2=1;
    long long next1=a1*c/d1+b1,next2=a2*c/d2+b2;
    
    while(Tsize!=N){
        if(next1<next2){
            if(next1 != T[Tsize]) T[++Tsize]=next1;
            next1=a1*T[++p1]/d1+b1;
        }else{
            if(next2 != T[Tsize]) T[++Tsize]=next2;
            next2=a2*T[++p2]/d2+b2;
        }
    }
    
    printf("%lld\n",T[N]);
    
    return 0;
}
