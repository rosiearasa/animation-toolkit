#include "atkmath/matrix3.h"
#include "atkmath/quaternion.h"

namespace atkmath
{

   Matrix3 getRx(double angle)
   {
      Matrix3 Rx = Matrix3(1, 0, 0,
                           0, cos(angle), -sin(angle),
                           0, sin(angle), cos(angle));

      return Rx;
   }
   Matrix3 getRy(double angle)
   {
      Matrix3 Ry = Matrix3(cos(angle), 0.0, sin(angle),
                           0.0, 1.0, 0.0,
                           -sin(angle), 0.0, cos(angle));

      return Ry;
   }
   Matrix3 getRz(double angle)
   {

      Matrix3 Rz = Matrix3(cos(angle), -sin(angle), 0.0,
                           sin(angle), cos(angle), 0.0,
                           0.0, 0.0, 1.0);

      return Rz;
   }

   Vector3 Matrix3::toEulerAnglesXYZ() const
   {
      double x, z;
      double y = asin(mM[0][2]);
      if (mM[0][2] != -1 && mM[0][2] != 1)
      {
         z = atan2(-mM[0][1], mM[0][0]);
         x = atan2(-mM[1][2], mM[2][2]);
      }
      if (mM[0][2] == 1)
      {
         z = 0;
         x = atan2(mM[1][0], mM[1][1]);
      }
      if (mM[0][2] == -1)
      {
         z = 0;
         x = atan2(mM[2][1], mM[2][0]);
      }

      Vector3(x, y, z);
   }

   Vector3 Matrix3::toEulerAnglesXZY() const
   {
      double z = asin(-mM[0][1]);

      double y, x;
      if (mM[0][1] != -1 && mM[0][1] != 1)
      {
         x = atan2(mM[2][1], mM[1][1]);
         y = atan2(mM[0][2], mM[0][0]);
      }
      if (mM[0][1] == 1)
      {
         y = 0;
         x = atan2(-mM[2][0], -mM[1][0]);
      }
      if (mM[0][1] == -1)
      {
         y = 0;
         x = atan2(mM[2][0], mM[1][0]);
      }

      return Vector3(x, y, z);
   }

   Vector3 Matrix3::toEulerAnglesYXZ() const
   {
      double x = asin(-mM[1][2]);

      double y, z;

      if (mM[1][2] != 1 && mM[1][2] != -1)
      {
         y = atan2(mM[0][2], mM[2][2]);

         z = atan2(mM[1][0], mM[1][1]);
      }

      if (mM[1][2] == 1)
      {
         z = 0;
         y = atan2(-mM[2][0], -mM[2][1]);
      }
      if (mM[1][2] == -1)
      {
         z = 0;
         y = atan2(mM[0][1], mM[0][0]);
      }

      return Vector3(x, y, z);
   }

   Vector3 Matrix3::toEulerAnglesYZX() const
   {
      double x, y;
      double z = asin(mM[1][0]);

      if (mM[1][0] != 1 && mM[1][0] != -1)
      {
         x = atan2(-mM[1][2], mM[1][1]);
         y = atan2(-mM[2][0], mM[0][0]);
      }
      if (mM[1][0] == -1 || mM[1][0] == 1)
      {

         y = 0;
         x = atan2(mM[2][1], mM[2][2]);
      }

      return Vector3(x, y, z);

      // return Vector3(x, y, z);
   }

   Vector3 Matrix3::toEulerAnglesZXY() const
   {
      double y, z;

      double x = asin(mM[2][1]);

      if (mM[2][1] != 1 && mM[2][1] != -1)
      {
         y = atan2(-mM[2][0], mM[2][2]);
         z = atan2(-mM[0][1], mM[1][1]);
      }
      if (mM[2][1] == 1 || mM[2][1] == -1)
      {
         z = 0;
         y = atan2(mM[0][2], mM[0][0]);
      }

      return Vector3(x, y, z);

      // return Vector3(x, y, z);
   }

   Vector3 Matrix3::toEulerAnglesZYX() const
   {

      double z, x;
      double y = asin(-mM[2][0]);
      if (mM[2][0] != 1 && mM[2][0] != -1)
      {

         x = atan2(mM[2][1], mM[2][2]);
         z = atan2(mM[1][0], mM[0][0]);
      }

      if (mM[2][0] == 1)
      {
         z = 0;
         x = atan2(-mM[0][1], -mM[0][2]);
      }
      if (mM[2][0] == -1)
      {
         z = 0;
         x = atan2(mM[0][1], mM[0][2]);
      }

      return Vector3(x, y, z);
   }

   void Matrix3::fromEulerAnglesXYZ(const Vector3 &angleRad)
   {

      //extract each of the (x,y,zs)
      double x = angleRad[0];
      double y = angleRad[1];
      double z = angleRad[2];

      Matrix3 Rx = getRx(x);
      Matrix3 Ry = getRy(y);
      Matrix3 Rz = getRz(z);

      Matrix3 Rxyz = Rx * Ry * Rz;

      *this = Rxyz;
   }

   void Matrix3::fromEulerAnglesXZY(const Vector3 &angleRad)

   {
      double x = angleRad[0];
      double y = angleRad[1];
      double z = angleRad[2];

      Matrix3 Rx = getRx(x);
      Matrix3 Ry = getRy(y);
      Matrix3 Rz = getRz(z);

      Matrix3 Rxzy = Rx * Rz * Ry;

      *this = Rxzy;
   }

   void Matrix3::fromEulerAnglesYXZ(const Vector3 &angleRad)
   {
      double x = angleRad[0];
      double y = angleRad[1];
      double z = angleRad[2];

      Matrix3 Rx = getRx(x);
      Matrix3 Ry = getRy(y);
      Matrix3 Rz = getRz(z);

      Matrix3 Ryxz = Ry * Rx * Rz;

      *this = Ryxz;
   }

   void Matrix3::fromEulerAnglesYZX(const Vector3 &angleRad)
   {
      double x = angleRad[0];
      double y = angleRad[1];
      double z = angleRad[2];

      Matrix3 Rx = getRx(x);
      Matrix3 Ry = getRy(y);
      Matrix3 Rz = getRz(z);

      Matrix3 Ryzx = Ry * Rz * Rx;

      *this = Ryzx;
   }

   void Matrix3::fromEulerAnglesZXY(const Vector3 &angleRad)
   {

      double x = angleRad[0];
      double y = angleRad[1];
      double z = angleRad[2];

      Matrix3 Rx = getRx(x);
      Matrix3 Ry = getRy(y);
      Matrix3 Rz = getRz(z);

      Matrix3 Rzxy = Rz * Rx * Ry;
      *this = Rzxy;
   }

   void Matrix3::fromEulerAnglesZYX(const Vector3 &angleRad)
   {

      double x = angleRad[0];
      double y = angleRad[1];
      double z = angleRad[2];

      Matrix3 Rx = getRx(x);
      Matrix3 Ry = getRy(y);
      Matrix3 Rz = getRz(z);

      Matrix3 Rzyx = Rz * Ry * Rx;

      *this = Rzyx;
   }

   void Matrix3::toAxisAngle(Vector3 &axis, double &angleRad) const
   {
      // TODO
   }

   void Matrix3::fromAxisAngle(const Vector3 &axis, double angleRad)
   {
      // TODO
      *this = Identity;
   }

}