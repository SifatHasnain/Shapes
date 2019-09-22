#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>

#define MAX 1000
#define PI 2*acos((double)0)

using namespace std;

class shape
{
protected:
    double x[1000],y[1000],z[1000];
public:
    static int count;
    static int obSER[MAX];
    shape();
    shape(int index,double m[],double n[]);
    shape(int index,double m[],double n[],double o[]);

    void get_ord(int index,double m[],double n[],double o[]);
    void get_ord(int index,double m[],double n[]);

	virtual double get_vol() { return 0; }
    virtual double get_area() { return 0; }
    virtual void showDIM() {}
    virtual void draw() {}
    virtual void get_dim(double *l){}

    friend ostream& operator<<(ostream& out,shape *shape);
};

int shape::count=1;
int shape::obSER[MAX];

shape::shape() {  memset(x,0,sizeof(x)); memset(y,0,sizeof(y)); memset(z,0,sizeof(z));  }

shape::shape(int index,double m[],double n[])
{
   for(int i=1;i<=index;i++) {  x[i]=m[i]; y[i]=n[i]; }
}

shape::shape(int index,double m[],double n[],double o[])
{
    for(int i=1;i<=index;i++) {  x[i]=m[i]; y[i]=n[i]; z[i]=o[i]; }
}
void shape::get_ord(int index,double m[],double n[],double o[])
{
    for(int i=1;i<=index;i++) {  m[i]=x[i]; n[i]=y[i]; o[i]=z[i]; }
}

void shape::get_ord(int index,double m[],double n[])
{
    for(int i=1;i<=index;i++) {  m[i]=x[i]; n[i]=y[i]; }
}

ostream& operator<<(ostream& out,shape *shape)
{
        shape->showDIM();
        out<<"Area : "<<shape->get_area()<<endl;
		cout<<"Volume : "<<shape->get_vol()<<endl;
        return out;
}


class triangle:public shape
{
    double Base,Height;
public:
    static int tri;
    triangle() {  Base=Height=0; }
    triangle(double *l,int index,double m[],double n[]):shape(index,m,n) {
           Base=l[1];   Height=l[2];
        }
    double get_area();
    void get_dim(double *l);
    void showDIM();
    friend istream& operator>>(istream& in,triangle &triangle);
};

int triangle::tri=1;

double triangle::get_area() {  return .5*Base*Height;  }

void triangle::get_dim(double *l) { l[1]= Base; l[2]= Height; }

void triangle::showDIM()
{
    cout<<endl<<"Triangle"<<endl<<"======"<<endl<<"Dimension: "<<endl;
    cout<<"Base: "<<Base<<"   "<<"Height: "<<Height<<endl<<endl;
    cout<<"Co-ordinates (x,y) -"<<endl;
        for(int i=1;i<=3;i++) cout<<i<<". (x"<<i<<" , y"<<i<<") : "<<x[i]<<" "<<y[i]<<endl;
}

istream& operator>>(istream& in,triangle &triangle)
{
        int choice;
    cout<<endl<<"Triangle"<<endl<<"======"<<endl;
    cout<<"1.Dimension 2.Co-ordinates 3.Both"<<endl<<"Choice: ";
        in>>choice;
        if (choice==1 || choice==3) {
                cout<<endl<<"Dimension: "<<endl;
                cout<<"Base: ";
        in>>triangle.Base;
                cout<<"Height: ";
        in>>triangle.Height;
        }
        if(choice==2 || choice==3) {
                cout<<endl<<"Co-ordinates (x,y) -"<<endl;
            for(int i=1;i<=3;i++) {
                cout<<i<<". (x"<<i<<" , y"<<i<<") : ";
            in>>triangle.x[i]>>triangle.y[i];
        }} cout<<endl;
    return in;
}


