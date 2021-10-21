#include "atkui/framework.h"
#include <GLFW/glfw3.h>

using namespace glm;


class Unique : public atkui::Framework
{
  public:
    Unique() : atkui::Framework(atkui::Orthographic) {
    }
    virtual void setup() {
      theta = 0.0;
      thetaRate= 0.5;
      radius = 40;      
    }
    virtual void scene() {
    theta = thetaRate*elapsedTime();
 

    for (double i = 0.5; i<10.0; i++){
    
    setColor(vec3(0,1,0)*elapsedTime());
   float cubePositionX = width()*0.5;
   float cubePositionY = height()*0.5+ 100.0f*sin(theta);
   float cubePositionY2 = height()*0.5+ 200.0f*sin(theta);

    drawCube(vec3(cubePositionX,cubePositionY,0) ,vec3(40,100,0));
    drawCube(vec3(cubePositionX*0.7,cubePositionY2,0) ,vec3(40,100,0));

    }
    
    }

private:
float thetaRate;
float radius;
float theta;
};

int main(int argc, char** argv) {
 Unique viewer;
  viewer.run();
  return 0;
}
