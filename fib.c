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



int main(int argc, char *argv[]) {

   if (argc != 4) {

      printf("Usage: %s <integer> <method: r/i> <filename>\n", argv[0]);

      return 1;

   }


   int num = atoi(argv[1]) - 1;

   char method = argv[2][0];

   FILE *fptr = fopen(argv[3], "r");
   

   if (fptr == NULL) {

      perror("Error opening file");

      return 1;

   }


   int file_num;


   if (fscanf(fptr, "%d", &file_num) != 1) {

      printf("Error reading integer from file\n");

      fclose(fptr);

      return 1;

   }


   fclose(fptr);

   int nthNumber = num + file_num;

   int result;


   if (method == 'i') {

      result = iterative_fibonacci(nthNumber);

   } else if (method == 'r') {

      result = recursive_fibonacci(nthNumber);

   } else {

      printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");

      return 1;

   }


   printf("%d\n", result);

   return 0;

}


