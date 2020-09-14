#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

int PI=3.14;

void scrclr()
{
 int poly[8]={1,1,640,1,640,480,1,480};

 setcolor(0);
 setfillstyle(1,0);
 fillpoly(4,poly);
 drawpoly(4,poly);

}

void putarea(int a, int b, int x, int y, int col)
{
 for(int i=0;i<x-a+1;i++)
 {
  for(int j=0;j<y-b+1;j++)
  {
   putpixel(a+i,b+j,col);
  }
 }
}

void Shipdisp(int a, int b, int fact)
{
 int Ship[5][10][10]={{{0,0,0,0,14,14,0,0,0,0},
		   {0,0,0,14,1,1,14,0,0,0},
		   {0,0,0,14,1,1,14,0,0,0},
		   {0,0,14,1,1,1,1,14,0,0},
		   {0,0,14,1,1,1,1,14,0,0},
		   {0,14,1,1,14,14,1,1,14,0},
		   {0,14,3,14,4,4,14,3,14,0},
		   {14,3,14,0,4,4,0,14,3,14},
		   {14,14,0,0,4,4,0,0,14,14},
		   {4,4,0,0,0,0,0,0,4,4}},

		  {{0,0,0,0,14,14,0,0,0,0},
		   {0,0,0,14,1,1,14,3,4,4},
		   {0,0,0,14,1,1,14,3,3,4},
		   {0,0,14,1,1,1,1,14,0,0},
		   {0,0,14,1,1,1,1,14,3,4},
		   {0,14,1,1,14,14,1,1,14,3},
		   {0,14,3,14,4,4,14,3,14,0},
		   {14,3,14,0,4,4,0,14,3,14},
		   {14,14,0,0,4,4,0,0,14,14},
		   {4,4,0,0,0,0,0,0,4,4}},

		  {{0,0,0,0,14,14,0,0,0,0},
		   {4,4,3,14,1,1,14,0,0,0},
		   {4,3,3,14,1,1,14,0,0,0},
		   {0,0,14,1,1,1,1,14,0,0},
		   {4,3,14,1,1,1,1,14,0,0},
		   {3,14,1,1,14,14,1,1,14,0},
		   {0,14,3,14,4,4,14,3,14,0},
		   {14,3,14,0,4,4,0,14,3,14},
		   {14,14,0,0,4,4,0,0,14,14},
		   {4,4,0,0,0,0,0,0,4,4}},

		  {{0,0,0,0,14,14,0,0,0,0},
		   {0,0,0,14,1,1,14,0,0,0},
		   {0,0,0,14,1,1,14,0,0,0},
		   {0,0,14,1,1,1,1,14,0,0},
		   {0,0,14,1,1,1,1,14,0,0},
		   {0,14,1,1,14,14,1,1,14,0},
		   {0,14,3,14,3,3,14,3,14,0},
		   {14,3,14,0,3,3,0,14,3,14},
		   {14,14,0,4,3,4,4,0,14,14},
		   {4,0,4,4,4,4,4,4,0,4}},

		  {{0,0,5,0,14,14,0,5,0,0},
		   {0,0,5,14,1,1,14,5,0,0},
		   {0,0,5,14,1,1,14,5,0,0},
		   {0,0,14,1,1,1,1,14,0,0},
		   {0,0,14,1,1,1,1,14,0,0},
		   {0,14,1,1,14,14,1,1,14,0},
		   {0,14,3,14,4,4,14,3,14,0},
		   {14,3,14,0,4,4,0,14,3,14},
		   {14,14,0,0,4,4,0,0,14,14},
		   {4,4,0,0,0,0,0,0,4,4}}};




 for(int i=0;i<10;i++)
  for(int j=0;j<10;j++)
   if(Ship[i][j])
    putarea(a+2*j-2,b+2*i-2,a+2*j,b+2*i,Ship[fact][i][j]);





}

void main()

