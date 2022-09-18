/* Write C code that generates a list of random integers and
 * computes the mean (as a real number). Your program should
 * take as input two parameters, the length of the list, and
 * a seed to generate the random numbers. It should print out
 * the list of integers and the calculated mean. Submit your
 * code, as well as the makefile you used to compile it.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
  uint_fast16_t listSize,seed;
  uint_fast64_t total = 0;
  size_t i;
  printf("Enter an integer for size of list: ");
  scanf("%hd",&listSize);
  printf("Enter Seed: ");
  scanf("%hd",&seed);
  srand(seed);
//  int_fast16_t
  uint_fast32_t randList[listSize];
  for(i=0;i<listSize;i++){
    uint_fast32_t temp = rand(); // returns int [0,RAND_MAX]. RAND_MAX is 2^31-1 on this machine, which is same as INT_MAX
    printf("%d",temp);
    printf("\n");
    randList[i] = temp;
    total+=temp;
  }
  printf("Mean is: ");
  double mean = (double) total/listSize;
  printf("%f",mean);
  return 0;
}
