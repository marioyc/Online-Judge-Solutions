#include<iostream>

using namespace std;

int main(){
    double r[10][4];
    int n=0,n2=0;
    char c;
    double x,y;
    bool contained;
    
    while(1){
        cin>>c;
        if(c=='*') break;
        
        if(c=='r'){
            cin>>r[n][0]>>r[n][1]>>r[n][2]>>r[n][3];
            n++;
        }
    }
    
    while(1){
        cin>>x>>y;
        if(x==9999.9 && y==9999.9) break;
        
        n2++;
        
        contained=false;
        
        for(int i=0;i<n;i++)
            if(x>r[i][0] && x<r[i][2] && y<r[i][1] && y>r[i][3]){
                cout<<"Point "<<n2<<" is contained in figure "<<i+1<<endl;
                contained=true;
            }
        
        if(!contained) cout<<"Point "<<n2<<" is not contained in any figure"<<endl;
    }
    
    return 0;
}
