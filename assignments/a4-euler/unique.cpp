#include "atkui/framework.h"
#include "atkmath/quaternion.h"
#include "atkmath/vector3.h"
#include "atkmath/matrix3.h"

using atkmath::Matrix3;
using atkmath::Vector3;
using glm::vec3;

using namespace glm;

class Unique : public atkui::Framework
{
public:
  Unique() : atkui::Framework(atkui::Orthographic)
  {
  }

  virtual void setup()
  {
    theta = 0.0;
    thetaRate = 0.05;
    radius = 40;
  }
  virtual void scene()
  {

    for (double i = 1.0; i < 10.0; i++)
    {
      theta += thetaRate;

      sphereX = width() * 0.75;
      sphereY = height() * 0.75;
      for (double j = 0.0; j < 10.0; j++)
      {
        theta += dt();
        translate(vec3(sphereX, sphereY, 0));
        rotate(acos(0.0), vec3(0, 0, 1));
        rotate(theta * 0.00005, vec3(0, 0, 1));
        setColor(vec3(0, 1, 0));
        drawSphere(vec3(sphereX / width(), sphereY * height(), 0), 30);
        drawLine(vec3(sphereX / width(), sphereY * height(), 0), vec3(0, 1, 1));
        setColor(vec3(1, 1, 0));
        drawLine(vec3(sphereX, sphereY, 0), vec3(0, 1, 0));
        drawSphere(vec3(sphereX, sphereY, 0), 30);
      }
    }
  }

private:
  float thetaRate;
  float radius;
  float theta;
  float sphereX;
  float sphereY;
};

int main(int argc, char **argv)
{
  Unique viewer;
  viewer.run();
  return 0;
}