class rect:public shape
{
    double Length,Breadth;
public:
    static int rec;
    rect() {  Length=Breadth=0;  }
    rect(double *l,int index,double m[],double n[]):shape(index,m,n) {
           Length=l[1];  Breadth=l[2];
    }
    double get_area();
    void get_dim(double *l);
    void showDIM();
    friend istream& operator>>(istream& in,rect &rect);
};

int rect::rec=1;

double rect::get_area() {  return Length*Breadth;  }

void rect::get_dim(double *l)
{
    l[1]= Length;
    l[2]=Breadth;
}

void rect::showDIM()
{
    cout<<endl<<"Rectangle"<<endl<<"======"<<endl;
    cout<<"Dimension: "<<endl;
    cout<<"Length: "<<Length<<"   "<<"Breadth: "<<Breadth<<endl<<endl;
    cout<<"Co-ordinates (x,y) -"<<endl;
        for(int i=1;i<=4;i++) cout<<i<<". (x"<<i<<" , y"<<i<<") : "<<x[i]<<" , "<<y[i]<<endl;
}

istream& operator>>(istream& in,rect &rect)
{
        int choice;
    cout<<endl<<"Rectangle"<<endl<<"======"<<endl;
    cout<<"1.Dimension 2.Co-ordinates 3.Both"<<endl<<"Choice: ";
    in>>choice;
    if (choice==1 || choice==3) {
        cout<<endl<<"Dimension: "<<endl;
        cout<<"Length: ";
            in>>rect.Length;
        cout<<"Breadth: ";
            in>>rect.Breadth;
    } if(choice==2 || choice==3) {
        cout<<"Co-ordinates (x,y) -"<<endl;
            for(int i=1;i<=4;i++) {
        cout<<i<<". (x"<<i<<" , y"<<i<<") : ";
             in>>rect.x[i]>>rect.y[i];
        }} cout<<endl;
    return in;
}

class cube:public shape {
    double Length,Breadth,Height;
public:
    static int cub;
    cube() {   Length=Breadth=Height=0; }
    cube(double *l,int index,double m[],double n[],double o[]) {
           Length=l[1];
           Breadth=l[2];
           Height=l[3];
           for(int i=1;i<=8;i++) {  x[i]=m[i];   y[i]=n[i]; z[i]=o[i];  }
    }
    double get_vol();
    double get_area();
    void get_dim(double *l);
    void showDIM();
    friend istream& operator>>(istream& in,cube &cube);
};

int cube::cub=1;

double cube::get_vol() {  return Length*Breadth*Height;  }

double cube::get_area() { return 2*(Length*Breadth+Breadth*Height+Height*Length);  }

void cube::get_dim(double *l)
{
            l[1]= Length;
            l[2]= Breadth;
            l[3]= Height;
}

void cube::showDIM()
 {
        cout<<endl<<"Cube"<<endl<<"======"<<endl;
        cout<<"Dimension: "<<endl;
        cout<<"Length: "<<Length<<endl<<"Breadth: "<<Breadth<<endl<<"Height: "<<Height<<endl<<endl;
        cout<<"Co-ordinates (x,y,z) -"<<endl;
        for(int i=1;i<=8;i++) cout<<i<<". (x"<<i<<" , y"<<i<<" , z"<<i<<") : "<<x[i]<<" , "<<y[i]<<" , "<<z[i]<<endl;
}

istream& operator>>(istream& in,cube &cube)
{
    int choice;
        cout<<endl<<"Cube"<<endl<<"======"<<endl;
        cout<<"1.Dimension 2.Co-ordinates 3.Both"<<endl<<"Choice: ";
    in>>choice;
     if (choice==1 || choice==3) {
            cout<<endl<<"Dimension: "<<endl;
            cout<<"Length: ";
        in>>cube.Length;
            cout<<"Breadth: ";
        in>>cube.Breadth;
            cout<<"Height: ";
        in>>cube.Height;
     } if(choice==2 || choice==3) {
        cout<<"Co-ordinates (x,y,z) -"<<endl;
            for(int i=1;i<=8;i++) {
        cout<<i<<". (x"<<i<<" , y"<<i<<" , z"<<i<<") : ";
             in>>cube.x[i]>>cube.y[i]>>cube.z[i];
        }} cout<<endl;
    return in;
}


