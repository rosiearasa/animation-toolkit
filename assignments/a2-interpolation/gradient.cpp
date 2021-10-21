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

     rows = y/N;
     cols = x/N;

     //initialize the values for the cube on the screen and the colors on each of the corners
     colorNE = vec3(1,1,0);
     colorNW = vec3(0,1,1);
     colorSE = vec3(1,0,0);
     colorSW = vec3(1,0,1);

   }

   virtual void scene() {
     for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){  
        //setColor();
        //drawCube();
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