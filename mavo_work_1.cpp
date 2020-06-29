/*
Assigend by:
Shay Bach #20463842,61101-7
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdarg.h>



/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();

/* Declarations of other functions */
int power1(int n);
int power2(int n);
int power3(int k);
int power4(int n);
int power5(int n);


/* ------------------------------- */

int main() 
{
	int select=0, i, all_Ex_in_loop=0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do 
		{
			for (i=1; i<=5; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select=0;
				printf("please select 0-5 : ");
				scanf("%d",&select);
			} while ((select<0)||(select>5));
			switch (select) 
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */

/* ------------------- */
/* Exercise1 */

int power1(int n)
{
	int i=0;
	unsigned long int  addone,sum=0;//incase the n value is bigger then 10
	addone=0;
	while(i<n)//finding the sum of the combined series of one's
	{
		sum+=addone;
		addone=addone*10;
		addone+=1;
		i++;

	}
	return sum;
}

void Ex1()
{
	int n,sum;
	printf("please enter netural number\n");
	scanf("%d",&n);


	power1(n);
	printf("the sum is %lu\n",power1(n));
}



/* Exercise 2 */

int power2(int n)
{
	int  i=0,num,counter1=1,counter2=0;
	int placea=1,placeb=1,orignnum=-1; 

	printf("enter binary number\n");
	while(i<n)//prevent the loop from working more then the series length
	{
		scanf("%d",&num);

		if (num==orignnum)//Count continuous length of one number
		{
			counter1++;
		}
		else//Continuous stops
		{
			if (counter1>counter2) //Count continuous length of the other number
			{
				placeb=placea;
				counter2=counter1;
			}
			placea=i+1;
			counter1=1;
			orignnum=num;
		}
		i++;
	}
	if (counter1>counter2)//Calculate which length to send to print
	{
		return placea;
	}
	else
	{
		return placeb;
	}
}


void Ex2(){
	int n;
	printf("enter quantity of digits ");
	scanf("%d",&n);

	printf("the longest series starts at %d\n", power2(n));




}


/* Exercise3 */


int power3(int k)
{
	int i=0,z=0,na=0,nb=0;
	printf("enter numbers\n");

	scanf("%d%d",&na,&nb);//to make sure there are at least two numbers
	while(na!=-1)
	{

		if(na+nb<k)//when there are two numbers that are smaller then k the function must stop
		{
			i=1;
		}
		if(nb>na)
		{
			nb=na;
		}
		scanf("%d",&na);
	}
	return i;
}


void Ex3()
{
	int k=0,z=1;
	printf("please enter k value\n");
	scanf("%d",&k);

	printf("%d\n",power3(k));

}



/* Exercise4 */

int power4(int n)
{
	int x1=0,y1=0,d=0,x2=n,y2=0;
	int mind= n;
	for(x1=0;x1<=n/3;x1++)//x can't be biger then n
	{

		for (y1=0;y1<=n/5;y1++)//y can't be biger then n
		{
			if (((3*x1)+(5*y1))==n)
			{	
				d=x1-y1;

				if(d<0)//complete value
				{
					d=d*(-1);
				}
				if (d<=mind)//check if mind is the minimum distance
				{
					mind=d;
					x2=x1;
					y2=y1;				
				}
			}
		}
	}
	printf("(x,y)= (%d, %d)\n",x2,y2);
	return n;

}


void Ex4()
{
	int n;
	printf("enter number higher then 7\n");
	scanf("%d",&n);

	power4(n);

}


/* Exercise5 */


int power5(int n)
{
	int num1,num2,count=0,sum=0, total_sum=0,leftover,i;
	num1=n;
	num2=n;
	sum=1;
	while(num1!=0)//Counting how many digits are in the number
	{
		num1=num1/10;
		count++;
	}

	while(num2!=0)//Check to see if the number is perfect
	{
		leftover=num2%10;
		num2=num2/10;
		sum=leftover;
		for(i=1;i<count;i++)//Exponentiation calculation 
		{

			sum=sum*leftover;
		}
		total_sum+=sum;
	}
	if(n==total_sum)//Which number to print
		return 1;
	return 0;

}
void Ex5()
{
	int n=0;
	printf("enter netural number\n");
	scanf("%d",&n);


	printf("returned:   %d\n",power5(n));




}