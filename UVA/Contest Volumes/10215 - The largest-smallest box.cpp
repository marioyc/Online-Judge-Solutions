#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    double L,W;
    double max,min1=0,min2;
    
    while(cin>>L>>W){
        max=(W+L-sqrt(W*W-W*L+L*L))/6;
        min2=fmin(W,L)/2+1e-8;
        printf("%.3f %.3f %.3f\n",max,min1,min2);
    }
    
    return 0;
}
