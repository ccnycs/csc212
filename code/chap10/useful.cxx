// FILE: useful.cxx
// IMPLEMENTS: A toolkit of functions (See useful.h for documentation.)

#include <cassert>    // Provides assert
#include <cctype>     // Provides toupper
#include <cstdlib>    // Provides rand, RAND_MAX
#include <iostream>   // Provides cout, cin, get
#include "useful.h"
using namespace std;

void display(double x)
// Library facilities used: iostream.h, stdlib.h
{
    const char STAR = '*';
    const char BLANK = ' ';
    const char VERTICAL_BAR = '|';
    const int  LIMIT = 39;
    int i;

    if (x < -LIMIT)
        x = -LIMIT;
    else if (x > LIMIT) 
        x = LIMIT;

    for (i = -LIMIT; i < 0; i++)
    {
        if (i >= x)
            cout << STAR;
        else
            cout << BLANK;
    }
    cout << VERTICAL_BAR;
    for (i = 1; i <= LIMIT; i++)
    {
        if (i <= x)
            cout << STAR;
        else
            cout << BLANK;
    }
    cout << endl;
}

double random_fraction( )
// Library facilities used: stdlib.h
{
    return rand( ) / double(RAND_MAX);
}

double random_real(double low, double high)
// Library facilities used: assert.h
{
    assert(low <= high);
    return low + random_fraction( ) * (high - low);
}

void eat_line( )
// Library facilities used: iostream.h
// 
{
    char next;

    do
        cin.get(next);
    while (next != '\n');
}

bool inquire(const char query[ ])
// Library facilities used: ctype.h, iostream.h
{
    char answer;
    do
    {
        cout << query << " [Yes or No]" << endl;
        cin >> answer;
        answer = toupper(answer);
        eat_line( );
    }
    while ((answer != 'Y') && (answer != 'N'));
    return (answer == 'Y');
}

