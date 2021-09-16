#include "atkui/framework.h"

using namespace glm;

class Particles : public atkui::Framework
{
 public:
  Particles() : atkui::Framework(atkui::Orthographic) {
  }





  virtual void setup() {
    //initializing the data
    numberOfParticles = 36;
    
  }





  virtual void scene() {
  }


  private:
  float center;
  float N;
  float numberOfParticles;
};

int main(int argc, char** argv) {
  Particles viewer;
  viewer.run();
  return 0;
}
