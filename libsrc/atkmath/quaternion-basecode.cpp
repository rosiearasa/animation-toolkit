#include "atkmath/quaternion.h"
#include "atkmath/matrix3.h"
#include "atkmath/vector3.h"

namespace atkmath {

Quaternion Quaternion::Slerp(const Quaternion& q0, const Quaternion& q1, double t)
{
	// TODO
	return Quaternion(1,0,0,0);
}

void Quaternion::toAxisAngle (Vector3& axis, double& angleRad) const
{
angleRad = acos(this->mW)*2;
axis = Vector3(this->mX, this->mY, this->mZ)* sin(angleRad/2.0f);



}

void Quaternion::fromAxisAngle (const Vector3& axis, double angleRad)
{
Vector3 XYZ = 	axis* sin(angleRad/2.0f);
double W = cos(angleRad/2.0f);
Quaternion(XYZ[0], XYZ[1], XYZ[2],W);
// normalize();
}

Matrix3 Quaternion::toMatrix () const
{
	float X, Y, Z, W;
	X = this->mX;
	Y = this->mY;
	Z = this->mZ;
	W = this->mW;

	Matrix3 XYZ(

		1-2*(pow(Y,2)+ pow(Z, 2)), 2*((X*Y) - (W*Z)), 2*((X*Z)+ (W* Y)),

		2*(X*Y + W *Z), 1-2*(pow(X, 2)+pow(Z, 2)), 2*(Y*Z - W*X),

		2*(X*Z - W*Y), 2*(Y* Z + W), 1-2*(pow(Y, 2)+ pow(X, 2)));

	
	return XYZ;
}

void Quaternion::fromMatrix(const Matrix3& rot)
{
	// TODO
}

}