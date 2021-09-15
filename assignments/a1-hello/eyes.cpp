#include "atkui/framework.h"

using namespace glm;
class Eyes : public atkui::Framework
{
  public:
    Eyes() : atkui::Framework(atkui::Orthographic) {
    }
  
    virtual void scene() {

    setColor(vec3(1,1,1));
    double x = width() * 0.5;
    double y = height() * 0.5;
    double radius = 100; 
    double s1X =x *0.7;
    double s2X = x * 1.5;
    drawSphere(vec3(s1X,y,-1000), radius);
    drawSphere(vec3(s2X,y,-1000), radius);

    smallSphere(s1X ,radius);
    smallSphere(s2X ,radius);



    }
      
    virtual void smallSphere(float center, float startPos) {

    setColor(vec3(0,0,1));
    double x = width() * 0.5 *sin(elapsedTime())+center;
    double y = height() * 0.5;
    double radius = 30; 

    drawSphere(vec3(x,y,0), radius);



    }
  
    
};

int main(int argc, char** argv) {
  Eyes viewer;
  viewer.run();
  return 0;
}
