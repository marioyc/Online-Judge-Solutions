#include <cstdio>

using namespace std;

int main(){
    int a,b,c,d;
    
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    double p1 = (double)a /b,p2 = (double)c/ d;
    
    printf("%.10f\n",p1 / (1 - (1 - p1) * (1 - p2)));
    
    return 0;
}
