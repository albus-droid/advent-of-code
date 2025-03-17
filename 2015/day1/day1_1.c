#include <stdio.h>

int floor_num = 0;
char c = 0;

int main(void) {

  FILE *f = fopen("day1.input", "r");
  
  while((c = fgetc(f)) != '\n') {

    switch(c) {
    case '(' : floor_num++;
      break;

    case ')' : floor_num--;
      break;

    default:
      break;
    }
  }  
  
  printf("Floor number is %d", floor_num);
  return 0;
}
