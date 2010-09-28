#include<iostream>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int R;
    double S1,S2;
    
    scanf("%d",&R);
    
    S1=PI*R*R;
    S2=2*R*R;
    
    printf("%.6f\n%.6f\n",S1,S2);
    
    return 0;
}
