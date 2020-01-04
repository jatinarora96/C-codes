#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include"functions.c"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
void menu();
void openmethod();
void closedmethod();
void display();
void gotoxy(int x,int y);
int acsivalue(void);
int menue(void);
int kbhit(void);
void display();
void method();
void regularfalsimethod();
void bisectionmethod();
void fixedpointmethod();
void newraphsonmethod();
void secantmethod();
void solutionofLE();
void simpson();
void trapiz();
void integration();
void legrange();
void newbackdiff();
void newfordiff();
void newdivdiff();
void newton();
void interp();
void parse();
void start();
void reg();
//returning the asci value
int ascivalue(void)
{
    int no;
    while(1)
    {
     no=kbhit();
      if(no!=0)
       break;
    }
    no=getchar();
    return no;
}

int menue(void)
{
    int no;
    while(1)
    {
     no=kbhit();
      if(no!=0)
       break;
    }
    if(no!=10)
    no=getchar();
    return no;
}

int kbhit(void)
 {
   struct termios oldt, newt;
   int ch,retch;
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
     retch=ch;
     ungetc(ch, stdin);
     return retch;
   }

   return 0;
 }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~THE MAIN FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void main()
{
     
    start();

    printf("\n\t\t\t\tTHANK YOU FOR RUNNING THE PROGRAM\n");
 
}
//this function displays the starting menu
void start()
{
   
  system("clear");
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\t\t\t\t\t\tUSE THE FOLLOWING KEYS:\n\t\t\t\t\t\t8-TO GO UP\n\t\t\t\t\t\t2-TO GO DOWN\n");
            printf("\n\n");
            printf("\t\t\t\t\t");
            printf(" \e[0;59m|  |  WELCOME  |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t \e[0;31mPARSE AN EXPRESSION\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t  \e[0;32mNUMERICAL METHODS\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t        \e[0;31mEXIT\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                parse();
                getchar();
                break;

            case 2:
                display();
                getchar();
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
//this function displays the numerical methods menu
void display()
{
    system("clear");
    getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("     \e[0;59m|  |  NUMERICAL METHODS |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t     \e[0;31mREGRESSION\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t    \e[0;32mROOT FINDING\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t    \e[0;31mINTERPOLATION\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            printf("\n");
            printf("\t\t\t\t\t     \e[0;32mINTEGRATION\e[m");
            if(num!=4)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            printf("\n");
            printf("\t\t\t\t     \e[0;31mSOLUTION OF LINEAR EQUATION\e[m");
            if(num!=5)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            printf("\n");
            printf("\t\t\t\t\t        \e[0;32mRETURN\e[m");
            if(num!=6)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<6))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }

        switch(no)
        {
            case 1:
         	 
                reg();

                getchar();

                break;

            case 2:
                method();

                getchar();

                break;

            case 3:

                interp();

                getchar();

                break;

            case 4:
                    
 		        integration();

                getchar();
         
                break;


            case 5:
                solutionofLE();

                getchar();

                break;

            case 6:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}


void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}
//this function displays the parse menu
void parse()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    double d;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("     \e[0;59m|  |  PARSING  |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t   \e[0;31mINFORMATION ABOUT PARSING\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t   \e[0;32mIMPLEMENTATION OF PARSING\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t           \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                info();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                d=parsing();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
//this function displays the regression menu
void reg()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    double d;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("         \e[0;70m|  |  REGRESSION |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t   \e[0;31mLINEAR REGRESSION\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;32mPOLYNOMIAL REGRESSION\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t        \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                linreg();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                polyreg();
                getchar();
		        getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}

//this function displays the open and closed method menu
void method()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf(" \e[0;70m|  |  NUMERICAL METHODS |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t \e[0;31mCLOSED METHODS\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t  \e[0;32mOPEN METHODS\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t     \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                closedmethod();
                getchar();
                break;

            case 2:
                openmethod();
                getchar();
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
//this function displays the interpolation menu
void interp()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("\e[0;70m| |  INTERPOLATION  | | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t  \e[0;31mNEWTONS METHODS\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;32mLEGRANGE'S METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t       \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                newton();
                getchar();
                break;

            case 2:
                legrange();
                getchar();
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
//this function displays the newton's method
void newton()
{
 system("clear");
    getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    float d;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t");
            printf("                  | |INTERPOLATION| |\n");
            printf("\n\n\n");
            printf("\t\t\t           \e[0;31mNEWTONS DIVIDED DIFFERENCE METHOD\e[m");
            if(num==1)
                printf("\e[0;1m <<<\e[m\n");
            else
                printf("\n");
                
            printf("\n");//
            printf("\t\t\t           \e[0;32mNEWTONS FORWARD DIFFERENCE METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");// 
            printf("\t\t\t           \e[0;31mNEWTONS BACKWARD DIFFERENCE METHOD\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            printf("\n");
            printf("\t\t\t\t\t        \e[0;32mRETURN\e[m");
            if(num!=4)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;            
            key=menue();
            if((key==50)&&(num<4))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                newdivdiff();
                getchar();
                break;

            case 2:
                newfordiff();
                getchar();
                break;

            case 3:
                newbackdiff();
                getchar();
                break;

            case 4:
                i=1;
                system("clear");
                break;

            default:         
                printf("invalid entry\n");
                getchar();
                break ;     

        }

        k=0;

    }

}

void newdivdiff()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("      \e[0;70m|  | INTERPOLATION  |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t \e[0;31mINFORMATION ABOUT NEWTONS DIVIDED DIFFERENCE METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t \e[0;32mIMPLEMENTATION OF NEWTONS DIVIDED DIFFERENCE METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t     \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infondd();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                newtdd();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}

void newfordiff()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("      \e[0;70m|  | INTERPOLATION  |  | \e[m");
            printf("\n\n\n\n\n");
            printf("\t\t\t \e[0;31mINFORMATION ABOUT NEWTONS FORWARD DIFFERENCE METHOD\e[m");

            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t \e[0;32mIMPLEMENTATION OF NEWTONS FORWARD DIFFERENCE METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t      \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infonfd();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                newtfd();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
   
void newbackdiff()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("      \e[0;70m|  | INTERPOLATION  |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t \e[0;31mINFORMATION ABOUT NEWTONS BACKWARD DIFFERENCE METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t \e[0;32mIMPLEMENTATION OF NEWTONS BACKWARD DIFFERENCE METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t      \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infonbd();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                newtbd();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
//this function displays the legrange's method
void legrange()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("      \e[0;70m|  | INTERPOLATION  |  | \e[m"); 
            printf("\n\n\n\n\n");
            printf("\t\t\t\t \e[0;31mINFORMATION ABOUT LEGRANGE'S METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t \e[0;32mIMPLEMENTATION OF LEGRANGE'S METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t      \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infoleg();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                leg();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
//this function displays the integration menu
void integration()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("      \e[0;70m|  | INTEGRATION |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\e[0;31mINFORMATION ABOUT INTEGRATION USING NUMERICAL METHODS\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;32mTRAPIZOIDAL METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t  \e[0;31mSIMPSON'S METHOD\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t      \e[0;32mRETURN\e[m");
            if(num!=4)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<4))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infoin();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                trapiz();
                getchar();
                system("clear");
                break;

            case 3:
                simpson();
                getchar();
                system("clear");
                break;

            case 4:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}

void trapiz()
{
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("        \e[0;70m|  | INTEGRATION |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t \e[0;31mINFORMATION ABOUT TRAPIZOIDAL METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t \e[0;32mIMPLEMENTATION OF TRAPIZOIDAL METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t         \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infotr();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                trapi();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}

void simpson()
{
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("        \e[0;70m|  | INTEGRATION |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t \e[0;31mINFORMATION ABOUT SIMPSON'S METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t \e[0;32mIMPLEMENTATION OF SIMPSON'S METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t       \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infosi();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                simp();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
//this function displays the solution of linear equation menu
void solutionofLE()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t");
            printf("   \e[0;70m|  |  SOLUTION OF LINEAR EQUATIONS  |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t \e[0;31mGAUSSIAN ELEMINATION METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t      \e[0;32mDOLITTLE'S METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t           \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                gausse();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                dolittle();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
//this function displays the open method menu
void openmethod()
{
    system("clear");
    getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    float d;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("     | |OPEN METHODS| |\n");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t       \e[0;31mSECANT METHOD\e[m");
            if(num==1)
                printf("\e[0;1m <<<\e[m\n");
            else
                printf("\n");
                
            printf("\n");//
            printf("\t\t\t\t\t    \e[0;32mNEWTON-RAPHSON METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;31mFIXED POINT ITERATION METHOD\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            printf("\n");
            printf("\t\t\t\t\t            \e[0;32mRETURN\e[m");
            if(num!=4)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;            
            key=menue();
            if((key==50)&&(num<4))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                secantmethod();
                getchar();
                break;

            case 2:
                newraphsonmethod();
                getchar();
                break;

            case 3:
                fixedpointmethod();
                getchar();
                break;

            case 4:
                i=1;
                system("clear");
                break;

            default:         
                printf("invalid entry\n");
                getchar();
                break ;     

        }

        k=0;

    }

}

void secantmethod()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("       | |OPEN METHODS| |\n");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t \e[0;31mINFORMATION ABOUT SECANT METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;32mIMPLEMENTATION OF SECANT MEHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t          \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infos();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                secant();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}

void newraphsonmethod()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("           | |OPEN METHODS| |\n");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t \e[0;31mINFORMATION ABOUT NEWTON-RAPHSONS METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;32mIMPLEMENTATION OF NEWTON-RAPHSONS METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t                 \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infon();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                newraphson();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
void fixedpointmethod()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("          | |OPEN METHODS| |\n");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t \e[0;31mINFORMATION ABOUT FIXED POINT METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;32mIMPLEMENTATION OF FIXED POINT METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t              \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infof();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                fixedp();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}

//this function displays the closed method menu
void closedmethod()
{
    system("clear");
    getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    float d;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("     | | ROOT FINDING | |\n");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t      \e[0;31mBISECTION METHOD\e[m");
            if(num==1)
                printf("\e[0;1m <<<\e[m\n");
            else
                printf("\n");
                
            printf("\n");//
            printf("\t\t\t\t\t    \e[0;32mREGULAR-FALSI METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");
            printf("\t\t\t\t\t            \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;            
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                bisectionmethod();
                getchar();
                break;

            case 2:
                regularfalsimethod();
                getchar();
                break;

            case 3:
                i=1;
                system("clear");
                break;

            default:         
                printf("invalid entry\n");
                getchar();
                break ;     

        }

        k=0;

    }

}

void bisectionmethod()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("     \e[0;70m|  |  ROOT FINDING |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t \e[0;31mINFORMATION ABOUT BISECTION METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;32mIMPLEMENTATION OF BISECTION METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t             \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
           case 1:
		system("clear");
                infob();
                getchar();
		getchar();
		system("clear");
                break;

            case 2:
		system("clear");
                bisect();
                getchar();
		getchar();
		system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
  
void regularfalsimethod()
{
   
   system("clear");
   getchar();
    int no=1,i=0,num=1,j=0,key,k=1;
    while(i==0)
    {
        while(j==0)
        {
            if(k==1)
                system("clear");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t");
            printf("       \e[0;70m|  |  ROOT FINDING  |  | \e[m");  
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t \e[0;31mINFORMATION ABOUT REGULAR-FALSI METHOD\e[m");
            if(num==1)
                printf("\e[0;9m <<<\e[m\n");
            else
                printf("\n");
            printf("\n");//
            printf("\t\t\t\t\t \e[0;32mIMPLEMENTATION OF REGULAR-FALSI METHOD\e[m");
            if(num!=2)
                printf("\n");
            else
                printf("\e[0;m <<<\e[m\n");
            printf("\n");//
            printf("\t\t\t\t\t                \e[0;31mRETURN\e[m");
            if(num!=3)
                printf("\n");
            else
                printf("\e[0;1m <<<\e[m\n");
            k=1;
            key=menue();
            if((key==50)&&(num<3))
            {
                no++;
                num++;
            }
            else if((key==56)&&(num>1))
            {                
                no--;
                num--;
            }
            else if(key==10)
                break;
        }
        switch(no)
        {
            case 1:
                system("clear");
                infor();
                getchar();
                getchar();
                system("clear");
                break;

            case 2:
                system("clear");
                regularfalsi();
                getchar();
                getchar();
                system("clear");
                break;

            case 3:
         
                i=1;
        
                system("clear");
         
                break;
     
            default: 
         
                printf("invalid entry\n");
         
                getchar();
        
                break ;     

        }

        k=0;

    }

}
  

