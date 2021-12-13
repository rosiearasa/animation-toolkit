#include "ik_controller.h"
#include <cmath>
#include <iostream>

using namespace atk;
using namespace glm;
using namespace std;

bool IKController::solveIKAnalytic(Skeleton& skeleton, 
    int jointid, const vec3& goalPos, float epsilon) {
  if (jointid == -1) return true;

  Joint* ankle = skeleton.getByID(jointid);
  if (!ankle->getParent()) {
    std::cout << "Warning: solveIKAnalytic() needs joint "
      "with parent and grandparent\n";
    return false;
  }

  Joint* knee = ankle->getParent();
  if (!knee->getParent()) {
    std::cout << "Warning: solveIKAnalytic() needs joint "
      "with parent and grandparent\n";
    return false;
  }

  Joint* hip = knee->getParent();

  // TODO: Your code here
  return true;
}

bool IKController::solveIKCCD(Skeleton& skeleton, int jointid, 
    const vec3& goalPos, const std::vector<Joint*>& chain, 
    float threshold, int maxIters, float nudgeFactor) {
  // There are no joints in the IK chain for manipulation
  if (chain.size() == 0) return true;

  //p, end effector pos in global
  Joint * endEffector = skeleton.getByID(jointid);
  vec3  globalEnd = endEffector->getGlobalTranslation();
  int i = 0;
  while (length(endEffector->getGlobalTranslation()-goalPos) >threshold &&  i <maxIters)
  {
    //for each joint
   for (int joint1=0; joint1<chain.size(); joint1++){
     Joint* currentJoint = chain.at(joint1);
     Joint* currentJointParent = currentJoint->getParent();
     //nudge
     //starting from the end effector
     vec3 r = endEffector->getGlobalTranslation();

     vec3 e = goalPos -endEffector->getGlobalTranslation();

     vec3 crossRE = cross(r,e);
     vec3 axis;

     if (length(crossRE)< 0.00001){
       continue;
     }
     axis = normalize(crossRE);
     float theta = nudgeFactor *atan2(length(crossRE), dot(r,r)+dot(r,e));
      
      
      
      vec3 localAxis = (currentJointParent != skeleton.getRoot()) ? currentJointParent->getLocal2Global().inverse().transformVector(axis) : axis;
 

      quat rot = angleAxis(theta, localAxis);
    

      currentJoint->setLocalRotation(rot * currentJoint->getLocalRotation());
      skeleton.fk();

    }
    i++;



   
  }
  
  return false;
}
