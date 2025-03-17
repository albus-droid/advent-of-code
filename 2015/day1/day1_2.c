#include <stdio.h>

long floor_num = 0;
unsigned long pos = 0;
unsigned char c = 0;
 
int main(void) {

  FILE *f = fopen("day1.input", "r");
 
  while ((c = fgetc(f)) != '\n') {

    ++pos;
    switch (c) {
    case '(' :
      floor_num++;
      break;
      
    case ')' :
      floor_num--;
      break;
      
    default:
      break;
        }
  
  if (floor_num == -1) {
   printf("The position is %d ", pos);
   break;
  }
 }


  return 0;
}
