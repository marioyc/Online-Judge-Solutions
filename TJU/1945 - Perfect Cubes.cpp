#include <iostream>

using namespace std;

int cubo[201];

int main(){

    int s,d;

    for(int i=0;i<201;i++) cubo[i]=i*i*i;
    
    for(int a=2;a<201;a++){
        s=0;
        for(int b=2;3*cubo[b]<=cubo[a];b++){
            s+=cubo[b];
            for(int c=b;2*cubo[c]<=(cubo[a]-cubo[b]);c++){
                s+=cubo[c];
                
                d=c;                
                while(s+cubo[d]<cubo[a]) d++;
                s+=cubo[d];
                if(s==cubo[a]) cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
                s-=(cubo[c]+cubo[d]);
            }
            s-=cubo[b];
        }
    }

    return 0;
}
