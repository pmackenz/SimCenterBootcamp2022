#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  if (argc != 5) {
    printf("Usage: %s sx sy tau theta\n", argv[0]);
    exit(-1);
  }

  //double pi = atan(1.0) * 4.0;

  double sx    = atof(argv[1]);
  double sy    = atof(argv[2]);
  double tau   = atof(argv[3]);
  double theta = atof(argv[4]) * M_PI / 180.;
  //double theta = atof(argv[4]) * 3.141267 / 180.;
  //double theta = atof(argv[4]) * pi / 180.;

  double sn = sin(theta);
  double cs = cos(theta);

  double sxp  = sx * cs * cs + sy * sn * sn + 2.0 * tau * cs * sn;
  double syp  = sx * sn * sn + sy * cs * cs + 2.0 * tau * cs * sn;
  double taup = (sy - sx) * sn * cs + tau * (cs * cs - sn * sn);

  printf("Sigma_x' = %12.6lf\n", sxp);
  printf("Sigma_y' = %12.6lf\n", syp);
  printf("Tau_xy'  = %12.6lf\n", taup);

  return 0;
}

