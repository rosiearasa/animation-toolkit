#include <random>
#include <functional>
#include "atkui/skeleton_drawer.h"
#include "atkui/framework.h"
#include "atk/toolkit.h"
#include "agl/renderer.h"

using namespace glm;
using namespace atk;
using namespace atkui;

class Unique : public atkui::Framework
{
public:
   Unique() : atkui::Framework(atkui::Perspective) {}
   virtual ~Unique() {}

   virtual void setup()
   {
       
  _alpha = 0.5;
      BVHReader reader;
      reader.load("../motions/10/10_01.bvh", skeleton, motion);
      reader.load("../motions/10/10_02.bvh", skeleton, motion1);
      reader.load("../motions/10/10_03.bvh", skeleton, motion2);
      
       motion.update(skeleton, 0);
      _blend = blend(motion, motion1, _alpha);
       _blend = blend(motion1, motion2, _alpha);
   
  

   }

   virtual void scene()
   {


      drawMotion(_blend, vec3(-200,1,0));
     
    
}
   Motion blend(const Motion& m1, const Motion& m2, double alpha)
   {
      Motion blend;
      blend.setFramerate(m1.getFramerate());
      double deltaT = 1/blend.getFramerate();
 
      double t1, t2 = 0.0;
      double duration= m1.getDuration()*(1-_alpha)+m2.getDuration()*_alpha;
      for (double t=0.0; t<=duration; t+=deltaT){
        t1 = (t/duration)* m1.getDuration();
        t2 = (t/duration)* m2.getDuration();
        Pose pos1 = m1.getValue(t1);
        Pose pos2 = m2.getValue(t2);
        Pose newkey = Pose::Lerp(pos1,pos2, alpha);
        blend.appendKey(newkey);
      }
     return blend;
   }

   void drawMotion(const Motion& m, const vec3& offset)
   {
      double t = elapsedTime() * 0.5;
      double time = m.getNormalizedDuration(t) * m.getDuration();
      m.update(skeleton, time, false);

      SkeletonDrawer drawer;
      drawer.pos = offset;
      drawer.draw(skeleton, *this);
   }
private:
  Skeleton skeleton;
  Motion motion;  
  Motion _blend;
    Motion jblend;
      Motion kblend;
  Motion motion1;
  Motion motion2;
  Motion motion3;
  Motion motion4;

   double _alpha;
   
};

int main(int argc, char **argv)
{
   Unique viewer;
   viewer.run();
}