{
 clrscr();

 int gd=DETECT,gm;
 initgraph(&gd,&gm,"(ENTER YOUR TC LOCATION USING \\ FOR DIRECTORIES, EG: C:\\TC)\\BGI");

 int a=5,b=400,n=0,t=0,fact=0, shields=3*3600, naughtical=0, hp=1000, enemy[15]={0}, enemyx[15]={0}, enemyy[15]={0},enemyr[15]={0};
 char ch='+';

 n=0;

 while(hp>0)
 {


  delay(20);

  n++;

  b++;
  int initfact=fact;
  //cleardevice();

  if(naughtical) naughtical--,fact=initfact;

  scrclr();

  shields+=5-(400-b)/10;

  if(kbhit())
  {
   char temp=ch;

   ch=getch();


   if(ch=='d'){ fact=2;}
   if(ch=='a'){ fact=1;}

   if(ch=='w'){ b-=10; fact=3;}
   if(ch=='s'){ fact=0;}
   if(ch=='x'){ fact=0; b+=5;}

   if(t<1)
    if(ch=='o'){ if(shields>=3600) t=200,ch=temp,shields-=3600;}
   if(ch==' '){ fact=4; ch=temp;naughtical=1;}






  }

   if(ch=='d') a+=5;
   if(ch=='a') a-=5;




  //-------------------------DYNAMICS CALCULATION-------------------------

  if(a-11<1)
   a=12;
  if(a+29>639)
   a=610;
  if(b>400)
   b=400;
  if(b<350)
   b=350;

  for(int wt=0;wt<15;wt++)
  {
   if(n>(wt+1)*100)
    enemy[wt]=1;
  }

  for(wt=0;wt<15;wt++)
  {
   if((enemy[wt])&&(((enemyx[wt]==0)&&(enemyy[wt]==0))||(enemyy[wt]>480)))
   {
    enemyr[wt]=rand()%38+3;
    enemyy[wt]=1-enemyr[wt];
    enemyx[wt]=rand()%(639-enemyr[wt]/2)+enemyr[wt]/2;
   }

  }

  for(wt=0;wt<15;wt++)
   if(enemy[wt])
    enemyy[wt]+=(400-b+4)/2;



  //------------------------------DISPLAY------------------------------


  Shipdisp(a,b,fact);

  //HitPoints Counter

  setcolor(8);

  line(5,455,105,455);

  if(hp<1000/3) setcolor(12);
  else if(hp<2000/3) setcolor(14);
  else setcolor(10);


  for(wt=1;wt<hp/10;wt++)
  {

   circle(5+wt,455,1);
  }


  if(t>0)
  {
   t--;

   setcolor(1);

   circle(a+9,b+9,19);

   setcolor(3);

   circle(a+9,b+9,20);
  }

  for(wt=0;wt<15;wt++)
  {
   if(enemy[wt])
   {
    setcolor(15);
    circle(enemyx[wt],enemyy[wt],enemyr[wt]);
   }
  }

  //Shields Counter

  setfillstyle(1,8);
  setcolor(8);

  for(wt=0;wt<3;wt++)
  {

   pieslice(170+30*wt,455,0,360,3);
  }

  setfillstyle(1,11);
  setcolor(11);

  if(shields<3600)
  {

   pieslice(170,455,0,shields/10,5);
  }
  else if(shields<7200)
  {

   pieslice(170,455,0,360,5);
   pieslice(200,455,0,shields/10-360,5);

   setcolor(3);
   circle(170,455,7);

  }
  else if(shields<10800)
  {

   pieslice(170,455,0,360,5);
   pieslice(200,455,0,360,5);
   pieslice(230,455,0,shields/10-720,5);

   setcolor(3);
   circle(170,455,7);
   circle(200,455,7);

  }
  else
  {

   pieslice(170,455,0,360,5);
   pieslice(200,455,0,360,5);
   pieslice(230,455,0,360,5);

   setcolor(3);
   circle(230,455,7);
   circle(170,455,7);
   circle(200,455,7);

  }


  setcolor(8);
  line(250,455,350,455);

  setcolor(11);
  for(wt=0;wt<t/2;wt++)
  {
   circle(250+wt,455,1);
  }


  //------------------------------EFFECTS------------------------------

  for(int ab=0;ab<20;ab++)
  {
   for(int bc=0;bc<20;bc++)
   {
    if(getpixel(a+ab,b+bc)==15)
    {
     if(t>0) bc=20,ab=20;
     else hp-=50+(400-b)*5,bc=20,ab=20;
    }
   }
  }
















 }







 getch();
}
