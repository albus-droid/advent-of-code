#include<stdio.h>

int main(void) {
  int position = 50;
  int cross_count = 0;
  char direction;
  int distance;

  while(scanf(" %c%d", &direction, &distance) == 2) {
	  for (int i = 0; i < distance; i++) {
		  if (direction == 'L') 
			  position = (position - 1 + 100) % 100;
		  else if (direction == 'R')
			  position = (position + 1) % 100;
		  if (position == 0)
			  cross_count++; 
	  }
  }

  printf("Cross count is %d\n", cross_count);
  return 0;
}
