
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
      B0 = vec3(250,250,0);

     //drawSphere(vec3(250, 250, 0), 10);


      for (float t = 0.0; t <= 1.0; t += 0.01)
      {

        points = (float)(pow((1 - t), 3)) * B0 + (float)(3.0 * t * pow((1 - t), 2)) * B0 + (float)(3.0 * pow(t, 2) * (1 - t)) * B0 + (float)(pow(t, 3)) * B0;
        setColor(vec3(1, 1, 0));
        drawSphere(points, 10);
       

      }



   }

   private:

  vec3 points;
  vec3 B0 ;


 };

 int main(int argc, char** argv) {
   ParticleCubic viewer;
   viewer.run();
 }
