#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/freeglut.h>
#include<iostream>

using namespace std;
char ch='\n';		// user's choice
int win=0;			// win status
int step=0;			// no. of steps
int gs=1500;		// graph size
int ib=600;			// inner block size
int ob=1300;		// outer block size
int ns=75;			// size of number
int ibgp=785;		// inner block gap
int ibspx=-1100;	// inner block starting position X-coordinate
int ibspy=1100;		// inner block starting position Y-coordinate
float lw=5.0;		// line width

float bgr=1.0;		// Background RED
float bgg=0.6;		// Background GREEN
float bgb=0.7;		// Background BLUE

float obr=0.0;		// Outer Block RED
float obg=0.0;		// Outer Block GREEN
float obb=0.0;		// Outer Block BLUE

float ibr=0.0;		// Inner Block RED
float ibg=0.0;		// Inner Block GREEN
float ibb=0.0;		// Inner Block BLUE

float ncr=1.0;		// Number Color RED
float ncg=1.0;		// Number Color GREEN
float ncb=1.0;		// Number Color BLUE

int wpx=50;			// window position X-axis
int wpy=50;			// window position Y-axis

int wsx=500;		// window Size X-axis
int wsy=500;		// window Size X-axis

int arr[9];			// stores input given by user

// following are pre-calculated values of center coordinates of each inner block
int cx[10]={0,-800,0,770,-800,0,770,-800,0,770};
int cy[10]={0,800,800,800,0,0,0,-800,-800,-800};

void init(void)
{
glClearColor(bgr,bgg,bgb,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-gs,gs,-gs,gs);
}

void draw_block(int x,int y)	//Draws an inner block
{
	for (int i=y;i>y-ib;i--)
	{	
		glVertex2i(x,i);      
		glVertex2i(x+ib,i);
	}
}

void swap(int i,int j)
{int tmp;
tmp=arr[i];
arr[i]=arr[j];
arr[j]=tmp;	
}

void test_mode()
{
arr[1]=1;
arr[2]=2;
arr[3]=3;
arr[4]=4;
arr[5]=5;
arr[6]=0;
arr[7]=7;
arr[8]=8;
arr[9]=6;
}

void input()
{
	cout<<"Enter numbers 1-8 randomly. 0 will be empty:\n";
	for(int i=1;i<=9;i++)
	cin>>arr[i];
}

void draw_outer_block(int s)
{
glVertex2i(-s,s);               // top line             
glVertex2i(s,s);

glVertex2i(-s,s);               // left line
glVertex2i(-s,-s);

glVertex2i(s,s);                // right line
glVertex2i(s,-s);

glVertex2i(-s,-s);      		// bottom line
glVertex2i(s,-s);
}

void print7seg(char c, int cx,int cy,int s)						// cx,cy => coordinates of center of 7 seg.	s=>size
{
			if(c=='a')
			{
				glVertex2i(cx-s,cy+(2*s));   //a
				glVertex2i(cx+s,cy+(2*s));
			}
	   else if(c=='b')
			{
				glVertex2i(cx+s,cy+(2*s));   //b
				glVertex2i(cx+s,cy);
			}
		else if(c=='c')
			{
				glVertex2i(cx+s,cy);	    //c
				glVertex2i(cx+s,cy-(2*s));					
			}
		else if(c=='d')
			{
				glVertex2i(cx-s,cy-(2*s));   //d
				glVertex2i(cx+s,cy-(2*s));
			}
		else if(c=='e')
			{
				glVertex2i(cx-s,cy);   	//e
				glVertex2i(cx-s,cy-(2*s));
			}
		else if(c=='f')
			{
				glVertex2i(cx-s,cy);   	//f
				glVertex2i(cx-s,cy+(2*s));
			}
		else if(c=='g')
			{
				glVertex2i(cx-s,cy);   	//g
				glVertex2i(cx+s,cy);
			}
}

void printnum(int n,int cx,int cy,int s)					// n=> number	cx,cy => coordinates of center of 7 seg.	s=>size
{
	switch (n)
		{
			case 1:{
					print7seg('b',cx-s,cy,s);
					print7seg('c',cx-s,cy,s);
				break;}
			case 2:{
					print7seg('a',cx,cy,s);
					print7seg('b',cx,cy,s);
					print7seg('d',cx,cy,s);
					print7seg('e',cx,cy,s);
					print7seg('g',cx,cy,s);
				break;}
			case 3:{
					print7seg('a',cx,cy,s);
					print7seg('b',cx,cy,s);
					print7seg('c',cx,cy,s);
					print7seg('d',cx,cy,s);
					print7seg('g',cx,cy,s);
				break;}
			case 4:{
					print7seg('b',cx,cy,s);
					print7seg('c',cx,cy,s);
					print7seg('f',cx,cy,s);
					print7seg('g',cx,cy,s);
				break;}
			case 5:{
					print7seg('a',cx,cy,s);
					print7seg('c',cx,cy,s);
					print7seg('d',cx,cy,s);	
					print7seg('f',cx,cy,s);
					print7seg('g',cx,cy,s);
				break;}
			case 6:{
					print7seg('a',cx,cy,s);
					print7seg('c',cx,cy,s);
					print7seg('d',cx,cy,s);
					print7seg('e',cx,cy,s);
					print7seg('f',cx,cy,s);
					print7seg('g',cx,cy,s);
				break;}
			case 7:{
					print7seg('a',cx,cy,s);
					print7seg('b',cx,cy,s);
					print7seg('c',cx,cy,s);
				break;}
			case 8:{
					print7seg('a',cx,cy,s);
					print7seg('b',cx,cy,s);
					print7seg('c',cx,cy,s);
					print7seg('d',cx,cy,s);
					print7seg('e',cx,cy,s);
					print7seg('f',cx,cy,s);
					print7seg('g',cx,cy,s);
				break;}
			case 9:{
					print7seg('a',cx,cy,s);
					print7seg('b',cx,cy,s);
					print7seg('c',cx,cy,s);
					print7seg('d',cx,cy,s);
					print7seg('f',cx,cy,s);
					print7seg('g',cx,cy,s);
				break;}
			case 0:{
					print7seg('a',cx,cy,s);
					print7seg('b',cx,cy,s);
					print7seg('c',cx,cy,s);
					print7seg('d',cx,cy,s);
					print7seg('e',cx,cy,s);
					print7seg('f',cx,cy,s);
				break;}
		}	
}

