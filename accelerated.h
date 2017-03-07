/*
        Book: Accelerated C++, Koenig & Moo.
        @author: Luisa Castano, fernanda16400@gmail.com
*/
#include <iostream>
#include <string>
#include <cmath>

#define SIZE 100

char input[SIZE];
int stops[SIZE/2];
using namespace std;

template <class T>
void print_array (T *array, int begin, int end){
  for (int i=begin;i<end;i++)
    cout << array[i] << " ";
  cout << endl;
}

/*********************** 33couter.cc ***************************/
// checks if 'elem' is an element of 'array'
bool elem_of(int elem, int* array, int array_len){
  bool res = true;
  for (int i=0;i<array_len;i++){
    res = array[i] == elem;
    if (res)
      break;
  }
  return res;
}

/* returns the amount of times that word is repeated in text
 *
 * begin:     index of char where word being compared starts with.
 * end:       index of char where word being compared ends + 1.
 * text_len:  length of user input.
 * stops_len: amount of white spaces, equal amout of words.
 * index:     current stop index.
 */
int compare_words(int begin, int end, int text_len, int stops_len, int index);

/* finds out how many not letter chars (stops) there are in input,
   and counts the words between those ones.
 *
 * stops_iter: iterates the stops. Equals amount of counted words - 1.
 * input_len:  length of user input.
 */
int find_splits_and_count(int stops_iter, int* input_len){
 int ascii;
 stops[0] = 0;
 for (int i=1;i<SIZE;i++){
   if (input[i] == '\0') // end of str?
     break;
   // find out how many words we have.
   ascii = (int) input[i];
   if (ascii < 65 || ascii > 122 ) {
     stops[stops_iter] = i;
     stops_iter++;
   }
   ++(*input_len);
 }
 // add last stop
 stops[stops_iter] = (*input_len) + 1;
 stops_iter++; // there is one more word than stops

 return stops_iter;
}

/******************** 34long_and_shortest.cc ************************/
// Finds maximal and minimal difference between numbers in array.
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
