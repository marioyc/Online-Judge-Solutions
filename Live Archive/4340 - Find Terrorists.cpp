#include <iostream>
#include <algorithm>

using namespace std;

int main(){    
    bool p[10001];
    fill(p,p+10001,true);
    
    p[0]=p[1]=false;
    
    for(int i=2;i<10001;i++){
        if(!p[i]) continue;
        
        for(int j=i*i;j<10001;j+=i) p[j]=false;
    }
    
    int a[]={4,9,16,25,49,64,81,121,169,289,361,529,625,729,841,961,1024,1369,1681,1849,2209,2401,2809,3481,3721,4096,4489,5041,5329,6241,6889,7921,9409};
    
    bool print[10001];
    fill(print,print+10001,false);
    
    for(int i=1;i<=10000;i++) print[i]=p[i];
    
    for(int i=0;i<33;i++) print[a[i]]=true;    
    
    int T;
    cin>>T;
    
    int L,H;
    bool start;
    
    for(int tc=1;tc<=T;tc++){
        cin>>L>>H;
        
        start=true;
        
        for(int i=L;i<=H;i++){
            if(print[i]){
                if(start) start=false;
                else cout<<" ";
                cout<<i;
            }
        }
        
        if(start) cout<<-1;
        
        cout<<endl;
    }
    
    return 0;
}
