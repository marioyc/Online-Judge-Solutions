#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    string line;
    
    getline(cin,line);
    
    istringstream is(line);
    
    int h;
    
    while(is >> h){
        if(h < 168){
           cout << "CRASH " << h << endl;
            return 0;
        }
    }
    
    cout << "NO CRASH" << endl;
    
    return 0;
}