class square:public shape
{
   double Length;
public:
    static int sq;
    square() { Length=0; }
    square(double *l,int index,double m[],double n[]):shape(index,m,n)
    { Length=l[1]; }
    double get_area();
    void get_dim(double *l);
    void showDIM();
    friend istream& operator>>(istream& in,square &square);
};

int square::sq=1;

double square::get_area() {  return  Length*Length;  }

void square::get_dim(double *l) {  l[1]= Length;  }

void square::showDIM()
{
    cout<<endl<<"Square"<<endl<<"======"<<endl;
    cout<<"Dimension: "<<endl;
    cout<<"Length : "<<Length<<endl<<endl;
    cout<<"Co-ordinates (x,y) -"<<endl;
        for(int i=1;i<=4;i++) cout<<i<<". (x"<<i<<" , y"<<i<<") : "<<x[i]<<" , "<<y[i]<<endl;
}

istream& operator>>(istream& in,square &square) {
        int choice;
    cout<<endl<<"Square"<<endl<<"======"<<endl;
    cout<<"1.Dimension 2.Co-ordinates 3.Both"<<endl<<"Choice: ";
        in>>choice;
      if (choice==1 || choice==3) {
            cout<<endl<<"Dimension: "<<endl;
            cout<<"Length : ";
        in>>square.Length;
      } if(choice==2 || choice==3) {
            cout<<"Co-ordinates (x,y) -"<<endl;
        for(int i=1;i<=4;i++) {
            cout<<i<<". (x"<<i<<" , y"<<i<<") : ";
        in>>square.x[i]>>square.y[i];
    }} cout<<endl;
    return in;
}


class circle:public shape
{
    double Radius;
public:
    static int cir;
    circle() {  Radius=0;  }
    circle(double *l,int index,double m[],double n[]):shape(index,m,n)
    {  Radius=l[1];  }
    double get_area() {  return PI*Radius*Radius;  }
    void get_dim(double *l) {  l[1]= Radius;   }
    void showDIM();
    friend istream& operator>>(istream& in,circle &circle);
};

int circle::cir=1;

void circle::showDIM()
{
    cout<<endl<<"Circle"<<endl<<"======"<<endl;
    cout<<"Dimension: "<<endl;
    cout<<"Radius: "<<Radius<<endl<<endl;
    cout<<"Co-ordinates of center(x,y) -"<<endl;
    for(int i=1;i<=1;i++) cout<<i<<". (x"<<i<<" , y"<<i<<") : "<<x[i]<<" , "<<y[i]<<endl;
}

istream& operator>>(istream& in,circle &circle)
{
        int choice;
    cout<<endl<<"Circle"<<endl<<"======"<<endl;
    cout<<"1.Radius 2.Co-ordinates of center 3.Both"<<endl<<"Choice: ";
    in>>choice;
    if (choice==1 || choice==3) {
        cout<<endl<<"Dimension: "<<endl;
        cout<<"Radius: ";
            in>>circle.Radius;
    } if(choice==2 || choice==3) {
        cout<<"Co-ordinates of center(x,y) -"<<endl;
            for(int i=1;i<=1;i++) {
        cout<<i<<". (x"<<i<<" , y"<<i<<") : ";
             in>>circle.x[i]>>circle.y[i];
        }} cout<<endl;
    return in;
}

class line:public shape {
    double Length;
public:
    static int lin;
    line() {  Length=0;  }
    line(double *l,int index,double m[],double n[]):shape(index,m,n)
    { Length=l[1]; }
    void get_dim(double *l) {  l[1]= Length;   }
    void showDIM();
    friend istream& operator>>(istream& in,line &line);
};

int line::lin=1;

