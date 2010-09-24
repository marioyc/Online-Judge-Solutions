#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,X1,Y1,X2,Y2,X3,Y3,X4,Y4;
    
    cin>>T;
    
    for(int i=0;i<T;i++){
        cin>>X1>>Y1>>X3>>Y3>>X2>>Y2>>X4>>Y4;
        
        if(X1+X3==X2+X4 && Y1+Y3==Y2+Y4) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}
