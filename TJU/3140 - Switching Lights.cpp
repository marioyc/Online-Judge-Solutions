#include<iostream>
#include<algorithm>

using namespace std;

int main(){    
    int N,M,command,a,b;
    
    scanf("%d %d",&N,&M);
        
    int light[N+1];
    fill(light,light+N+1,0);
    
    for(int i=0;i<M;i++){
        scanf("%d %d %d",&command,&a,&b);
        
        if(command==1) printf("%d\n",count(light+a,light+b+1,1));
        else for(int j=a;j<=b;j++) light[j]^=1;
    }
}
