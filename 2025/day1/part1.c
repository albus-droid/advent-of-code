#include<stdio.h>

int main(void) {
  int position = 50;
  int zero_count = 0;	
  char direction;
  int distance;

  while(scanf(" %c%d", &direction, &distance) == 2) {
    if (direction == 'L') {
      position = (position - distance + 100) % 100;
    }
    else if (direction == 'R')
      position = (position + distance) % 100;
    if (position == 0)
      zero_count++; 
  }

  printf("Zero count is %d\n", zero_count);
  return 0;
}
