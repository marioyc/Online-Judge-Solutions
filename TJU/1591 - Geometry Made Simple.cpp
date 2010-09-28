#include<iostream>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int a,b,c,test_case=1;
    
    while(1){
        scanf("%d %d %d",&a,&b,&c);
        
        if(a==0 && b==0 && c==0) break;
        
        printf("Triangle #%d\n",test_case);
        test_case++;
        
        if(a==-1){
            if(c<b) printf("Impossible.\n\n");
            else printf("a = %.3f\n\n",sqrt(c*c-b*b));
        }else if(b==-1){
            if(c<a) printf("Impossible.\n\n");
            else printf("b = %.3f\n\n",sqrt(c*c-a*a));
        }else printf("c = %.3f\n\n",sqrt(a*a+b*b));
    }

    return 0;
}
