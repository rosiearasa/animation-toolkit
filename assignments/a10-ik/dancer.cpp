#include "atk/toolkit.h"
#include "atkui/framework.h"
#include "cyclops.h"
#include "ik_controller.h"
#include <algorithm>
#include <string>

using namespace atk;
using namespace glm;
using namespace std;

class ADancer : public atkui::Framework
{
public:
   ADancer() : atkui::Framework(atkui::Perspective) {}
   virtual ~ADancer() {}

   void setup()
   {
      BVHReader reader;
      reader.load("../motions/Beta/idle.bvh", _skeleton, _motion);
      _drawer.color = vec3(1,0,0);
      _lhandOriginal = _skeleton.getByName("Beta:LeftHand")->getGlobalTranslation() + vec3(0, 50, 15);
      _lhandTarget = _lhandOriginal;
      _rhandOriginal = _skeleton.getByName("Beta:RightHand")->getGlobalTranslation() + vec3(0, 50, 15);
      _rhandTarget = _rhandOriginal;
      _leftHandId = _skeleton.getByName("Beta:LeftHand")->getID();
      _rightHandId = _skeleton.getByName("Beta:RightHand")->getID();

      _hipId = _skeleton.getByName("Beta:Hips")->getID();
      oldHip.setT(_motion.getKey(0).rootPos);
      oldHip.setR(_motion.getKey(0).jointRots[0]);

      _leftFootId = _skeleton.getByName("Beta:LeftFoot")->getID();
      _leftFootTarget = _skeleton.getByName("Beta:LeftFoot")->getGlobalTranslation();

      _rightFootId = _skeleton.getByName("Beta:RightFoot")->getID();
      _rightFootTarget = _skeleton.getByName("Beta:RightFoot")->getGlobalTranslation();

      _lfootRotation = _skeleton.getByName("Beta:LeftFoot")->getGlobalRotation();
      _rfootRotation = _skeleton.getByName("Beta:RightFoot")->getGlobalRotation();

   }

   void update()
   {
      _motion.update(_skeleton, elapsedTime());

      IKController ik;
      Transform moveHip = Transform::Translate(vec3(
                                                5.0f * sin(speed * elapsedTime()),
                                                3.0f * cos(5.0 * elapsedTime()), 
                                                0
                                                ));

      // std::cout << "loc " <<  sin(fmod(elapsedTime() * speed, float(2 * M_PI))) << std::endl;
      // std::cout << "angle " << fmod(elapsedTime() * speed, float(2 * M_PI)) << std::endl;
      Transform newHip = moveHip * oldHip;
      _skeleton.getByID(_hipId)->setLocal2Parent(newHip);

      _skeleton.fk();

      // std::cout << "sin " << sin(elapsedTime()) << std::endl;
   
      ik.solveIKCCD();
      ik.solveIKCCD();
      bool solved = ik.solveIKCCD();

      bool solved2 = ik.solveIKCCD();
    

      _skeleton.getByID(_leftFootId)->setLocalRotation(_skeleton.getByName("Beta:LeftFoot")->getLocalRotation() * inverse(_skeleton.getByName("Beta:LeftFoot")->getGlobalRotation()) * _lfootRotation);
      _skeleton.getByID(_rightFootId)->setLocalRotation(_skeleton.getByName("Beta:RightFoot")->getLocalRotation() * inverse(_skeleton.getByName("Beta:RightFoot")->getGlobalRotation()) * _rfootRotation);
     
      
      //animate hand targets

      //position hands to follow target

      //animate the positions of the hips

      //pin feet to original position using IKController

      //reset the rotation of the feet to theur original global rotation

   }

   void scene()
   {  
      update();
      _drawer.draw(_skeleton, *this);
      setColor(vec3(0,0,1));
      drawSphere(_lhandTarget, 10);
      drawSphere(_rhandTarget, 10);
   }

protected:
   Cyclops _drawer;
   Skeleton _skeleton;
   Motion _motion;

    // Hand target positions
   vec3 _lhandTarget;
   vec3 _lhandOriginal;
   vec3 _rhandTarget;
   vec3 _rhandOriginal;
   float handRange = 0.8f;
   int _leftHandId;
   int _rightHandId;

   int _hipId;
   Transform oldHip;

   int _leftFootId;
   vec3 _leftFootTarget;
   quat _lfootRotation;
   int _rightFootId;
   vec3 _rightFootTarget;
   quat _rfootRotation;
float speed = 2.0;


   float epsilon = 0.0001f;
};

int main(int argc, char** argv)
{
   ADancer viewer;
   viewer.run();
   return 0;
}

