#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int C,N,above_average;
    int nota[1000];
    double prom;
    
    scanf("%d",&C);
    
    for(int caso=1;caso<=C;caso++){
        scanf("%d",&N);
        
        prom=0;
        
        for(int i=0;i<N;i++){
            scanf("%d",&nota[i]);
            prom+=nota[i];
        }
        prom/=N;
        
        above_average=0;
        
        for(int i=0;i<N;i++)
            if(nota[i]>prom) above_average++;
            
        printf("%.3f%c\n",above_average*100.0/N,'%');
    }

    return 0;
}
