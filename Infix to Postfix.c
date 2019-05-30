#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include<alloc.h>
#include<process.h>
#define size 10
void displaystk(char);
void displaypo(char);
void push(char);
char pop();
int prec(char);
char in[50],po[50],stk[50],*str,*str2;
int i,top=-1,j=0,midx,midy,incrementpo=0,incrementstk=0;

void main()
{
  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\tc\\bgi");
  midx=getmaxx()/2;
  midy=getmaxy()/2;
  setcolor(RED);
  settextstyle(8,0,2);
  outtextxy(midx-300,midy-100,"INFIX TO POSTFIX CONVERSION USING C GRAPHIS");
  setcolor(9);
  settextstyle(7,0,2);
  outtextxy(midx+150,midy+150,"Developed by");
  outtextxy(midx+170,midy+170,"Sonal Roche");
  getch();
  clrscr();
//while(k)
//{
  setcolor(BLACK);
  setfillstyle(SOLID_FILL,BLACK);
  floodfill(2,2,BLACK);
  rectangle(0,0,getmaxx(),getmaxy());
  printf("  enter your infix expression \n");
  gets(in);
  push('\0');
  for(i=0;in[i]!='\0';i++)
  {  switch(in[i])
   { case '(':push(in[i]); break;
     case ')':while(stk[top]!='(')
	     { po[j]=pop();
		displaypo(po[j]);
	     j++;
	      }
	      top--;
	      break;
     case '+':
     case '-':
     case '*':
     case '/': while((prec(stk[top]))>=(prec(in[i])))
	      { po[j]=pop();
		displaypo(po[j]);
		j++;
		}
	       push(in[i]);
	       break;
    default: po[j]=in[i];
	      displaypo(po[j]);
	      j++;
  }
    getch();
	}

    while(top!=-1)
    po[j++]=pop();
    printf("  the postfix expression is %s  ",po);

    getch();
  }

    void push(char a)
    { top++;
      stk[top]=a;
      displaystk(stk[top]);
    }

    char pop()
    { char k;
      k=stk[top];
      top--;
      return k;
    }

    int prec(char b)
   {  if(b== '+'|b== '-')
      return 1;
      else if(b=='*'|b=='/')
      return 2;
      else
      return -1;
    }

   void displaystk(char cch)
  {int n,i;
   setfillstyle(SOLID_FILL,BLACK);
   floodfill(2,2,BLACK);
   rectangle(0,0,getmaxx(),getmaxy());
   settextstyle(7,0,2);
   settextstyle(0,0,1);
   setcolor(2);
   setcolor(RED);
   outtextxy(midx+30,midy-100,"INDEX");
   setcolor(GREEN);
   outtextxy(midx+70,midy+105,"STACK");
   setcolor(RED);
   outtextxy(midx+55,midy+90,"0");
   outtextxy(midx+55,midy+70,"1");
   outtextxy(midx+55,midy+50,"2");
   outtextxy(midx+55,midy+30,"3");
   outtextxy(midx+55,midy+10,"4");
   outtextxy(midx+55,midy-10,"5");
   outtextxy(midx+55,midy-30,"6");
   outtextxy(midx+55,midy-50,"7");
   outtextxy(midx+55,midy-70,"8");
   outtextxy(midx+55,midy-90,"9");

   setcolor(GREEN);
   line(midx+100,midy+100,midx+100,midy-100);
   line(midx+70,midy+100,midx+70,midy-100);

   line(midx+100,midy+100,midx+70,midy+100);
   line(midx+100,midy+80,midx+70,midy+80);
   line(midx+100,midy+60,midx+70,midy+60);
   line(midx+100,midy+40,midx+70,midy+40);
   line(midx+100,midy+20,midx+70,midy+20);
   line(midx+100,midy,midx+70,midy);
   line(midx+100,midy-20,midx+70,midy-20);
   line(midx+100,midy-40,midx+70,midy-40);
   line(midx+100,midy-60,midx+70,midy-60);
   line(midx+100,midy-80,midx+70,midy-80);
   str=&cch;

   setcolor(14);
   settextstyle(7,0,2);
   settextstyle(0,0,0);
   outtextxy(midx+80,midy+90-incrementstk,str);
   incrementstk+=20;
  }

  void displaypo(char var)
  { int i;
    str2=&var;
    setcolor(13);
    outtextxy(midx+170,midy+105,"POSTFIX");

    line(midx+200,midy+100,midx+200,midy-100);
    line(midx+170,midy+100,midx+170,midy-100);

    line(midx+200,midy+100,midx+170,midy+100);
    line(midx+200,midy+80,midx+170,midy+80);
    line(midx+200,midy+60,midx+170,midy+60);
    line(midx+200,midy+40,midx+170,midy+40);
    line(midx+200,midy+20,midx+170,midy+20);
    line(midx+200,midy,midx+170,midy);
    line(midx+200,midy-20,midx+170,midy-20);
    line(midx+200,midy-40,midx+170,midy-40);
    line(midx+200,midy-60,midx+170,midy-60);
    line(midx+200,midy-80,midx+170,midy-80);

    setcolor(3);
    settextstyle(7,0,2);
    settextstyle(0,0,0);
    outtextxy(midx+180,midy+90-incrementpo,str2);
    incrementpo+=20;
  }


