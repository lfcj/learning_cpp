#include "accelerated.h"

/*
        @author: Luisa Castano, fernanda16400@gmail.com
*/
/** PROBLEM:
  Write a program to count how many times each distinct
  word appears in its input. **/
  /************   Solution *************
This solution tries to not use predefined string functions and
tries to create create the least amount of char arrays.
-> O(n)

Let's say input: "abcd efg abcd lmn o@lm"
Words are "abcd efg abcd  lm    n   o   lm"
stops are = [  4,  8,   13,  16, 18, 20,  (23)] *23 is just the end.

We find the biggest and smalles word by finding the maximal and mininmal
difference between every two numbers in the array stops.

In case of tie, the word that comes later in the text is chosen.

Result would be:
'abcd' is biggest word.
'o'    is smallest word.
***********************/


int main () {
  cout << "Please enter something: " << endl;
  cin.getline(input, sizeof(input));

  int text_len = 0, stop_iter = 0;
  stop_iter = find_splits_and_count(stop_iter, &text_len);
  // {min_start, max_start, min_end, max_end}
  int starts_and_ends[4] = {0,0,0,0};
  find_biggest_and_smallest(stops, stop_iter, starts_and_ends);
  cout << "Smallest word is: " << endl;
  print_array<char>(input, starts_and_ends[0], starts_and_ends[2]);
  cout << "Biggest word is: " << endl;
  print_array<char>(input, starts_and_ends[1], starts_and_ends[3]);

}
