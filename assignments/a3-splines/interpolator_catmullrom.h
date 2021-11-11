#ifndef _interpolator_catmullrom_
#define _interpolator_catmullrom_

#include <string>
#include <vector>
#include "interpolator.h"
#include<cmath>

//--------------------------------
// Catmull-Rom 
//--------------------------------

class InterpolatorCatmullRom : public Interpolator
{
public:
    InterpolatorCatmullRom() : Interpolator("Catmull-Rom") {}

    virtual glm::vec3 interpolate(int segment, double u) const {
       // todo: your code here

       // see: interpolator.h and writeup for details
       int t =3;
      
      //  glm::vec3 p0 = getControlPoint(segment*t);
      //  glm::vec3 p1 = getControlPoint(segment*t+1);
      //  glm::vec3 p2= getControlPoint(segment*t+2);
      //  glm::vec3 p3= getControlPoint(segment*t+3);
   
       


       //do catmull rom
     //glm::vec3 p= (pow((1-(float)u),3))*p0 +(3*((float)u)*(pow(1-(float)u,2)))*p1+ (3*(pow((float)u,2)*(1-(float)u)))*p2 + (pow((float)u,3))*p3;

     

        return glm::vec3(0);
     //  return p;
    } 

    virtual void computeControlPoints(const std::vector<glm::vec3>& keys) {
       // todo: your code here
       // see: interpolator.h and writeup for details
       //segment 0
        // std::vector<glm::vec3>  b11;
        // std::vector<glm::vec3> b12;
        // std::vector<glm::vec3> b13;



      //segment 1
        // std::vector<glm::vec3>  b21;
        // std::vector<glm::vec3>  b22;
        // std::vector<glm::vec3>  b23;



        // for (int i= 0; i< keys.size(); i++){
          //compute each of the control points 
        //mCtrlPoints.push_back();
      
      //}
    }
};

#endif
