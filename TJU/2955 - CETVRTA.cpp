#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int x1,x2,x3,y1,y2,y3;
    
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    
    if(x1==x2) cout<<x3;
    else if(x1==x3) cout<<x2;
    else cout<<x1;
    
    cout<<" ";
    
    if(y1==y2) cout<<y3;
    else if(y1==y3) cout<<y2;
    else cout<<y1;
    
    cout<<endl;
    
    return 0;
}
