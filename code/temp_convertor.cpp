// library imports
#include <cassert> // assert functions
#include <cstdlib> // EXIT_SUCCESS for portability
#include <iomanip> // Pretty formatting functions
#include <iostream> // cout (input and output)

// C to F conversion function
double celsius_to_fahrenheit(double c){
    //pre: c >= -273.15, post: f = c*(9/5) + 32
    const double MINIMUM_CELSIUS = -273.15; 
    if (c < MINIMUM_CELSIUS){ throw c; } 
    return (9.0/5.0) * c + 32;
}

// Set up the pretty number printing
void setup_cout_fractions(int fraction_digits){
    if (fraction_digits < 0){ throw fraction_digits; }
    std::cout.precision(fraction_digits);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);
    if (fraction_digits == 0){
        std::cout.unsetf(std::ios::showpoint);
        }
}

// let's make a function to print the table:
void print_temperature_table(double start, double stop, double increment, 
                             const int WIDTH, const int DIGITS){
    const char SEP[] = "    ";
    setup_cout_fractions(DIGITS);
    
    std::cout<< "Celsius" << SEP <<"Fahrenheit" << std::endl;
    
    for(double celsius = start; celsius <= stop; celsius+=increment){
        std::cout<< std::setw(WIDTH) << celsius << "C°" << SEP;
        std::cout<< std::setw(WIDTH) << celsius_to_fahrenheit(celsius) <<"F°"<<std::endl;
    }
}

// lets call the functions we wrote (put the program together)
int main(){
    const int DIGITS = 2;
    const int WIDTH = 7;
    //optimally these would be user input, but limited by (jupyter environment)

    double start, stop, increment;
    std::cout<<"What is the starting temperature? ";
    std::cin>>start;
    std::cout<<"What is the final temperature? ";
    std::cin>>stop;
    std::cout<<"How many degrees is the temperature increasing by? ";
    std::cin>>increment;
    print_temperature_table(start, stop, increment, WIDTH, DIGITS);

    return EXIT_SUCCESS;
}