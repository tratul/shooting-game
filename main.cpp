#include<bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<windows.h>
#include<mmsystem.h>

#include "imageloader.h"

using namespace std;
#define ROWS 700.0
#define COLUMNS 900.0
#define FPS 50.0

GLuint _textureId;
GLuint _textureId1;
int zomX=100,zomY=175;
int heroX=50,heroY=175;
int hScore,high;
float velocityY = 2.0; //upor theke enemy porar velocity

bool gameover = false;
int score=0;
int life=30;
int level=1;

float getx(int x)
{
    return float(x)/50;
}
float gety(int y)
{
    return float(y)/50;
}

//STR



class object
{
    public:
    int x;int y;
    bool state;
    object()
    {
        x=0,y=0,state=false;
    }

};


void printS(char *string,int x,int y)
{
	glColor3f(0.0, 1.0, 1.0);
	char *c;
	glRasterPos2i(x, y);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}
void printScore(char *string)
{
	glColor3f(1.0, 1.0, 0.0); // initial score == 0 er color er jonno
	char *c;
	glRasterPos2d(850, 650);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}

void printlevel(char *string)
{
	glColor3f(1.0, 1.0, 0.0); // level == 1 er color er jonno
	char *c;
	glRasterPos2d(850, 550);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}

void printScore1(char *string)
{
	glColor3f(1.0, 1.0, 0.0);
	char *c;
	glRasterPos2d(400, 400); // game over howar por score show korbe
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}
void printLife(char *string)
{
	glColor3f(1.0, 1.0, 0.0);
	char *c;
	glRasterPos2d(850, 600);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}
