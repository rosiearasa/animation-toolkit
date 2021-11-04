
 #include "atkui/framework.h"
 using namespace glm;

 class ParticleCubic : public atkui::Framework {
  public:
   ParticleCubic() : atkui::Framework(atkui::Orthographic) {
   }

   void setup() {
      B0= vec3(250,250,0);
      
   }

   void scene() {

     setColor(vec3(1,1,0));
      BX = vec3(250,250,0);

     drawSphere(BX, 10);


      for (float t = 0.0; t <= 1.0; t += 0.01)
      {

        points = (float)(pow((1 - t), 3)) * B0 + (float)(3.0 * t * pow((1 - t), 2)) * B1 + (float)(3.0 * pow(t, 2) * (1 - t)) * B2 + (float)(pow(t, 3)) * B3;
        points2 = (float)(pow((1 - t), 3)) * B0*t + (float)(3.0 * t * pow((1 - t), 2)) * B1*t + (float)(3.0 * pow(t, 2) * (1 - t)) * B2*t + (float)(pow(t, 3)) * B3*t;
        vec3 color = (vec3(1*t, 1*t, 0));
        
        
    drawSphere(points, 5 );
     drawSphere(points2, 5);
      }
     



   }

   private:

  vec3 points;
  vec3 points2;
  vec3 BX;
  vec3 B0 = vec3(100, 50, 0);
  vec3 B1 = vec3(150, 200, 0);
  vec3 B2 = vec3(250, 100, 0);
  vec3 B3 = vec3(300, 300, 0);


 };

 int main(int argc, char** argv) {
   ParticleCubic viewer;
   viewer.run();
 }
