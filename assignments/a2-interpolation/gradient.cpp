#include <iostream>
#include "atkui/framework.h"
using namespace glm;




class Gradient : public atkui::Framework {
 public:
  Gradient() : atkui::Framework(atkui::Orthographic) {
  }

  virtual void setup() {
	  gridX = 10;
	  gridY = 10;
	
  }

  virtual void scene() {
	  unit(gridX, gridY);
	
  }


  
  void unit(int x, int y) {
	  
	  //se the color
	  glLineWidth(1.0);
	  glColor3f(1.0, 1.0, 1.0);

	  glBegin(GL_LINE_LOOP);
	  glVertex2f(x, y);
	  glVertex2f(x + 1, y);
	  glVertex2f(x + 1, y + 1);
	  glVertex2f(x, y + 1);
	  glBegin(GL_LINE_LOOP);
	  glEnd();
  }

  int gridX, gridY;


};

int main(int argc, char **argv) {
  Gradient viewer;
  viewer.run();
}
