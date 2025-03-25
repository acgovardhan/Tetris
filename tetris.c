#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

int background[MAX][MAX];
int tempBack[MAX][MAX]={0};
int rmrow[MAX][MAX]={0};
int n,m;//position of block;
int curr_shape;
int score=0;


void saveTemp()
{
  for(int i=0;i<MAX;i++)
  {
    for(int j=0;j<MAX;j++)
    {
      tempBack[i][j]=background[i][j];
    }
  }
}

void pasteTemp()
{
  for(int i=0;i<MAX;i++)
  {
    for(int j=0;j<MAX;j++)
    {
      background[i][j]=tempBack[i][j];
    }
  }
}

void clear()
{
  for(int i=0;i<MAX;i++)
	{
		for(int j=0;j<MAX;j++)
		{
			background[i][j]=0;
		}
	}
}

void display()
{
	for(int i=0;i<MAX;i++)
	{
	        printf("<-- | ");
		for(int j=0;j<MAX;j++)
		{
		        if(background[i][j]==0)
		        {
		          printf("%s"," .");
		        }
		        else if(background[i][j]==1)
		        {
		          printf("%s","▓▓");
		        }
			
		}
		printf(" | -->");
		printf("\n");
	}
	printf("\nScore :%d\n",score*MAX);
		
}


//I shape
void I1(int n,int m)
{
  for(int i=0;i<4;i++)
  {
    background[i+n][m]= 1;
  }
}
void IR(int n,int m)
{
  for(int i=0;i<4;i++)
  {
    background[n][i+m]=1;
  } 
}

//Square
void square(int n,int m)
{
  background[n][m]=1;
  background[n+1][m]=1;
  background[n][m+1]=1;
  background[n+1][m+1]=1;
}

//S shape
void S1(int n,int m)
{
  background[n][m+1]=1;
  background[n][m+2]=1;
  background[n+1][m]=1;
  background[n+1][m+1]=1;
}
void SR(int n,int m)
{
  background[n][m]=1;
  background[n+1][m]=1;
  background[n+1][m+1]=1;
  background[n+2][m+1]=1;
}

//Z shape
void Z1(int n,int m)
{
  background[n][m]=1;
  background[n][m+1]=1;
  background[n+1][m+1]=1;
  background[n+1][m+2]=1;
}
void ZR(int n,int m)
{
  background[n][m+1]=1;
  background[n+1][m]=1;
  background[n+1][m+1]=1;
  background[n+2][m]=1;
}

//T shapes
void T1(int n,int m)
{
  background[n][m]=1;
  background[n][m+1]=1;
  background[n][m+2]=1;
  background[n+1][m+1]=1;
}
void T1R(int n,int m)
{
  background[n][m+1]=1;
  background[n+1][m]=1;
  background[n+1][m+1]=1;
  background[n+2][m+1]=1;
}

void T2(int n,int m)
{
  background[n][m+1]=1;
  background[n+1][m]=1;
  background[n+1][m+1]=1;
  background[n+1][m+2]=1;
}
void T2R(int n,int m)
{
  background[n][m]=1;
  background[n+1][m]=1;
  background[n+1][m+1]=1;
  background[n+2][m]=1;
}


//L shapes
void L1(int n,int m)
{
  background[n][m]=1;
  background[n+1][m]=1;
  background[n+2][m]=1;
  background[n+2][m+1]=1;
}
void L1R(int n,int m)
{
  background[n][m]=1;
  background[n][m+1]=1;
  background[n][m+2]=1;
  background[n+1][m]=1;
}

void L2(int n,int m)
{
  background[n][m+1]=1;
  background[n+1][m+1]=1;
  background[n+2][m]=1;
  background[n+2][m+1]=1;
}
void L2R(int n,int m)
{
  background[n][m]=1;
  background[n+1][m]=1;
  background[n+1][m+1]=1;
  background[n+1][m+2]=1;
}


void callShape(int shapenum)
{
  switch(shapenum)
  {
    case 1:   I1(n,m);
              break;     
    case 2:   S1(n,m);
              break;
    case 3:   Z1(n,m);
              break;
    case 4:   T1(n,m);
              break;
    case 5:   T2(n,m);
              break;
    case 6:   L1(n,m);
              break;
    case 7:   L2(n,m);
              break;
    case 8:   square(n,m);
              break;
    case 9:   IR(n,m);
              break;
    case 10:  SR(n,m);
              break;
    case 11:  ZR(n,m);
              break;
    case 12:  T1R(n,m);
              break;
    case 13:  T2R(n,m);
              break;
    case 14:  L1R(n,m);
              break;
    case 15:  L2R(n,m);
              break;
    default:  printf("Erorr!!\n");
              break;
  }
}
int randomShape()
{
  return (rand() % 15) + 1;
}

int rotate_opp(int shapenum)
{
  if(shapenum<8) return shapenum+8;
  else if(shapenum>8) return shapenum-8;
  else if(shapenum==8) return shapenum;
}

