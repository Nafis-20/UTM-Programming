#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;

void drawTriangle(double x[],double y[],int gd,int gm);
void rotateTriangle(double x[],double y[],int gd,int gm);
void moveTriangle(double x[],double y[],int gd,int gm);
void scaleTriangle(double x[],double y[],int gd,int gm);
void rotateAnime(double x[],double y[],int &f,int gd,int gm);
void moveAnime(double x[],double y[],int &d,int gd,int gm);
void scaleAnime(double x[],double y[],double &s,int gd,int gm);

// Driver code

int main()
{
    int gd=DETECT,gm,a;    // gm is Graphics mode, gd=graphics driver
    double x[3],y[3];

    cout<<"1. Draw a Triangle\n";
    cout<<"2. Rotate the Triangle\n";
    cout<<"3. Move the Triangle\n";
    cout<<"4. Scale the Triangle\n";
    cout<<"5. Rotating Animation\n";
    cout<<"6. Moving Animation\n";
    cout<<"7. Scaling Animation\n";
    cout<<"\nWhat you want to do? (Choose 1/2/3/4/5/6/7) - ";
    cin>>a;

    for(int i=0;i<3;i++)
    {
        cout<<"\nEnter the x"<<i+1<<"- ";
        cin>>x[i];
        cout<<"Enter the y"<<i+1<<"- ";
        cin>>y[i];
    }

    switch(a)
    {
    case 1 : drawTriangle(x,y,gd,gm);
        break;
    case 2 : rotateTriangle(x,y,gd,gm);
        break;
    case 3 : moveTriangle(x,y,gd,gm);
        break;
    case 4 : scaleTriangle(x,y,gd,gm);
        break;
    case 5 : initgraph(&gd, &gm, (char*)"");
             for(int i=0;i<1000;i++)
             {
                 cleardevice();
                 rotateAnime(x,y,i,gd,gm);
                 swapbuffers();
                 delay(10);
             }
        break;
    case 6 : initgraph(&gd, &gm, (char*)"");
             for(int i=0;i<1000;i++)
             {
                 cleardevice();
                 moveAnime(x,y,i,gd,gm);
                 swapbuffers();
                 delay(20);
             }
        break;
    case 7 : initgraph(&gd, &gm, (char*)"");
             for(double i=0;i<1000;i=i+0.1)
             {
                 cleardevice();
                 scaleAnime(x,y,i,gd,gm);
                 swapbuffers();
                 delay(200);
             }
        break;
    default : cout<<"Invalid Input";
        break;
    }

    getch();
    closegraph();
    return 0;
}

void drawTriangle(double x[],double y[],int gd,int gm)
{
    initgraph(&gd, &gm, (char*)"");

    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[0],y[0]);
}

void rotateTriangle(double x[],double y[],int gd,int gm)
{
    double f,a[3],b[3];
    double x_pivot;
    double y_pivot;

    cout<<"\nEnter the rotation triangle- ";
    cin>>f;
    cout<<"\nEnter X pivot and Y pivot. (Give X and Y pivot = 0 to rotate about origin(0,0)):";
    cout<<"\n\nX pivot- ";
    cin>>x_pivot;
    cout<<"Y pivot- ";
    cin>>y_pivot;

    initgraph(&gd, &gm, (char*)"");

    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[0],y[0]);

    for(int i=0;i<3;i++)
    {
        double x_shifted = x[i] - x_pivot;
        double y_shifted = y[i] - y_pivot;

        a[i]=x_pivot+(x_shifted*cos(f*3.14159/180)-y_shifted*sin(f*3.14159/180));
        b[i]=y_pivot+(x_shifted*sin(f*3.14159/180)+y_shifted*cos(f*3.14159/180));
    }

    line(a[0],b[0],a[1],b[1]);
    line(a[1],b[1],a[2],b[2]);
    line(a[2],b[2],a[0],b[0]);
}

void moveTriangle(double x[],double y[],int gd,int gm)
{
    int d;
    cout<<"\nEnter the moving distance- ";
    cin>>d;

    initgraph(&gd, &gm, (char*)"");

    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[0],y[0]);

    for(int i=0;i<3;i++)
    {
        x[i]=x[i]+d;
        y[i]=y[i]+d;
    }

    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[0],y[0]);
}

void scaleTriangle(double x[],double y[],int gd,int gm)
{
    double s;
    cout<<"\nEnter the scale factor- ";
    cin>>s;

    initgraph(&gd, &gm, (char*)"");

    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[0],y[0]);

    for(int i=0;i<3;i++)
    {
        x[i]=s*x[i];
        y[i]=s*y[i];
    }

    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[0],y[0]);
}

void rotateAnime(double x[],double y[],int &f,int gd,int gm)
{
    double a[3],b[3];
    double x_pivot=319.5;
    double y_pivot=239.5;

    for(int i=0;i<3;i++)
    {
        double x_shifted = x[i] - x_pivot;
        double y_shifted = y[i] - y_pivot;

        a[i]=x_pivot+(x_shifted*cos(f*3.14159/180)-y_shifted*sin(f*3.14159/180));
        b[i]=y_pivot+(x_shifted*sin(f*3.14159/180)+y_shifted*cos(f*3.14159/180));
    }

    line(a[0],b[0],a[1],b[1]);
    line(a[1],b[1],a[2],b[2]);
    line(a[2],b[2],a[0],b[0]);
}

void moveAnime(double x[],double y[],int &d,int gd,int gm)
{
    double a[3],b[3];

    for(int i=0;i<3;i++)
    {
        if(x[i]+d<=0 || x[i]+d>640 || y[i]+d<=0 || y[i]+d>450)
            d=0;

        a[i]=x[i]+d;
        b[i]=y[i]+d;
    }

    line(a[0],b[0],a[1],b[1]);
    line(a[1],b[1],a[2],b[2]);
    line(a[2],b[2],a[0],b[0]);
}

void scaleAnime(double x[],double y[],double &s,int gd,int gm)
{
    double a[3],b[3];

    for(int i=0;i<3;i++)
    {
        if(x[i]*s<=0 || x[i]*s>640 || y[i]*s<=0 || y[i]*s>450)
            s=0;

        a[i]=s*x[i];
        b[i]=s*y[i];
    }

    line(a[0],b[0],a[1],b[1]);
    line(a[1],b[1],a[2],b[2]);
    line(a[2],b[2],a[0],b[0]);
}
