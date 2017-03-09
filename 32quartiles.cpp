#include <iostream>
#include <algorithm> // sort
#include <vector>
#include <cstdlib> // rand und srand.
#include <ctime>

/*
        @author: Luisa Castano, fernanda16400@gmail.com
*/
/** PROBLEM:
  Write a program to compute and print the quartiles of a
  set of integers **/


using namespace std;
typedef vector<int>::size_type vc_size;
// notice: call-by-value, which is not necessarily efficient.
double find_median(vc_size size, vector<int> set) {
  vc_size mid = size/2;
  return size % 2 == 0? (set[mid-1] + set[mid])/2
                      : (double) set[mid];
}

int main () {
  vector<int> set;
  srand(time(0)); // set a seed
  vc_size size = rand()%50;

  // fill vector with random values between 0 and 100
  for (int i=0;i<size;i++)
    set.push_back(rand()%100);

  sort(set.begin(), set.end());
  // second quartile or median
  double median = find_median(size, set);

  // first quartile
  vc_size mid = size/2;
  double fst_quartile = find_median(mid, set);

  // third quartile
  double trd_quartile = find_median(size+mid, set);

  cout << "size: " << size << endl;
  for (vector<int>::const_iterator i = set.begin(); i != set.end(); ++i){
      cout << *i << ' ';
  }
  cout << endl;
  cout << "first q: " << fst_quartile << endl;
  cout << "second q: " << median << endl;
  cout << "trd_quartile: " << trd_quartile << endl;

  return 0;
}
