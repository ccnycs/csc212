// FILE: bag_demo.cxx
// This is a small demonstration program showing how the bag class is used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "bag1.h"      // With value_type defined as an int


// PROTOTYPES for functions used by this demonstration program:
void get_ages(bag& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bag, stopping
// when the bag is full or when the user types a negative number.

void check_ages(bag& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bag when it is typed,
// stopping when the bag is empty.


int main( )
{
    bag ages;

    get_ages(ages);
    check_ages(ages);
    std::cout << "May your family live long and prosper." << std::endl;
    return EXIT_SUCCESS;  
}


void get_ages(bag& ages)
{
    int user_input;

    std::cout << "Type the ages in your family." << std::endl;
    std::cout << "Type a negative number when you are done:" << std::endl;
    std::cin >> user_input;
    while (user_input >= 0)
    {
        if (ages.size( ) < ages.CAPACITY) 
            ages.insert(user_input);
        else 
	  std::cout << "I have run out of room and can�t add that age." << std::endl;
	std::cin >> user_input;
    }
}

void check_ages(bag& ages)
{
    int user_input;

    std::cout << "Type those ages again. Press return after each age:" << std::endl;
    while (ages.size( ) > 0)
    {
      std::cin >> user_input;
        if (ages.erase_one(user_input))
	  std::cout << "Yes, I've got that age and will remove it." << std::endl;
        else
	  std::cout << "No, that age does not occur!" << std::endl;   
    }
}
