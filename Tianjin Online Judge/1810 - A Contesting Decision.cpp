#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct team{
    string name;
    long long solved, penalty;
    
    team(){
    }
    
    bool operator < (team X) const{
        if(solved!=X.solved) return solved>X.solved;
        return penalty<X.penalty;
    }
};

int main(){    
    int n;
    
    cin>>n;
    
    team a[n];
    int num, time;
    
    for(int i=0;i<n;i++){
        cin>>a[i].name;
        
        a[i].solved=0;
        a[i].penalty=0;
        
        for(int j=0;j<4;j++){
            cin>>num>>time;
            
            if(time != 0){
                a[i].solved++;
                
                a[i].penalty+=time+20*(num-1);
            }
        }
    }
    
    sort(a,a+n);
    
    cout<<a[0].name<<" "<<a[0].solved<<" "<<a[0].penalty<<endl;
    
    return 0;
}
