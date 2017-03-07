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

void find_biggest_and_smallest(int *array, int array_len, int *res){
    // res = {min_start, max_start, min_end, max_end}
    int cur_min = array[0];
    int cur_max = array[0];
    res[2] = array[0]; res[3] = array[0];
    if (array_len < 2)
      return;
    int temp = 0;
    for (int i=1;i<array_len;i++){
      temp = array[i]-array[i-1];
      if (cur_min > temp){
        cur_min = temp;
        res[0] = array[i-1]; res[2] = array[i];
      }
      if (cur_max < temp){
        cur_max = temp;
        res[1] = array[i-1]; res[3] = array[i];
      }
    }
}
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
