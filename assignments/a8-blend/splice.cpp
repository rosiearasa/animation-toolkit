#include "atk/toolkit.h"
#include "atkui/framework.h"
#include "atkui/skeleton_drawer.h"
#include <algorithm>
#include <string>

using namespace atk;
using namespace atkui;
using namespace glm;

class ASplice : public atkui::Framework
{
public:
   ASplice() : atkui::Framework(atkui::Perspective) {}
   virtual ~ASplice() {}

   void setup()
   {
      _alpha = 0;

      BVHReader reader;
      reader.load("../motions/Beta/walking.bvh", _skeleton, _lower);
      reader.load("../motions/Beta/gangnam_style.bvh", _skeleton, _upper);
      _splice = spliceUpperBody(_lower, _upper, _alpha);
   }

   Motion spliceUpperBody(const Motion& lower, const Motion& upper, float alpha)
   {
     

      Motion result=lower;
      result.setFramerate(lower.getFramerate());
   for (int i =0; i<result.getNumKeys(); i++){
      Pose pose  = result.getKey(i);
      
      Pose upperbody = upper.getKey(i);

      //Use glm::slerp to blend local rotations for the upper body
     // for (int j = 0; j< _skeleton.getNumJoints(); j++){

      //  if (isUpperBody(_skeleton.getByID(j)== true)
      // {
      //      Joint * jointsUpper = _skeleton.getByID(j);
        
      // }

      // }

      //compute new pose
      result.editKey(i, pose);
  }

      return result;
   }
bool isUpperBody(Joint *joint){

  for (Joint *currentJoint = joint; currentJoint!=NULL; currentJoint=currentJoint->getParent()){
     if(currentJoint->getName()=="Beta:Spine1"){
      return true;
   }
  }
  
      return false;
   
  
}
   void scene()
   {  
      _splice.update(_skeleton, elapsedTime() * 0.5);
      SkeletonDrawer drawer;
      drawer.draw(_skeleton, *this);
      drawText("alpha: "+std::to_string(_alpha), 10, 15);
   }

   void keyUp(int key, int mods) 
   {
      if (key == GLFW_KEY_UP)
      {
         _alpha = std::min(_alpha+0.05, 1.0);
         _splice = spliceUpperBody(_lower, _upper, _alpha);
      }
      else if (key == GLFW_KEY_DOWN)
      {
         _alpha = std::max(_alpha-0.05, 0.0);
         _splice = spliceUpperBody(_lower, _upper, _alpha);
      }
   }

   Skeleton _skeleton;
   Motion _upper;
   Motion _lower;
   Motion _splice;
   float _alpha;
};

int main(int argc, char** argv)
{
   ASplice viewer;
   viewer.run();
   return 0;
}

