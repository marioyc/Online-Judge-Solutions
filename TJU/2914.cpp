#include <cstdio>

using namespace std;

int main(){
    int d,num,dem;
    double p1,p2,p3,p4;
    
    for(int a=1;a<=500;++a){
        for(int b=a;a+b<=1000;++b){
            for(int c=b;a+b+c<=1500;++c){
                num = 1000000*(a+b+c); dem = a*b*c-1000000;
                if(dem<=0 || num%dem!=0) continue;
                d = num/dem;
                if(c<=d && a+b+c+d<=2000){
                    p1 = a/100.0; p2 = b/100.0; p3 = c/100.0; p4 = d/100.0;
                    printf("%.2lf %.2lf %.2lf %.2lf\n",p1,p2,p3,p4);
                }
            }
        }
    }
    
    return 0;
}
