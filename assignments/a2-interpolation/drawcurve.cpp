#include <iostream>
#include <math.h>
#include "atkui/framework.h"
using namespace glm;

class Curve
{
public:
  vec3 P1;
  vec3 P2;
};

class DrawCubic : public atkui::Framework
{
public:
  DrawCubic() : atkui::Framework(atkui::Orthographic, 400, 400)
  {
  }

  virtual void scene()
  {
    setColor(vec3(0, 0, 1));
    drawSphere(B0, 10);
    drawSphere(B3, 10);

    setColor(vec3(1, 1, 0));
    drawSphere(B1, 10);
    drawSphere(B2, 10);

    if (keypressed == 1)
    {
      // draw Bernstein
      //  𝑝(𝑡)=(1−𝑡)3𝑏0+3𝑡(1−𝑡)2𝑏1+3𝑡2(1−𝑡)𝑏2+𝑡3𝑏3
      for (float t = 0.0; t <= 1.0; t += 0.01)
      {
        points = (float)(pow((1 - t), 3)) * B0 + (float)(3.0 * t * pow((1 - t), 2)) * B1 + (float)(3.0 * pow(t, 2) * (1 - t)) * B2 + (float)(pow(t, 3)) * B3;
        setColor(vec3(1, 1, 0));
        drawLine(BX, points);
        BX = points;
      }
    }


    if (keypressed == 2){



      
    }
    BX = B0;
  }

  void keyUp(int key, int mod)
  {
    if (key == GLFW_KEY_1)
    {
      keypressed = 1;
    }

    else if (key == GLFW_KEY_2)
    {
      keypressed = 2;


    }
  }
  //control points
private:
  vec3 BX;
  vec3 points;
  vec3 B0 = vec3(100, 50, 0);
  vec3 B1 = vec3(150, 200, 0);
  vec3 B2 = vec3(250, 100, 0);
  vec3 B3 = vec3(300, 300, 0);
  float keypressed = 0;
};

int main(int argc, char **argv)
{
  DrawCubic viewer;
  viewer.run();
}