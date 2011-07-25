#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int diff = 0;
    string line,s;
    
    while(getline(cin,line)){
        for(int i = line.size()-1;i >= 0;--i)
            if(!((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')))
                line[i] = ' ';
        
        istringstream is(line);
        
        while(is >> s){
            if(s == "tram") ++diff;
            else if(s == "trolleybus") --diff;
        }
    }
    
    if(diff > 0) cout << "Tram driver" << endl;
    else if(diff < 0) cout << "Trolleybus driver" << endl;
    else cout << "Bus driver" << endl;
    
    return 0;
}
