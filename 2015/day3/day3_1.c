#include<stdio.h>
#include<stdlib.h>

struct house {
   int x;
   int y;
   struct house *next;
};

char AddHouse(int, int, struct house *);
void RemHouse(struct house *);

int main(void) {
   
   struct house *curr;  // Current house
   curr = (struct house *) malloc(sizeof(struct house));
   *curr = (struct house) {0,0,NULL};
   
   char c; // for reading character by character from stream
   int x = 0;
   int y = 0;
   int houses = 1; // No of house visited
   
   while ((c = fgetc(stdin)) != EOF) {
      switch (c) {
      case '^':
         y++;
	 break;

      case 'v':
         y--;
	 break;

      case '>':
         x++;
	 break;
      
      case '<':
         x--;
	 break;

      default:
         printf("Unknown character input: %c.\n", c);
	 break;
      }
      houses += AddHouse(x,y,curr);
   }
   printf("Houses visited: %d\n",houses);
   RemHouse(curr);
   return 0;
}

char AddHouse(int x, int y, struct house *H) {
   while(H->x != x || H->y != y) {
      if(H->next) {
         H = H->next;
      } else {
         H->next = (struct house *) malloc(sizeof(struct house));
         *(H->next) = (struct house) {x,y,NULL};
         return 1;
      }
   }
   return 0;
}

void RemHouse(struct house *H) {
   struct house *curr, *old;
   curr = old = H;
   while(curr->next) {
      old = curr;
      curr = curr->next;
      free(old);
   }
   return ;
}