int checkRight(int shapenum)
{
  if(shapenum==1) return 1;
  else if(shapenum==9)return 4;
  else if(shapenum<=5 || shapenum>=14) return 3;
  else return 2;
}

int checkLowest(int shapenum)
{
  if(shapenum==1) return 3;
  else if(shapenum==8) return 1;
  else if(shapenum==9)return 0;
  else if(shapenum<=5 || shapenum>=14) return 1;
  else return 2;
}

int checking(int shape)
{
  if(shape == 1)
  {
    if(background[n+4][m]==1) return 1;
    else return -1;
  }
  else if(shape == 2)
  {
    if(background[n+2][m]==1 || background[n+2][m+1]==1 || background[n+1][m+2]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 3)
  {
    if(background[n+1][m]==1 || background[n+2][m+1]==1 || background[n+2][m+2]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 4)
  {
    if(background[n+1][m]==1 || background[n+1][m+2]==1 || background[n+2][m+1]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 5)
  {
    if(background[n+2][m]==1 || background[n+2][m+1]==1 || background[n+2][m+2]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 6)
  {
    if(background[n+3][m]==1 || background[n+3][m+1]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 7)
  {
    if(background[n+3][m]==1 || background[n+3][m+1]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 8)
  {
    if(background[n+2][m]==1 || background[n+2][m+1]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 9)
  {
    if(background[n+1][m]==1 || background[n+1][m+1]==1 || background[n+1][m+2]==1 || background[n+1][m+3]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 10)
  {
    if(background[n+2][m]==1 || background[n+3][m+1]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 11)
  {
    if(background[n+2][m+1]==1 || background[n+3][m]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 12)
  {
    if(background[n+2][m]==1 || background[n+3][m+1]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 13)
  {
    if(background[n+3][m]==1 || background[n+2][m+1]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 14)
  {
    if(background[n+2][m]==1 || background[n+1][m+1]==1 || background[n+1][m+2]==1)
    {
      return 1;
    }
    else return -1;
  }
  else if(shape == 15)
  {
    if(background[n+2][m]==1 || background[n+2][m+1]==1 || background[n+2][m+2]==1)
    {
      return 1;
    }
    else return -1;
  }
}


void right()
{
  int x= checkRight(curr_shape);
  if(m+x<MAX)
  {
    n=n+1;
    m=m+1;
  }
  else
  {
    n=n+1;
  }
  
}

void left()
{
  if(m-1>=0)
  {
    n=n+1;
    m=m-1;
  }
  else
  {
    n=n+1;
  }
  
}

void down()
{
  n=n+1;
}

int checkSucc()
{
  int count;
  for(int i=0;i<MAX;i++)
  {
    count=0;
    for(int j=0;j<MAX;j++)
    {
      if(background[i][j]==0) break;
      count++;
    }
    if(count==MAX) return i;
  }
  return -1;
}

void removeRow(int n)
{
  int k=MAX-1;
  for(int i=MAX-1;i>=0;i--)
  {
    for(int j=0;j<MAX;j++)
    {
      if(i==n) 
      {
        k++;
        break;
      }
      rmrow[k][j]=tempBack[i][j];
    }
    k--;
  }
  
  for(int i=0;i<MAX;i++)
  {
    for(int j=0;j<MAX;j++)
    {
      tempBack[i][j]=rmrow[i][j];
    }
  }
}

int gameover()
{
  for(int i=0;i<MAX;i++)
  {
    if(background[0][i]==1)
    {
      return 1;
    }
  }
  return -1;
}

  
int main()
{
        srand(time(0));
	
	char ch;
	int temp,low;
	int b;
	
	
	while(1)
	{
	  int succ = checkSucc();
	  if(succ != -1)
	  {
	    score++;
	    removeRow(succ);
	  }
	  int gg = gameover();
	  if(gg != -1)
	  {
	    printf("\n<---GAME OVER--->\n");
	    printf("<---SCORE : %d --->\n",score*MAX);
	    break;
	  }
	  n=0,m=MAX/2;
	  clear();
	  pasteTemp();
	  curr_shape = randomShape();
	  callShape(curr_shape);
	  printf("\033[H\033[J");
	  display();
	  
	  while(1)
	  {
	    b = checking(curr_shape);
	    low = checkLowest(curr_shape);
	    if(n+low == MAX-1 || b==1)
	    {
	      saveTemp();
	      printf("hello");
	      break;
	    }
	    printf(" :");
	    scanf(" %c",&ch);
	    
            if(ch=='R')
            {
              right();
            }
            else if(ch=='D')
            {
              down();
            }
            else if(ch=='U')
            {
              n=n+1;
              temp=curr_shape;
              curr_shape=rotate_opp(temp);
            }
            else if(ch=='L')
            {
              left();
            }
            else
            {
              printf("Error !!!\n");
            }
            printf("\033[H\033[J");//ansi escape
            clear();
            pasteTemp();
            callShape(curr_shape);
            display();
	  }
	}

	return 0;
}
