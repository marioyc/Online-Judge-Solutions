#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
    
    double x,y;
    double dist;
    int t[2];
    string s;
    bool ok=true;
    
    while(true){
        t[0]=0;
        t[1]=0;
        
        for(int i=0;i<6;i++){
            cin>>x>>y;
            
            if(x==-100){
                ok=false;
                break;
            }
            
            dist=x*x+y*y;
            
            if(dist<=9) t[i/3]+=100;
            else if(dist<=36) t[i/3]+=80;
            else if(dist<=81) t[i/3]+=60;
            else if(dist<=144) t[i/3]+=40;
            else if(dist<=225) t[i/3]+=20;
        }
        
        if(!ok) break;
        
        if(t[0]==t[1]) cout<<"SCORE: "<<t[0]<<" to "<<t[1]<<", TIE."<<endl;
        else cout<<"SCORE: "<<t[0]<<" to "<<t[1]<<", PLAYER "<<(t[0]>t[1] ? 1 : 2)<<" WINS."<<endl;
    }
    
    return 0;
}  
