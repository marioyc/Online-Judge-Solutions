#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,n;
    double c[3000];
    double a,b,a1;
    double S;
    
    cin>>T;
    
    for(int caso=0;caso<T;caso++){
        cin>>n;
        
        cin>>a>>b;
        for(int i=0;i<n;i++) cin>>c[i];
        
        S=0;
        for(int i=0;i<n;i++) S+=2*(n-i)*c[i];
        
        a1=(n*a+b-S)/(n+1);
        
        printf("%.2f\n",a1);
        
        if(caso!=T-1) printf("\n");
    }
        
    return 0;
}
