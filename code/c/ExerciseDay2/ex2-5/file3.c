
// program to read values from a file, each file a csv list of int and two double
// written: fmk

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stdout, "ERROR correct usage appName inputFile\n");
    return -1;
  }
  
  FILE *filePtr = fopen(argv[1],"r"); 

  int i = 0;
  float float1, float2;
  int maxVectorSize = 10;
  double *vector1 = (double *)malloc(maxVectorSize*sizeof(double));
  double *vector2 = (double *)malloc(maxVectorSize*sizeof(double));  
  int vectorSize = 0;
  
  while (fscanf(filePtr,"%d, %f, %f\n", &i, &float1, &float2) != EOF) {
    vector1[vectorSize] = float1;
    vector2[vectorSize] = float2;
    printf("%d, %f, %f\n",i, vector2[i], vector1[i]);
    vectorSize++;

    if (vectorSize == maxVectorSize) {
      // some code needed here I think .. programming exercise

      // allocate larger vectors
      double *tmp = (double *)malloc((maxVectorSize + 10)*sizeof(double));
      for (int i=0; i<maxVectorSize; tmp[i]=vector1[i], i++) {}
      free(vector1);
      vector1 = tmp;

      tmp = (double *)malloc((maxVectorSize + 10)*sizeof(double));
      for (int i=0; i<maxVectorSize; tmp[i]=vector2[i], i++) {}
      free(vector2);
      vector2 = tmp;
      
      maxVectorSize += 10;
    }
  }

  fclose(filePtr);  
}
