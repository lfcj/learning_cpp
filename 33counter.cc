#include <iostream>
#include <string>
#include <cmath>

/*
        Book: Accelerated C++, Koenig & Moo.
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
using namespace std;
// ascii A (65) to z (122)

bool next_is_stop(int index, int* stops, int stops_len){
  bool res = true;

  for (int i=0;i<stops_len;i++){
    res = stops[i] == index;
    if (res)
      break;
  }
  return res;
}
// returns the amount of times that word is repeated in text
int compare_words(char* text, int begin, int end, int* stops, int text_len, int stops_len, int index){
  int stop_iterator = index;
  // int current_begin = end + 1;
  int current_begin = stops[stop_iterator] + 1;
  int current_end;
  int count = 1;
  int word_len = end-begin;
  bool equal;
  int iterator = begin;
  // aslkj aslekj aslkvnlas asekj asasdkj nk kls elksj
  // 0     6      13        23    29      37 40  44
  while ((current_begin + word_len) <= text_len +1){
    equal = true;
    current_end = current_begin + word_len;
    for (int i = current_begin; i < current_end && equal;i++){
      equal = equal && (text[i] == text[iterator]);
      iterator++;
    }
    if (equal && next_is_stop(current_end, stops, stops_len)){
      count++;

      // delete word not to count it again.
      for (int i=current_begin;i<current_end;i++)
        text[i]='^';
    }
    // keep comparing
    iterator = begin;
    stop_iterator++;
    current_begin = stops[stop_iterator] + 1;
  }
  return count;

}
int main () {
  int size = 100;
  int input_len = 0;
  char input[size];
  int stops[size/2];
  cout << "Please enter something: " << endl;
  cin.getline(input, sizeof(input));

  // find word separators
  int ascii;
  int stops_iterator = 0; // represents # words-1.
  stops[0] = 0;
  for (int i=1;i<size;i++){
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
  // add last stop
  stops[stops_iterator] = input_len+1;
  stops_iterator++; // there is one more word than stops
  // count words
  int current_count = 0;
  int begin;
  for (int i=0;i<stops_iterator;i++){
    begin = i==0? i:stops[i-1]+1;
    current_count = compare_words(input, begin, stops[i], stops, input_len, stops_iterator, i);
    if (input[begin] != '^'){
      cout << "Word '";
      for (int j=begin;j<stops[i];j++)
        cout << input[j];
      cout << "' is " << current_count << " times in text." << endl;
    }
  }

  return 0;
}
