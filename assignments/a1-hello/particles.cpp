#include "atkui/framework.h"
#include <random>

constexpr auto COUNT = 150;

using namespace glm;
using namespace std;

struct  Particle {
	vec3 position;
	vec3 color;
	vec3 velocity;


};

class Particles : public atkui::Framework
{




public:
	Particles() : atkui::Framework(atkui::Orthographic) {
	}





	virtual void setup() {
		theta = 0.0;
		thetaRate = 0.001;






	}





	virtual void scene() {
		Particle movingParticles[COUNT];
		
		vec3 position = agl::randomUnitVector();
	


		//random colors
		vector <vec3> pallet = {
   vec3(0,165,227) / 255.0f,
   vec3(141,215,191) / 255.0f,
   vec3(255,150,197) / 255.0f,
   vec3(255,87,104) / 255.0f,
   vec3(255,162,58) / 255.0f

		};
		for (int i = 0; i < 1000; i++) {
			movingParticles->position =  vec3(agl::randomUnitVector());
			theta += thetaRate * elapsedTime();
			//INITIALIZE RANDOM VELOCITY
			movingParticles->velocity = vec3(agl::randomUnitVector())*theta;
			//CHOOSE AND SET A RANDOM COLOR  FROM GIVEN PALLET
			int randColor = rand() % pallet.size();
			vec3 value = pallet[randColor];
			setColor(movingParticles->color = value);
			//GENERATE RANDOM POSITION    
				drawSphere((movingParticles->position*theta), 10);


		}
		
			
	}


private:
	float theta;
	float thetaRate;

};

int main(int argc, char** argv) {
	Particles viewer;
	viewer.run();
	return 0;
}
