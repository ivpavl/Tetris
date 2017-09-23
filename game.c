#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>

#define AC_RED     "\x1b[31;1m"
#define AC_GREEN   "\x1b[32;1m"
#define AC_BLUE    "\x1b[34;1m"
#define AC_RESET   "\x1b[0m"

char startGame(char array[15][8], char figure)
{
  char blc1we,
       blc2we,
       blc3we,
       blc4we,
       blc1hi,
       blc2hi,
       blc3hi,
       blc4hi;



    if(figure == 0){
      blc1we = 0, blc2we = 1, blc3we = 0, blc4we = 1, blc1hi = 0, blc2hi = 0, blc3hi = 1, blc4hi = 1;
      array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
    }
    else if (figure == 1){
      blc1we = 0, blc2we = 1, blc3we = 2, blc4we = 3, blc1hi = 0, blc2hi = 0, blc3hi = 0, blc4hi = 0;
      array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
    } 
    else if (figure == 2){
      blc1we = 0, blc2we = 0, blc3we = 1, blc4we = 2, blc1hi = 0, blc2hi = 1, blc3hi = 1, blc4hi = 1;
      array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
    } 
    else if (figure == 3){
      blc1we = 2, blc2we = 0, blc3we = 1, blc4we = 2, blc1hi = 0, blc2hi = 1, blc3hi = 1, blc4hi = 1;
      array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
    } 
    else if (figure == 4){
      blc1we = 1, blc2we = 2, blc3we = 0, blc4we = 1, blc1hi = 0, blc2hi = 0, blc3hi = 1, blc4hi = 1;
      array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
    } 
    else if (figure == 5){
      blc1we = 0, blc2we = 1, blc3we = 1, blc4we = 2, blc1hi = 0, blc2hi = 0, blc3hi = 1, blc4hi = 1;
      array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
    } 
    else if (figure == 6){
      blc1we = 1, blc2we = 0, blc3we = 1, blc4we = 2, blc1hi = 0, blc2hi = 1, blc3hi = 1, blc4hi = 1;
      array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
    } 
    shMatrix(8, 15, array, figure);
    char fig0flip = 0,
         fig1flip = 0,
         fig2flip = 0,
         fig3flip = 0,
         fig4flip = 0,
         fig5flip = 0,
         fig6flip = 0;

  while(1)
  {
    if(kbhit())
    {
      if (getch() == 47) return;
      if (getch() == 'w'){
        if(figure == 0){
          array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
        }
        else if (figure == 1){
          char fig1flip;
          if(fig1flip == 0){
            array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
            array[blc1hi][blc1we] = 1, array[blc2hi = blc2hi + 1][blc2we = blc2we - 1] = 1, array[blc3hi = blc3hi + 2][blc3we = blc3we - 2] = 1, array[blc4hi = blc4hi + 3][blc4we = blc4we - 3] = 1;
            fig1flip = 1;
          shMatrix(8, 15, array, figure);
        }
          if (fig1flip == 1) {
            array[blc1hi][blc1we] = 0, array[blc2hi][blc2we] = 0, array[blc3hi][blc3we] = 0, array[blc4hi][blc4we] = 0;
            array[blc1hi][blc1we] = 1, array[blc2hi = blc2hi - 1][blc2we = blc2we + 1] = 1, array[blc3hi = blc3hi - 2][blc3we = blc3we + 2] = 1, array[blc4hi = blc4hi - 3][blc4we = blc4we + 3] = 1;
            fig1flip = 0;
          shMatrix(8, 15, array, figure);
        }
          printf("%d\n", fig1flip);
        } 
        else if (figure == 2){
          array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
        } 
        else if (figure == 3){
          array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
        } 
        else if (figure == 4){
          array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
        } 
        else if (figure == 5){
          array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
        } 
        else if (figure == 6){
          array[blc1hi][blc1we] = 1, array[blc2hi][blc2we] = 1, array[blc3hi][blc3we] = 1, array[blc4hi][blc4we] = 1;
        } 
      }
    }
  }
  

  
  system("clear");
  printf("GAME OVER\n");
}

int kbhit(void);
int getch(void);

char getRand();
char getWidth(void);
char getHeight(void);
void shMatrix(char width, char height, char array[height][width], char figureNow);

void main(void)
{
  char width = 8,
       height = 15,
       array[8][15];
  memset(array, 0, height * width);
  char figureNow = getRand();
  startGame(array, figureNow);
  shMatrix(width, height, array, figureNow);



  return;
}

short * matrixFigure(char figure)
{
  if(figure == 0)
    return "11";
  else if (figure == 1)
    return "1111";
  else if (figure == 2)
    return "1";
  else if (figure == 3)
    return "  1";
  else if (figure == 4)
    return " 11";
  else if (figure == 5)
    return "11";
  else if (figure == 6)
    return " 1 ";
}
short * matrixFigure2(char figure) 
{
  if(figure == 0)
    return "11";
  else if (figure == 1)
    return "";
  else if (figure == 2)
    return "111";
  else if (figure == 3)
    return "111";
  else if (figure == 4)
    return "11";
  else if (figure == 5)
    return " 11";
  else if (figure == 6)
    return "111";
}
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
  
void shMatrix(char width, char height, char array[height][width],char figureNow) 
{
  char figure = figureNow;
  char * mat = matrixFigure(figure);
  char * mat2 = matrixFigure2(figure);
  system("clear");
  for(char i = 0;i < height;i++)
  {
    printf("| ");
      for(char j = 0;j < width;j++){
        if (array[i][j] == 1) {
          printf(AC_GREEN"1 %s", AC_RESET);
        } else {printf("0 ", array[i][j]);}
      }
      if(i == 3)
        printf("| Score = %d\n", 55);
      else if (i == 5)
        printf("| Now part is:\n");
      else if (i == 7)
        printf("|    %s\n", mat);
      else if (i == 8)
        printf("|    %s\n", mat2);
      else
        printf("| \n");
      
  }
}
char getRand()
{
  srand(time(NULL));
  int r = rand() % 7;
  return r;
}