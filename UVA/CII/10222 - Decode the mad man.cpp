#include <iostream>
#include <string>

using namespace std ;

int main()
{
    string str ;
    char LINE[47] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 91, 93, 92,
                     'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 59, 39,
                     'z', 'x', 'c', 'v', 'b', 'n', 'm', 44, 46, 47,
                     '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 45, 61} ;
    
    while(getline(cin, str, '\n'))
    {
        for(int i = 0;i<str.size(); i++)
        {
            if((str[i] == ' ')||(str[i] == '\n'))
                cout << str[i] ;
            else
            {
                for(int j = 1; j < 47; j++)
                {
                    if(str[i] == LINE[j])
                    {
                        cout << LINE[j-2] ;
                        break ;
                    }
                }
            }
        }
        
        cout << endl ;
    }
    
    return 0 ;
}
