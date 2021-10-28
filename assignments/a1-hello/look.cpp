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

        setColor(vec3(1, 0, 1));
        vec3 target = vec3(_mouseX, _mouseY, 0);
        drawSphere(target, 5);

        setColor(vec3(1, 1, 1));
        double x = width() * 0.5;
        double y = height() * 0.5;
        double radius = 100;

        double s1X = x * 0.5;
        double s2X = x * 1.5;

        /*draw the white spheres*/
        drawSphere(vec3(s1X, y, -1000), radius); //right sphere
        drawSphere(vec3(s2X, y, -1000), radius); //left sphere

        //rotation computations for left and right eyes
        float angle1 = atan2(_mouseY, _mouseX);
        float angle2 = atan2(_mouseY, _mouseX);

        setColor(vec3(0, 1, 0));
        vec3 spherepos = vec3(s1X * cos(angle1), s1X * sin(angle1) + y, 0);

        vec3 spherepos2 = vec3(s2X * cos(angle2), s2X * sin(angle2) + y, 0);

        vec3 final = vec3(spherepos.x + s1X, spherepos.y, 0);
        vec3 final2 = vec3(spherepos2.x + s2X, spherepos2.y / height() * 0.5, 0);

        drawSphere(final, 10);
        drawSphere(final2, 10);
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
