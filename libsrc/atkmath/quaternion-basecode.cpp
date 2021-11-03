#include "atkmath/quaternion.h"
#include "atkmath/matrix3.h"
#include "atkmath/vector3.h"
#include <algorithm>
#include<math.h>

namespace atkmath {

Quaternion Quaternion::Slerp(const Quaternion& q0, const Quaternion& q1, double t)
{
	Quaternion q;
	double omega = Dot(q0, q1);
	double angle = acos(omega);


//check for naan and division by 0

if(omega<0){
	omega = -(Dot(q0, q1));
	Quaternion q2 = -q1;
		q = (sin(angle*(1.0-t)))/(sin(angle))* q0 + (sin(angle*t)/sin(angle))*q2;
}
else{
		q = (sin(angle*(1.0-t)))/(sin(angle))* q0 + (sin(angle*t)/sin(angle))*q1;

}

	q.normalize();
	return q;
}

void Quaternion::toAxisAngle (Vector3& axis, double& angleRad) const
{
angleRad = acos(mW)*2;

if (angleRad == 0){
	axis = Vector3 (1,0,0);
}
else{
axis = Vector3(mX,mY,mZ)* (1.0/sin(angleRad/2.0));

}

}

void Quaternion::fromAxisAngle (const Vector3& axis, double angleRad)
{
Vector3 XYZ = 	axis* sin(angleRad/2.0);
double W = cos(angleRad/2.0);
mW = 	W;
mX = XYZ[0];
mY = XYZ[1];
mZ = XYZ[2];
normalize();

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

		2*(X*Z - W*Y), 2*(Y* Z + W*X), 1-2*(pow(Y, 2)+ pow(X, 2)));

	
	return XYZ;
}


void Quaternion::fromMatrix(const Matrix3& rot)

{
	
	Vector3 axis = Vector3();
	double angle = 0.0;
	
	rot.toAxisAngle(axis, angle);

	mX=axis.x();
	mY=axis.y();
	mZ=axis.z();
	mW=angle;

	normalize();
}

}