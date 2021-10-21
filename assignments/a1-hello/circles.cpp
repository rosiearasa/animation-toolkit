#include "atkui/framework.h"
#include <vector>

using namespace glm;
using namespace std;


struct  Particle {
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
      radius = 10;
      xPos =width()*0.5;
      yPos = height()*0.5;
      thetha =0.0;
      thetaRate = 0.ß1;
     
     
   
      
      
   }

   virtual void scene() {
       vector <Particle> particles;

   //random colors
		vector <vec3> pallet = {
   vec3(0,165,227) / 255.0f,
   vec3(141,215,191) / 255.0f,
   vec3(255,150,197) / 255.0f,
   vec3(255,87,104) / 255.0f,
   vec3(255,162,58) / 255.0f

		};

     N = 10;
  // Particle p[10];
// for (int i = 0; i<36*N; i++){
//    //CHOOSE AND SET A RANDOM COLOR  FROM GIVEN PALLET
// 	int randColor = rand() % pallet.size();
// 	vec3 value = pallet[randColor];
// 	setColor(p->color = value);
   
//    p->position= agl::randomUnitVector();
//    p->velocity= agl::randomUnitVector();

//    particles.insert(p);
//    drawSphere(particles.pop_back()->position,10);
   
// }
      for (int i = 0; i<200 ; i+=10){
         thetha+= thetaRate;
         xPos = i*cos(thetha)+width()*0.5;
         yPos = i*sin(thetha)+height()*0.5;
         setColor(vec3(1,0,1));




    drawSphere(vec3(xPos, yPos, 0),10);


        
       

      }

      //update the x and y positions


      
      

   }
   private:
   float xPos,yPos;
   float thetha; 
   int radius;
   float thetaRate;
   
   int N;//number of circles


};

int main(int argc, char** argv)
{
   Circles viewer;
   viewer.run();
   return 0;
}