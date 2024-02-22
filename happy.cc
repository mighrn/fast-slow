#pragma once

#include <cmath>
#include <iostream>

using namespace std;

///take each digit, square it, then sum all results
int transform(int input)
{
    int digit = input;

    int sum = 0;
    while (input > 0)
    {
        //side note: this extracts digits in reverse order
        digit = input % 10;
        sum += pow(digit, 2);
        input /= 10;
    }

    return sum;
}

bool isHappy(int const & n)
{
    //start with an offset of one step
    //if slow starts at i, fast starts at i + 1
    int slow = n;
    int fast = transform(slow);

    bool iterate = true;
    bool result = false;
    while (iterate)
    {
        if (fast == slow)
        {
            iterate = false;
            result = false;
        }
        else if (fast == 1)
        {
            iterate = false;
            result = true;
        }
        else
        {
            //iterate slow by one step ()
            //iterate fast by two steps ()
            slow = transform(slow);
            cout << '<' << slow << ' ';
            fast = transform(transform(fast));
            cout << fast << "> ";
        }
    }
    
    cout << endl;
    return result;
}