void line::showDIM()
{
    cout<<endl<<"Line"<<endl<<"======"<<endl;
    cout<<"Dimension: "<<endl;
    cout<<"Length: "<<Length<<endl<<endl;
    cout<<"Co-ordinates of its end points(x,y) -"<<endl;
        for(int i=1;i<=2;i++) cout<<i<<". (x"<<i<<" , y"<<i<<") : "<<x[i]<<" , "<<y[i]<<endl;
}

istream& operator>>(istream& in,line &line)
{
        int choice;
    cout<<endl<<"Line"<<endl<<"======"<<endl;
    cout<<"1.Length 2.Co-ordinates of its end points 3.Both"<<endl<<"Choice: ";
    in>>choice;
    if (choice==1 || choice==3) {
        cout<<endl<<"Dimension: "<<endl;
        cout<<"Length: ";
            in>>line.Length;
    } if(choice==2 || choice==3) {
        cout<<"Co-ordinates of center(x,y) -"<<endl;
            for(int i=1;i<=2;i++) {
        cout<<i<<". (x"<<i<<" , y"<<i<<") : ";
             in>>line.x[i]>>line.y[i];
        }} cout<<endl;
    return in;
}


class cylinder:public shape
{
    double Radius,Height;
public:
    static int clndr;
    cylinder() {  Radius=0; Height=0; }
    cylinder(double *l,double m[],double n[]) {  Radius=l[1];  }
    double get_area();
    double get_vol();
    void get_dim(double *l);
    void showDIM();
    friend istream& operator>>(istream& in,cylinder &cylinder);
};

int cylinder::clndr=1;

double cylinder:: get_area() { return 2*PI*Radius*Height;  }

double cylinder::get_vol() {   return PI*Radius*Radius*Height;  }

void cylinder::get_dim(double *l) {  l[1]= Radius; l[2]=Height;  }

void cylinder::showDIM()
{
    cout<<endl<<"Cylinder"<<endl<<"======"<<endl;
    cout<<"Dimension: "<<endl;
    cout<<"Radius: "<<Radius<<endl;
    cout<<"Height: "<<Height<<endl<<endl;
}

istream& operator>>(istream& in,cylinder &cylinder)
{
    cout<<endl<<"Cylinder"<<endl<<"======"<<endl;
    cout<<"Dimension: "<<endl;
    cout<<"Radius: ";
            in>>cylinder.Radius;
    cout<<"Height: ";
            in>>cylinder.Height;
    cout<<endl;
    return in;
}


 void switch_ob(int no,shape *obj_shape[])
{
    int choice;
    cout<<endl<<"Shape type :"<<endl<<"(1. Triangle 2. Rectangle 3. Cube 4. Square 5.Circle";
    cout<<" 6.Straight line 7.Cylinder)"<<endl<<endl<<"Choice: ";
    cin>>choice;
    shape::obSER[no]=choice;
    cout<<"Shape no: "<<no<<endl;
    switch(choice)
        {
            case 1: {
               triangle *tr;
               tr = new triangle;
                    cin>>*tr;
                        obj_shape[no] = tr;
                        triangle::tri++;
                       break;
                       }
            case 2: {
                rect *re;
                re = new rect;
                    cin>>*re;
                       obj_shape[no]=re;
                       rect::rec++;
                       break;
                       }
            case 3: {
                cube *cu;
                cu = new cube;
                    cin>>*cu;
                       obj_shape[no]=cu;
                       cube::cub++;
                       break;
                       }
            case 4: {
                square *sq;
                sq = new square;
                cin>>*sq;
                       obj_shape[no]=sq;
                       square::sq++;
                       break;
                       }
            case 5: {
                circle *circ;
                circ = new circle;
                    cin>>*circ;
                       obj_shape[no]=circ;
                       circle::cir++;
                       break;
                       }
            case 6: {
                line *ln;
                ln = new line;
                    cin>>*ln;
                       obj_shape[no]=ln;
                       line::lin++;
                       break;
            }
            case 7: {
                cylinder *cdr;
                cdr = new cylinder;
                    cin>>*cdr;
                       obj_shape[no]=cdr;
                       cylinder::clndr++;
                       break;
            }
            default: {
                cout<<"Enter again!"<<endl;
                switch_ob(no,obj_shape);
                }
        }
}

