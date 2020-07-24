#include <stdio.h>

struct player{
  char a[2];
  char b[3];
  char c[3];
  char d[4];
  char e[5];
  char gu[9][9];
  char pl[9][9];
};

void init(struct player * p) {
  int i, j;
  for (i = 0; i < 9; i++) {
    for (j = 0; j < 9; j++) {
      p->gu[i][j]=' ';
      p->pl[i][j]=' ';
    }
  }
}

void display(char b[9][9]) {
  int i, j;
  printf("\n    0   1   2   3   4   5   6   7   8\n");
  printf("  ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗");
  for (i = 0; i < 9; i++) {
    printf("\n%c ║", i+'A');
    for (j = 0; j < 9; j++) {
      printf(" %c ║", b[i][j]);
    }
    if (i != 8)
      printf("\n  ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣");
    else
      printf("\n  ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝");
  }
  printf("\n");
}

void display_boat(int i) {
  int j;
  printf("╔");
  for (j = 0; j < i-1; j++)
    printf("═══╦");
  printf("═══╗\n");

  printf("║");
  for (j = 0; j < i; j++)
    printf(" X ║");

  printf("\n╚");
  for (j = 0; j < i-1; j++)
      printf("═══╩");
  printf("═══╝");
}

int is_invalid(int x, int y, char o, int size, struct player * p) {
  int j;
  if (o == 'h' || o == 'H') {
    for (j=0;j<size;j++) {
      if(p->pl[y][x+j] == 'X' || x+j > 8)
        return 1;
    }
  } else if (o == 'v' || o == 'V') {
    for (j=0;j<size;j++) {
      if(p->pl[y+j][x] == 'X' || y+j > 8)
        return 1;
    }
  } else
    return 1;
  return 0;
}

void place(struct player * p) {
  int x, y, i, j;
  char o;
  char line[64];
  int boats[] = {5,4,3,3,2};
  for (i=0;i<5;i++) {
    display(p->pl);

    do {
      display_boat(boats[i]);
      x = 9;
      y = 9;
      o = 'A';
      while(y<0 || y>8) {
        printf("\nLinha (A-I):\t");
        fgets(&line,64,stdin);
        y = line[0] - 'A';
        if (y > 8) {
          y += 'A';
          y -= 'a';
        }
      }

      while(x<0 || x>8) {
        printf("Coluna (0-8):\t");
        fgets(&line,64,stdin);
        x = line[0] - '0';
      }

      while (o!='v'&&o!='V'&&o!='h'&&o!='H') {
        printf("Direção (H/V):\t");
        fgets(&line,64,stdin);
        o = line[0];
      }
    } while(is_invalid(x,y,o,boats[i],p));

    if (o == 'h' || o == 'H') {
      for (j=0;j<boats[i];j++) {
        p->pl[y][x+j] = 'X';
      }
    }
    if (o == 'v' || o == 'V') {
      for (j=0;j<boats[i];j++) {
        p->pl[y+j][x] = 'X';
      }
    }
  }
  display(p->pl);
}

int main() {
  struct player p1, p2;
  init(&p1);
  init(&p2);
  place(&p1);
  place(&p2);
  int x, y;
  while (1) {
    system("clear");
    x = 2;
    y = 3;
    scanf("%d %d", &x, &y);
    p1.gu[y][x]='X';
    display(p1.gu);
  }
  return 0;
}


