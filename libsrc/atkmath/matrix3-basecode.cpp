#include "atkmath/matrix3.h"
#include "atkmath/quaternion.h"

namespace atkmath {

Vector3 Matrix3::toEulerAnglesXYZ() const
{
   return Vector3();
   
}

Vector3 Matrix3::toEulerAnglesXZY() const
{
   return Vector3();
}

Vector3 Matrix3::toEulerAnglesYXZ() const
{
   return Vector3();
}

Vector3 Matrix3::toEulerAnglesYZX() const
{
   return Vector3();
}

Vector3 Matrix3::toEulerAnglesZXY() const
{
   return Vector3();
}

Vector3 Matrix3::toEulerAnglesZYX() const
{
   return Vector3();
}
Matrix3 getRx(double angle ){
   Matrix3  Rx =Matrix3(1,0,0,
                        0,cos(angle), -sin(angle), 
                        0, sin(angle), cos(angle));


   return Rx;

}
Matrix3 getRy(double angle ){
   Matrix3 Ry=  Matrix3(cos(angle), 0.0, sin(angle), 
                     0.0, 1.0, 0.0,
                     -sin(angle),0.0, cos(angle));

 
   return Ry;
}
Matrix3 getRz(double angle ){
      
   Matrix3 Rz = Matrix3(cos(angle) , -sin(angle), 0.0, 
                        sin(angle), cos(angle), 0.0,
                        0.0, 0.0 , 1.0 )  ;

      return Rz  ;                  

}
void Matrix3::fromEulerAnglesXYZ(const Vector3& angleRad)
{

    //extract each of the (x,y,zs)
    double x = angleRad[0];
    double y = angleRad[1];
    double z = angleRad[2];


Matrix3 Rx =getRx(x);
Matrix3 Ry =getRy(y);
Matrix3 Rz =getRz(z);



                     
Matrix3 Rxyz = Rx*Ry*Rz;

   *this = Rxyz;
}

void Matrix3::fromEulerAnglesXZY(const Vector3& angleRad)

{
   double x = angleRad[0];
    double y = angleRad[1];
    double z = angleRad[2];

Matrix3 Rx =getRx(x);
Matrix3 Ry =getRy(y);
Matrix3 Rz =getRz(z);

    Matrix3 Rxzy = Rx*Rz*Ry;


   *this = Rxzy;
}

void Matrix3::fromEulerAnglesYXZ(const Vector3& angleRad)
{
   double x = angleRad[0];
    double y = angleRad[1];
    double z = angleRad[2];

    Matrix3 Rx =getRx(x);
   Matrix3 Ry =getRy(y);
   Matrix3 Rz =getRz(z);

Matrix3 Ryxz = Ry*Rx*Rz;

   *this = Ryxz;
}

void Matrix3::fromEulerAnglesYZX(const Vector3& angleRad)
{
      double x = angleRad[0];
    double y = angleRad[1];
    double z = angleRad[2];
        
    Matrix3 Rx =getRx(x);
   Matrix3 Ry =getRy(y);
   Matrix3 Rz =getRz(z);

Matrix3 Ryzx = Ry*Rz*Rx;

   *this = Ryzx;
}

void Matrix3::fromEulerAnglesZXY(const Vector3& angleRad)
{

      double x = angleRad[0];
    double y = angleRad[1];
    double z = angleRad[2];
       
    Matrix3 Rx =getRx(x);
   Matrix3 Ry =getRy(y);
   Matrix3 Rz =getRz(z);

Matrix3 Rzxy = Rz*Rx*Ry;
   *this = Rzxy;
}

void Matrix3::fromEulerAnglesZYX(const Vector3& angleRad)
{

      double x = angleRad[0];
    double y = angleRad[1];
    double z = angleRad[2];

  Matrix3 Rx =getRx(x);
   Matrix3 Ry =getRy(y);
   Matrix3 Rz =getRz(z);

Matrix3 Rzyx = Rz*Ry*Rx;

   *this = Rzyx;
}

void Matrix3::toAxisAngle(Vector3& axis, double& angleRad) const
{
   // TODO
}

void Matrix3::fromAxisAngle(const Vector3& axis, double angleRad)
{
   // TODO
   *this = Identity;
}

}