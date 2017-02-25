#include <iostream>
#include <string>
#include <ios> //for streamsize
#include <iomanip> // for setprecision.
#include <vector>
#include <algorithm> // sort
using namespace std;

int main ()
{
  // 0-2.
  cout << "This (\") is a qoute, and this (\\) is a blackslash" << endl;
  cout << "This is a tab \t" << "see how many spaces?";
  cout << endl; // flash buffer

  /******************* page 26 **********************/
  cout << "Please enter your first name: ";
  string name;
  cin >> name;

  // build the msg that we intend to write
  const string greeting = "Hello " + name + "!";

  /***first attempt***/
  // build the second and fourth lines of the output
  const string spaces(greeting.size(), ' ');
  const string second = "* " + spaces + " *";

  // build the first and fifth lines of the output
  const string first(second.size(), '*');

  // write it all
  cout << endl;
  cout << first << endl;
  cout << second << endl;
  cout << "* " << greeting << " *" << endl;
  cout << second << endl;
  cout << first << endl;

  /** *************second attempt page 49**************/
  // number of blanks surrounding greeting
   const int pad = 0; // Exercise 2-0

  // total numbers of rows and columns to write
  const int rows = pad*2 + 3;
  const string::size_type cols = greeting.size() + pad*2 + 2;

  // write a blank line to separate input from output
  cout << endl;

  // write rows of output
  for (int r = 0; r!= rows; ++r) {
    string::size_type c = 0;

    while (c!= cols) {
      //is it time to write the greeting?
      if (r == pad + 1 && c == pad + 1) {
        cout << greeting;
        c += greeting.size();
      } else {
        // are we on the border?
        if (r==0 || r == rows -1 || c==0 || c == cols-1)
          cout << "*";
        else
          cout << " ";
        ++c;
      }
    }
    cout << endl;
  }

  /******************** page 57 *******************/
  // ask for and read the student's name
  cout << "Please enter your first name: ";
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final; // same as cin >> midterm;cin >> final;

  // ask for the homework grades
  cout << "Enter all your homework grades, "
  "followed by end-of-file: ";
  /* This works because 2 or more strings in a program,
  separated only by a whitespace, are automatically concatenated*/

  // the number and sum of grades read so far
  int count = 0;
  double sum = 0;

  // a variable into which to read
  double x;
  vector<double> homework;
  // invariant:
  // we have read count grades so far, and
  // sum is the sum of the first count grades
  while (cin >> x) { // same as cin >> x; while (cin) {...}
    homework.push_back(x);
    ++count;
    sum += x;
  }
  typedef vector<double>::size_type vec_sz;
  vec_sz size_of_howework = homework.size();

  // verify we have data
  if (!size_of_howework) {
    cout << endl << "You must enter your grades"
                    "Please try again." << endl;
    return 1;
  }

  // sort vector
  sort(homework.begin(), homework.end());

  // find median.
  vec_sz mid = size_of_howework/2;
  double median;
  median = size_of_howework & 2 == 0? (homework[mid-1]+homework[mid])/2
                                    : homework[mid];

  // streamsize is the type that the in-out library uses to represent sizes.
  // We save the current precision the stream uses for floating-point output
  streamsize prec = cout.precision();

  // setprecision let us say how many significant digits we want our output to contain.

  // We said such precision to 3 (usually 2 before the dec point, one after),
  // and set it to the original precision when we are done.
  cout << "Your final grade is " << setprecision(3)
  << 0.2 * midterm + 0.4 * final + 0.4 * median //before median -> sum / count
  << setprecision(prec) << endl;
  return 0;
}