int match()
{
	if(
	(arr[1]==1)&&
	(arr[2]==2)&&
	(arr[3]==3)&&
	(arr[4]==4)&&
	(arr[5]==5)&&
	(arr[6]==6)&&
	(arr[7]==7)&&
	(arr[8]==8)&&
	(arr[9]==0)
	)return 1;
}

void print_nos()
{
	for(int i=1;i<=9;i++)
	{
		if(arr[i]!=0)
		printnum(arr[i],cx[i],cy[i],ns);
	}
}

void setpixel()
{

do{
		glClear(GL_COLOR_BUFFER_BIT);
		glLineWidth(lw);
		glBegin(GL_LINES);
		glColor3f(obr,obg,obb);
		draw_outer_block(ob);

		glColor3f(ibr,ibg,ibb);
		
		int x=ibspx;
		int y=ibspy;
		
		int k=1;	//for traversing arr
		for(int i=0,x=ibspx;i<3;i++,y=y-ibgp)
		{	
			for(int j=0;j<3;j++,x=x+ibgp)
			{	
				if(arr[k]!=0)
				{draw_block(x,y);k++;}
				else{draw_block(x-5000,y);k++;}
			}
			x=ibspx;
		}

		glColor3f(ncr,ncg,ncb);
		print_nos();
		glEnd();
		glFlush();

cin>>ch;
step++;	
switch(ch)
	{
			case 'w':{
				     if(arr[1]==0){swap(1,4);}
				else if(arr[2]==0){swap(2,5);}
				else if(arr[3]==0){swap(3,6);}
				else if(arr[4]==0){swap(4,7);}
				else if(arr[5]==0){swap(5,8);}
				else if(arr[6]==0){swap(6,9);}
				else if(arr[7]==0){swap(7,7);}
				else if(arr[8]==0){swap(8,8);}
				else if(arr[9]==0){swap(9,9);}
				break;
				}
			case 'a':{
				     if(arr[1]==0){swap(1,2);}
				else if(arr[2]==0){swap(2,3);}
				else if(arr[3]==0){swap(3,3);}
				else if(arr[4]==0){swap(4,5);}
				else if(arr[5]==0){swap(5,6);}
				else if(arr[6]==0){swap(6,3);}
				else if(arr[7]==0){swap(7,8);}
				else if(arr[8]==0){swap(8,9);}
				else if(arr[9]==0){swap(9,9);}
				break;
				}
			case 's':{
				     if(arr[1]==0){swap(1,1);}
				else if(arr[2]==0){swap(2,2);}
				else if(arr[3]==0){swap(3,3);}
				else if(arr[4]==0){swap(4,1);}
				else if(arr[5]==0){swap(5,2);}
				else if(arr[6]==0){swap(6,3);}
				else if(arr[7]==0){swap(7,4);}
				else if(arr[8]==0){swap(8,5);}
				else if(arr[9]==0){swap(9,6);}
				break;
				}
			case 'd':{
		   		     if(arr[1]==0){swap(1,1);}
				else if(arr[2]==0){swap(2,1);}
				else if(arr[3]==0){swap(3,2);}
				else if(arr[4]==0){swap(4,4);}
				else if(arr[5]==0){swap(5,4);}
				else if(arr[6]==0){swap(6,5);}
				else if(arr[7]==0){swap(7,7);}
				else if(arr[8]==0){swap(8,7);}
				else if(arr[9]==0){swap(9,8);}
				break;
				}
	}
	win=match();
}
while(win!=1);
}

int main(int argc, char **argv)
{int win=0;
input();
//test_mode();
glutInit(&argc,argv);
glutInitWindowPosition(wpx,wpy);
glutInitWindowSize(wsx,wsy);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutCreateWindow("8 Block Puzzle");
init();
glutDisplayFunc(setpixel);
glutMainLoopEvent();
glutLeaveMainLoop();
cout<<"you won...\n";
cout<<"Steps="<<step<<"\n\n";
return 0;
}

