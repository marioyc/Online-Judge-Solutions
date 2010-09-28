#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int B,N,A;
    double x,ans;
    
    while(1){
        cin>>B>>N;
        if(B==0 && N==0) break;
        
        ans=-1000000.0;
        
        for(int i=floor(pow(B*1.0,1.0/N))-1;;i++){
            x=pow(i*1.0,N*1.0);
            
            if(x>B){
                if(fabs(x-B)<fabs(ans-B)){
                    A=i;
                    ans=x;
                }
                break;
            }else{
                if(fabs(x-B)<fabs(ans-B)){
                    A=i;
                    ans=x;
                }
            }
        }
        
        cout<<A<<endl;
    }
    
    return 0;
}
