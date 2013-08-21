#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
        string line;
    
    cin >> n;
    getline(cin,line);
    
    while(n--){
        getline(cin,line);
        
        int res = 0;
        
        if(line.size() >= 5){
            if(line.substr(line.size() - 5,5) == "lala.") res |= 1;
            if(line.substr(0,5) == "miao.") res |= 2;
        }
        
        if(res == 1) cout << "Freda's\n";
        else if(res == 2) cout << "Rainbow's\n";
        else cout << "OMG>.< I don't know!\n";
    }
    
    return 0;
}
