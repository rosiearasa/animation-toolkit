#include "atkmath/quaternion.h"
#include "atkmath/matrix3.h"
#include "atkmath/vector3.h"
#include <algorithm>

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
	

	//diagonal terms to solve vx2, vy2, vz2, w2

	float Vx2, Vy2, Vz2, w2;
    float x, y, z, w;

	w2 = 0.25f*(rot.m11+ rot.m22 +rot.m33 +1);
	Vx2  = 0.25f*(1+rot.m11-  rot.m22 - rot.m33);
	Vy2   = 0.25f*(1-rot.m11+ rot.m22 -rot.m33);
	Vz2   = 0.25f*(1- rot.m11 - rot.m22 + rot.m33);
    
	//get largest
	std::vector<float> Vxyzw {Vx2, Vy2, Vz2, Vz2, w2};

	float maxV = *std::max_element(Vxyzw.begin(),Vxyzw.end() );

		
	
	if (maxV == Vx2){
		x = sqrt(std::abs(Vx2));

		w = (0.25f*(rot.m32 -rot.m23))/x;
		y = (0.25f*(rot.m21 + rot.m12))/x;
		z = (0.25f*(rot.m13 + rot.m31))/x;



	}
	else if (maxV == Vy2){
		y = sqrt(std::abs(Vy2));

		w =(0.25f*(rot.m13 -rot.m31))/ y;

		x = (0.25f*(rot.m12 + rot.m21))/ y;
		z = (0.25f*(rot.m23 + rot.m32))/ y;
		
		
	}
	else if (maxV == Vz2){
		z = sqrt(std::abs(Vz2));

		w = (0.25f*(rot.m21- rot.m31))/z;
		x  =  (0.25f*(rot.m13+rot.m21))/z;
		y =  (0.25f*(rot.m23 +rot.m32))/z;


		
	}
	else if (maxV == w2){
		w = sqrt(std::abs(w2));

		Vx2 =(0.25f *(rot.m32 - rot.m23))/w;
		Vy2 = (0.25f *(rot.m13 - rot.m31))/w;
		Vz2 = (0.25f* (rot.m21 - rot.m12))/w;

		
	}


mX =x;
mY =y;
mZ = z;
mW= w;
normalize();







}

}