#include "atk/toolkit.h"
#include "atkui/framework.h"
#include "atkui/skeleton_drawer.h"
#include <algorithm>
#include <deque>
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
      _alpha = 10;

      BVHReader reader;
      reader.load("../motions/Beta/walking.bvh", _skeleton, _lower);
      reader.load("../motions/Beta/gangnam_style.bvh", _skeleton, _upper);
      _splice = spliceUpperBody(_lower, _upper, _alpha);
   }

   Motion spliceUpperBody(const Motion &lower, const Motion &upper, float alpha)
   {

      Motion result;
      result.setFramerate(lower.getFramerate());

      Joint *isupper = _skeleton.getByName("Beta:Spine1");

      std::deque<int> jointsqueue;
      std::vector<int> iDs;
      jointsqueue.push_back(isupper->getID());
      while (!jointsqueue.empty())
      {
         isupper = _skeleton.getByID(jointsqueue.front());
         jointsqueue.pop_front();
         iDs.push_back(isupper->getID());
         for (int i = 0; i < isupper->getNumChildren(); i++)
         {
            jointsqueue.push_back(isupper->getChildAt(i)->getID());
         }
      }
      for (int i = 0; i < lower.getNumKeys(); i++)
      {
         Pose lowerPose = lower.getKey(i);
         Pose upperPose = upper.getKey(120 + i);

         for (int j = 0; j < iDs.size(); j++)
         {
            lowerPose.jointRots[iDs[j]] =
                glm::slerp(upperPose.jointRots[iDs[j]], lowerPose.jointRots[iDs[j]], alpha);
         }
         result.appendKey(lowerPose);
      }

      return result;
   }

   void scene()
   {
      _splice.update(_skeleton, elapsedTime() * 0.5);
      SkeletonDrawer drawer;
      drawer.draw(_skeleton, *this);
      drawText("alpha: " + std::to_string(_alpha), 10, 15);
   }

   void keyUp(int key, int mods)
   {
      if (key == GLFW_KEY_UP)
      {
         _alpha = std::min(_alpha + 0.05, 1.0);
         _splice = spliceUpperBody(_lower, _upper, _alpha);
      }
      else if (key == GLFW_KEY_DOWN)
      {
         _alpha = std::max(_alpha - 0.05, 0.0);
         _splice = spliceUpperBody(_lower, _upper, _alpha);
      }
   }

   Skeleton _skeleton;
   Motion _upper;
   Motion _lower;
   Motion _splice;
   float _alpha;
};

int main(int argc, char **argv)
{
   ASplice viewer;
   viewer.run();
   return 0;
}
