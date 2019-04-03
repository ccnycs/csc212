// FILE: useful.h
// PROVIDES: A toolkit of useful functions for random numbers and displays.
// Note that these are in the global namespace.
//
// FUNCTIONS in the toolkit:
//   double random_fraction( )
//     Postcondition: The return value is a random real number in the closed
//     interval [0..1] (including the endpoints).
//
//   double random_real(double low, double high)
//     Precondition: low <= high.
//     Postcondition: The return value is a random real number in the closed
//     interval [low..high] (including the endpoints).
//
//   void display(double x)
//     Postcondition: The function has written one line of output to the
//     standard ouput, with a vertical bar in the middle. If x is positive,
//     then approximately x stars are printed to the right of the vertical
//     bar. If x is negative, then approximately -x stars are printed to the
//     left of the vertical bar. If the absolute value of x is more than
//     39, then only 39 stars are printed.
//     Examples:
//     display(8) prints:                          |********
//     display(-4) prints:                     ****|
//
//   void eat_line( )
//     Postcondition: Up to next newline has been read and discarded from cin.
//
//   bool inquire(const char query[ ])
//     Precondition: query is a null-terminated string of characters.
//     Postcondition: query has been printed, and a one-line response read 
//     from the user. The function returns true if the user's response begins 
//     with 'Y' or 'y', and returns false if the user's response begins with 
//     'N' or 'n'. (If the response begins with some other letter, then the
//     query is repeated.)

#ifndef USEFUL_H  // Prevent duplicate definition
#define USEFUL_H

    double random_fraction( );
    double random_real(double low, double high);
    void display(double x);
    void eat_line( );
    bool inquire(const char query[ ]);

#endif
