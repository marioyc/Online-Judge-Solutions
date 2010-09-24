#include <iostream>

using namespace std;

int i,s1,s2,m;

bool es(int n){
    m=n;    
    s1=0;
    
    for(i=0;i<4;i++){
        s1+=m%10;
        m/=10;
    }
    
    m=n;
    s2=0;
    
    for(i=0;i<4;i++){
        s2+=m%12;
        m/=12;
    }
    
    if(s1!=s2) return false;
    
    m=n;
    s2=0;
    
    for(i=0;i<4;i++){
        s2+=m%16;
        m/=16;
    }
    
    if(s1!=s2) return false;
    return true;
}

int main(){
    freopen("out.txt","w",stdout);

    for(int j=2992;j<10000;j++)
        if(es(j)) cout<<j<<endl;

    return 0;
}
