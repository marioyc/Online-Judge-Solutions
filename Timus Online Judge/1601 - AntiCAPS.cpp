#include <cstdio>

using namespace std;

int main(){
    char c;
    bool first = true;
    
    while((c = getchar()) != EOF){
        if(c == '.' || c == '!' || c == '?'){
            putchar(c);
            first = true;
        }else{
            if(c >= 'a' && c <= 'z'){
                if(first) putchar(c - 'a' + 'A');
                else putchar(c);
                first = false;
            }else if(c >= 'A' && c <= 'Z'){
                if(first) putchar(c);
                else putchar(c - 'A' + 'a');
                first = false;
            }else putchar(c);
        }
    }
    
    return 0;
}
