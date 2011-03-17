#include <cstdio>

using namespace std;

int main(){
    int N,A;
    double x,y;
    
    while(true){
        scanf("%d %d",&N,&A);
        if(N == 0) break;
        
        int cont = 0,R2 = A*A;
        
        for(int i = 0;i<N;++i){
            scanf("%lf %lf",&x,&y);
            
            bool valid = true;
            
            if((x-0)*(x-0)+(y-0)*(y-0)>R2) valid = false;
            if((x-0)*(x-0)+(y-A)*(y-A)>R2) valid = false;
            if((x-A)*(x-A)+(y-0)*(y-0)>R2) valid = false;
            if((x-A)*(x-A)+(y-A)*(y-A)>R2) valid = false;
            
            if(valid) ++cont;
        }
        
        printf("%.5f\n",(double)cont*(A*A)/N);
    }
    
    return 0;
}
