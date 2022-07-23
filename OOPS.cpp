#include<bits/stdc++.h>
using namespace std;


/*he keywords public, private, and protected are called 
access specifiers .A class can have multiple public, protected, or private labeled sections. Each 
section remains in effect until either another section label or the closing right 
brace of the class body is seen. */


class Box{
    public:// can be private or protected 
    int x,y,z;
    // one way of function declaration 
    //inline definition of the function
    int getvol()
    {
        return x*y*z;
    }
    
    //declared function to be called outide using scope operator 
    int getvol1();
    void  setx(int x);
};

//:: scope operator
int Box :: getvol1(){
    return x*y*z;
};
//setting function 
void Box:: setx(int x){
    this->x = x;
    // this points to this object **
}

void classintro(){
    int a,b,c;
    cin >> a >> b >> c;
    Box B1;//called an object
    B1.setx(a);
    B1.y = b;
    B1.z = c;
    cout << B1.getvol();
}

/*
A PRIVATE function can not be accesses or viewed from outside 
the class they can be viewed using the class and friend fucntion
By default the class access is private 
*/

class Box1{
    int x;
    int y;
    int z;
    public:
    int getvol(){return x*y*z;}
    void set(int x,int y,int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

void privatedep(){
    int a,b,c;
    cin >> a >> b >> c;
    Box1 b1;
    // below will give compilation error
    // b1.x = a;
    // b1.y = b;
    // b1.z = c;
    b1.set(a,b,c);
    cout << b1.getvol();
    //now workkning 
}

///////////////////////////////////DERIVED CLASSED/////////////////

/*
The class which is subpart of the main class is called the
derived class . Note that the protected member can be accessd 
using the derived classes.
*/

class Box2{
    protected:
    int x;
    int y;
    int z;
    public:
    int getvol(){return x*y*z;}
   
};



//derived class
class derivedclass: Box{
    public:
    void set(int x,int y,int z);
    int getvol(){return x*y*z;}
};
void derivedclass:: set(int x,int y,int z){
     this->x = x;
     this->y = y;
     this->z = z;
};



void protecteddep(){
    int a,b,c;
    cin >> a >> b >> c;
    derivedclass b1;
    // below will give compilation error
    // b1.x = a;
    // b1.y = b;
    // b1.z = c;
    b1.set(a,b,c);
    cout << b1.getvol()  << endl;

}

/////////////////////////////////////CONSTURCTORS

// Inbuilt function which is called whenver we create an object of a class
// can be parameterised or not 

class Box3{
    public:
    int x,y,z;
    //constructor
    Box3(int a,int b,int z);
    ~Box3();//destructor
};

//constructor outside the class 
// could be inline too 
 Box3 :: Box3(int a, int b, int c){
    cout << "Object created";
    x = a;
    y = b;
    z = c;
}
//destuctor
// A destructor is a special member function of a class that is executed whenever 
// an object of it's class goes out of scope or whenever the delete expression is 
// applied to a pointer to the object of that class.
 Box3 :: ~ Box3(){
    cout << "Object deleted";
    
}
void constdep(){
    int a,b,c;
    cin >> a >> b >> c;
    Box3 b1(a,b,c);
    cout << b1.x << endl;
}
int main(){
    // classintro();
    // privatedep();
    // protecteddep();
    constdep();
}