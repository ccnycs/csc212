/*
This was written by call number 1.
    This was written by call number 2.
        This was written by call number 3.
             This was written by call number 4.
             This ALSO written by call number 4.
        This ALSO written by call number 3.
    This ALSO written by call number 2.
This ALSO written by call number 1.
*/

/*base:
This was written by call number 1.
This ALSO written by call number 1.
*/
#include <iostream>

using namespace std;

void print_tab(int k)
{
    if(k <= 0)
    {
        return;
    }
    else
    {
        cout << "\t";
        print_tab(k-1);
    }
}

void print_tree(int n, int cnt)
{

    if (n==0)
    {
        return ;
    }

    int call_num = cnt;
    cnt++;

    print_tab(call_num);
    std::cout<<"This was written by call number "<<cnt<<std::endl;

    print_tree(n-1, cnt);

    print_tab(call_num);
    std::cout<<"This ALSO written by call number "<<cnt<<std::endl;

}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    print_tree(num, 0);
    return 0;
}
