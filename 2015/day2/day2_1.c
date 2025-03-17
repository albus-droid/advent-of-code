#include<stdio.h>

unsigned long long PaperArea(unsigned int, unsigned int, unsigned int);

int main(void) {
  unsigned long long total = 0;
  unsigned int dim[3], temp;
  char c;
  unsigned char i;

  FILE *f = fopen("input.txt", "r");

  temp = dim[0] = dim[1] = dim[2] = 0;

  while ((c = getc(f)) != EOF) {
    switch (c) {
        case '9':
        case '8':
        case '7':
        case '6':
        case '5':
        case '4':
        case '3':
        case '2':
        case '1':
        case '0':
            temp *= 10;
            temp += c-'0';
            break;
        case 'x':
        case '\n':
            for(i=0;dim[i]!=0;i++){;}
            dim[i] = temp;
            temp = 0;
            break;
        default:
            printf("Error: Unknown character occured");
            break;
     }
    if (c == '\n') {
      total+=PaperArea(dim[0], dim[1], dim[2]);
      temp = dim[0] = dim[1] = dim[2] = 0;
    }

  }
  printf("Total is %llu", total);
  return 0;
}


unsigned long long PaperArea(unsigned int l, unsigned int w, unsigned int h) {
  unsigned long long a = l*w;
  unsigned long long b = h*w;
  unsigned long long c = l*h;
  unsigned long long tot_area = 2*a + 2*b + 2*c;
  unsigned long long smallest = (a <= b && a <= c) ? a : (b <= c ? b : c);
  return tot_area + smallest;
}
