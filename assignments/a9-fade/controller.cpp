#include "atkui/framework.h"
#include "atkui/skeleton_drawer.h"
#include "atk/toolkit.h"
#include <iostream>
#include <cmath>

using namespace glm;
using namespace std;
using namespace atk;

class WASDSimple : public atkui::Framework
{
public:
  WASDSimple() : atkui::Framework(atkui::Perspective) {}

  virtual void setup()
  {
    BVHReader reader;
    reader.load("../motions/Beta/walking.bvh", _skeleton, _walk);
    _drawer.showAxes = true;
  }

  virtual void scene()
  {
    update();
    _drawer.draw(_skeleton, *this);

    // draw heading
    vec3 p = _skeleton.getRoot()->getGlobalTranslation();
    p[1] = 10; // set height close above the floor

    setColor(vec3(0, 1, 1));
    push();
    translate(p);
    rotate(_heading, vec3(0, 1, 0));
    translate(vec3(0, 0, 25));
    scale(vec3(10, 10, 50));
    drawCylinder(vec3(0), 1.0f);
    pop();
  }

  virtual void update()
  {
    _walk.update(_skeleton, elapsedTime());

    Pose pose = _skeleton.getPose();
    //set rotation
    pose.jointRots[0] = glm::angleAxis(_heading, vec3(0, 1, 0));
    // update
    Transform t = Transform::Rot(glm::angleAxis(_heading, vec3(0, 1, 0)));

    pose.rootPos += pos + speed * t.transformVector(vec3(0, 0, 1)) * elapsedTime();
    _skeleton.setPose(pose);

    Joint *head = _skeleton.getByName("Beta:Head");

    vec3 _pos = head->getLocal2Global().transformPoint(vec3(0, 0, 0));

    vec3 look = head->getLocal2Global().transformPoint(vec3(0, 0, -200));
    // TODO: Override the default camera to follow the character
    lookAt(look, _pos, vec3(0, 1, 0));
    // update heading when key is down
    if (keyIsDown('D'))
      _heading -= 0.05;
    if (keyIsDown('A'))
      _heading += 0.05;
  }

protected:
  float _heading;
  vec3 pos;
  float speed;
  Motion _walk;
  Skeleton _skeleton;
  atkui::SkeletonDrawer _drawer;
};

int main(int argc, char **argv)
{
  WASDSimple viewer;
  viewer.run();
}