void switch_ob(shape *obj_shape[],int no)
{
    int choice=shape::obSER[no];
    double m[100],n[100],l[100],o[100];
        obj_shape[no]->get_dim(l);
    cout<<"Shape no: "<<no<<endl;
    switch(choice)
        {
            case 1: {
                obj_shape[no]->get_ord(3,m,n);
                triangle *tr;
                tr=new triangle(l,3,m,n);
                    cin>>*tr;
                obj_shape[no] = tr;
            break;
            }
            case 2: {
                obj_shape[no]->get_ord(4,m,n);
                rect *re;
                re = new rect(l,4,m,n);
                    cin>>*re;
                obj_shape[no]=re;
            break;
            }
            case 3: {
                obj_shape[no]->get_ord(8,m,n,o);
                cube *cu;
                cu = new cube(l,8,m,n,o);
                    cin>>*cu;
                obj_shape[no]=cu;
            break;
            }
            case 4: {
                obj_shape[no]->get_ord(4,m,n);
                square *sqr;
                sqr = new square(l,4,m,n);
                    cin>>*sqr;
                obj_shape[no]=sqr;
            break;
            }
            case 5: {
                obj_shape[no]->get_ord(1,m,n);
                circle *circ;
                circ = new circle(l,1,m,n);
                    cin>>*circ;
                obj_shape[no]=circ;
            break;
            }
            case 6: {
                obj_shape[no]->get_ord(2,m,n);
                line *ln;
                ln = new line(l,2,m,n);
                    cin>>*ln;
                obj_shape[no]=ln;
            break;
            }
            case 7: {
                cylinder *cdr;
                cdr = new cylinder(l,m,n);
                    cin>>*cdr;
                       obj_shape[no]=cdr;
                       break;
            }
            default: {
                cout<<"Enter again!"<<endl;
                switch_ob(obj_shape,no);
                }
        }
}

void flag(int no)
{
    if(shape::obSER[no]==1) triangle::tri--;
       else if(shape::obSER[no]==2) rect::rec--;
       else if(shape::obSER[no]==3) cube::cub--;
       else if(shape::obSER[no]==4) square::sq--;
       else if(shape::obSER[no]==5) circle::cir--;
       else if(shape::obSER[no]==6) line::lin--;
	   else if(shape::obSER[no]==7) cylinder::clndr--;
}

void edit(shape *obj_shape[])
{
    char ch;
    int no;
            while(1){
        cout<<"Edit shape no: ";
                cin>>no;
                if(no==shape::count) {
                    cout<<no<<" number shape has not been entered yet!"<<endl;
                    break;
                }
        cout<<obj_shape[no];
        cout<<"New shape? (y/n)"<<endl<<"Choice: ";
                cin>>ch;
            if(ch=='y')
            {
                flag(no);
                switch_ob(no,obj_shape);
            }
            else {
                    cout<<"Edit: "<<endl;
                switch_ob(obj_shape,no);

                }
        cout<<"Edit more?"<<endl<<"(y/n): ";
                cin>>ch;
            if(ch=='n') break;
        }
}

