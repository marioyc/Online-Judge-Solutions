#include<cstdio>

using namespace std;

int main(){    
    int n,x,pos,cont,cities;
    bool ok;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
                 
        for(int x=2;;x++){
            cities=n-1;
            pos=(x-1)%cities;
            ok=true;
            
            while(cities>1){
                if(pos==0){
                    ok=false;
                    break;
                }
                
                cities--;
                pos=(pos+x-1)%cities;
            }
            
            if(ok){
                printf("%d\n",x);
                break;
            }
        }
    }
    
    return 0;
}
