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
//uint_fast8_t
  int listSize,seed;
  int total = 0;
  size_t i;
  printf("Enter an integer for size of list: ");
  scanf("%d",&listSize);
  printf("Enter Seed: ");
  scanf("%d",&seed);
  srand(seed);
//  int_fast16_t
  int randList[listSize];
  for(i=0;i<listSize;i++){
    int temp = rand();
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
