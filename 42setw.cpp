#include <ios> //for streamsize
#include <iostream> // cout, endl
#include <iomanip>  // setw

/*
        @author: Luisa Castano, fernanda16400@gmail.com
*/
/** PROBLEM:
  Write a program to calculate the squares of int values up to 100.
  The program should write two columns: The first lists the value;
  the second contains the square of that value. Use setw to manage
  the output so that the values line up in colums. **/


using std::cout;    using std::endl;
using std::setw;
int main () {
  for (int i=0;i<101;i++){
    cout << i;
    cout << setw(10);
    cout << i*i << endl;
  }
  return 0;
}
