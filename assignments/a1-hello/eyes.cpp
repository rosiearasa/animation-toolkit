#include "atkui/framework.h"

using namespace glm;

class Eyes : public atkui::Framework
{
  public:
    Eyes() : atkui::Framework(atkui::Orthographic) {
    }
    virtual void setup() {
        theta = 0.0;
        thetaRate = 0.7;
        
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

    smallSphere(s1X ,radius/3);
    smallSphere(s2X ,radius/3);



    }

    virtual void smallSphere(double center, double startPos) {
     theta = thetaRate * elapsedTime();

    setColor(vec3(0,0,0));
    double x = startPos * cos(theta) + center;
    double y = height() * 0.5;
    double radius = 30;
    drawSphere(vec3(x,y,0), radius);

    }

private:
    float theta;
    float thetaRate;

};

int main(int argc, char** argv) {
  Eyes viewer;
  viewer.run();
  return 0;
}
