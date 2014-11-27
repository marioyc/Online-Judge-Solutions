#include<iostream>
 
using namespace std;
 
main()
{
   int c, first = 0, second = 1, next,sum=0;
 
        do
        {
            next= first+ second;
            first = second;
            second =next ;

            if (next % 2 == 0)
                sum = sum + next;
    }
        while (next < 4000000);
   cout<<sum;
 
   return 0;
}
