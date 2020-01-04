#include"newform2.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include <time.h>
#define MAX 10
#define max 10
#define err 0.0000001
#define MAXN 100
#define ORDER 4
#define de 0.01745329252 //converting into degrees
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STARTING OF FUNCTION DECLARATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//FUNCTION TO CHECK IF THE EXPRESSION IS VALID
int check(char str[10],int len2)
{
	FILE *fp2;
    	
	if(len2!=0)//CHECKING IF THE LENGTH OF THE EXPRESION IS ZERO
	{
	    	if(isdigit(str[0]))//CHECKING IF THE EXPRESION IS A DIGIT
		{
		    	return 1;
	    
		}
    		int len,i=0,t;
    		fp2=fopen("PRE.dat","r");//OPENING THE FILE IN WHICH THE FUNCTION WHICH CAN BE EVALUATED ARE PRESENT
    		char ch,str2[10]; 
    		ch=fgetc(fp2);
    

    		while(ch!=EOF)
    		{

    			i=0;
    			while(ch!='\n')
    			{
    				str2[i]=ch;
    				ch=fgetc(fp2);
    				i++;
        
    			}
		  	str2[i]='\0';
	      		len=strlen(str2);
           

	      		if(strcmp(str,str2)==0)//COMPARING IF THE STRING PASSED IS SAME AS THE STRING OBTAINED FROM THE FILE
				return 1;
	      		ch=fgetc(fp2);
      
		}
	  	return 0;//IF THE STRING PASSED IS NOT SAME THEN RETURN ZERO

    	} 
    
	else
		return 0;//IF THE LENGTH OF GIVEN STRING IS ZERO THEN RETURN 0

    	fclose(fp2);//CLOSING THE FILE

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF CHECK FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FUNCTION TO CALCULATE THE VALUES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

float calc(char s[10],double p)
{
               

    	double e=0.0;
    
	if(strcmp("sinx",s)==0) //IF THE STRING IS sinx                   
		e=sin(de*p);                        

	else if(strcmp("cosx",s)==0)  //IF THE STRING IS cosx                  
		e=cos(de*p);                        

	else if(strcmp(s,"x")==0)  //IF THE STRING IS x
		e=p;  

	else if(strcmp("tanx",s)==0) //IF THE STRING IS tanx
		e=tan(de*p);

	else if(strcmp("exp",s)==0)  //IF THE STRING IS expx
		e=exp(1.0);

	return e;      //RETURNING THE CALCULATED VALUE

}           
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF CALC FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FUNCTION TO ASSIGN THE VALUE BASED ON THE OPERATOR~~~~~~~~~~~~~~~~~~~~~~~~~~
int assign(double s1[],int top1,char x)
{

    	double  A=0.0,B=0.0;
    
	if(x=='*')//CHECKING IF THE OPERATOR IS '*'
    	{
    
	    	A=s1[top1];

		B=s1[--top1];

		s1[top1]=B*A;
        
		return top1;//RETURNING THE VALUE AFTER EVALUATION

    	}
    
	if(x=='/')//CHECKING IF THE OPERATOR IS '/'
    	{

	    	A=s1[top1];

		B=s1[--top1];
        
		s1[top1]=B/A;

		return top1;//RETURNING THE VALUE AFTER EVALUATION
    
	}

    	if(x=='+')//CHECKING IF THE OPERATOR IS '+'
	{
        
		A=s1[top1];

		B=s1[--top1];
        
		s1[top1]=B+A;

		return top1;//RETURNING THE VALUE AFTER EVALUATION
    
	}

    	if(x=='-')//CHECKING IF THE OPERATOR IS '-'
	{
        
		A=s1[top1];

		B=s1[--top1];
        
		s1[top1]=B-A;

		return top1;//RETURNING THE VALUE AFTER EVALUATION
    
	}

    	if(x=='^')//CHECKING IF THE OPERATOR IS '^'
	{
        
		A=s1[top1];

		B=s1[--top1];
        
		s1[top1]=pow(B,A);

		return top1;//RETURNING THE VALUE AFTER EVALUATION
	}

    	if(x=='(')
	{

		return top1;
    	}
    
	if(x=='\n')
    	{

		return top1;//RETURNING THE VALUE 
    	}

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF ASSIGN FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SECANT METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float fu(float x)//FUNCTION WHOSE ROOT IS TO BE EVALUATED
{
    	return(x*x-4*x-10); // f(x)=x^2-4x-10
}

float secant()
{

    	clock_t start, end;
	double cpu_time_used;
    	float a,b,i,d,e;//a,b ARE THE 2 INITIAL GUESSES AND i IS THE VALUE OF THE FUNCTION AT EACH ITERATION & e IS THE ALLOWED ERROR
    	int count=1,n;

    	start = clock();//TIMER STARTS
    	printf("\n\nThis method finds the root of the function f(x)=x^2-4x-10\n");
    	printf("\n\nEnter the values of a and b:\n"); //(a,b) MUST CONTAIN THE SOLUTION.
    	scanf("%f%f",&a,&b);//INITIAL GUESSES
	printf("Enter the values of allowed error and maximun number of iterations:\n");
    	scanf("%f %d",&e,&n);//NUMBER OF MAXIMUM ITERATIONS

    	do
	{

		if(fu(a)==fu(b))//IF BOTH a AND b ARE SAME
		{

	    		printf("\nSolution cannot be found as the values of a and b are same.\n");
			return 0;//NO SOLUTION CAN BE FOUND

		}
        
		i=(a*fu(b)-b*fu(a))/(fu(b)-fu(a));//EVALUATING  THE VALUE AT EACH ITERATION
		a=b;
		b=i;
		printf("Iteration No-%d    x=%f\n",count,i);
		count++;

		if(count==n)//COUNTING THE NUMBER OF ITERATION
		{

			break;

		}

    
	} while(fabs(fu(i))>e);//REPEAT THE PROCESS UNTILL THE FUNCTION VALUE IS GREATER THAN THE ALLOWED ERROR

    	end = clock();//ENDING THE TIMER
	printf("\n The required solution is %f\n",i);
    	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTime taken to execute in seconds : %lf\n", duration);//TIME TAKE
    	return i;//RETURNING THE ROOT OF THE FUNCTION
}
/*THIS FUNCTION CAN BE USED TO CALCULATE THE ROOT AF ANY GIVEN FUNCTION 
 *BUT THE VALUE RETURNING FROM THE FUNCTION fu(x) MUST BE CHANGED TO THE DESIRED FUNCTION 
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF SECANT FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NEWTON-RAPHSON METHOD ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

float fl(float x)//RETURNING THE VALUE OF THE FUNCTION
{
    
	return x*x+2*x-10;//f(x)=x*x+2*x-10
}

float df (float x)//RETURNING THE VALUE OF DERIVATIVE OF THE FUNCTION 
{

    	return (2*x+2);
}
int newraphson(void)
{

    	clock_t start, end;
	int itr, maxmitr;//maxmitr IS THE MAX. NO. OF ITERATIONS & itr IS THE ITERATION NUMBER
    	float h, x0, x1, allerr;//allerr IS THE ALLOWED ERROR & x0 IS THE INITIAL GUESS
    	double cpu_time_used;
	start = clock();//TIMER STARTS
    	printf("\n\nThis method finds the root of the function f(x)=x*x+2*x-10\n");
	printf("\nEnter x0, allowed error and maximum iterations\n");
    	scanf("%f %f %d", &x0, &allerr, &maxmitr);
    
	for (itr=1; itr<=maxmitr; itr++)
    	{
    
	    	h=fl(x0)/df(x0);
		x1=x0-h;
		printf(" At Iteration no. %3d, x = %9f\n", itr, x1);
		if (fabs(h) < allerr)//CHECKING IF THE VALUE IS LESSER THAN THE ERROR
		{

	    		printf(" After %3d iterations, root = %9f\n", itr, x1);
			return 0;

		}
		x0=x1;
    
	}

    	printf(" The required solution does not converge or iterations are insufficient\n");//IF THE VALUE DOES NOT CONVERGE
	end = clock();//END TIMER
    	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTime taken to execute in seconds : %lf", duration);
    	return 1;

}
 /*THIS FUNCTION CAN BE USED TO CALCULATE THE ROOT AF ANY GIVEN FUNCTION 
  *BUT THE VALUE RETURNING FROM THE FUNCTION fl(x) MUST BE CHANGED TO THE DESIRED FUNCTION 
  AND THE DERIVATIVE OF THE FUNCTION MUST BE CHANGED IN dl()
  *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF NEWTON-RAPHSON FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~FIXED POINT METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int fixedp(void)
{   

    	clock_t start, end;
	double cpu_time_used;
    	float a[100],c=100.0;
	int i=1,j=0;
    	start = clock();
	printf("\n\nThis method finds the root of the function f(x)=(cos(x)+2)/3\n");
    	printf("\nEnter initial guess:\n");//TAKING THE INITIAL GUESS
	scanf("%f",&a[0]);
    	printf("\n\n The values of iterations are:\n\n ");//DISPLAYING THE VALUE AT EACH ITERATION
    
	while(c>0.00001)//LOOP RUNNING TILL THE DIFFERENCE IS LARGER THAN THE ERROR i.e;0.00001
    	{
    
	    	a[j+1]=func(a[j]);//STORING THE VALUES IN THE ARRAY a[]
		c=a[j+1]-a[j];
		c=fabs(c);//TAKING THE MODULO OF THE DIFFERENCE
		printf("%d\t%f\n",j,a[j]);
		j++;
 

    	}
    
	printf("\n The root of the given function is %f",a[j]);//DISPLAYING THE ANSWER
    	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
    	printf("\nTime taken to execute in seconds : %lf", duration);

}


float func(float x)//RETURNING THE VALUE OF THE FUNCTION f(x)
{

    	float y;
	y=(cosf(x)+2)/3;//f(x)=(cos(x)+2)/3
    	return y;
} 
  /*THIS FUNCTION CAN BE USED TO CALCULATE THE ROOT OF ANY GIVEN FUNCTION
   *BUT THE VALUE RETURNING FROM THE FUNCTION func(x) MUST BE CHANGED TO THE DESIRED FUNCTION
   *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF FIXED POINT FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INTEGRATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TRAPIZOIDAL METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void trapi()
 {
    
	 clock_t start, end;
     	 double cpu_time_used;
     	 start = clock();

     	 int n,i;
     	 float a,b,h,sum,ict;//a-LOWER LIMIT b-UPPER LIMIT h-WIDTH OF EACH SEGMENT ict-VALUE OF THE INTEGRAL
     	 float F(float x);

     	 printf("\n\nThis method finds the integration of the function f(x)=x^3-2\n");
     	 printf("\nEnter initial value of x\n");
     	 scanf("%f",&a);
     	 printf("\nEnter final value of x\n");
     	 scanf("%f",&b);

     	 if(a!=b)//CHECKING IF LOWER LIMIT != UPPER LIMIT
     	 {
    

	 	 printf("\nEnter width value of h\n");
	 	 scanf("%f",&h);
	 	 if(a<b)//CHECKING IF LOWER LIMIT <= UPPER LIMIT
	 	 {
      
         
		      	 n=(b-a)/h;//CALCULATING NUMBER OF SEGMENTS
	     		 printf("\n n=%d",n);
	     		 sum=F(a);//CALLING THE FUNCTION AND SUMMING


	     		 for(i=1;i<=n-1;i++)
		 		 sum=sum+2*F(a+i*h);


	     		 sum=sum+F(b);
	     		 ict=sum*h/2.0;
    
        
		 }
  

	 	 else//IF LOWER LIMIT >= UPPER LIMIT
	 	 {
         
		      	 int t=a;
	     		 a=b;
	     		 b=t;
	     		 n=(b-a)/h;
	     		 printf("\n n=%d",n);
	     		 sum=F(a);

	     		 for(i=1;i<=n-1;i++)
		 		 sum=sum+2*F(a+i*h);

	     		 sum=sum+F(b);
	     		 ict=-1*sum*h/2.0;

	 	 }

	 	 printf("\nIntegration between %f and %f is %f \n",a,b,ict);
	 	 printf("\n");
    
	 }

     	 else
	 {

	 	 ict=0.0;
	 	 printf("\nIntegration between %f and %f is %f \n",a,b,ict);

     	 }

     	 end = clock();
     	 double duration = ((double)end - start)/CLOCKS_PER_SEC;
     	 printf("\nTime taken to execute in seconds : %lf", duration);

 }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RETURNING THE VALUE OF THE FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float F(float x)
{
  
      	float f;
    	f=pow(x,3)-2;//f(x)=x^3-2
    	return f;
}
  /*THIS FUNCTION CAN BE USED TO CALCULATE THE ROOT OF ANY GIVEN FUNCTION
   *BUT THE VALUE RETURNING FROM THE FUNCTION F(x) MUST BE CHANGED TO THE DESIRED FUNCTION
   * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF TRAPIZOIDAL FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SIMPSON METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void simp()
{
    
	clock_t start, end;
    	double cpu_time_used;
    	start = clock();

    	int n,i;
    	float a,b,h,sum,ics;//a-LOWER LIMIT b-UPPER LIMIT h-WIDTH OF EACH SEGMENT ict-VALUE OF THE INTEGRAL

    	printf("\n\nThis method finds the integration of the function f(x)=x^3-2\n");
    	printf("\nEnter the initial value of x\n");
    	scanf("%f",&a);
    	printf("\nEnter the final value of x\n");
    	scanf("%f",&b);
	printf("\nEnter the value of n\n");
    	scanf("%d",&n);
    	h=(b-a)/n;//CALCULATING THE WIDTH OF THE SEGMENT
    	printf("\nh=%f",h);
    	sum=F(a);

    	for(i=1;i<=n-1;i++)
    	{

		if(i%2==0)//IF i IS EVEN
	    		sum=sum+2*F(a+i*h);

		else//IF i IS ODD
	    		sum=sum+4*F(a+i*h);

    	}
	
    
	sum=sum+F(b);
    	ics=sum*h/3.0;
    	printf("\nIntegral is %f\n",ics);
    	end = clock();
    	double duration = ((double)end - start)/CLOCKS_PER_SEC;
    	printf("\nTime taken to execute in seconds : %lf", duration);


}

float FL(float x)//RETURNING THE VALUE OF THE FUNCTION
{

    	float f;
	f=pow(x,3)-2;//f(x)=x^3-2
    	return f;
}
 /*THIS FUNCTION CAN BE USED TO CALCULATE THE ROOT OF ANY GIVEN FUNCTION
  * BUT THE VALUE RETURNING FROM THE FUNCTION FL(x) MUST BE CHANGED TO THE DESIRED FUNCTION
  *  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF SIMPSON FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INTERPOLATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void leg()//FUNCTION TO EVALUATE LEGRANGE's POLYNOMIAL
{
    
	clock_t start, end;
    	double cpu_time_used;
    	start = clock();

    	float x[100],y[100],a,s=1,t=1,k=0;//x[]-x coordinates y[]-y coordinates
    	int n,i,j,d=1;//n- no. of data points

    	printf("\n\n Enter the number of the terms : ");
    	scanf("%d",&n);
    	printf("\n\n Enter the respective values of the variables x and y: \n");

    	for(i=0; i<n; i++)
	{

		scanf("%f",&x[i]);
		scanf("%f",&y[i]);
    
	}

    	printf("\n\n The numbers you entered are as follows :\n\n");

    	for(i=0; i<n; i++)//DISPLAYING THE NUMBERS
	{

		printf("%0.3f\t%0.3f",x[i],y[i]);
		printf("\n");
    
	}
	printf(" \n\n\n Enter the value of the x to find the respective value of y\n\n\n");
	scanf("%f",&a);//VALUE OF X WHERE Y IS TO BE FOUND
        for(i=0; i<n; i++)
        {
    		s=1;
		t=1;

    		for(j=0; j<n; j++)
		{
        
			if(j!=i)
			{
        
		    		s=s*(a-x[j]);//(x-x0)(x-x1)...(x-x(n-1))
				//LEGRANGE'S interpolation basis FUNCTIONS
				t=t*(x[i]-x[j]);//(xi-x0)...(xi-x(i-1))(xi-x(i+1))...(xi-xn)
                
			}
            
		}

    		k=k+((s/t)*y[i]);//SUMMING
     
     	}
        
	printf("\n\n The respective value of the variable y is: %f",k);
        end = clock();
        double duration = ((double)end - start)/CLOCKS_PER_SEC;
        printf("Time taken to execute in seconds : %lf", duration);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF LEGRANGE'S INTERPOLATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NEWTON'S INTERPOLATION BEGINS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NEWTON'S BACKWARD INTERPOLATION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int newtbd()
{

    	clock_t start, end;
	double cpu_time_used;
    	start = clock();
    
	int number,i,j,k=0,m;
    	float xvalue[MAX],yvalue[MAX],search;//xvalue[MAX]-X COORDINATES yvalue[MAX]-YCOORDINATES
	float differ[MAX][MAX],uvalue,hvalue,product,sum;//differ[MAX][MAX]-DIFFERNCE IN THE Y COORDINATES

    	printf("\n\n");
	printf("\n\n");
    	printf("How many numbers you want to enter for x  : ");//INPUTINDG THE NUMBER OF DATA POINTS
    	scanf("%d",&number);
    
	for(i=0;i<number;i++)
    	{
    
	    	printf("\nEnter value for x(%d)  : ",i);//TAKING THE X COORDINATES 
		scanf("%f",&xvalue[i]);
		printf("\nEnter value for y(%d)  : ",i);//TAKING THE Y COORDINATES
		scanf("%f",&yvalue[i]);
    
	}

    	printf("\nEnter any value of x for which you want to find y : ");//VALUE TO BE EVALUATED
	scanf("%f",&search);

    	if(search<xvalue[0] || search>xvalue[number-1])//CHECKING IF THE VALUES ARE WITHIN THE RANGE
	{
        
		printf("\n\nValue lies outside the given values of x ");

		exit(1);
    
	}

    	else
	{
        
		printf("\n\nNEWTON'S BACKWARD DIFFERENCE INTERPOLATION ");
		for(j=0;j<number-1;j++)
		{
	    		for(i=j+1;i<number;i++)
			{
				if(j==0)
				{
		    			differ[i][j]=yvalue[i]-yvalue[i-1];//TAKING THE DIFFERENCE BETWEEN THE Y COORDINATES
				}
				else
				{
		    			differ[i][j]=differ[i][j-1]-differ[i-1][j-1];///TAKING THE DIFFERENCE BETWEEN THE HIGHER ORDER DERIVATIVES
				}
			}
        
		}
		printf("\n\n");
		printf(" x       y   ");
		for(i=1;i<number;i++)
		{
	    		printf("   d^%dy(i) ",i);
        
		}
		printf("\n\n");
		for(i=0;i<number;i++)
		{
		    	printf(" %.2f    %.2f  ",xvalue[i],yvalue[i]);//DISPLAYING THE X AND Y COORDINATES
	    		for(j=0;j<i;j++)
			{
		    		printf("  %.4f  ",differ[i][j]);//DISPLAYING THE HIGHER ORDER DIFFERENCES
            
			}
	    		printf("\n");
		}
		for(i=0;i<number;i++)
		{
	    		if(search>xvalue[i])//TRAVERSING TO THE CORRECT INTERVAL
			{
				k=k+1;
			}
		}
		hvalue=xvalue[1]-xvalue[0];//CALCULATING THE WIDTH
		uvalue=(search-xvalue[k])/hvalue;
		sum=yvalue[k];
		for(i=0;i<number-1 ;i++)
		{

	    		product=1;
			for(j=0;j<=i;j++)
			{
				product=product*(uvalue+j);
            
			}

	    		m=factorial(i+1);
			sum=sum+(differ[k][i]*product)/m;
        
		}

		printf("\n\n");
		printf("Interpolated value is  :  %f ",sum);//INTERPOLATED VALUE AT THE GIVEN POINT
    
	}

    	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
    	printf("\nTime taken to execute in seconds : %lf", duration);
 
}


int factorial(int value)
{
	int i,temp=1;

    	for(i=value;i>=1;i--)
	{
        
		temp=temp*i;
    
	}

    	return(temp);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF NEWTON'S BACKWARD DIFFERENCE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NEWTON'S DIVIDED DIFFERENCE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void newtdd()
{
    
	clock_t start, end;
    	double cpu_time_used;
	start = clock();

    	int x[10], y[10], p[10];//X[]-X COORDINATES Y[]-Y COORDINATES
	int k,f,n,i,j=1,f1=1,f2=0;

    	printf("\nEnter the number of observations:\n");
	scanf("%d", &n);


    	printf("\nEnter the different values of x:\n");//TAKING THE VALUES OF X COORDINATES
    
	for (i=1;i<=n;i++)
		scanf("%d", &x[i]);


    	printf("\nThe corresponding values of y are:\n");//TAKING THE VALUES OF Y COORDINATES

    	for (i=1;i<=n;i++)
	    	scanf("%d", &y[i]);


    	f=y[1];
	printf("\nEnter the value of 'k' in f(k) you want to evaluate:\n");//TAKING THE VALUE TO BE EVALUATED
    	scanf("%d", &k);

    
	do
    	{

		for (i=1;i<=n-1;i++)
		{
        
		    	p[i] = ((y[i+1]-y[i])/(x[i+j]-x[i]));//CALCULATING f[xi,x(i+1)]
	    		y[i]=p[i];//REPLACING THE Y COORDINATE WITH NEW VALUES

		}
        
		f1=1;
		for(i=1;i<=j;i++)
	    	{

			f1*=(k-x[i]);

    		}
		f2+=(y[1]*f1);//OBTAINING THE RESULT AT THE GIVEN VALUE
		n--;
		j++;
    	}while(n!=1);
    
	f+=f2;
    	printf("\nf(%d) = %d", k , f);//DISPLAYING THE VALUE AT THE GIVEN POINT
	end = clock();
    	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTime taken to execute in seconds : %lf", duration);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF NEWTON'S DIVIDED DIFFERENCE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~NEWTON'S FORWARD DIFFERENCE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void newtfd()
{

    	clock_t start, end;
	double cpu_time_used;
    	start = clock();

    	float ax[MAXN+1], ay [MAXN+1], diff[MAXN+1][ORDER+1], nr=1.0, dr=1.0,x,p,h,yp;//ax – an array containing values of x ay – an array containing values of y yp – calculated value of y diff[MAXN+1][ORDER+1]-difference table h – spacing between values of x nr – numerator of the terms in expansion of y.p dr – denominator of the terms in expansion of y.p
	int n,i,j,k;

    	printf("\nEnter the value of n:\n");//taking the input
	scanf("%d",&n);
    	printf("\nEnter the values in form x,y:\n");
    
	for (i=0;i<n;i++)
		scanf("%f %f",&ax[i],&ay[i]);//taking the value of x and y

    	printf("\nEnter the value of x for which the value of y is wanted: \n");
	scanf("%f",&x);//the value to be evaluated
    	h=ax[1]-ax[0];//calculating the width
 
    
	//now making the difference table
    	//calculating the 1st order of differences

    	for (i=0;i<=n-1;i++)
		diff[i][1] = ay[i+1]-ay[i];
 

    	//now calculating the second and higher order differences
    
	for (j=2;j<=ORDER;j++)
		for(i=0;i<=n-j;i++)
			diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
 

    	//now finding x0
	i=0;

    	while (!(ax[i]>x))
	    	i++;
 

    	//now ax[i] is x0 and ay[i] is y0
    
	i--;
    	p = (x-ax[i])/h;
    	yp = ay[i];
 
    //now carrying out interpolation
    
	for (k=1;k<=ORDER;k++)
    	{

		nr *=p-k+1;
		dr *=k;
		yp +=(nr/dr)*diff[i][k];

    	}
    
	printf("\nWhen x = %6.1f, corresponding y = %6.2f\n",x,yp);//printing the answer
    	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
    	printf("\nTime taken to execute in seconds : %lf", duration);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF NEWTON'S FORWARD DIFFERENCE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~REGULAR FALSI METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

float fun(float x)//returning the value of the function
{
    
	return (cosf(x) - x*exp(x));//f(x)=cos(x)-x*exp(x)
}

void regula (float *x, float x0, float x1, float fx0, float fx1, int *itr)
{

    	*x = x0 - ((x1 - x0) / (fx1 - fx0))*fx0;//x – value of root at nth iteration in the regula function
    	++(*itr);//itr – a counter which keeps track of the no. of iterations performed
	printf("Iteration no. %3d X = %7.5f \n", *itr, *x);
}

int regularfalsi()
{

    	clock_t start, end;
    	double cpu_time_used;
	start = clock();

    	int itr = 0, maxmitr;//itr – a counter which keeps track of the no. of iterations performed,maxmitr – maximum number of iterations to be performed
    	float x0,x1,x2,x3,allerr;//x0, x1 – the limits within which the root lies,x2 – the value of root at nth iteration,x3 – the value of root at (n+1)th iteration,allerr – allowed error

    	printf("\n\nThis method finds the root of the function f(x)=cos(x)-x*exp(x)\n");
    	printf("\nEnter the values of x0, x1, allowed error and maximum iterations:\n");//taking the inputs
	scanf("%f %f %f %d", &x0, &x1, &allerr, &maxmitr);
    	regula (&x2, x0, x1, fun(x0), fun(x1), &itr);//calling the function

    	do
    	{
    
	    	if (fun(x0)*fun(x2) < 0)//checking if the product is less than 0
	    		x1=x2;

		else
	    		x0=x2;

		regula (&x3, x0, x1, fun(x0), fun(x1), &itr);

		if (fabs(x3-x2) < allerr)//if the diff. is less than the allowed error
		{

	    		printf("After %d iterations, root = %6.4f\n", itr, x3);
	    		return 0;

		}
        
		x2=x3;

    	}while (itr<maxmitr);
    	printf("\nSolution does not converge or iterations not sufficient:\n");//if the diff. is not less than the alloewd error
	end = clock();
    	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTime taken to execute in seconds : %lf", duration);

    	return 1;
}
///*THIS FUNCTION CAN BE USED TO CALCULATE THE ROOT AF ANY GIVEN FUNCTION 
// *BUT THE VALUE RETURNING FROM THE FUNCTION fun(x) MUST BE CHANGED TO THE DESIRED FUNCTION 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF REGULAR FALSI METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~BISECTION METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
float funct(float x)//returning the value of the function
{
	return (sinf(x)-x*cosf(x)+10);//f(x)=sin(x)-x*cos(x)+10
}
void bisection (float *x, float a, float b, int *itr)// this function performs and prints the result of one iteration 
{

    	*x=(a+b)/2;
    	++(*itr);
	printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
}

int bisect()
{

    	clock_t start, end;
	double cpu_time_used;
    	start = clock();

    	int itr = 0, maxmitr;//maxmitr-max no. iteration
    	float x, a, b, allerr, x1;//allerr-allowed error,a,b-interval,x-mean of a,b

    	printf("\n\nThis method finds the root of the function f(x)=sin(x)-x*cos(x)+10\n");
    	printf("\nEnter the values of a, b, allowed error and maximum iterations:\n");//taking the input
	scanf("%f %f %f %d", &a, &b, &allerr, &maxmitr);
    	bisection (&x, a, b, &itr);
    
	do
    	{

		if (funct(a)*funct(x) < 0)//checking if f(a)*f(c)<0
	    		b=x;
		else//checking if f(b)*f(c)<0
	    		a=x;
		bisection (&x1, a, b, &itr);

		if (fabs(x1-x) < allerr)//if the diff. is less than the allowed error
		{
	    		printf("\nAfter %d iterations, root = %6.4f\n", itr, x1);//displaying the root
			end = clock();
	    		double duration = ((double)end - start)/CLOCKS_PER_SEC;
	    		printf("\nTime taken to execute in seconds : %lf", duration);
	    		return 0;
        
		}

		x=x1;

    	}while (itr < maxmitr);

    	printf("The solution does not converge or iterations are not sufficient");//if the diff. is more than the allowed error
	end = clock();
    	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("\nTime taken to execute in seconds : %lf", duration);
    	return 1;
}
//*THIS FUNCTION CAN BE USED TO CALCULATE THE ROOT AF ANY GIVEN FUNCTION
// *BUT THE VALUE RETURNING FROM THE FUNCTION funct(x) MUST BE CHANGED TO THE DESIRED FUNCTION
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF BISECTION METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~SOLVING THE LINEAR EQUATIONS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~GAUSSIAN ELIMINATION METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int gausse()
{
    	clock_t start, end;
	double cpu_time_used;
    	start = clock();
    
	int i,j,k,n;
    	float A[20][20],c,x[10],sum=0.0;//A-matrix storing the coeff. of LEqn's,x-RHS matrix
    
	printf("\nEnter the order of matrix: ");//taking the order
    	scanf("%d",&n);
	printf("\nEnter the elements of augmented matrix row-wise:\n\n");//entering the matrix

    	for(i=1; i<=n; i++)
	{

		for(j=1; j<=(n+1); j++)
		{

	    		printf("\tA[%d][%d] : ", i,j);
	    		scanf("%f",&A[i][j]);
        
		}
    
	}

    	for(j=1; j<=n; j++) // loop for the generation of upper triangular matrix
	{
        
		for(i=1; i<=n; i++)
		{

        
		    	if(i>j)
	    		{
            
			    	c=A[i][j]/A[j][j];

				for(k=1; k<=n+1; k++)
				{

		    			A[i][k]=A[i][k]-c*A[j][k];
                
				}
            
			}
        
		}
    
	}

    	x[n]=A[n][n+1]/A[n][n];
    
	// this loop is for backward substitution

    	for(i=n-1; i>=1; i--)
	{
        
		sum=0;

		for(j=i+1; j<=n; j++)
		{
	    		sum=sum+A[i][j]*x[j];

		}
		x[i]=(A[i][n+1]-sum)/A[i][i];
	}

    	printf("\nThe solution is: \n");
    
	for(i=1; i<=n; i++)
	{
        
		printf("\nx%d=%f\t",i,x[i]); // x1, x2, x3 are the required solutions
    
	}

    	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
    	printf("\nTime taken to execute in seconds : %lf", duration);

    	return(0);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF GUASSIAN ELEMINATION METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DOLITTLE'S METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void dolittle()
{
    
	clock_t start, end;
    	double cpu_time_used;
	start = clock();

    	float A[20][20]= {0},L[20][20]= {0}, U[20][20];//A-the matrix,L-lower triangular matrix,U-upper triangular matrix
	float B[20]= {0}, X[20]= {0},Y[20]= {0};//B-RHS matrix,X-solution matrix
    	int i,j,k,n;
    
	printf("Enter the order of square matrix: ");//taking the order
    	scanf("%d",&n);
	printf("\nEnter matrix element:\n");

    	for(i=0; i<n; i++)
	{

		for(j=0; j<n; j++)
	      	{

	    		printf("Enter A[%d][%d] element: ", i,j);
	    		scanf("%f",&A[i][j]);
        
		}
	}
    	printf("\nEnter the constant terms: \n");
    	for(i=0; i<n; i++)
	{
		printf("B[%d]",i);
		scanf("%f",&B[i]);
	}
    	
	//this loop evaluates the upper and the lower triangular matrix
	
	for(j=0; j<n; j++)
	{
		for(i=0; i<n; i++)
		{
	    		if(i<=j)
			{
				U[i][j]=A[i][j];
				for(k=0; k<i-1; k++)
		    			U[i][j]-=L[i][k]*U[k][j];
				if(i==j)
		    			L[i][j]=1;
				else
		    			L[i][j]=0;
			}
	    		else
			{
				L[i][j]=A[i][j];
				for(k=0; k<=j-1; k++)
		    			L[i][j]-=L[i][k]*U[k][j];
				L[i][j]/=U[j][j];
				U[i][j]=0;
			}
		}
	}
    	printf("[L]: \n");
	//printing the lower triangular matrix
    	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		    	printf("%9.3f",L[i][j]);
		printf("\n");
	}
    	printf("\n\n[U]: \n");
	//printing the upper triangular matrix
    	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
	    		printf("%9.3f",U[i][j]);
		printf("\n");
	}
    	//LY=X
	for(i=0; i<n; i++)
    	{
	    	Y[i]=B[i];
		for(j=0; j<i; j++)
		{
	    		Y[i]-=L[i][j]*Y[j];
		}
    	}
	printf("\n\n[Y]: \n");
    	//printing the y matirix
	for(i=0; i<n; i++)
    	{
		printf("%9.3f",Y[i]);
    	}
	//UX=B
    	for(i=n-1; i>=0; i--)
	{
		X[i]= Y[i];
		for(j=i+1; j<n; j++)
		{
	    		X[i]-=U[i][j]*X[j];
		}
		X[i]/=U[i][i];
    	}
	//printing the x matirix
    	printf("\n\n[X]: \n");
	for(i=0; i<n; i++)
    	{
	    	printf("%9.3f",X[i]);
    	}
	printf("\n");
    	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
    	printf("\nTime taken to execute in seconds : %lf", duration);

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF DOLITTLE'S METHOD~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~REGRESSION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void linreg()
{
    	int i,n;
    	float x[10],y[10];
    	float sumx,sumy,sumxx,sumyy,sumxy,xmean,ymean,denom,a,b;
    	printf("\n\n                                LINEAR REGRESSION                         \n\n");
    	printf("________________________________________\n");
    	printf("\n  Enter the number of data points  \n");
    	scanf("%d",&n);
    	printf("\n  Enter the values of X and Y\n");
	for(i=1;i<=n;i++)
		scanf("%f %f",&x[i],&y[i]);//taking the values of x and y
    	sumx=0.0;
    	sumy=0.0;
    	sumxx=0.0;//sums x*x
    	sumxy=0.0;//sums x*y
	//loop evaluates the required sums
    	for(i=1;i<=n;i++)
	{
		sumx+=x[i];
		sumy+=y[i];
		sumxx+=x[i]*x[i];
		sumxy+=x[i]*y[i];
    	}
	xmean=sumx/n;//taking the mean
    	ymean=sumy/n;
    	denom=n*sumxx-sumx*sumx;
    	if(fabs(denom)>err)//chcking if the value is less than the allowed error
    	{
		b=(n*sumxy-sumx*sumy)/denom;
		a=ymean-b*xmean;
		printf("\n  The Linear Equation is Y = %f + %f X \n",a,b);
    	}
    	else
		printf("\n  No Solution \n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF LINEAR REGRESSION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~POLYNOMIAL REGRESSION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void polyreg()
{
    	int n,mp,m,i;
    	float x[max],y[max],c[max][max],a[max],b[max];
    	printf("\n       POLYNOMIAL REGRESSION      \n");
    	printf("Input num of data points n\n");
    	scanf("%d",&n);
    	printf("Input the order of polynomial\n");
    	scanf("%d",&mp);
    	printf("Input the data values,x and y \n");
    	for(i=0;i<n;i++)
		scanf("%f%f",&x[i],&y[i]);
    	/*checking  the  order */
    	if(n<=mp)
    	{
		printf("\nRegression not possible\n");
		exit(1);
    	}
    	//Number of polynomial coefficients
	m=mp+1;
    	//Computing the value of c and b
    	compute(x,y,c,b,n,m);
    	//computing the coefficients 1 to m
    	coeff(m,c,b,a);
    	//Printing the coefficients
    	printf("\n POLYNOMIAL COEFFICIENTS \n");
    	for(i=1;i<=m;i++)
		printf("%10f",a[i]);
    	printf("\n");
	printf("\nEND\n");
}


//Defining function compute
void compute(float x[max],float y[max],float c[max][max],float b[max],int n,int m)
{

    	//This function computes the values ofc and b

    	int i,j,k,l1,l2;

    	for(j=1;j<=m;j++)

    	{
    
	    	for(k=1;k<=m;k++)
	    
	    	{
            
			c[j][k]=0.0;

	    		l1=k+j-2;

            
			for(i=1;i<=n;i++)

				c[j][k]=c[j][k]+pow(x[i],l1);
        
		}
    
	}

    	for(j=1;j<=m;j++)

    	{

		b[j]=0.0;
        
		l2=j-1;

		for(i=1;i<=n;i++)

	    		b[j]=b[j]+y[i]*pow(x[i],l2);
    
	}


    	return;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF FUNCTION COMPUTE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//Defining function coeff
void coeff(int n,float a[max][max],float b[max],float x[max])
{
    //This function solves the equation
    int i,j,k;
    float pivot,factor,sum;
    for(k=1;k<=n-1;k++)
    {
        pivot=a[k][k];
        for(i=k+1;i<=n;i++)
        {
            factor=a[i][k]/pivot;
            for(j=k+1;j<=n;j++)
                a[i][j]=a[i][j]-factor*a[k][j];
            b[i]=b[i]-factor*b[k];
        }
    }
    x[n]=b[n]/a[n][n];
    for(k=n-1;k>=1;k--)
    {
        sum=0.0;
        for(j=k+1;j<=n;j++)
            sum=sum+a[k][j]*x[j];
        x[k]=(b[k]-sum)/a[k][k];
    }
    return;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF FUNCTION COEFF~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PARSING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
double parsing()
{
    	clock_t start, end;
    	double cpu_time_used;
    	start = clock();
	char s[10],s2[10],ch;//s-parsed string,s2-character stack
    	int j,i=0,l,k=1,len2=0,p=1,top1=-1,top2=-1,count=0;//len2-length of the parsed string,top1-index of the topmost element in the stack containing numbers, top2-index of the topmost element in the stack containing characters.
    	double d=0.0,s1[10];//s1- stack containing numbers, d-holds the value of the parsed string
    	int z=0,v=0,cv=0;
    	double x;
	char f[50];//expression string
    	printf("\n\t\t\tENTER THE FULLY PARENTHISED EXPRESSION \t\t\t\t\n");
    	fgets(f,50,stdin);
    	fgets(f,50,stdin);
    	l=strlen(f);//calc. the length of the string
    	for(v=0;v<=l;v++)
    	{
	    	if(f[v]=='x')//if the function has an independent variable x
			cv++;
    	}
	if(l==1)//if only a digit is entered
    	{

	    	if(isdigit(f[0]))
	    	{
			d=atof(f);
			printf("\nAnswer is %lf",d);
			exit(1);
		}
    	}
	else
    	{

		if(cv!=0)//if the expression contains the variable x
		{
			printf("\n\t\t\tENTER THE VALUE OF THE VARIABLE\t\t\t\n");
		    	scanf("%lf",&x);
		}
		if(f[i]!='*'&& f[i]!='/')//if the function does not start with '*','/'
		{
	    		while(k<=l)
	    		{         
				if(p==1)
				{
		    			j=0;
					if(f[i]=='-')//if the starting char is negetive
					{
			    			z=1;
			    			i++;
			    			k++;
					}
					printf("\n");
					while(f[i]!='+'&& f[i]!='-' && f[i]!='*' && f[i]!='/' && f[i]!='('&& f[i]!=')'&& f[i]!='^'&& k<=l)
						//the expression is broken up accoring to the given operators
					{
			    			
						if(f[i]=='\n')
			    			{
							break;
			    			}
			    			s[j]=f[i];//parsing
			  // 			printf("%c\n",s[j]);
			    			j++;
			    			i++;
			    			k++;
		       			}
		       			printf("\n");
		       			s[j]='\0';
		       			len2=strlen(s);//clac. the length of the parsed string
		       			if(len2!=0)
		       			{  
			   			count++;
			   			p=check(s,len2);//if the check function returns 0 then the function is invalid                     
			   			if(p==0)                     
			   			{
			       				printf("\nINVALID\n");
			       				exit(1);
			   			}
		       			}
		       
					//checks for the validity of the expression
		       			if(count==1&&((f[i+1]=='\n'&&(f[i]=='+'||f[i]=='-'||f[i]=='*'||f[i]=='/'||f[i]=='^'||f[i]==')'||f[i]=='('))||f[i]=='\n'))
		       			{
			       			printf("\nINVALID EXPRESSION\n");
		       				exit(1);
				      	}
		       			if(count==1&&f[i]=='\n')
		       			{                 
			   			if(isdigit(s[j-1]))                     
			   			{                     
			       				d=atof(s);//converts the string into double
			       				if(z==1)
			       				{
				   				d=-1*d;
				   				z=0;
				   				printf("\nAnswer is %lf",d);
			       				}                        
			       				printf("\nAnswer is %lf",d);
			       				break;
			   			}
			    			//evaluates the expression if it contains the variable x    
			   			else
			   			{                    
			       				d=calc(s,x); 
			       				if(z==1)
			       				{
				   				d=-1*d;
				   				z=0;
				   				printf("\nAnswer is %lf",d);
			       				}
			    				printf("\nAnswer is %lf",d);                        
			    				break;
			   			}

		       			}

		       			//parses the expression and evaluates the parsed string and put the answer in the stack
		       			else
		       			{
			   			if(len2!=0)
			   			{
			       				if(isdigit(s[j-1]))
				   				d=atof(s);
							else
				    				d=calc(s,x);//calc function bieng called
						}
			    			if(z==1)
			    			{
							d=-1*d;
							z=0;
			    			}
			    			if(f[i]!='('&&f[i-1]!=')')
			    			{
							++top1;
							s1[top1]=d;
			    			}
			    			if(f[i]!=')'&& f[i]!='\n')
			    			{
							top2++;
							s2[top2]=f[i];
			    			}
			    			else
			    			{
							if(f[i]=='\n'&&(f[i-1]=='+'|| f[i-1]=='-' || f[i-1]=='*' || f[i-1]=='/'||f[i-1]=='^'||f[i-1]=='('||f[i-len2-1]=='('))
							{
								printf("\nINVALID EXPRESSION\n");
								exit(1);
							}
							while(s2[top2]!='(')
							{
				    				top1=assign(s1,top1,s2[top2]);
				    				top2--;
				    				if(top2==-1)              
				    				{
									printf("\nAnswer is %lf",s1[top1]);
									end = clock();
									double duration = ((double)end - start)/CLOCKS_PER_SEC;
									printf("\n\nTime taken to execute in seconds : %lf", duration);
									return s1[top1];
				    				}
				    				else if((top2-1)==-1&&(s2[top2]=='('&& (f[i+1]=='\n'&&f[i]==')')))
				    				{
									printf("\nAnswer is %lf",s1[top1]);
									end = clock();
									double duration = ((double)end - start)/CLOCKS_PER_SEC;
									printf("\n\nTime taken to execute in seconds : %lf", duration);
									return s1[top1];
				    				}
							}
							top2--;
			    			}
                                                         
			    		}
					i++;
		    		} 
		    		else if(p==0)            
		    		{            
					printf("wrong input\n Please Enter Again\n");                
					break;                
		    		}
	    		}
			printf("\nINVALID EXPRESSION\n");
	    		exit(1);
		}

    	}       
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END OF PARSING FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//FILE to get info about parsing
int info()
 {
     FILE *p;
     int ch;
     if((p=fopen("parsefile.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
 }
//FILE to get info about legrange's interpolation
int infoleg()
 {
     FILE *p;
     int ch;
     if((p=fopen("legrangefile.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
 }
//FILE to get info about integration
int infoin()
 {
     FILE *p;
     int ch;
     if((p=fopen("integration.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
 }
//FILE to get info about trapizoidal method
int infotr()
 {
     FILE *p;
     int ch;
     if((p=fopen("trapi.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
 }
//FILE to get info about simpson's method
int infosi()
 {
     FILE *p;
     int ch;
     if((p=fopen("simp.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
 } 

//FILE to get info about secant method
int infos()
{
     FILE *p;
     int ch;
     if((p=fopen("secant.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
} 
//FILE to get info about newton raphson method
int infon()
{
     FILE *p;
     int ch;
     if((p=fopen("newraph.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
} 
//FILE to get info about fixed point method
int infof()
{
     FILE *p;
     int ch;
     if((p=fopen("fixedp.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
}
//FILE to get info about newton backward difference
int infonbd()
{
     FILE *p;
     int ch;
     if((p=fopen("newtbd.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
}
//FILE to get info about newton forward difference
int infonfd()
{
     FILE *p;
     int ch;
     if((p=fopen("newfd.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
}
//FILE to get info about newton divided difference
int infondd()
{
     FILE *p;
     int ch;
     if((p=fopen("newdd.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
}
//FILE to get info about bisection method
int infob()
{
     FILE *p;
     int ch;
     if((p=fopen("bisection.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
}
//FILE to get info about regular falsi method 
int infor()
{
     FILE *p;
     int ch;
     if((p=fopen("regulafalsi.dat","r"))==NULL)
     {
         printf("\n    ERROR IN OPENING FILE   \n");
         exit(1);
     }
     while((ch=fgetc(p))!=EOF)
         printf("%c",ch);
     fclose(p);
     return 0;
}