void printHighScore(char *string)
{
	glColor3f(1.0, 1.0, 0.0); // game over howar por high score show korbe
	char *c;
	glRasterPos2d(450, 450);
	for (c = string; *c != '\0'; c++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}
void writeHScore()
{
      int x;
    ifstream fin;
    fin.open("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\score.txt");
    fin>>x;

    if(score>x){


  std::ofstream fout;

    fout.open("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\score.txt", std::ios_base::app );
    fout<<score;
    cout<<endl;
     high = score;}

    else high = x;
      glPushMatrix();
        stringstream ss;
        ss << high;
        string str = ss.str();
        char* char_type = (char*) str.c_str();
        //cout<<str<<endl;
        printHighScore(char_type); //new
       printS("Highest Score: ", 300, 450);
    glPopMatrix();

}
void highScore()

{
    ifstream fin;
    fin.open("score.txt");
    fin>>hScore;
}

object e1,e2,e3,f1,p1,f2,f3,e4;


//END

void plot(double x, double y)
{

    glPointSize(0.01);

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}
void Cloud(int a, int b, int c, int d,int e, int f)
{
    double i,px,py,t=0.001;
    double x1=a,x2=b,x3=c,y1=d,y2=e,y3=f;
    for(i=t;t<=1;t+=0.001){
    px=(1-t)*(1-t)*x1+2*(1-t)*t*x2+t*t*x3;
    py=(1-t)*(1-t)*y1+2*(1-t)*t*y2+t*t*y3;
    plot(px,py);
    }
}

void nextlevel()
{

    //if(score>6)
    //{


          if (f2.state==false)
    {
     f3.x=(heroX+(heroX+50))/2-2;
     f3.y=heroY+50;
     f3.state=true;
    }
    glColor3f(64.0,0.0,64.0);
    glRectd(f3.x,f3.y,f3.x+5,f3.y+5);

    if(f3.y>700)
    {
        f3.state=false;
    }

         f1.y+=11;
         f2.y+=10;
         f3.y+=9;
          //enemy4
           if(!e1.state)
    {
        e4.x=rand()%270+20;
        e4.y=rand()%700+650;
        e4.state=true;
    }
    glColor3f(1.0,0.0,0.0);
    glRectd(e4.x,e4.y,e4.x+20,e4.y+20);
    e1.y-=velocityY;
    if(e4.y<175)
    {
        e4.state=false;
    }
         velocityY = 6.0;
         level=2;


    //}


}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//glPushMatrix();

	//glTranslatef(0.0, 0.0, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 700.0, 0.0);

	glTexCoord2f(0.0, 1.0);
	glVertex3f(900.0, 700.0, 0.0);

	glTexCoord2f(1.0, 0.0);
	glVertex3f(900.0, 0.0, 0.0);

	glEnd();

	//ADD CLOUD

	glColor3f(0.0,0.0,0.0);
    Cloud(100,150,200,700,620,650);
    Cloud(200,250,300,650,620,700);
    Cloud(250,300,400,650,600,700);

    Cloud(520,580,620,700,580,630);

    Cloud(600,620,650,700,600,620);
    Cloud(650,680,720,620,580,660);
    Cloud(620,720,750,700,620,700);

	//END CLOUD
    //Hero

    /*glColor3ub(204,209,209);
    glRectd(0,175,900,700);
    glColor3ub(133,193,233);
    glRectd(0,0,900,175);
    glColor3ub(1,1,1);
    glRectd(heroX,heroY,heroX+50,heroY+50);
    glBegin(GL_LINES);
    glVertex2d(0,175);
    glVertex2d(900,175);
    glEnd();*/
    //end hero
    //start hero
   // glColor3ub(1,1,1);
   // glRectd(heroX,heroY,heroX+50,heroY+50);

     glColor3f(0,0,0);
   glPointSize(5.0);
   glBegin(GL_QUADS);
   glVertex2i(heroX-20 , heroY);
   glVertex2i(heroX-50 , heroY+38);
    glVertex2i(heroX+100 , heroY+38);
   glVertex2i(heroX+70 , heroY);
   glEnd();

      glColor3f(0.8,0.4, 0.6);
   glPointSize(5.0);
   glBegin(GL_QUADS);
   glVertex2i(heroX-10 , heroY+38);
   glVertex2i(heroX-10 , heroY+70);
    glVertex2i(heroX+50 , heroY+70);
   glVertex2i(heroX+50 , heroY+38);
   glEnd();


    //glColor3ub(200,210,215);
    //glBegin(GL_LINES);
   // glVertex2d(0,175);
   // glVertex2d(900,175);
   // glEnd();




   // glColor3ub(200,210,215);
   // glBegin(GL_LINES);
 //   glVertex2d(0,175);
   // glVertex2d(900,175);
  //  glEnd();
    //end hero
	//ADD FROM OTHERS
	 if (p1.state==true)
    {
    p1.x=rand()%850+20;
    p1.y=rand()%700+650;
    cout<<"power"<<endl;
     p1.state=false;
    }
    glColor3f(0.0,1.0,0.0);
    glRectd(p1.x,p1.y,p1.x+20,p1.y+20);


    p1.y-=velocityY;




    //fire
    if (f1.state==false)
    {
     f1.x=(heroX+(heroX+50))/2-2;
     f1.y=heroY+50;
     f1.state=true;
    }
    glColor3f(1.0,0.0,0.0);
    glRectd(f1.x,f1.y,f1.x+5,f1.y+5);

    if(f1.y>700)
    {
        f1.state=false;
    }

     //fire2
       if (f2.state==false)
    {
     f2.x=(heroX+(heroX+50))/2-2;
     f2.y=heroY+50;
     f2.state=true;
    }
    glColor3f(0.0,0.0,1.0);
    glRectd(f2.x,f2.y,f2.x+5,f2.y+5);

    if(f2.y>700)
    {
        f2.state=false;
    }



    //enemy1

    if(!e1.state)
    {
        e1.x=rand()%270+20;
        e1.y=rand()%700+650;
        e1.state=true;
    }
    glColor3f(1.0,0.0,0.0);
    glRectd(e1.x,e1.y,e1.x+20,e1.y+20);
    e1.y-=velocityY;
    if(e1.y<175)
    {
        e1.state=false;
    }

//    e2
    if(!e2.state)
    {
        e2.x=rand()%570+300;
        e2.y=rand()%750+650;
        e2.state=true;
    }
    glColor3f(1.0,0.0,0.0);
    glRectd(e2.x,e2.y,e2.x+20,e2.y+20);
    e2.y-=velocityY;
    if(e2.y<175)
    {
        e2.state=false;
    }

    if(!e3.state)
    {
        e3.x=rand()%870+320;
        e3.y=rand()%800+650;
        e3.state=true;
    }
    glColor3f(1.0,0.0,0.0);
    glRectd(e3.x,e3.y,e3.x+20,e3.y+20);
    e3.y-=velocityY;
    if(e3.y<175)
    {
        e3.state=false;
    }
     glPushMatrix();
        stringstream ss,ll,hl,label;
        ss << score;
        ll<<life;
        label<<level;
        string str = ss.str();
        string ltr = ll.str();
        string labeltr = label.str();
        char* char_type = (char*) str.c_str();
        char* char_lype = (char*) ltr.c_str();
        char* char_labeltype = (char*) labeltr.c_str();
        //cout<<str<<endl;
        printScore(char_type); //new
        printLife(char_lype);//new
        printlevel(char_labeltype);
        printS("Score: ",780, 650); //new
        printS("Life: ",780, 600);//new
        printS("Level: ",780, 550);

    glPopMatrix();
     if(score>6)
    nextlevel();


	//END FROM OTHERS


//glPopMatrix();
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glPushMatrix();
//glEnable(GL_TEXTURE_2D);
//glNormal3f(0.0f, 0.0f, 1.0f);
glLineWidth(7.0f);
glTranslatef(0.0, 0.0, 0.0f);
    glBegin(GL_LINES);
    glColor3ub(255,0,0);
      glVertex3f(getx(0), gety(175), 0.0);
      glVertex3f(getx(512), gety(175), 0.0);
    glEnd();
glPopMatrix();
	glutSwapBuffers();
}

