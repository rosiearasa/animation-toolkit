#include "atkui/framework.h"

using namespace glm;

class Unique : public atkui::Framework
{
  public:
    Unique() : atkui::Framework(atkui::Orthographic) {
    }
    virtual void setup() {
      
        
    }
    virtual void scene() {



    }



private:



};

int main(int argc, char** argv) {
 Unique viewer;
  viewer.run();
  return 0;
}
