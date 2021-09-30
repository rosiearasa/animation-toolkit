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

  vec3 lerp(const vec3 &s, const vec3 &e, float t){
    return vec3(
      s.x +(e.x-s.x)* t,

      s.y+ (e.y -s.y) * t,

      s.z +(e.z-s.z) *t 

    );
  }
   Cube interpolate(Bezier <Cube> &curve,float t ){
        


    }

   


   virtual void setup(){
     //initialize the values for the cube on the screen and the colors on each of the corners


     colorNE = vec3(1,1,0);
     colorNW = vec3(0,1,1);
     colorSE = vec3(1,0,0);
     colorSW = vec3(1,0,1);


   }

   virtual void scene() {

    


   }

   //initialize cube
   Cube theCube;

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