//FUCTION DIFF STARTS
void moveLeft()
{
    if(heroX>5)
    heroX-=15;

}
void moveRight()
{   if(heroX<845)
    heroX+=15;
}
void Over()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

        glColor3ub(59,118,41);


        glPushMatrix();
            glColor3f(.9,.8,.0);
            glTranslatef(0,.6,0);
            glScalef(3,.9,0);
        glutSolidCube(.2);
        glPopMatrix();

        glColor3f(0,.3,.2);
        glPushMatrix();
            glTranslatef(0,.2,0);
            glScalef(2,.9,0);
            glutSolidCube(.2);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0,0,0);
            glScalef(2,.8,1);
            glutSolidCube(.2);
        glPopMatrix();



    glPopMatrix();

    glColor3f(1,0,0);
    printS("Game Over.\n", 350, 580);
    writeHScore();
      stringstream ss;
        ss << score;
        string str = ss.str();
        char* char_type = (char*) str.c_str();
        printScore1(char_type); //new
    printS("Score: \n", 335, 400);

    glColor3f(0,0.8,0.5);
   // printS("START GAME", 350, 400);
    printS("QUIT", 380,300);




 glutSwapBuffers();

}

bool inRangeFire(int a_min,int a_max,int b_min,int b_max)
{
    if(b_min<a_min && b_max>a_max)
    {
        return true;
    }

    else
   {
        return false;
   }
}
bool inRangePower(int a_min,int a_max,int b_min,int b_max)
{
    if(b_min<a_min && b_max>a_max)
    {
        return true;
    }

    else
   {
        return false;
   }
}


bool inRangeHero(int a_min,int a_max,int b_min,int b_max)
{
    if(b_min<a_min && b_max>a_max )
    {
        return true;
    }
    else if((b_min<a_min && b_max<a_max && b_max>=a_min) || (b_min>a_min && b_max<a_max && b_min<=a_max))
    {
        return true;
    }

    else
   {
        return false;
   }
}


