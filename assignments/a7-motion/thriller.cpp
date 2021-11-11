#include <random>
#include <functional>
#include "atkui/framework.h"
#include "atk/toolkit.h"
#include "agl/renderer.h"
#include "devil.h"

using namespace atk;
using namespace glm;

class Thriller : public atkui::Framework
{
public:
   Thriller() : atkui::Framework(atkui::Perspective) {}
   virtual ~Thriller() {}

   virtual void setup()
   {
      BVHReader reader;
      reader.load("../motions/Warrok/WarrokThriller.bvh", _skeleton, _motion);

      // vec3 position = vec3(0);
      // vec3 color = vec3(1,0,0);
      // float size = 1.0f;
      // _devil = Devil(position, color, size);

      //the devils
      int colNum = 3;
      float space = 250.0f;
      int jitter = 200;
      vec3 mid = vec3(width() / 2.0f, 0, height() / 2.0f);
      for (int i = 0; i < numDevils; i++)
      {
         int row = i / colNum;
         int col = i % colNum;

         vec3 position = vec3(row * space + rand() % jitter, 0, col * space + rand() % jitter) - mid;
         vec3 color = agl::randomUnitVector();

         float size = 0.5f + static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
         ;
         _devil.push_back(Devil(position, color, size));
      }
   }

   virtual void scene()
   {
      if (!_paused)
         _motion.update(_skeleton, elapsedTime());
      for (int i = 0; i < _devil.size(); i++)
      {
         _devil[i].draw(_skeleton, *this);
      }
   }

   virtual void keyUp(int key, int mods)
   {
      if (key == 'P')
         _paused = !_paused;
   }

protected:
   std::vector<Devil> _devil;
   Motion _motion;
   Skeleton _skeleton;
   bool _paused = false;
   int numDevils = 12;
};

int main(int argc, char **argv)
{
   Thriller viewer;
   viewer.run();
}
