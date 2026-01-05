#include <iostream>
#include <math.h>

using namespace std;
 
int main() {
 
int sum=2;
 
int s;
for ( s=3;s<2000000;s+=2)
{
    bool is_prime = true;
 
    for (int i = 2; i <= sqrt(s); i++)
    {
 
        if (s % i == 0)
            is_prime = false;
    }
    if (is_prime)
    {
 
        sum=sum+s;
 
    }
 

}
cout <<sum;
 

return 0;
}
 
