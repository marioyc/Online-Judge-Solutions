#include<cstdio>
#include<cmath>

using namespace std;

int main(){
    unsigned int n;
    unsigned int x;
    
    while(1){
        scanf("%u",&n);
        if(n==0) break;
        
        x=sqrt(n);
        
        if(n==x*x) printf("yes\n");
        else printf("no\n");
    }
    
    return 0;
}
