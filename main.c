#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 4

void print_board(int n,int board[n][n]);
void next_board(int n,int board[n][n],char c);
void swap(int*a,int*b);
int checkGameover(int n, int board[n][n]);

int main (int argc, char *argv[]) {
  printf("Press any key to conitnue\n");
  int c;

  system("/bin/stty raw onlcr");  // enterを押さなくてもキー入力を受け付けるようになる

  //ここからかく
  srand(time(NULL));//ランダムにする
  int w[4][4];//変えるならここも変える

  //初期値出す
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      w[i][j]=0;
    }
  }

  int n1;
  int n2;
  int n1i,n1j,n2i,n2j;
  n1=rand()%16;
  n2=rand()%16;
  while(n2==n1){
    n2=rand()%16;
  }
  
  
  n1i=n1/4;
  n1j=n1-n1i*4;

  n2i=n2/4;
  n2j=n2-n2i*4;
  int r1=rand()%2;
  int r2=rand()%2;

  if(r1==0){
    w[n1i][n1j]=2;
  }else{
    w[n1i][n1j]=4;
  }
  if(r2==0){
    w[n2i][n2j]=2;
  }else{
    w[n2i][n2j]=4;
  }
  

  
  




  

  //ここまで書いた


  while(c != '.') {
    system("clear");
    printf("Press '.' to close\r\n");
    printf("up:'↑'\r\n");
    printf("down:'↓'\r\n");
    printf("right:'→' \r\n");
    print_board(4,w);
    if(c=='A'){
      printf("You pressed ↑\r\n");
    }else if(c=='B'){
      printf("You pressed ↓\r\n");
    }else if(c=='C'){
      printf("You pressed →\r\n");
    }else if(c=='D'){
      printf("You pressed ←\r\n");
    }else{
      printf("Please press ↑,↓,→or←\r\n");
    } 

    do{
      c = getchar();
    }while(c!='A'&&c!='B'&&c!='C'&&c!='D'&&c!='.');  
    if(c=='.')break;
    

    next_board(4,w,c);
    


    if(checkGameover(4,w)==10){
      printf("\x1b[31mGame over\x1b[39m");
      break;
    }else if(checkGameover(4,w)==2){
      printf("\x1b[33mCongradulation!!\x1b[39m");
      break;
    }  
  }

  system("/bin/stty cooked");  // 後始末

  return 0;
}

void swap(int*a,int* b){
  int c;
  c=*a;
  *a=*b;
  *b=c;


}
void print_board(int n,int board[n][n]) {
  //以下、表示している。
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("+-----");
      if(j==3){
        printf("+");
      }
    }
    printf("\r\n");
    printf("|");
    for(int j=0;j<4;j++){
      if(board[i][j]==0){
        printf("     ");
      }
      if(board[i][j]==2){
        printf("  \x1b[1m\x1b[36m2\x1b[39m\x1b[0m  ");
      }
      if(board[i][j]==4){
        printf("  \x1b[1m\x1b[34m4\x1b[39m\x1b[0m  ");
      }
      if(board[i][j]==8){
        printf("  \x1b[1m\x1b[32m8\x1b[39m\x1b[0m  ");
      }
      if(board[i][j]==16){
        printf(" \x1b[1m\x1b[33m16\x1b[39m\x1b[0m  ");
      }
      if(board[i][j]==32){
        printf(" \x1b[1m\x1b[35m32\x1b[39m\x1b[0m  ");
      }
      if(board[i][j]==64){
        printf(" \x1b[1m\x1b[31m64\x1b[39m\x1b[0m  ");
      }
      if(board[i][j]==128){
        printf(" \x1b[1m\x1b[45m128\x1b[49m\x1b[0m ");
      }
      if(board[i][j]==256){
        printf(" \x1b[1m\x1b[46m256\x1b[49m\x1b[0m ");
      }
      if(board[i][j]==512){
        printf(" \x1b[1m\x1b[44m512\x1b[49m\x1b[0m ");
      }
      if(board[i][j]==1024){
        printf("\x1b[1m\x1b[42m1024\x1b[49m\x1b[0m ");
      }
      if(board[i][j]==2048){
        printf("\x1b[1m\x1b[41m	2048\x1b[49m\x1b[0m ");
      }
      printf("|");
    }
    
    printf("\r\n");
  }
  for(int j=0;j<4;j++){
    printf("+-----");
    if(j==3){
      printf("+");
    }
  }
  printf("\r\n");
  
  //保険
  /*
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      printf("%d ",board[i][j]);
    }
    printf("\r\n");
  }
  */
  
}

