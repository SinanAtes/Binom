#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include <iomanip>
using namespace std;

int N,nmax,n1;
double p;
double q;

double yolcek=10;        //Yukseklik olcegi
double xolcek=0.04;
double asagiKaydir=0.7;
double solaKaydir=0.7;

double faktoriyel(int);
double binom(int);
void sahne();
void klavye (unsigned char, int , int );

int main(int argc, char** argv) {
    cout<<"Grafigi yatayda buyutup kucultmek icin q(+)-w(-) tuslarini"<<endl;
    cout<<"Grafigi dikeyde buyutup kucultmek icin a(+)-s(-) tuslarini kullanabilirsiniz."<<endl;
    cout<<"N sayisini giriniz ";
    cin>>N;
    cout<<"p degerini giriniz ";
    cin>>p;
    q=1-p;
    cout<<"n sayisinin araligini giriniz.(Ilk deger bosluk ikinci deger seklinde) ";
    cin>>n1>>nmax;
    for(int n=n1;n<=nmax;n++){
        cout<<"P("<<n<<")="<<setw(8)<<binom(n)<<endl;
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    glutInitWindowSize(800,600);
    glutCreateWindow("Binom Dagilimi");
    glutDisplayFunc(sahne);
    glutKeyboardFunc(klavye);
    glutMainLoop();  
    return 0;
}
void sahne(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex2f(-1,-asagiKaydir);                //X ekseni
    glVertex2f(1,-asagiKaydir);
    glVertex2f(0-solaKaydir,-1);                //Y ekseni
    glVertex2f(0-solaKaydir,1);
    glEnd();
    glColor3f(0,1,0);
    glLineWidth(3);
    double y;
    glBegin(GL_LINES);
    //double x=0*xolcek-solaKaydir,y;   
    for(int n=n1;n<=nmax;n++){
        y=0;
        glVertex2f(n*xolcek-solaKaydir,y*yolcek-asagiKaydir);
        y=binom(n);
        glVertex2f(n*xolcek-solaKaydir,y*yolcek-asagiKaydir);
        
    }
    glEnd();
    glutSwapBuffers();        
    
    
}
double faktoriyel(int a){
    if(a==0){
        return 1;
    }
    double faktoriyel=1;
    while(a>0){
        faktoriyel*=a;
        a--;
    }
    return faktoriyel;
}
double binom(int n){
    double Pn=0;
    Pn=faktoriyel(N)/(faktoriyel(n)*faktoriyel(N-n))*pow(p,n)*pow(q,(N-n));
    return Pn;
}
void klavye (unsigned char tus, int x, int y){
    if(tus=='q'){
        xolcek+=0.001;
    }
    if(tus=='w'){
        xolcek-=0.001;
    }
    if(tus=='a'){
        yolcek+=0.1;
    }
    if(tus=='s'){
        yolcek-=0.1;
    }
    sahne();
}
