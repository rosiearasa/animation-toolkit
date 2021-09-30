#include "atkui/framework.h"
#include "math.h"


using namespace glm;
using namespace std;
#define PI 3.14159265

class Look : public atkui::Framework
{


public:
    Look() : atkui::Framework(atkui::Orthographic) {
    }
    virtual void setup() {

        //gett the postion of the mouse in terms of x and y
    
    
      

    }
    virtual void scene() {
    double  _mouseX = width() * 0.5;
       double _mouseY = height() * 0.5;

        setColor(vec3(1, 1, 1));
        double x = width() * 0.5;
        double y = height() * 0.5;
        double radius = 100;

        double s1X = x * 0.7;
        double s2X = x * 1.5;

        //drawSphere(vec3(s1X, y, -1000), radius);//right sphere
        //drawSphere(vec3(s2X, y, -1000), radius);//left sphere

        

        vec3 target = vec3(_mouseX, _mouseY, 0);


        cout << target<< endl;
        double xpop =target[0];
        double ypop = target[1];





        //draw small sphere right eye
        //get the center of the large sphere
        double centerLeft = s1X ;
        double centerRight = s2X;
       

        //update the scene with the target

   


         setColor(vec3(0, 0, 0));
        


        //update the position of the left eye relative to the target
       // setColor(vec3(0, 0, 1));
        double centerLefts = updateSmall(xpop,ypop);
        double centerRights = updateSmall(xpop, ypop);

        //update the position of the right eye relative to the target
   


         
        float px =(cos(centerLeft)+ s1X+target[0]);
        float py = (sin(centerLeft)+s1X+target[1]);

        float px1 = (cos(centerRight) + s2X + target[0]);
        float py1 = (sin(centerRight) + s2X + target[1]);

       // drawSphere(vec3(px, py, 0), 10);
        //drawSphere(vec3(px1, py1, 0), 10);








        //setColor(vec3(1, 0, 0));
        //drawSphere(target, 5);

    }

   double updateSmall(double xproportion, double yproportion) {
       return  atan2(xproportion, yproportion)* 180 / PI;
       

    }
    virtual void mouseMotion(int x, int y, int dx, int dy) {
       double  _mouseX = x;
       double  _mouseY = height() - y;
    }





  


};

int main(int argc, char** argv) {
    Look viewer;
    viewer.run();
    return 0;
}



