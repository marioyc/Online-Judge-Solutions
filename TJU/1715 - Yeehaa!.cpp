#include<iostream>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){    
    double R,r;
    int T,n;
    
    cin>>T;
    
    for(int caso=1;caso<=T;caso++){
        printf("Scenario #%d:\n",caso);
        
        cin>>R>>n;
        r=R/(1+1/sin(PI/n));
        
        printf("%.3f\n\n",r);
    }
    
    return 0;
}
