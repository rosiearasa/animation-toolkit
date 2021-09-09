#include "atkui/framework.h"
#include <random>

using glm::vec3;
vec3 currentPosition;
vec3 vel;

class Sphere3D : public atkui::Framework {
 public:
  Sphere3D() : atkui::Framework(atkui::Perspective) {
  }

void scene() {
    
    // colors are RGB triplets in range [0,1]
    setColor(vec3(0,1,0));

    // draw a sphere at center of the world
    float radius = 50.0;
    drawSphere(currentPosition, radius);
  
  }
  
  //update
 void update(){
  vel = vec3(agl::randomUnitVector())* 100.0f;
  currentPosition = currentPosition + vel * dt();
  }


void keyUp(int key, int mods){
  if ( key == GLFW_KEY_K){
    //reset position of object to (0,0,0)
    currentPosition = vec3(0,0,0);
    }
    if (key == GLFW_KEY_SPACE){
      update();
    }
  
 }

};

int main(int argc, char** argv)
{
  Sphere3D viewer;
  
  viewer.run();//this runs the game loop
  return 0;
}
