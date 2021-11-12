#include "atkui/framework.h"


using namespace glm;

struct Particle
{
	vec3 position;
	vec3 color;
	vec3 velocity;
};

class Circles : public atkui::Framework
{
public:
   Circles() : atkui::Framework(atkui::Orthographic) {
   }

   virtual void setup() {
      theta = 0.0f;
      thetarate=1.0;
      displacement = 2.0;
      radius = 5;


   }

   virtual void scene() {
 
      for (int i =0; i<36; i+=2){
         theta += thetarate;

         hypnotic[i].position =vec3(radius+i*2*cos(theta)+width()*0.5, radius+i*2*sin(theta)+height()*0.5, 0);
      // if (hypnotic[i].position.x <= width() && hypnotic[i].position.y <= height())
		// 	{
				//CHOOSE AND SET A RANDOM COLOR  FROM GIVEN PALLET
				int randColor = rand() % pallet.size();
				vec3 value = pallet[randColor];
				setColor(hypnotic[i].color = value);
				//GENERATE RANDOM POSITION
   drawSphere(hypnotic[i].position, 10);
			
		//	}
      
	

   }
   }
   private:
   float theta;
   float thetarate;
   double displacement;
   float radius;

   std::vector<Particle> PPP;
	Particle hypnotic[36];
   std::vector<vec3> pallet =
   {
      vec3(0,165,227)/255.0f,
      vec3(141,215,191)/255.0f,
      vec3(255,150,197)/255.0f,
      vec3(255,87,104)/255.0f,
      vec3(255,162,58)/255.0f
   };



};


int main(int argc, char** argv)
{
   Circles viewer;
   viewer.run();
   return 0;
}