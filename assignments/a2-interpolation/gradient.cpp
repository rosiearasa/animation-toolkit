#include <iostream>
#include "atkui/framework.h"
using namespace glm;

class Gradient : public atkui::Framework
{
public:
  Gradient() : atkui::Framework(atkui::Orthographic)
  {
  }

  virtual void setup()
  {

    N = 20;

    //initialize the values for the cube on the screen and the colors on each of the corners
    colorNW = vec3(1, 1, 0);
    colorNE = vec3(0, 1, 1);
    colorSW = vec3(1, 0, 0);
    colorSE = vec3(1, 0, 1);

    px = 0;
    py = 0;
  }

  virtual void scene()
  {
    for (int j = 0; j < height() / N + 1; j++)
    {
      py = j * N;
      for (int i = 0; i < width() / N + 1; i++)
      {
        px = i * N;
        float tx = px / width();
        c0x = colorNW * (1 - tx) + colorNE * tx;
        c1x = colorSW * (1 - tx) + colorSE * tx;

        float ty = py / height();

        c = c0x * (1 - ty) + c1x * ty;
        setColor(c);
        drawCube(vec3(px, py, 0), vec3(N, N, 0));
      }
    }
  }

private:
  int N;
  float px;
  float py;
  vec3 c0x;
  vec3 c1x;
  vec3 c;

  //initialize the variables for the colors
  vec3 colorNW;
  vec3 colorNE;
  vec3 colorSW;
  vec3 colorSE;
};

int main(int argc, char **argv)
{
  Gradient viewer;
  viewer.run();
}