#include<graphics.h>
#include<math.h>
#include<time.h>
#include<conio.h>
#include<string.h>

#define PI 3.14

int telldigit(char c)
{
return int(c)-48;
}

void gettime(char m[100])
{
  time_t tim;
 tim=time(NULL);
  strcpy(m,ctime(&tim));
}
void sec_hand(int x1,int y1,int r,char m[100])
{
 int sec;
 sec=telldigit(m[17])*10+telldigit(m[18]);
 int s=6*sec;
 if(s>=0&&s<90)
 {
 s=90-s;
 line(x1,y1,x1+r*cos((s*PI)/180),y1-r*sin((s*PI)/180));
 }
 else if(s>=90&&s<180)
 {
 s=s-90;
 line(x1,y1,x1+r*cos((s*PI)/180),y1+r*sin((s*PI)/180));
 }
 else if(s>=180&&s<270)
 {
 s=270-s;
 line(x1,y1,x1-r*cos((s*PI)/180),y1+r*sin((s*PI)/180));
 }
 else if(s>=270&&s<360)
 {
 s=s-270;
 line(x1,y1,x1-r*cos((s*PI)/180),y1-r*sin((s*PI)/180));
 }
}
void min_hand(int x1,int y1,int r,char m[100])
{
  int min=telldigit(m[14])*10+telldigit(m[15]);
 int mm=6*min;
 if(mm>=0&&mm<90)
 {
 mm=90-mm;
 line(x1,y1,x1+r*cos((mm*PI)/180),y1-r*sin((mm*PI)/180));
 }
 else if(mm>=90&&mm<180)
 {
 mm=mm-90;
 line(x1,y1,x1+r*cos((mm*PI)/180),y1+r*sin((mm*PI)/180));
 }
 else if(mm>=180&&mm<270)
 {
 mm=270-mm;
 line(x1,y1,x1-r*cos((mm*PI)/180),y1+r*sin((mm*PI)/180));
 }
 else if(mm>=270&&mm<360)
 {
 mm=mm-270;
 line(x1,y1,x1-r*cos((mm*PI)/180),y1-r*sin((mm*PI)/180));
 }
}
void hour_hand(int x1,int y1,int r,char m[100])
{
 int hr=telldigit(m[11])*10+telldigit(m[12]);
 if(hr!=0)
 hr%=12;
 else
 hr=0;
 int h=30*hr;
 if(h>=0&&h<90)
 {
 h=90-h;
 line(x1,y1,x1+r*cos((h*PI)/180),y1-r*sin((h*PI)/180));
 }
 else if(h>=90&&h<180)
 {
 h=h-90;
 line(x1,y1,x1+r*cos((h*PI)/180),y1+r*sin((h*PI)/180));
 }
 else if(h>=180&&h<270)
 {
 h=270-h;
 line(x1,y1,x1-r*cos((h*PI)/180),y1+r*sin((h*PI)/180));
 }
 else if(h>=270&&h<360)
 {
 h=h-270;
 line(x1,y1,x1-r*cos((h*PI)/180),y1-r*sin((h*PI)/180));
 }
}
int change(char m[100],char b[100])
{
 int o=telldigit(m[17])*10+telldigit(m[18]);
 gettime(b);
 int n=telldigit(b[17])*10+telldigit(b[18]);
 if(n-o!=0)
 return 1;
 o=telldigit(m[14])*10+telldigit(m[15]);
 n=telldigit(b[14])*10+telldigit(b[15]);
 if(n-o!=0)
 return 1;
 o=telldigit(m[11])*10+telldigit(m[12]);
 n=telldigit(b[11])*10+telldigit(b[12]);
 return 0;

}
void clock(int x,int y,char new_time[100],char old_time[100],int radi,int radi_min=-1,int radi_hr=-1)
{
 circle(x,y,radi*1.1);
 if(radi_hr==-1)
 radi_hr=radi/1.8;
 if(radi_min==-1)
 radi_min=radi/1.3;
     setcolor(BLACK);
  sec_hand(x,y,radi,old_time);
   min_hand(x,y,radi_min,old_time);
   hour_hand(x,y,radi_hr,old_time);
  setcolor(RED);
  sec_hand(x,y,radi,new_time);
  setcolor(WHITE);
  min_hand(x,y,radi_min,new_time);
  hour_hand(x,y,radi_hr,new_time);
  gettime(old_time);
}
void main()
{
clrscr();
int d=DETECT,c;
initgraph(&d,0,"c:\\turboc3\\bgi");
 char old_time[100],new_time[100];
 int x=getmaxx()/2;
 int y=getmaxy()/2;
 int radi=50;
while(!kbhit())
 {
  if(change(old_time,new_time)!=0)
   clock(x,y,new_time,old_time,radi);
 }
}