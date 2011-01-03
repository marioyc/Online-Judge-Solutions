#include<iostream>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    double a,b,c,p,r;
    
    while(cin>>a>>b>>c){
        p=(a+b+c)/2+1e-8;
        r=sqrt((p-a)*(p-b)*(p-c)/p);
        
        printf("The radius of the round table is: %.3f\n",r);
    }
    
    return 0;
}
