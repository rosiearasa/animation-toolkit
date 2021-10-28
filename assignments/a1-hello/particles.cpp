#include "atkui/framework.h"
#include <random>

constexpr auto COUNT = 150;

using namespace glm;
using namespace std;

struct Particle
{
	vec3 position1;
	vec3 position;
	vec3 color;
	vec3 velocity;
};

class Particles : public atkui::Framework
{

public:
	Particles() : atkui::Framework(atkui::Orthographic)
	{
	}

	virtual void setup()
	{

		vel = vec3(width(), height(), 0);
	}

	virtual void scene()
	{

		vec3 position = agl::randomUnitVector();

		//random colors
		vector<vec3> pallet = {
			vec3(0, 165, 227) / 255.0f,
			vec3(141, 215, 191) / 255.0f,
			vec3(255, 150, 197) / 255.0f,
			vec3(255, 87, 104) / 255.0f,
			vec3(255, 162, 58) / 255.0f

		};

		float velocitymag = 30.4;
		std::vector<Particle> PPP;
		Particle movingParticles[1000];

		for (int i = 0; i < 1000; i++)
		{
			velocitymag += elapsedTime();

			//random position
			movingParticles[i].position1 = vec3(agl::randomUnitVector());
			movingParticles[i].position = movingParticles[i].position1 * velocitymag;
			if (movingParticles[i].position.x <= width() && movingParticles[i].position.y <= height())
			{
				//CHOOSE AND SET A RANDOM COLOR  FROM GIVEN PALLET
				int randColor = rand() % pallet.size();
				vec3 value = pallet[randColor];
				setColor(movingParticles[i].color = value);
				//GENERATE RANDOM POSITION

				drawSphere(movingParticles[i].position, 10);
			}
			else if (movingParticles[i].position.x >= width() || movingParticles[i].position.y >= height())
			{
				movingParticles[i].position.x = 0.0;
				movingParticles[i].position.y = 0.0;
			}
		}
	}

private:
	vec3 vel;
};

int main(int argc, char **argv)
{
	Particles viewer;
	viewer.run();
	return 0;
}