void collisionDetection()
{    //fire1 with enemy collission
    if( inRangeFire(f1.x,f1.x+7,e1.x,e1.x+25) && inRangeFire(f1.y,f1.y+7,e1.y,e1.y+25) )
    {
        score++;
       sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e1 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }



        e1.state=false;
    }
    if( inRangeFire(f1.x,f1.x+7,e2.x,e2.x+25) && inRangeFire(f1.y,f1.y+7,e2.y,e2.y+25) )
    {
        score++;
    sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e2 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }
        e2.state=false;
    }
    if( inRangeFire(f1.x,f1.x+7,e3.x,e3.x+25) && inRangeFire(f1.y,f1.y+7,e3.y,e3.y+25) )
    {
        score++;
    sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e3 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }
        e3.state=false;
    }

       if (f1.state==false)
    {
     f1.x=(heroX+(heroX+50))/2-2;
     f1.y=heroY+50;
     f1.state=true;
    }
    glColor3f(1.0,0.0,0.0);
    glRectd(f1.x,f1.y,f1.x+5,f1.y+5);

    if(f1.y>700)
    {
        f1.state=false;
    }




     //fire2 with enemy collission
    if( inRangeFire(f2.x,f2.x+7,e1.x,e1.x+25) && inRangeFire(f2.y,f2.y+7,e1.y,e1.y+25) )
    {
        score++;
       sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e1 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }



        e1.state=false;
    }
    if( inRangeFire(f2.x,f2.x+7,e2.x,e2.x+25) && inRangeFire(f2.y,f2.y+7,e2.y,e2.y+25) )
    {
        score++;
    sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e2 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }
        e2.state=false;
    }
    if( inRangeFire(f2.x,f2.x+7,e3.x,e3.x+25) && inRangeFire(f2.y,f2.y+7,e3.y,e3.y+25) )
    {
        score++;
    sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e3 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }
        e3.state=false;
    }

       if (f2.state==false)
    {
     f2.x=(heroX+(heroX+50))/2-2;
     f2.y=heroY+50;
     f2.state=true;
    }
    glColor3f(1.0,0.0,0.0);
    glRectd(f2.x,f2.y,f2.x+5,f2.y+5);

    if(f2.y>700)
    {
        f2.state=false;
    }



    //fire3 with enemy collission
    if( inRangeFire(f3.x,f3.x+7,e1.x,e1.x+25) && inRangeFire(f3.y,f3.y+7,e1.y,e1.y+25) )
    {
        score++;
       sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e1 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }



        e1.state=false;
    }
    if( inRangeFire(f3.x,f3.x+7,e2.x,e2.x+25) && inRangeFire(f3.y,f3.y+7,e2.y,e2.y+25) )
    {
        score++;
    sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e2 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }
        e2.state=false;
    }
    if( inRangeFire(f3.x,f3.x+7,e3.x,e3.x+25) && inRangeFire(f3.y,f3.y+7,e3.y,e3.y+25) )
    {
        score++;
    sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot.wav",SND_ASYNC);
        cout<<" e3 "<<" score :"<<score<<endl;
        if(score%5==0)
        {
            p1.state=true;
        }
        e3.state=false;
    }

       if (f3.state==false)
    {
     f3.x=(heroX+(heroX+50))/2-2;
     f3.y=heroY+50;
     f3.state=true;
    }
    glColor3f(1.0,0.0,0.0);
    glRectd(f3.x,f3.y,f3.x+5,f3.y+5);

    if(f3.y>700)
    {
        f3.state=false;
    }





    //power
    if( inRangePower(f1.x,f1.x+5,p1.x,p1.x+20) && inRangePower(f1.y,f1.y+5,p1.y,p1.y+20) )
    {
        sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\gun-gunshot-01.wav",SND_ASYNC);
        while(life<90)
        {life+=10;

        p1.state=false;
        p1.x=0;
        p1.y=0;
        p1.state=false;
        }





    }

    //Hero & emnemy collision
    if( inRangeHero(heroX,heroX+240,e1.x,e1.x+50) && inRangeHero(heroY,heroY+50,e1.y,e1.y+20) )
    {
        life--;
        sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\Gun+Empty.wav",SND_ASYNC);
        cout<<" e1 "<<life<<endl;
        if(life<=0)
            {
        gameover=true;
        glutDisplayFunc(Over);
        }
    }
   if( inRangeHero(heroX,heroX+240,e2.x,e2.x+50) && inRangeHero(heroY,heroY+50,e2.y,e2.y+20) )
    {
        life--;
        sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\Gun+Empty.wav",SND_ASYNC);
        cout<<" e1 "<<life<<endl;
        if(life<=0){
        gameover=true;
        glutDisplayFunc(Over);
        }
    }
    if( inRangeHero(heroX,heroX+240,e3.x,e3.x+50) && inRangeHero(heroY,heroY+50,e3.y,e3.y+20) )
    {
        life--;
        sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\Gun+Empty.wav",SND_ASYNC);
        cout<<" e1 "<<life<<endl;
        if(life<=0)
        {
        gameover=true;
        glutDisplayFunc(Over);
        }
    }

     if( inRangeHero(heroX,heroX+240,e4.x,e4.x+50) && inRangeHero(heroY,heroY+50,e4.y,e4.y+20) )
    {
        life--;
        sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\Gun+Empty.wav",SND_ASYNC);
        cout<<" e1 "<<life<<endl;
        if(life<=0)
        {
        gameover=true;
        glutDisplayFunc(Over);
        }
    }
}



