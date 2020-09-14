#include<conio.h>
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

void scrclr();
void Shipdisp(long, long, long);
void Powerdisp(long []);
void finish(long ,long ,int,int [],int [],int [], int [], int);
int gamecheck(long,int);
void instructions();

void main()

{

 int gd=DETECT,gm;
 initgraph(&gd,&gm,"\\GD");

 instructions();

 Here:

 int diff=5,lvl=0,wol,u,conc;
   cleardevice();
 gotoxy(1,1);
 cout<<"Space Man Adventures, By Akarsh Jain: \nEnter Difficulty from 1-9: "; cin>>diff;

 Next:

 cleardevice();
 gotoxy(1,1);
 cout<<"\nCurrent Level: "<<lvl+1;

 long spoc, a=5,sai=0, b=400,n=0,t=0,fact=0, shields=3*3600, spec=1, score=0, dist=0,naughtical=0, hp=1000, enemy[300]={0}, enemyx[300]={0}, enemyy[300]={0},enemyr[300]={0},power[3]={0};
 int bgx[1000]={0}, bgy[1000]={0}, bg[1000]={0}, bgn=0, bgcol[1000]={0}, bgr[1000]={0};
 char ch='+';
 int s=0, f=0, z=400, pcol;


 if(diff%10!=0) diff%=10;
 else diff=10, spoc=20, power[0]=300, hp=10, power[1]=1, t=200, power[2]=1;
 if(diff<10) spoc=diff;

 if(diff>8) shields=0;
 else if(diff>6) shields=3600;
 else if(diff>4) shields=2*3600;
 else shields=3*3600;

 n=0;

 cout<<"\nDifficulty is: ";

 if(diff!=10) cout<<diff;
 else cout<<" PRO MODE ACTIVATED!!";
 /*cout<<diff;
 if(diff>9) diff=9;
 cout<<diff;*/

 getch();

 while(hp>0)
 {


  delay(30);

  n++;

  b++;
  int initfact=fact;
  //cleardevice();

  if(naughtical) naughtical--,fact=initfact;

  scrclr();

  shields+=5-(400-b)/10;

  dist+=1+(400-b)/2;

  score+=2+3*(400-b)/2;

  if(shields>3*3600) shields = 3*3600;

  if(kbhit())
  {
   regetch:

   char temp=ch;

   ch=getch();
   if(ch==0) ch=getch();

   if((ch=='d')||(ch==77)||(ch=='6')){ fact=2;}
   if((ch=='a')||(ch==75)||(ch=='4')){ fact=1;}

   if(spec) if((ch=='w')||(ch==72)||(ch=='8')){ b-=10; fact=3;}
   if((ch=='s')||(ch==80)||(ch=='5')){ fact=0;}
   if(ch==' '){ fact=0; b+=20;}

   if(t<1)
    if(ch=='o'){ if(shields>=3600) t=200,ch=temp,shields-=3600;}
   if(ch=='u'){ fact=4; ch=temp;naughtical=1;}

   if(ch=='p') { ch=temp; goto regetch;}




  }
  if(diff>5)
  {
   if((ch=='d')||(ch==77)||(ch=='6')) a+=5+(400-b)/10;
   if((ch=='a')||(ch==75)||(ch=='4')) a-=5+(400-b)/10;
  }
  else
  {
   if((ch=='d')||(ch==77)||(ch=='6')) a+=5;
   if((ch=='a')||(ch==75)||(ch=='4')) a-=5;
  }



  //-------------------------DYNAMICS CALCULATION-------------------------

  if(a-11<1)
   a=12;
  if(a+29>639)
   a=610;
  if(b>400)
   b=400;
  if(spec==1)
  {
   /*if(spoc>10)
   {

    if(b<100)
     b=100;
   }
   else */if(b<350)
   b=350;
  }
  if(spec==0) if(b>350) spec=1;

  for(int wt=0;wt<spoc*3;wt++)
  {
   if(n>(wt+1)*500/diff)
    enemy[wt]=1;
  }

  if(n%(200/diff)==0)
  {
   bg[bgn++]=67;

  }

  if(bgn>999) bgn=999;

  for(int bgc=0;bgc<bgn;bgc++)
  {
   if(bg[bgc])
   {
    if((bgy[bgc]>480)||(bgx[bgc]==0))
    {
     bgy[bgc]=1;
     bgx[bgc]=rand()%638+2;

     bgr[bgc]=rand()%2+1;

     int temp=rand()%100+1;
     if(temp<85) bgcol[bgc]=7;
     else if (temp<90) bgcol[bgc]=14;
     else if (temp<93) bgcol[bgc]=12;
     else if (temp<95) bgcol[bgc]=1;
     else bgcol[bgc]=8;

    }
    else bgy[bgc]++;
   }
  }

  if((n/(diff*(50-5*lvl))>1)&&((n-(diff*50))%(diff*50*3/5)==0)&&(power[2]==0))
  {
   power[2]=rand()%3+1;
   power[1]=1;
   power[0]=rand()%600+50;
  }

  if(power[1]>479)
  {
   power[2]=0;
  }

  for(wt=0;wt<spoc*3+lvl*10;wt++)
  {
   if((enemy[wt])&&(((enemyx[wt]==0)&&(enemyy[wt]==0))||(enemyy[wt]>480)))
   {
    enemyr[wt]=rand()%(30+lvl*3)+3;
    enemyy[wt]=1-enemyr[wt];
    enemyx[wt]=rand()%(639-enemyr[wt]/2)+enemyr[wt]/2;
   }

  }

  for(wt=0;wt<spoc*3+lvl*10;wt++)
   if(enemy[wt])
    enemyy[wt]+=(400-b+4)/2;


  //------------------------------DISPLAY------------------------------


  Shipdisp(a,b,fact);

  //Powerup display:

  if(power[2])
  {
   Powerdisp(power);
   power[1]+=2;
  }


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
   if(diff<6) t--;
   else t-=3;

   setcolor(1);

   circle(a+9,b+9,19);

   setcolor(3);

   circle(a+9,b+9,20);
  }

  for(wt=0;wt<spoc*3+lvl*10;wt++)
  {
   if(enemy[wt])
   {
    setcolor(15);
    setfillstyle(10+rand()%2,7);
    //pieslice(enemyx[wt],enemyy[wt],0,360,enemyr[wt]);
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


  for(bgc=0;bgc<bgn;bgc++)
  {
   //int tempo=rand()%15;
   setcolor(bgcol[bgc]); setfillstyle(1,bgcol[bgc]);
   pieslice(bgx[bgc],bgy[bgc],0,360,bgr[bgc]);
  }

  gotoxy(1,1); cout<<"Distance: "<<dist/1000<<" Score: "<<score/100<<" Stars(in background): "<<bgn<<" Difficulty: "<<diff<<" Level: "<<lvl+1;

  //------------------------------EFFECTS------------------------------

  for(int ab=0;ab<20;ab++)
  {
   for(int bc=0;bc<20;bc++)
   {
    if(getpixel(a+ab,b+bc)==15)
    {
     if(t>0) bc=20,ab=20;
     else { setcolor(12); circle(a+9,b+9,20); hp-=50+(400-b)*5,bc=20,ab=20;}
    }
   }
  }

  if((power[1]>=b-3)&&(power[1]<=b+20)&&(power[0]>=a-3)&&(power[0]<=a+20))
  {
   if(power[2]==1)
   {
    if(diff>4)
    hp+=500;
    else hp+=1000;
    if(hp>1000) hp=1000;
    t=3;
   }
   else if(power[2]==2)
   {
    shields+=7200;
    if(t<5) t=3;
   }
   else if(power[2]==3)
   {
    t=200; b-=200, spec=0;
   }
   power[2]=0;
  }


  if((dist/1000>=(15*lvl + 20))&&(lvl<6))
  {
   //cleardevice();

   finish(a,b,bgn,bgx,bgy,bgcol,bgr,lvl);

   goto Win;

  }













 }




 while(ch!='0')
 {

  setcolor(rand()%15+1+BLINK);

  if(z==0) s=0,z=400;
  if(f==400) s=1,f=0;

  if(s==0)
  {
   f+=5;
   circle(a,b,f);
  }
  else if(s)
  {
   z-=5;
   circle(a,b,z);
  }
  gotoxy(1,2); cout<<"PRESS 0 TO CONTINUE";







  if(kbhit()) ch=getch();
 }

 s=0, f=0, z=400;

 cleardevice();

 if(spoc>10) diff=10;

 for(wol=0, conc=0; wol<diff-3;wol++)
 {
  if((dist/1000)-wol*5>0) conc++;
 }

 sai = score*10*diff/(dist-conc*3);



 cout<<"GAME OVER!!!";
 for( u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\n\t+ At difficulty: "<<diff;
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\t+ Distance: "<<dist/1000<<" kilo-miles.";
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\t+ Score: "<<score/100<<" million.";
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\t----------------------------------------";
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\t= Spaceman Aptitude Index(SAI): "<<sai;
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\n\n GOODBYE!";

 getch();
 cout<<"\n\n\tEnter 'r' to restart, 'q' to redo level: "; cin>>ch;
 if(ch=='r')
 goto Here;
 else if(ch=='q')
 goto Next;
 else goto ex;

 Win:

 s=0, f=0, z=400;

 if(spoc>10) diff=10;

 for(wol=0, conc=0; wol<diff-3;wol++)
 {
  if((dist/1000)-wol*5>0) conc++;
 }

 sai = score*10*diff/(dist-conc*3);



 cout<<"CONGRATULATIONS!!!";
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\n\t+ At difficulty: "<<diff;
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\t+ Distance: "<<dist/1000<<" kilo-miles.";
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 cout<<"\n\t+ Score: "<<score/100<<" million.";
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}

 cout<<"\n\t----------------------------------------";

 cout<<"\n\t= Spaceman Aptitude Index(SAI): "<<sai;
 for(u=0;u<2000;u++) { if(kbhit()) u=2000; else delay(1);}
 getch();
 cout<<"\n\n\tEnter 'r' to restart, 'q' to continue: "; cin>>ch;

 if(ch=='r')
 goto Here;
 else if(ch=='q')
 { lvl++; goto Next;}
 else goto ex;


 ex:
}

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

void Powerdisp(long P[])
{
 int Powerup[3][10][10]={{{0,0,0,0,0,0,0,0,0,0},
			  {0,12,12,0,0,0,0,12,12,0},
			  {0,12,12,0,0,0,0,12,12,0},
			  {0,12,12,0,0,0,0,12,12,0},
			  {0,12,12,12,12,12,12,12,12,0},
			  {0,12,12,12,12,12,12,12,12,0},
			  {0,12,12,0,0,0,0,12,12,0},
			  {0,12,12,0,0,0,0,12,12,0},
			  {0,12,12,0,0,0,0,12,12,0},
			  {0,0,0,0,0,0,0,0,0,0}},

			 {{0,0,0,0,0,0,0,0,0,0},
			  {0,1,0,0,0,0,0,0,1,0},
			  {0,1,1,1,0,0,1,1,1,0},
			  {0,1,11,1,1,1,1,11,1,0},
			  {0,1,11,11,11,11,11,11,1,0},
			  {0,1,1,11,11,11,11,1,1,0},
			  {0,0,1,1,11,11,1,1,0,0},
			  {0,0,0,1,11,11,1,0,0,0},
			  {0,0,0,0,1,1,0,0,0,0},
			  {0,0,0,0,0,0,0,0,0,0}},

			 {{0,0,0,0,14,14,0,0,0,0},
			  {0,0,0,14,14,14,14,0,0,0},
			  {0,0,14,14,11,11,14,14,0,0},
			  {0,14,14,11,14,14,11,14,14,0},
			  {14,14,11,14,14,14,14,11,14,14},
			  {14,11,14,14,11,11,14,14,11,14},
			  {11,14,14,11,0,0,11,14,14,11},
			  {14,14,11,0,0,0,0,11,14,14},
			  {14,11,0,0,0,0,0,0,11,14},
			  {0,0,0,0,0,0,0,0,0,0}}};

 int a=P[0]-9, b=P[1]-9;

 for(int i=0;i<10;i++)
  for(int j=0;j<10;j++)
   if(Powerup[i][j])
    putpixel(a+j,b+i,Powerup[P[2]-1][i][j]);

 setcolor(1);

 circle(a+4,b+4,10);
}

// COLORS (text mode)
//ßßßßßßßßßßßßßßßßßßßß³Back-³Fore-
// Constant     ³Value³grnd?³grnd?
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍØÍÍÍÍÍØÍÍÍÍÍØÍÍÍÍÍ
// BLACK        ³  0  ³ Yes ³ Yes
// BLUE         ³  1  ³ Yes ³ Yes
// GREEN        ³  2  ³ Yes ³ Yes
// CYAN         ³  3  ³ Yes ³ Yes
// RED          ³  4  ³ Yes ³ Yes
// MAGENTA      ³  5  ³ Yes ³ Yes
// BROWN        ³  6  ³ Yes ³ Yes
// LIGHTGRAY    ³  7  ³ Yes ³ Yes
// DARKGRAY     ³  8  ³ No  ³ Yes
// LIGHTBLUE    ³  9  ³ No  ³ Yes
// LIGHTGREEN   ³ 10  ³ No  ³ Yes
// LIGHTCYAN    ³ 11  ³ No  ³ Yes
// LIGHTRED     ³ 12  ³ No  ³ Yes
// LIGHTMAGENTA ³ 13  ³ No  ³ Yes
// YELLOW       ³ 14  ³ No  ³ Yes
// WHITE        ³ 15  ³ No  ³ Yes
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÄ
// BLINK        ³128  ³ No  ³ ***





void Shipdisp(long a, long b, long fact)
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

void finish(long a,long b,int bgn,int bgx[],int bgy[],int bgcol[],int bgr[], int lvl)
{
 cleardevice();

 int sx=320, sy=-399;

 for(int bgc=0;bgc<bgn;bgc++)
  {
   //int tempo=rand()%15;
   setcolor(bgcol[bgc]); setfillstyle(1,bgcol[bgc]);
   pieslice(bgx[bgc],bgy[bgc],0,360,bgr[bgc]);
  }


 for(int i=0;i<50;i++)
 {
  delay(100);

  //scrclr();

  //delay(10);


  putarea(a-3,b-3,a+21,b+21,0);

  b-=3;
    Shipdisp(a,b,0);




  setcolor(lvl+8);
  setfillstyle(1,lvl+8);

  pieslice(sx,sy,180,360,400);



  sy+=2;

  Shipdisp(a,b,0);

  gotoxy(25,13); cout<<"You Have Reached: ";

  switch(lvl)
  {
   case 0: cout<<"Alpha Centauri\n\n";break;
   case 1: cout<<"Sirius\n\n";  break;
   case 2: cout<<"A Ball of Fused Rice\n\n";break;
   case 3: cout<<"Einstien's Brraiiinn\n\n";             break;
   case 4: cout<<"Void Main()\n\n";                            break;
   case 5: cout<<"Infinity! Whoa, Well done!";
  }




 }

 getch();


}

void instructions()
{

 long page=1,power[4]={300,300,1,1};

 char ch='0';

 while(page<5)
 {

  //if(ch==0) ch=getch();
  cleardevice();
  if((ch=='n')||(ch=='N')/*||(ch=='6')||(ch==77)*/)
  page++;
  else if((ch=='P')||(ch=='p')/*||(ch==75)||(ch=='4')*/)
  page--;

  if(page<1) page=1;
  if(page>4) goto nex;

  switch(page)
  {
   case 1:
   gotoxy(18,10); cout<<"SpaceMan Adventures v8, By Akarsh Jain";
   gotoxy(18,20); cout<<"(Navigate Instructions using P and N)";Shipdisp(150,180,2);Shipdisp(250,180,0);
   Shipdisp(350,180,3);Shipdisp(450,180,1);
   gotoxy(73,25); cout<<"Next-=>";
   break;

   case 2:
   gotoxy(1,1); cout<<"Instructions Page 1:";
   cout<<"\n\nYou have  a Ship. You embark on a journey to Infinity, (and not beyond):\n\n(1):: You can Guide your ship using WASD, or Arrow Keys, or the Numbers in your NumPad.\n\n(2):: To use Sheilds press the 'o' key in-game.\n\n(3):: Handbrake can be applied using the Spacebar.\n\n(4):: Collect powerups, and dodge the rocks or 'Bubbles'.\n\n(5):: Enjoy!\n\n(6):: Enter Difficulty as 10 for PRO MODE. Lvl 1 = 20 kilomiles. Lvl 2 = 35 Kilomiles, and so on. Press 'P' ingame to pause, press any of the movement keys to unpause.";
   Shipdisp(150,300,2);Shipdisp(250,300,0);
   Shipdisp(350,300,3);Shipdisp(450,300,1);
   gotoxy(73,25); cout<<"Next-=>";gotoxy(1,25); cout<<"<=-Previous";
   break;

   case 3:
   gotoxy(1,1); cout<<"Health:";
   cout<<"\n\nYour health is shown below by a red/yellow/green bar at the bottom of the gaming screen(Eg. is given just below). If your speed is higher, an impact will drain more health. \n\n\n(1):: You can gain speed by 'w', Up arrowkey, or '8' of NumPad.\n\n(2):: You can decrease speed by hitting Spacebar or Handbrake.\n\n(3):: If you have a low health or red bar, look out for this powerup:(powerups continue to appear in the game, to collect, come into contact with them)";
   gotoxy(73,25); cout<<"Next-=>";gotoxy(1,25); cout<<"<=-Previous";

   for(int i=0;i<3;i++)
   {
    setcolor(8);
    line(50*(i+1)+100*i,90,150*(i+1),90);
    if(i==0) setcolor(12);
    else if(i==1) setcolor(14);
    else setcolor(10);
    for(int wt=1;wt<20*(i+1);wt++)
    {
     circle(50*(i+1)+i*100+wt,90,1);
    }
   }
   Powerdisp(power);
   break;

   case 4:
   gotoxy(1,1); cout<<"Sheilds:";
   cout<<"\n\nShields can be used by the 'o' key. The Maximum number of charged shields is 3.\n\n(1):: While the shield is on, the shield 'Bar', indicated by a sky-blue slider, will slowly decrease till the shields run out.\n\n(2):: Shields regenerate over time, the faster your ship is, the slower they Regenerate.\n\n\t PRESS NEXT (N) TO BEGIN GAME.";
   gotoxy(73,25); cout<<"Next-=>";gotoxy(1,25); cout<<"<=-Previous";
   break;

  }




  ch=getch();
 }

 //getch();


 nex:
}

int gamecheck(long dist, int pcol)
{

 int dist[4]={0}, pcol[4]={0};

 fstream F;

 F.open("game.txt",ios::

