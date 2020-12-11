#include<graphics.h>
//#include<myturbo.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
union REGS in,out;
void showmouse()
{
 in.x.ax=1;
 int86(0x33,&in,&out);
 //return(out.x.ax);
}
int xmouse()
{
 in.x.ax=3;
 int86(0x33,&in,&out);
 return(out.x.cx);
}
int ymouse()
{
 in.x.ax=3;
 int86(0x33,&in,&out);
 return(out.x.dx);
}
void re()
{
 in.x.ax=0;
 int86(0x33,&in,&out);
}
int main()
{
 int d=DETECT;
 initgraph(&d,0,"c:\\turboc3\\bgi");
 float x1=getmaxx()/2,y1=getmaxy()/2,r=50,y2,x2,x3,y3;
 int x10=getmaxx()/2,y10=getmaxy()/2,r0=50,y20,x20,x30,y30;
 re();
 while(!kbhit())
 {
 showmouse();
 x2=xmouse();
 y2=ymouse();
 if(x2>x1&&y2>y1&&(x2!=x1&&y2!=y1))
 {
 x3=r/sqrt(pow((y2-y1)/(x2-x1),2)+1)+x1;
 y3=r/sqrt(pow((x2-x1)/(y2-y1),2)+1)+y1;
 }
 else if(x2>x1&&y2<y1&&(x2!=x1&&y2!=y1))
 {
 x3=r/sqrt(pow((y2-y1)/(x2-x1),2)+1)+x1;
 y3=y1-r/sqrt(pow((x2-x1)/(y2-y1),2)+1);
 }
 else if(x2<x1&&y2<y1&&(x2!=x1&&y2!=y1))
 {
 x3=x1-r/sqrt(pow((y2-y1)/(x2-x1),2)+1);
 y3=y1-r/sqrt(pow((x2-x1)/(y2-y1),2)+1);
 }
 else if(x2<x1&&y2>y1&&(x2!=x1&&y2!=y1))
 {
 x3=x1-r/sqrt(pow((y2-y1)/(x2-x1),2)+1);
 y3=r/sqrt(pow((x2-x1)/(y2-y1),2)+1)+y1;
 }
  x20=xmouse();
 y20=ymouse();
 if(x20>x10&&y20>y10&&(x20!=x10&&y20!=y10))
 {
 x30=r0/sqrt(pow((y20-y10)/(x20-x10),2)+1)+x10;
 y30=r0/sqrt(pow((x20-x10)/(y20-y10),2)+1)+y10;
 }
 else if(x20>x10&&y20<y10&&(x20!=x10&&y20!=y10))
 {
 x30=r0/sqrt(pow((y20-y10)/(x20-x10),2)+1)+x10;
 y30=y10-r0/sqrt(pow((x20-x10)/(y20-y10),2)+1);
 }
 else if(x20<x10&&y20<y10&&(x20!=x10&&y20!=y10))
 {
 x30=x10-r0/sqrt(pow((y20-y10)/(x20-x10),2)+1);
 y30=y10-r0/sqrt(pow((x20-x10)/(y20-y10),2)+1);
 }
 else if(x20<x10&&y20>y10&&(x20!=x10&&y20!=y10))
 {
 x30=x10-r0/sqrt(pow((y20-y10)/(x20-x10),2)+1);
 y30=r0/sqrt(pow((x20-x10)/(y20-y10),2)+1)+y10;
 }

 line(x1,y1,x3,y3);
 setcolor(RED);
 line(x10,y10,x30,y30);
  delay(90);
  setcolor(BLACK);
  line(x1,y1,x3,y3);
  line(x10,y10,x30,y30);
  setcolor(WHITE);
 }
 getch();
 return 0;
}