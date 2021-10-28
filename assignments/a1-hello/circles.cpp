#include "atkui/framework.h"
#include <vector>

using namespace glm;
using namespace std;

struct Particle
{
   vec3 position;
   vec3 color;
   vec3 velocity;
};

class Circles : public atkui::Framework
{

public:
   Circles() : atkui::Framework(atkui::Orthographic)
   {
   }

   virtual void setup()
   {
      radius = 10;
      xPos = width() * 0.5;
      yPos = height() * 0.5;
      thetha = 0.0;
      thetaRate = 0.2;
   }

   virtual void scene()
   {
      vector<Particle> particles;

      //random colors
      vector<vec3> pallet = {
          vec3(0, 165, 227) / 255.0f,
          vec3(141, 215, 191) / 255.0f,
          vec3(255, 150, 197) / 255.0f,
          vec3(255, 87, 104) / 255.0f,
          vec3(255, 162, 58) / 255.0f,

      };

      N = 10;
          thetha +=elapsedTime();
    
       for (int i = 0; i<=100; i++){
         xPos = cos(thetha) + width() * 0.5;
         yPos = sin(thetha) + height() * 0.5;
         setColor(vec3(1, 0, 1));

         drawSphere(vec3(xPos, yPos, 0), N);
         drawSphere(vec3(xPos+10, yPos+10, 0), N);
      
       }
        

      //update the x and y positions
   }

private:
   float xPos, yPos;
   float thetha;
   int radius;
   float thetaRate;

   int N; //number of circles
};

int main(int argc, char **argv)
{
   Circles viewer;
   viewer.run();
   return 0;
}