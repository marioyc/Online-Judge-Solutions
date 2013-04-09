#include <cstdio>

using namespace std;

int main(){
    int vp,vd,t,f,c;
    
    scanf("%d %d %d %d %d",&vp,&vd,&t,&f,&c);
    
    if(vp > vd) printf("0\n");
    else{
        double tp = (double)c / vp,tcur = 0;
        int cont = 0;
        
        while(true){
            if(cont == 0) tp -= t,tcur += t;
            else tp -= f,tcur += f;
            
            if(tp <= 0) break;
            
            double tcatch = (tcur * vp) / (vd - vp);
            tp -= tcatch;
            tcur += tcatch;
            
            if(tp <= 0) break;
            
            tp -= tcatch;
            tcur += tcatch;
            
            ++cont;
        }
        
        printf("%d\n",cont);
    }
    
    return 0;
}
