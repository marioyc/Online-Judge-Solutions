#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    
    int fac=2;
    double s=2.5;
    
    cout<<0<<" "<<1<<endl;
    cout<<1<<" "<<2<<endl;
    cout<<2<<" "<<2.5<<endl;
    for(int i=3;i<=9;i++){
        fac*=i;
        s+=1*1.0/fac;
        cout<<i<<" "<<fixed<<setprecision(9)<<s<<endl;
    }


    return 0;
}
