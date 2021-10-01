#include <iostream>
 #include "atkui/framework.h"
 using namespace glm;

//a struct to hold the cube
struct Cube{
  vec3 cubePosition;
  vec3 cubeColor;
  int cubeSize;
};

template <typename Cube> 
class Bezier{
  public:
  Cube P1;
  Cube C1;
  Cube P2;
  Cube C2;

};



 class Gradient : public atkui::Framework {
  public:
   Gradient() : atkui::Framework(atkui::Orthographic) {
   }

        


    

   


   virtual void setup(){
     x = width();
     y = height();

     N = 50;

     rows = y/N+1;
     cols = x/N+1;

     //initialize the values for the cube on the screen and the colors on each of the corners
     colorNE = vec3(1,1,0);
     colorNW = vec3(0,1,1);
     colorSE = vec3(1,0,0);
     colorSW = vec3(1,0,1);


   }

   virtual void scene() {


     for(int i=0;i<rows;i++){
      int posY=(i)*N;
      for(int j=0;j<cols;j++){
        //first round interpolation
        float tX=((float)(j*N)/(float)x);
        vec3 Cx0= colorNW*(1-tX)+colorNE*tX;
        vec3 Cx1=colorSW*(1-tX)+colorSE*tX;
        //second round interpolation
       
        float tY=((float)(i*N)/(float)y);
        
        vec3 C=Cx1*(1-tY)+Cx0*tY;
        
        
        setColor(C);
        drawCube(vec3(j*N, posY, 0),vec3(N, N, 0) );
        //drawSphere(vec3(j*N, posY, 0), 4);

      }
     }



   }

   int N, x, y;

   int rows;
   int cols;


   //nitialize the variables for the colors
   vec3 colorNW;
   vec3 colorNE;
   vec3 colorSW;
   vec3 colorSE;



 };

 int main(int argc, char **argv) {
   Gradient viewer;
   viewer.run();
 }