#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // need this for the constant pi = M_PI

#include "stresstransform.h"


int main(int argc, char **argv) {

	// get dth from the first argument.  This is given in degrees!
	if (argc < 2) { exit(1); }

	double dth = atof(argv[1]);
	// might be smart to set a default value, just in case the user
	// forgets when calling this  program;)

	double th = 0.0;


	// set the initial stress state

	STRESS S0;
	STRESS Sp;

	S0.sigx = 12.0;
	S0.sigy = -5.5;
	S0.tau  =  3.5;

	// loop to compute transformed states
	
	FILE *f = fopen("list.csv","w");

	while (th <= 180.) {
	    StressTransform(S0, &Sp, th);
	    fprintf(f, "%12.6f,%12.6f,%12.6f,%12.6f\n", th, Sp.sigx, Sp.sigy, Sp.tau);
	    th += dth;
	}

	fclose(f);
}

