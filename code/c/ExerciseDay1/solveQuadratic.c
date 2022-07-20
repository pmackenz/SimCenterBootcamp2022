// program to solve quadratic equation
//        ax^2 + bx + c = 0
//
// soln: x = -b/2a +/- sqrt(b^2-4ac)/2a
//
// write a program to take 3 inputs and output the soln
// deal with possible errors in input, i.e. b^2-4ac negative

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 4) {
    printf("Usage: appName a b c\n");
    exit(-1);
  }

  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = atof(argv[3]);

  float p = -b/2.0;
  float q = b*b - 4.0*a*c;

  if (q < 0.0 ) { return 1; }

  q = sqrt(q) / (2.0*a);

  float x1 = p + q;
  float x2 = p - q;

  //printf("Have a Nice Day!\n");
  printf("Solution x1 = %f\n", x1);
  printf("Solution x2 = %f\n", x2);
  return 0;
}

