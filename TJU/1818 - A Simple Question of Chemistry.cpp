#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    double prev,cur;
    cin>>cur;
    
    while(true){
        prev = cur;
        cin>>cur;
        if(cur>900) break;
        
        cout<<setprecision(2)<<fixed<<cur-prev<<'\n';
    }
    
    cout<<"End of Output\n";
    
    return 0;
}
