# Summary Chapter 1-Chapter 4

## Chapter 1: Software development:
* iterative test driven cycle
* specifications, pre/post conditions, invariant
* invariant - thing that must be true after code is run
* informal runtime analysis/memory complexity

## Chapter 2: Abstract Data Type & Classes
* Declaration (.h file)
    ```cpp
    class Point{
        //class methods and members here
    }
    ```
* Attributes/Members - metadata/variables 
    - int x;
    - int y;
    - formally:
    ```cpp
    class Point{
        private:
            int x;
            int y;
        public:
            
    }
    ```
* methods/ member functions
    - int get_x();
    - int get_y();
    - formally:
    ```cpp
    class Point{
        private:
            int x;
            int y;
        public:
            * int get_x();
            * int get_y();
    }
    ```
* constructor
    - empty constructor: point()
    - constructor: point(int nx, int ny)
        ```cpp
        point(int nx, int ny){
            x = nx;
            y = ny;
            }
        ```
* inline functions:
    ```cpp 
    class Point{
        private:
            int x;
            int y;
        public:
            Point(){};
            Point(int nx, int ny){x=nx; y=ny;}
            get_x(){return x;}
            get_y(){return y;}
    }
    ```
* public vs private members
    - private: access via class methods
    - public: access via any method 
* getters & setters: give public access to private attributes
    - `get_x()` - returns the private value x
    - `set_x(int nx)` - changes the private value x
* operator overloading
    - +-<>etc for objects
* `const` - do not change
    - const variables - can't be reassigned
    - const member functions - don't change object attributes/even indirectly
* `typedef` - templeting types
* implement methods of a class:
    ```cpp
        Point::distance(Point& P){
            //implement here
        }
    ```
    function `distance` is a member of class `Point`
* default arguments:
    ```cpp
        Point::Point(int nx=0, int ny=0)
    ```
    - if all args have default, don't need empty constructor
    - uses assigned values, (0,0) as values
    when function called as `Point P()`
* references/pass by value
    - value: `int f(int x){return x+1;}`
    ```cpp
        int y = 4;
        f(y);//copy of y, just the value 4
        //y = 4
    ```
    - reference: `void f(int &x){x+1;}`
        ```cpp
        int y = 4;
        f(y);//pointer address of y
        //y = 5 because changed in place
    ``` 
* exceptions-stop execution
    - trigger with `throw`
    - `catch` to suppress exceptions
        +  can catch generic type, or std::library exceptions
    - throw value or exceptions defined in standard library

* files: point library, test application
    - Point.h - header : declarations
    - Point.cpp : implementations
    - test.cpp/main.cpp: test the Point library

## Chapter 3: Container Class:
* what are containers?
    + class that stores data
        - methods for getting stuff in, out, searching, etc
    + container vs array?
        - bag - holds stuff
        - sequence - stuff + order
* Bag - what, why, when, 
    + implement the bag: insert, remove, get, count, length, 
        copy, concatenate (combine two objects)
    + pros/cons of static, dynamic, linked list

## Chapter 4: Pointers/dynamic arrays
* memory:
    - __heap__ memory set aside for allocating on the fly
    - __stack__ memory set aside for an execution thread
* pointers
    - __address operator &__ *where* the address of the variable
    - __indirection operator *__ *what* the value stored at that address
* dynamic memory:
    - __new__ allocates on fly
    ```cpp
    int size;
    std::cin>>size;
    double *ptr;//make a pointer to a double
    ptr = new double[size]; //create an array named ptr
    ptr[0] = 5; //place 5 in index 0 of ptr array
    ```