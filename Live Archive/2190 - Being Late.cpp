#include <cstdio>

using namespace std;

int main(){
    int N,h1,m1,h2,m2,sum;
    
    while(scanf("%d",&N)==1){
        sum=0;
        
        for(int i=0;i<N;i++){
            scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
            
            if(h2==h1+1){
                m2+=60;
                sum+=m2-m1;
            }else if(m2>m1) sum+=m2-m1;
        }
        
        printf("%d\n",sum/N);
    }
    
    return 0;
}
