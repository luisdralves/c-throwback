#include <stdio.h>

int win(char b[10]) {
  char a[8][3];
  a[0][0] = b[0];
  a[0][1] = b[1];
  a[0][2] = b[2];
  a[1][0] = b[3];
  a[1][1] = b[4];
  a[1][2] = b[5];
  a[2][0] = b[6];
  a[2][1] = b[7];
  a[2][2] = b[8];
  a[3][0] = b[0];
  a[3][1] = b[3];
  a[3][2] = b[6];
  a[4][0] = b[1];
  a[4][1] = b[4];
  a[4][2] = b[7];
  a[5][0] = b[2];
  a[5][1] = b[5];
  a[5][2] = b[8];
  a[6][0] = b[0];
  a[6][1] = b[4];
  a[6][2] = b[8];
  a[7][0] = b[2];
  a[7][1] = b[4];
  a[7][2] = b[6];

  int i;
  for (i = 0; i < 8; i++) {
    if (a[i][0]!=' ' && a[i][0]==a[i][1] && a[i][1]==a[i][2])
      return 1;
  }
  return 0;
}

void draw_board(char b[10]){
  printf("\t\t %c ║ %c ║ %c\n",b[0],b[1],b[2]);
  printf("\t\t═══╬═══╬═══\n");
  printf("\t\t %c ║ %c ║ %c\n",b[3],b[4],b[5]);
  printf("\t\t═══╬═══╬═══\n");
  printf("\t\t %c ║ %c ║ %c\n",b[6],b[7],b[8]);
  printf("\n");
}

int main(){
  char b[] = "          ";
  int play = 10;
  char c[64];
  int player = 0;
  int cnt = 0;
  while (1) {
    printf("\n\n\t\t Jogador %d\n", player + 1);
    printf("\t   Seleciona uma posição:\n\n");
    draw_board("123456789");
    draw_board(b);
    while (play < 1 || play > 9 || b[play-1]!=' ') {
      printf(">");
      fgets(&c,64,stdin);
      play = c[0]-'0';
    }
    if (player)
      b[play-1] = 'O';
    else
      b[play-1] = 'X';
    if (win(b)) {
      printf("Jogador %d ganha!\n",player + 1);
      draw_board(b);
      break;
    }
    if (cnt >= 8) {
      printf("Empate!\n");
      draw_board(b);
      break;
    }
    play = 10;
    player++;
    player%=2;
    cnt++;
  }
  return 0;
}
