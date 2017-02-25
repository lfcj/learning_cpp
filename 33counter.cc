#include <iostream>
#include <string>
#include <cmath>


/** Write a program to count how many times each distinct
    word appears in its input. **/
using namespace std;
// ascii A (65) to z (122)

int max (int a, int b){
  return ((a+b)-abs(a+b));
}
int main () {
  int size = 100;
  int input_len = 0;
  char input[size];
  int stops[size/2];
  cout << "Please enter something: " << endl;
  cin.getline(input, sizeof(input));

  // split function.
  int ascii;
  int stops_iterator = 0;
  for (int i=0;i<size;i++){
    if (input[i] == '\0') // end of string?
      break;

    // find out how many words we have.
    ascii = (int) input[i];
    if (ascii < 65 || ascii > 122 ) {
      stops[stops_iterator] = i;
      stops_iterator++;
    }
    ++input_len;
  }
  int max_len = 0;

  // find biggest word
  // for (int i=stops_iterator;i>0;i--){
  //   if (i > 0){
  //
  //   } else
  //     break;
  //
  //
  //   max_len = max(stops[i]-stops)
  // }

  cout << (-1 % 1) << endl;
  cout << endl << stops_iterator <<  endl;
  cout  << input_len <<  endl;

  return 0;
}
