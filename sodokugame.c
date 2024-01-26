#include<stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h> // For Windows
#else
#include <unistd.h> // For Unix-like systems (Linux, macOS)
#endif
typedef int u16;
u16 check_result(int num,char (*a)[9],int row,int column)
{
    u16  flag_row=0,flag_column=0,flag_block=0;
    //check row & column  duplicate
    for(int i=0; i<9; i++)
    {

        if((*(*(a+row)+i))==num)
        {
            flag_row=1;

        }
        if((*(*(a+i)+column))==num)
        {
            flag_column=1;
            break;
        }
    }
    //check block inshallah
    //---------------------------------------------------
    //top left block
    if (column<3 && column>=0 &&row>=0 && row<3)
    {
       for(int i=0;i<3;i++)
       {
          for(int j=0;j<3;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }
     //mid left block
    if (column<3 && column>=0 &&row>=3 && row<6)
    {
       for(int i=3;i<6;i++)
       {
          for(int j=0;j<3;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }
   //down left block
    if (column>=0 && column<3  &&row>=6 && row<9)
    {
       for(int i=6;i<9;i++)
       {
          for(int j=0;j<3;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }
    //top mid block
    if (column<6 && column>=3 &&row>=0 && row<3)
    {
       for(int i=0;i<3;i++)
       {
          for(int j=3;j<6;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }
    //center block
    if (column<6 && column>=3 &&row>=3 && row<6)
    {
       for(int i=3;i<6;i++)
       {
          for(int j=3;j<6;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }
    //mid down block
    if (column<6 && column>=3 &&row>=6 && row<9)
    {
       for(int i=6;i<9;i++)
       {
          for(int j=3;j<6;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }
    //right top block
    if (column<9 && column>=6 &&row>=0 && row<3)
    {
       for(int i=0;i<3;i++)
       {
          for(int j=6;j<9;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }
    //right mid block
    if (column<9 && column>=6 &&row>=3 && row<6)
    {
       for(int i=3;i<6;i++)
       {
          for(int j=6;j<9;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }
    //right down block
    if (column<9 && column>=6 &&row>=6 && row<9)
    {
       for(int i=6;i<9;i++)
       {
          for(int j=6;j<9;j++)
          {
               if((*(*(a+i)+j))==num)
               {
                  flag_block=1;
               }
          }
       }
    }

    //---------------------------------------------------
    //checking...
    if(flag_row==0 && flag_column==0 && flag_block==0)
    {
        return 1;
    }
    else
    {
       if(flag_row==1)
       {
          printf("%d =>row duplicate \n",num);

       }
      if(flag_column==1)
       {
          printf("%d =>column duplicate\n",num);

       }
       if (flag_block==1)
       {
          printf("%d =>block duplicate\n",num);
       }
       printf("try again in 3 sec\n");
       sleep(3);
       return 0;
    }

}
void change_element(char (* a)[9],char (* image)[9])
{
    int row,column,num;
    fflush(stdin);
    printf("Enter The Row Number\n");
    scanf("%d",&row);
	
    printf("Enter The Column Number\n");
    scanf("%d",&column);
	if(column>8 ||column<0 || row>8 ||row<0)
	{
		printf("wrong row or column  entry");
		sleep(3);
		return;
	}
    printf("Enter The Number You Want To Change(1 to 9\n");
    scanf("%d",&num);
    if(row>=0 && row <9 && column>=0 && column <9 && num>0 && num <10)
    {
        if( *(*(image+row)+column)==(char)32 )
        {
            if(check_result(num,a,row,column))
            {
                *(*(a+row)+column)=num;
            }
        }
        else
        {
            printf("\033[1;31myou can't change that num\033[0m^_^\n");
            //printf("item=%d",(*(a+row)));
            sleep(5);
            system("cls");

            return;
        }
    }
    else
    {
       printf("wrong entry\n");
       sleep(3);
       system( "cls");
    }



}
void print_sodoku(char (*a)[9],char (*image)[9])
{
    printf("column   \033[1;31m 0   1   2    3   4   5    6   7   8    \033[0m Row \n");
    printf("        \033[1;36m=======================================\033[0m\n");
    for(int j=0; j<9; j++)
    {
        if (j==3 ||j==6 &&~(j==0))
        {
            printf("        \033[1;36m|===|===|===||===|===|===||===|===|===|\033[0m\n");
        }
        else if (j>0)
        {
            printf("        \033[1;36m|---|---|---||---|---|---||---|---|---|\033[0m\n");
        }

        printf("        \033[1;36m|\033[0m");

        for(int i=0; i<9; i++)
        {
            if(*(*(a+j)+i)==32 && *(*(image+j)+i)==32 )
            {
                printf("   ");
            }
            else if(*(*(a+j)+i)!=32 && *(*(image+j)+i)!=32)
            {
                printf(" \033[1;34m%d\033[0m ",*(*(a+j)+i));
            }
            else if (*(*(a+j)+i)!=32 && *(*(image+j)+i)==32)
            {
                printf(" \033[1;32m%d\033[0m ",*(*(a+j)+i));
            }
            if (i==2 ||i==5)
            {
                printf("\033[1;36m||\033[0m");
            }
            else
            {
                printf("\033[1;36m|\033[0m");
            }


        }

        printf("    \033[1;31m%d\033[0m\n",j);

    }

    printf("        \033[1;36m=======================================\033[0m\n");

}
int main()
{
  int x,y,num;
    char game;
    printf("choose a game \n 1.sedoku\n");
    scanf("%d",&game);
    system("cls");
    char a[9][9]=
    {
        {5,3,32,32,7,32,32,32,32},
        {6,32,32,1,9,5,32,32,32},
        {32,9,8,32,32,32,32,6,32},

        {8,32,32,32,6,32,32,32,3},
        {4,32,32,8,32,3,32,32,1},
        {7,32,32,32,2,32,32,32,6},

        {32,6,32,32,32,32,2,8,32},
        {32,32,32,4,1,9,32,32,5},
        {32,32,32,32,8,32,32,7,9}
    };
    char image[9][9]=
    {
        {5,3,32,32,7,32,32,32,32},
        {6,32,32,1,9,5,32,32,32},
        {32,9,8,32,32,32,32,6,32},

        {8,32,32,32,6,32,32,32,3},
        {4,32,32,8,32,3,32,32,1},
        {7,32,32,32,2,32,32,32,6},

        {32,6,32,32,32,32,2,8,32},
        {32,32,32,4,1,9,32,32,5},
        {32,32,32,32,8,32,32,7,9}

    };
    switch(game)
    {
    case 1:
       printf("Sudoku is played on a grid of 9 x 9 spaces.\n Within the rows and columns are 9 squares (made up of 3 x 3 spaces). \n Each row, column and square (9 spaces each) needs to be filled out with the numbers 1-9, \n without repeating any numbers within the row, column or square. \n hope you have fun \n eng.omar mohamed abdelmaksod  \n tel/01090875825 \n for any feedback pls contact me ^_^");
            sleep(10);
            system("cls");
        while (1)
        {

            print_sodoku(a,image);
            change_element(a,image);
             system( "cls");



        }
        break;




    default:
        printf("wrong number");
    }
}
