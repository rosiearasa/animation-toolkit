#include "atkui/framework.h"


using namespace glm;

class Look : public atkui::Framework {
 public:
  Look() : atkui::Framework(atkui::Orthographic) {
  }

  virtual void setup() {
    _mouseX = width() * 0.5;
    _mouseY = height() * 0.5;
  }

  virtual void scene() {
    vec3 target = vec3(_mouseX, _mouseY, 0);
    setColor(vec3(1,0,0));
    drawSphere(target, 15);
   
   

  }

 virtual void mouseDown(int button, int action){

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
    //move the circle
    }
  }

 virtual void mouseMove(int x, int y) {
    _mouseX = x;
    _mouseY = height() - y;
  }

 private:
  int _mouseX;
  int _mouseY;


  float theta;
  float thetaRate;

};

int main(int argc, char** argv) {
  
  Look viewer;
  viewer.run();
  return 0;
}
