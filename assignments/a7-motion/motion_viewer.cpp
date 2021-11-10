#include <iostream>
#include "atkui/framework.h"
#include "atk/toolkit.h"

using namespace glm;
using namespace atk;

class MotionViewer : public atkui::Framework
{
public:
  MotionViewer() : atkui::Framework(atkui::Perspective)
  {
  }

  void setup()
  {
    BVHReader reader;
    reader.load("../motions/Beta/jump.bvh", skeleton, motion);
    motion.update(skeleton, 0);
  }

  void scene()
  {

    time += dt();

    if (!paused)
    {
      currentFrame = motion.getKeyID(time);
      motion.update(skeleton, time);
    }
    else
    {
      Pose newPose = motion.getKey(currentFrame);
      skeleton.setPose(newPose);
    }

    setColor(vec3(0, 0, 0.8));
    for (int i = 0; i < skeleton.getNumJoints(); i++)
    {
      Joint *joint = skeleton.getByID(i);
      if (joint->getParent() == 0)
        continue;

      vec3 p1 = joint->getGlobalTranslation();
      vec3 p2 = joint->getParent()->getGlobalTranslation();
      drawEllipsoid(p1, p2, 5);
    }

    drawText(paused ? "Paused" : "Playing", 10, 15);
    drawText("Current frame: " + std::to_string(currentFrame), 10, 35);
    drawText("Time scale: " + std::to_string(timeScale), 10, 55);
  }

  virtual void keyUp(int key, int mods)
  {

    if (key == GLFW_KEY_P)
    {
      paused = !paused;
    }

    else if (key == GLFW_KEY_0)
    {

      currentFrame = 0;
    }
    else if (key == GLFW_KEY_PERIOD && paused)
    {
      currentFrame += 1;
    }
    else if (key == GLFW_KEY_COMMA && paused)
    {
      if (currentFrame > 0)
      {
        currentFrame -= 1;
      }
    }
    else if (key == GLFW_KEY_RIGHT_BRACKET)
    {
      if (timeScale > 0.2)
      {
        timeScale -= 1.2f;
        motion.setDeltaTime(timeScale);
      }
    }
    else if (key == GLFW_KEY_LEFT_BRACKET)
    {

      timeScale += 1.2f;
      motion.setDeltaTime(timeScale);
    }
  }

private:
  Skeleton skeleton;
  Motion motion;

  float timeScale = 1.0f;
  int currentFrame = 0;
  bool paused = false;
  float time = 0;
};

int main(int argc, char **argv)
{
  MotionViewer viewer;
  viewer.run();
}