void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    /*glColor3ub(204,209,209);
    glRectd(0,175,900,700);
    glColor3ub(133,193,233);
    glRectd(0,0,900,175);
    glColor3ub(1,1,1);
    glRectd(heroX,heroY,heroX+50,heroY+50);
    glBegin(GL_LINES);
    glVertex2d(0,175);
    glVertex2d(900,175);
    glEnd();*/
//    fire();
   // initialize();
    drawScene();
    //nextlevel();

    glutSwapBuffers();
}

void reshape_callback(int w, int h)
{
    glViewport(0,0,(GLfloat)w,GLfloat(h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void update()
{

    f1.y+=10;
    f2.y+=9;

    //sndPlaySound("Gun+Empty.wav",SND_ASYNC);

}
void Menu()
{
    glLoadIdentity();
    glPushMatrix();

        glColor3ub(59,118,41);

        glPushMatrix();
            glColor3f(.9,.8,.0);
            glTranslatef(450,46,0);
            glScalef(345,569,0);
        glutSolidCube(20);
        glPopMatrix();

        glColor3f(0,.3,.2);
        glPushMatrix();
            glTranslatef(0,.2,0);
            glScalef(2,.9,0);
            glutSolidCube(.2);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(0,0,0);
            glScalef(2,.8,1);
            glutSolidCube(.2);
        glPopMatrix();



    glPopMatrix();

    glColor3f(1,0,0);
    printS("Shooting Game ", 350, 580);

    glColor3f(01,1,1);
    printS("START GAME", 350, 400);
    printS("QUIT", 380,300);



 //   glFlush();
 glutSwapBuffers();

}
int mouseX = 0, mouseY = 0;
void mouse(int button, int state, int x, int y)
{
//     sndPlaySound("beep.wav",SND_ASYNC);
    mouseX = x;
    mouseY = y;
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
            {

                    if(mouseX >=330 && mouseX <= 900)
                            if(mouseY >= 265 && mouseY <= 320)
                            {
                                //if(newgame) main();
                                glutDisplayFunc(drawScene);
                            }
                    else if(mouseX >=330 && mouseX <= 900)
                            if(mouseY >= 350 && mouseY <= 420)
                            {
                                exit(0);

                            }
            }
            default:
            break;
    }

}
void keyboard_callback(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            exit(0);
        break;
        case 97:
            moveLeft();
            break;
        case 100:
            moveRight();
            break;
    }
}





void timer_callback(int)
{
    update();
    collisionDetection();
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}

//FUNCTION DIFF ENDS



GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

void initialize() {

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	//gluPerspective(45.0, 1.00, 1.0, 200.0);
	//Image* image = loadBMP("text.bmp");
	Image* image = loadBMP("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\bin\\Debug\\kk.bmp");
	//_textureId = loadTexture(image);
	_textureId = loadTexture(image);
	delete image;
}
void DrawShotting()
{
    Menu();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(900, 700);

	glutCreateWindow("Textures");
	initialize();
	//lightSetting();
	glutDisplayFunc(DrawShotting);
	//gluOrtho2D(0, 900, 0, 700);
    glutReshapeFunc(reshape_callback);
    glutMouseFunc(mouse);
  //  glClearColor(1,1,1,0);
//   glutSpecialFunc(specialKeys); //Special Key Handler
    glutKeyboardFunc(keyboard_callback);
    sndPlaySound("D:\\Graphics\\final1\\Graphics-master-20181216T045713Z-001\\Graphics-master\\image\\industry_mad.wav",SND_ASYNC);
    //PlaySound("G:\\Spring-18\\COMPUTER  GRAPHICS [I]\\7\\industry_mad.wav", NULL, SND_ASYNC);
    //PlaySound(TEXT("industry_mad.wav"), NULL, SND_FILENAME);
    glutTimerFunc(1000/FPS,timer_callback,0);
	glutMainLoop();
	return 0;
}









