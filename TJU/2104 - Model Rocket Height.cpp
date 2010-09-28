#include<iostream>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){
    
    double D,H,a,b,c;
    int h;
    
    cin>>D>>H;
        
    while(1){
        cin>>a>>b>>c;
        if(a<=0||b<=0||c<=0) break;
        
        h=round(H+sqrt(2)*D/sqrt((1/(tan(a*PI/180)*tan(a*PI/180))+1/(tan(c*PI/180)*tan(c*PI/180))-2*1/(tan(b*PI/180)*tan(b*PI/180)))));
        cout<<h<<endl;
    }
}
