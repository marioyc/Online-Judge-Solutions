#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int h[50];
    int n,prom,min,caso=1;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",&h[i]);
        
        prom=0;
        for(int i=0;i<n;i++) prom+=h[i];
        prom/=n;
        
        min=0;
        for(int i=0;i<n;i++)
            if(h[i]>prom) min+=h[i]-prom;
            
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",caso,min);
        caso++;
    }

    return 0;
}
