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
-> O(n^2) -> linear in average
TODO: Solve the same creating first a tree with the text. -> O(n) + O(tree creation)

Let's say input: "abcd efg abcd lm;n o@lm"
Words are "abcd efg abcd  lm    n   o   lm"
stops are = [  4,  8,   13,  16, 18, 20,  (23)] *23 is just the end.
We start comparing 'abcd' with every other word and stop at the first
non-match.

Result would be:
'abcd' is 2 times in text
'efg'  is 1 time in text
'lm'   is 2 times in text
'n'    is 1 time in text
'o'    is 1 time in text
***********************/

int compare_words(int begin, int end, int text_len, int stops_len, int index){
  int stop_iterator = index;
  int current_begin = stops[stop_iterator] + 1;
  int current_end;
  int count = 1;
  int word_len = end-begin;
  bool equal;
  int iterator = begin;

  while ((current_begin + word_len) <= text_len +1){
    equal = true;
    current_end = current_begin + word_len;
    for (int i = current_begin; i < current_end && equal;i++){
      equal = equal && (input[i] == input[iterator]);
      iterator++;
    }
    if (equal && elem_of(current_end, stops, stops_len)){
      count++;

      // delete word not to count it again.
      for (int i=current_begin;i<current_end;i++)
        input[i]='^';
    }
    // keep comparing
    iterator = begin;
    stop_iterator++;
    current_begin = stops[stop_iterator] + 1;
  }
  return count;
}

int main () {
  cout << "Please enter something: " << endl;
  cin.getline(input, sizeof(input));

  // find word separators
  int input_len = 0;
  int stops_iter = 0; // represents # words-1.
  stops[0] = 0;
  stops_iter = find_splits_and_count(stops_iter, &input_len);

  // count words
  int cur_count = 0;
  int begin;
  for (int i=0;i<stops_iter;i++){
    begin = i==0? i:stops[i-1]+1;
    cur_count = compare_words(begin, stops[i], input_len, stops_iter, i);
    if (input[begin] != '^'){
      cout << "Word '";
      for (int j=begin;j<stops[i];j++)
        cout << input[j];
      cout << "' is " << cur_count << " times in text." << endl;
    }
  }
  return 0;
}
