#include<graphics.h>
#include<conio.h>
#include<iostream>
using namespace std;

int arr[4]={0},wait=0,tot=4;
int main()
{
int i=0,j=0;
int left, top,right ,bottom;

initwindow(800,700,"bathroom Problem");
outtextxy(100,50,"Process Synchronization Using bathroom Problem");

// First Chair Drawing
left=100, top =100,right =200, bottom =200; 
rectangle(left,top,right,bottom);
/*bar(left,top,right,bottom);
line(140, 300, 240, 300);
line(100, 200, 140, 300);
line(200, 200, 240, 300);
line(100,200,100,300);
line(140,300,140,400);
line(240,300,240,400);*/

//Second Chair Drawing
left=300, top =100,right =400, bottom =200; 
rectangle(left,top,right,bottom);
//bar(left,top,right,bottom);
//line(340, 300, 440, 300);
//line(300, 200, 340, 300);
//line(400, 200, 440, 300);
//line(300,200,300,300);
//line(340,300,340,400);
//line(440,300,440,400);


// Third Chair Drawing
left=500, top =100,right =600, bottom =200; 
rectangle(left,top,right,bottom);
//bar(left,top,right,bottom);
/*line(540, 300, 640, 300);
line(500, 200, 540, 300);
line(600, 200, 640, 300);
line(500,200,500,300);
line(540,300,540,400);
line(640,300,640,400);*/


//Fourth Chair Drawing
left=450, top =450,right =550, bottom =550; 
rectangle(left,top,right,bottom);
//bar(left,top,right,bottom);
/*line(490, 650, 590, 650);
line(450, 550, 490, 650);
line(550, 550, 590, 650); 
line(450,550,450,650);
line(490,650,490,700);
line(590,650,590,700);*/

// Barber 
outtextxy(125,125,"1.empty");
outtextxy(325,125,"2.empty");
outtextxy(525,125,"3.empty");
outtextxy(480,480,"4.empty");
outtextxy(100,480,"Available resource");
outtextxy(100,500,"4");

outtextxy(100,600,"waiting person");
outtextxy(100,650,"0");
//outtextxy(350, 600,"Barber");

// Customer 1 moves

for(i=800,j=400; i >= 50; i--)
{
     delay(10);
     outtextxy(i,j,"person");
}

outtextxy(125,125,"             ");
outtextxy(125,125,"1.fulll");
outtextxy(100,500,"3");
tot--;
//Customer 2 moves

for(i=800,j=400; i >= 50; i--)
{
     delay(10);
     outtextxy(i,j,"person");
   
}
outtextxy(325,125,"             ");
outtextxy(325,125,"2.fulll");
outtextxy(100,500,"2");
tot--;
//Customer 3 moves
for(i=800,j=400; i >= 50; i--)
{
     delay(10);
     outtextxy(i,j,"person");
   
}
outtextxy(525,125,"             ");
outtextxy(525,125,"3.fulll");
outtextxy(100,500,"1");
tot--;
// Customer 4 moves
for(i=800,j=400; i >= 50; i--)
{
     delay(10);
     outtextxy(i,j,"person");
   
}




outtextxy(480,480,"             ");




outtextxy(480,480,"4.fulll");
outtextxy(100,500,"0");
tot--;
//system("pause");
// Customer 5 moves
//arr[4]={1};
for(i=800,j=400; i >= 50; i--)
{
     delay(10);
     outtextxy(i,j,"person");
   
}
if(!tot)
{
outtextxy(50,400,"all resources are allocated....go into waiting queue");
delay(6000);
outtextxy(50,400,"                                                                                      ");
wait++;
outtextxy(100,650,"1");
}
// Customer 6 moves
for(i=800,j=400; i >= 100; i--)
{
     delay(10);
     outtextxy(i,j,"person");
   
}
if(!tot)
{
outtextxy(50,400,"all resources are allocated....go into waiting queue");
delay(11000);
outtextxy(50,400,"                                                                                      ");
wait++;
outtextxy(100,650,"2");
}
delay(5000);
outtextxy(50,400,"person leaving resource 1 ");
delay(5000);
outtextxy(50,400,"                                                                                      ");

for(i=50,j=400; i < 900; i++)
{
                delay(10);
     outtextxy(i,j,"person leaving");
}                
delay(100);
outtextxy(50,400,"                                                                                      ");
outtextxy(125,125,"1.empty");
 delay(5000);
 if(wait)
 {
         outtextxy(50,400,"waiting process will occupy vacent resource  ");
         delay(5000);
         outtextxy(50,400,"                                                                                      ");
       outtextxy(125,125,"                ");
       outtextxy(125,125,"1.full");
       outtextxy(50,400,"waiting process occupied resources 1  ");
       
       delay(5000);
       outtextxy(50,400,"                                                                                      ");
         delay(100);
         outtextxy(100,650,"1");
}    
 
delay(3000);


//system("clear");

cleardevice();
cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::";
cout<<endl;
cout<<"!!!!!!!!!!   thank you !!!!!!!!!!!!!!!!!!";
outtextxy(300,400,"Thank You");
delay(5000);


closegraph();

//getch();
}
