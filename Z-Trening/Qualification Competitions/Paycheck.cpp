#include <cstdio>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int total = 0,cont = 0;
    
    for(int i = 0,a,p;i < N;++i){
        scanf("%d %d",&a,&p);
        
        total += a * p;
        cont += a;
    }
    
    printf("%.2f\n",(double)total / cont);
    
    return 0;
}
