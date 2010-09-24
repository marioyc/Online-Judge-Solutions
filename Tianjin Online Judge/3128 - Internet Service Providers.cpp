#include <cstdio>

using namespace std;

int main(){
    int N,C,t1,t2;
    long long f1,f2;
    
    while(scanf("%d %d",&N,&C)==2){
        if(N==0) printf("0\n");
        else{
            t1=C/(2*N); t2=(C+2*N-1)/(2*N);
            f1=(long long)t1*(C-N*t1); f2=(long long)t2*(C-N*t2);
            if(f1>=f2) printf("%d\n",t1);
            else printf("%d\n",t2);
        }
    }
    
    return 0;
}