void show_one(shape *obj_shape[]) {
    int choice; char ch;
        while(1) {
            cout<<endl<<"1.Triangle 2.Rectangle 3.Cube 4.Square 5.Circle ";
            cout<<"6.Straight line 7.Cylinder"<<endl<<endl<<"Choice : ";
                cin>>choice;
        switch(choice)
        {
          case 1: {
                if(triangle::tri==1) cout<<"No triangular shape is available."<<endl;
                    for(int i=1;i<shape::count;i++) {
                if(shape::obSER[i]==1) cout<<obj_shape[i];
        } break;
        } case 2: {
                if(rect::rec==1) cout<<"No rectangular shape is available."<<endl;
                    for(int i=1;i<shape::count;i++) {
                if(shape::obSER[i]==2) cout<<obj_shape[i];
        } break;
        } case 3: {
                if(cube::cub==1) cout<<"No cube is available."<<endl;
                    for(int i=1;i<shape::count;i++) {
                if(shape::obSER[i]==3) cout<<obj_shape[i];
        } break;
        } case 4: {
                if(square::sq==1) cout<<"No square shape is available."<<endl;
                    for(int i=1;i<shape::count;i++) {
                if(shape::obSER[i]==4) cout<<obj_shape[i];
        } break;
        } case 5: {
                if(circle::cir==1) cout<<"No circular shape is available."<<endl;
                    for(int i=1;i<shape::count;i++) {
                if(shape::obSER[i]==5) cout<<obj_shape[i];
        } break;
        } case 6: {
                if(line::lin==1) cout<<"Shape is not available."<<endl;
                    for(int i=1;i<shape::count;i++) {
                if(shape::obSER[i]==7) cout<<obj_shape[i];
        } break;
        } case 7: {
                if(cylinder::clndr==1) cout<<"No cylindrical shape is available."<<endl;
                    for(int i=1;i<shape::count;i++) {
                if(shape::obSER[i]==7) cout<<obj_shape[i];
        } break;
        } default: {
                cout<<"Enter again!"<<endl;
                    show_one(obj_shape);
                   }
        } cout<<endl<<"Any other shape? (y/n) ";
          cin>>ch;
          if(ch=='n') break;
          }
}

void add(shape *obj_shape[])
{
    int no;
    char ch;
    while(1) {
            cout<<"How many shape: ";
                cin>>no;
            no+=shape::count;
                for(int j=shape::count;j<no;j++) {
                    switch_ob(j,obj_shape);
                    shape::count++;
           } cout<<"Add more? (y/n)"<<endl<<"Your choice :";
           cin>>ch;
                if(ch=='n') break;
        }
}

void deleteOB(shape *obj_shape[])
{
    int no;
    cout<<"Which shape?"<<endl<<"Object no. :";
        cin>>no;
            flag(no);
            shape::count--;
       for(int k=no;k<shape::count;k++) {
            shape::obSER[k]=shape::obSER[k+1];
            obj_shape[k]=obj_shape[k+1];
       }
}

int menu()
{
    int choice;
    cout<<endl<<"1.Add shapes?"<<endl<<"2.Add all areas?"<<endl<<"3.Add all volumes?"<<endl;
        cout<<"4.Show all shape details?"<<endl<<"5.Edit"<<endl;
        cout<<"6.Show individual shape details?"<<endl<<"7.Delete any shape?";
        cout<<endl<<"8.Exit"<<endl<<endl<<"Choice : ";
            cin>>choice;
            return choice;
}


int main()
{
    shape *obj_shape[MAX];
    int choice;
        do{
                choice=menu();
    double A=0,V=0;
    switch(choice) {
            case 1: {
                add(obj_shape);
                break;
          } case 2: {
                for(int i=1;i<shape::count;i++) A+=obj_shape[i]->get_area();
                    cout<<"Required addition : "<<A<<endl;
                break;
          } case 3: {
                for(int i=1;i<shape::count;i++) V+=obj_shape[i]->get_vol();
                    cout<<"Required addition : "<<V<<endl;
                break;
          } case 4: {
                if(shape::count==1) cout<<"No shape available."<<endl;
                    for(int i=1;i<shape::count;i++) {
                        cout<<endl<<"Shape : "<<i;
                        cout<<obj_shape[i];
          } break;
          } case 5: {
                edit(obj_shape);
                break;
          } case 6:  {
                show_one(obj_shape);
            break;
          } case 7: {
                deleteOB(obj_shape);
            break;
          }}}while(choice!=8);
    return 0;
}
