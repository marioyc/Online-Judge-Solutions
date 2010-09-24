#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int generator[100001];
    int aux,sum;
    
    fill(generator,generator+100001,0);
    
    for(int i=1;i<100000;i++){        
        sum=i;
        aux=i;
        while(aux!=0){
            sum+=aux%10;
            aux/=10;
        }
        
        if(sum<=100000 && generator[sum]==0) generator[sum]=i;
    }
    
    
    int T,N;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        printf("%d\n",generator[N]);
    }
    
    return 0;
}
