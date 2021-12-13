#include "atkui/framework.h"
#include "math.h"

using namespace glm;
using namespace std;
#define PI 3.14159265

class Look : public atkui::Framework
{

public:
    Look() : atkui::Framework(atkui::Orthographic)
    {
    }
    virtual void setup()
    {
    }
    virtual void scene()
    {
        if (mouseIsDown(GLFW_MOUSE_BUTTON_LEFT))
        {
            mouseMotion(mousePosition().x, mousePosition().y);
        }

       
    }
   virtual void drawWhites()
    {
     
        setColor(vec3(1, 1, 1));
        double x = width() * 0.5;
        double y = height() * 0.5;
        double radius = 100;

        double s1X = x * 0.5;
        double s2X = x * 1.5;

        /*draw the white spheres*/
        drawSphere(vec3(s1X, y, -1000), radius); //right sphere
        drawSphere(vec3(s2X, y, -1000), radius); //left sphere

    }

    virtual void mouseMotion(int x, int y)
    {
        _mouseX = x;
        _mouseY = height() - y;
    }

private:
    int _mouseX;
    int _mouseY;
};

int main(int argc, char **argv)
{
    Look viewer;
    viewer.run();
    return 0;
}
