#include <iostream>

using namespace std;

/*where n is the number of rows of the painting, and m is the number of columns of the painting.
c is always 0 or 1, where 0 indicates that the bottom right corner of the painting is black,
and 1 indicates that this corner is white.*/

int n,m,c;
int a,b,i,j;

int f(int x, int y){
    
    a=0; b=0;
    i=x-1;
    while(i>=7){
        i-=2;
        a++;
    }
            
    j=y-1;
    while(j>=7){
        j-=2;
        b++;
    }
    
    return a*b;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while(1){
        scanf("%d %d %d",&n,&m,&c);
        if(n==0 && m==0 && c==0) break;
        
        if(c==0){
            int tot=f(n-1,m)+f(n,m-1);
            cout<<f(n-1,m)+f(n,m-1)<<endl;
        }
        else cout<<f(n,m)+f(n-1,m-1)<<endl;
    }
    
    return 0;
}
