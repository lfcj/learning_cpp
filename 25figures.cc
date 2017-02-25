#include <iostream>
#include <math.h>
using namespace std;
// page 55, 2-5
float dist (int x,int y, int u, int w) {
  int yaxis = abs(y-w);
  int xaxis = abs(x-u);
  return (sqrt(yaxis*yaxis + xaxis*xaxis));
}

bool isInLine (float x, float y, float x1, float y1, float x2, float y2) {
  /* A = (x1,x2)      B = (x,y)          C = (x2,y2)*/
  /* (x,y) is in line if dist(A,B)+dist(B,C) == dist (A,C) */
  float distto1 = sqrt ((x-x1)*(x-x1)+(y-y1)*(y-y1));
  float distto2 = sqrt ((x-x2)*(x-x2)+(y-y2)*(y-y2));
  float dist1to2 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

  return (floor((distto1+distto2)*100) == floor( dist1to2*100));
}

int main () {
  
  float size = 4;
  float step = 0.1;
  // circle
  float r = 1.5;
  //center 
  int a = 2;
  int b = 2;
  for (float y = 0; y<size;y+=step){
    for (float x = 0; x<size;x+=step){
      if (floor((x-a)*(x-a) + (y-b)*(y-b)) == floor(r*r) )
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }
  
  // triangle: given are points A, B, C
  float Ax = a; float Ay = b;
  float Bx = 1; float By = 1;
  float Cx = 0.5; float Cy = 3.9;
  for (float y = 0; y<size;y+=step){
    for (float x = 0; x<size;x+=step){
      if (isInLine(x,y,Ax,Ay,Bx,By))
        cout << "O";
      if (isInLine(x,y,Ax,Ay,Cx,Cy))
        cout << "O";
      if (isInLine(x,y,Bx,By,Cx,Cy))
        cout << "O";
      else
        cout << " ";
    }
    cout << endl;
  }
  for (float y = 0; y<size;y+=step){
    for (float x = 0; x<size;x+=step){
      if (x<a&&y<b)

        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }
  
  // rectangle
  
  cout << endl;
  return 0;
}

