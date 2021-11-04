
 #include "atkui/framework.h"
 using namespace glm;

 class Unique : public atkui::Framework {
  public:
   Unique() : atkui::Framework(atkui::Orthographic) {
   }

   void setup() {
      B0= vec3(250,250,0);
      slower = 0.3;
      
   }

   void scene() {

    

       slower = elapsedTime()/slower;
         for (float t = 0.0; t <= 1.0; t += 0.01)
      {
     

        points = (float)(pow((1 - t), 3)) * B0 + (float)(3.0 * t * pow((1 - t), 2)) * B1 + (float)(3.0 * pow(t, 2) * (1 - t)) * B2 + (float)(pow(t, 3)) * B3;
        points2 = (float)(pow((1 - t), 3)) * B0*t + (float)(3.0 * t * pow((1 - t), 2)) * B1*t + (float)(3.0 * pow(t, 2) * (1 - t)) * B2*t + (float)(pow(t, 3)) * B3*t;
        setColor(vec3(1*t, 0, 1));
        points =points*slower;
        points2 =points2*slower;
        
       if((points.x < width() && points.y <height())  && (points2.y<height()&&points2.x<width())){
      drawSphere(points, 5 );
      setColor(vec3(1, 1*t, 0));
      drawSphere(points2, 5);
   
} 
else{
   points = vec3(0,0,0);
   points2= vec3(0,0,0);
  
}
     
      }
 
   
   
    


 

   }

   private:

  vec3 points;
  vec3 points2;
  float slower;
  
  vec3 B0 = vec3(50, 50, 0);
  vec3 B1 = vec3(100,10, 150);
  vec3 B2 = vec3(200, 0, 100);
  vec3 B3 = vec3(250, 200, 50);


 };

 int main(int argc, char** argv) {
   Unique viewer;
   viewer.run();
 }
