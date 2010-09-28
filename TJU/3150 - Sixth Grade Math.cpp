#include<cstdio>
#include<algorithm>

using namespace std;

int MCD(int a, int b){
    while(a%b!=0){
        a%=b;
        swap(a,b);
    }
    
    return b;
}

int main(){    
    int N,a,b,mcd,lcm;
    
    scanf("%d",&N);
    
    for(int i=1;i<=N;i++){
        scanf("%d %d",&a,&b);
        
        mcd=MCD(a,b);
        lcm=a/mcd*b;
        
        printf("%d %d %d\n",i,lcm,mcd);
    }
    
    return 0;
}
