#include <iostream>
#include "atkui/framework.h"
#include "atk/toolkit.h"

using namespace glm;
using namespace atk;

class Butterfly : public atkui::Framework
{
public:
   Butterfly() : atkui::Framework(atkui::Perspective) {
   }

   void setup() {
    



      Joint* body = new Joint("Body");
      body->setLocalTranslation(vec3(1,2,1)*100.0f);
      body->setLocalRotation(glm::angleAxis(glm::radians<float>(45.0f), vec3(0,1,0)));
      skeleton.addJoint(body);

      //The head
      Joint *head = new Joint ("head");
      head->setLocalTranslation(vec3(0,0,0)*100.0f);
      head->setLocalRotation(glm::angleAxis(glm::radians<float>(90.0f), vec3 (0,0,1)));
      skeleton.addJoint(body, head);


      Joint* lwing = new Joint("LWing");
      lwing->setLocalTranslation(vec3(0.1,0,0)*100.0f);
      skeleton.addJoint(lwing, body);

      Joint* llwing = new Joint("llwing");
      llwing->setLocalTranslation(vec3(0, 0.1,0)*50.0f);
      skeleton.addJoint(llwing, lwing);


      Joint* rwing = new Joint("RWing");
      rwing->setLocalTranslation(vec3(-0.1,0,0)*100.0f);
      skeleton.addJoint(rwing, body);

      skeleton.fk();
   }

   void scene() {
      Joint *hhead = skeleton.getByName("head");
      Joint* body = skeleton.getByName("Body");
      Joint* lwing = skeleton.getByName("LWing");
      
      Joint* llwing = skeleton.getByName("llwing");
      llwing->setLocalRotation(glm::angleAxis(sin(elapsedTime()), vec3(0,0,1)));
      llwing->setLocalRotation(glm::angleAxis(sin(elapsedTime()), vec3(0,0,1)));
 
      Joint *head = skeleton.getByName("head");



      Joint* rwing = skeleton.getByName("RWing");
      rwing->setLocalRotation(glm::angleAxis(-sin(elapsedTime()), vec3(0,0,1))); 
      skeleton.fk();
  for (int i = 0; i<skeleton.getNumJoints(); i++){
      Joint *joint = skeleton.getByID(i);
      if (joint->getParent() == 0)
        continue;

      vec3 p1 = joint->getGlobalTranslation();
      vec3 p2 = joint->getParent()->getGlobalTranslation();
      drawEllipsoid(p1, p2, 5);
      }

      // attach geometry to skeleton 
      Transform B = body->getLocal2Global(); 
      Transform LT = lwing->getLocal2Global(); 
      Transform LLT = llwing->getLocal2Global(); 
      Transform RT = rwing->getLocal2Global(); 

      // draw body
      Transform bodyGeometry(
         glm::angleAxis(glm::pi<float>()*0.5f, vec3(1,0,0)), // rotation
         vec3(0), vec3(25, 200, 25)); // position, scale

      Transform headGeometry(
         glm::angleAxis(glm::pi<float>()*0.5f, vec3(0,1,0)),
         vec3(0), vec3(25, 200, 25)); // position, scale

      

      Transform lwingGeometry(
         eulerAngleRO(XYZ, vec3(0,0,0)),
         vec3(-80,0,0), 
         vec3(120,20,200)
         );

      Transform rwingGeometry(
         eulerAngleRO(XYZ, vec3(0,0,0)),
         vec3(80,0,0), 
         vec3(120,20,200));

      Transform llwingGeometry(
         eulerAngleRO(XYZ, vec3(0,0,0)),
         vec3(-80,0,0),
         vec3(100,20,100)
      );

      setColor(vec3(0.4, 0.4, 0.8));
      push();
      transform(B * bodyGeometry);
      drawSphere(vec3(0), 1);
      pop();

      setColor(vec3(0.8, 0, 0.0));
      push();
      transform(LT * lwingGeometry);
      drawSphere(vec3(0), 1);
      pop();
      
      // setColor(vec3(0.3,0,0.0));
      // push();
      // transform(LLT* lwingGeometry);
      // drawSphere(vec3(0),1);
      // pop();


      setColor(vec3(0, 0.8, 0.0));
      push();
      transform(RT * rwingGeometry);
      drawSphere(vec3(0), 1);
      pop();

   }

private:
   Skeleton skeleton;
};


int main(int argc, char** argv) {
   Butterfly viewer;
   viewer.run();
}