void next_board(int n,int board[n][n],char c){
  //↑
  if(c=='A'){
    int new[4][4];
    for(int j=0;j<4;j++){
      for(int i=0;i<4;i++){
        if(board[i][j]==0){
          
          for(int i2=i;i2<4;i2++){
            if(board[i2][j]!=0){
              swap(&board[i][j],&board[i2][j]);
              break;

            }
          }
        }
      }
    }
    for(int j=0;j<4;j++){
      for(int i=0;i<3;i++){
        if(board[i][j]==board[i+1][j]){
          board[i][j]=2*board[i][j];
          board[i+1][j]=0;
        }
      }
    }
    for(int j=0;j<4;j++){
      for(int i=0;i<4;i++){
        if(board[i][j]==0){
          
          for(int i2=i;i2<4;i2++){
            if(board[i2][j]!=0){
              swap(&board[i][j],&board[i2][j]);
              break;

            }
          }
        }
      }
    }
  }
  //↓
  if(c=='B'){
    int new[4][4];
    for(int j=0;j<4;j++){
      for(int i=0;i<4;i++){
        if(board[3-i][3-j]==0){
          
          for(int i2=i;i2<4;i2++){
            if(board[3-i2][3-j]!=0){
              swap(&board[3-i][3-j],&board[3-i2][3-j]);
              break;

            }
          }
        }
      }
    }
    for(int j=0;j<4;j++){
      for(int i=0;i<3;i++){
        if(board[3-i][3-j]==board[3-(i+1)][3-j]){
          board[3-i][3-j]=2*board[3-i][3-j];
          board[3-(i+1)][3-j]=0;
        }
      }
    }
    for(int j=0;j<4;j++){
      for(int i=0;i<4;i++){
        if(board[3-i][3-j]==0){
          
          for(int i2=i;i2<4;i2++){
            if(board[3-i2][3-j]!=0){
              swap(&board[3-i][3-j],&board[3-i2][3-j]);
              break;

            }
          }
        }
      }
    }
  }
  //→
  if(c=='C'){
    int new[4][4];
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(board[3-i][3-j]==0){
          
          for(int j2=j;j2<4;j2++){
            if(board[3-i][3-j2]!=0){
              swap(&board[3-i][3-j],&board[3-i][3-j2]);
              break;

            }
          }
        }
      }
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<3;j++){
        if(board[3-i][3-j]==board[3-i][3-(j+1)]){
          board[3-i][3-j]=2*board[3-i][3-j];
          board[3-i][3-(j+1)]=0;
        }
      }
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(board[3-i][3-j]==0){
          
          for(int j2=j;j2<4;j2++){
            if(board[3-i][3-j2]!=0){
              swap(&board[3-i][3-j],&board[3-i][3-j2]);
              break;

            }
          }
        }
      }
    }
  }
  //←
  if(c=='D'){
    int new[4][4];
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(board[i][j]==0){
          
          for(int j2=j;j2<4;j2++){
            if(board[i][j2]!=0){
              swap(&board[i][j],&board[i][j2]);
              break;

            }
          }
        }
      }
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<3;j++){
        if(board[i][j]==board[i][j+1]){
          board[i][j]=2*board[i][j];
          board[i][j+1]=0;
        }
      }
    }
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(board[i][j]==0){
          
          for(int j2=j;j2<4;j2++){
            if(board[i][j2]!=0){
              swap(&board[i][j],&board[i][j2]);
              break;

            }
          }
        }
      }
    }
  }

  if(checkGameover(4,board)==0){
    int z,zi,zj;
    do{
      z=rand()%16;
      zi=z/4;
      zj=z-zi*4;
    }while(board[zi][zj]!=0);

    int r=rand()%3;
    if(r==0){
      board[zi][zj]=4;
    }else{
      board[zi][zj]=2;
    }
    
  }

  
}

int checkGameover(int n, int board[n][n]){
  int c=1;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(board[i][j]==0){
        c=0;
      }
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      if(board[i][j]==2048){
        c=2;
      }
    }
  }
  
  if(c==1){
    int saveA[4][4];
    int saveB[4][4];
    int saveC[4][4];
    int saveD[4][4];
    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        saveA[i][j]=board[i][j];
        saveB[i][j]=board[i][j];
        saveC[i][j]=board[i][j];
        saveD[i][j]=board[i][j];
        
      }

    }
    next_board(4,saveA,'A');
    next_board(4,saveB,'B');
    next_board(4,saveC,'C');
    next_board(4,saveD,'D');

    int d=1;

    for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
        if(saveA[i][j]==board[i][j] && saveB[i][j]==board[i][j] && saveC[i][j]==board[i][j] && saveD[i][j]==board[i][j]){
          d=d*1;
        }else{
          d=0;
        } 
      }
    }

    if(d==1){
      c=10;
    }    
  }


  return c;

}
