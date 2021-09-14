#include "atkui/framework.h"

using namespace glm;
class Eyes : public atkui::Framework
{
  public:
    Eyes() : atkui::Framework(atkui::Orthographic) {
    }
    virtual void setup(){
      theta = 0.0;
      thetaRate = 0.9;
      sR = 50;

    }

    virtual void scene() {
      //draw two circles  the center
      setColor (vec3(1,1,1));
  
      double radius = 100;

      double x = width()*0.75;
      double y= height()/2.0;
      drawSphere(vec3(x,y,0), radius);

      double x1 = width()*0.25;
      double y1= height()/2.0;
      drawSphere(vec3(x1,y1,0), radius);


      setColor(vec3(1,0,0));
      smallSphere();
    

    }
    virtual void smallSphere(){
      theta+= thetaRate *dt();
      float px = 5.0+sR*cos(theta)+ 0.5* width();
      float py =  sR + 0.5 *height();
      drawSphere(vec3(px,py,-1000), 80);

    }
private:
float theta;
float thetaRate;
float sR;
    
};

int main(int argc, char** argv) {
  Eyes viewer;
  viewer.run();
  return 0;
}
