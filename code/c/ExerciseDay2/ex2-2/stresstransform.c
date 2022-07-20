#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stresstransform.h"


// 
// check out the new function header:
// ... much more compact
// ... much easier to adapt to 3d states of stree (just change STRESS)
//

void StressTransform(STRESS s, STRESS *sp, double theta) {

	double th = theta * M_PI/180.;

	double sn = sin(th);
	double cs = cos(th);

	// these next lines need to be adapted to work with the new header ...

	sp->sigx = s.sigx*cs*cs + s.sigy*sn*sn + 2.*s.tau*sn*cs;
	sp->sigy = s.sigx*sn*sn + s.sigy*cs*cs - 2.*s.tau*sn*cs;
	sp->tau  = (s.sigy - s.sigx)*sn*cs + s.tau*(cs*cs - sn*sn);
}

