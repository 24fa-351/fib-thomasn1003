#include <stdio.h>
#include <stdlib.h>



int iterative_fibonacci(int nthNum) {
   int prevprevnum = 0;

   int prevnum = 1;

   int currentnum = 0;


   for (int i = 0; i < nthNum; i++) {

      prevprevnum = prevnum;

      prevnum = currentnum;

      currentnum = prevprevnum + prevnum;

   }


   return currentnum;

}



int recursive_fibonacci(int nthNum) {

   if ( nthNum == 0) {

      return 0;

   } else if (nthNum == 1) {

      return 1;

   }


   return recursive_fibonacci(nthNum - 1) + recursive_fibonacci(nthNum - 2);
}



int main(int arg1, char *arg2[]) {


   int num = atoi(arg2[1]);

   char method = arg2[2][0];


   FILE *fptr = fopen(arg2[3], "r");
   int file_num;
   fscanf(fptr, "%d", &file_num);
   fclose(fptr);

  
   int nthNumber = num + file_num - 1;

   int result;


   if (method == 'i') {

      result = iterative_fibonacci(nthNumber);

   } else if (method == 'r') {

      result = recursive_fibonacci(nthNumber);

   } 


   printf("%d", result);

   return 0;
   
}
