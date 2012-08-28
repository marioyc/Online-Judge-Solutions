#include <cstdio>

using namespace std;

int main(){
    int T,N,p;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&p);
        
        puts(p == 0? "Airborne wins." : "Pagfloyd wins.");
    }
    
    return 0;
}
