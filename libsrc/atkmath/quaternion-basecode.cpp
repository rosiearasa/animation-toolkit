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
    float x;
	float y;
	float z;
	float w;

	w2 = 0.25f*(rot[1][1]+ rot[2][2] +rot[3][3] +1);
	Vx2  = 0.25f*(1+rot[1][1]- rot[2][2] - rot[3][3]);
	Vy2   = 0.25f*(1-rot[1][1]+ rot[2][2]-rot[3][3]);
	Vz2   = 0.25f*(1- rot[1][1] - rot[2][2] + rot[3][3]);
    
	//get largest
	std::vector<float> Vxyzw {Vx2, Vy2, Vz2, w2};

	float maxV = *std::max_element(Vxyzw.begin(),Vxyzw.end() );

		
	if (maxV >= w2){
		w = sqrt(w2);

		x =((rot[3][2]- rot[2][3])/4)/w;
		y = ((rot[1][3] - rot[3][1])/4)/w;
		z= ( (rot[2][1] - rot[1][2])/4)/w;

		
	}
	else if (maxV >= Vx2){
		x = sqrt(Vx2);

		w = ((rot[3][2] -rot[2][3])/4)/x;
		y = ((rot[2][1] + rot[1][2])/4)/x;
		z = ((rot[1][3] + rot[3][1])/4)/x;



	}
	else if (maxV >= Vy2){
		y = sqrt(Vy2);

		w =((rot[1][3] -rot[3][1])/4)/ y;

		x = ((rot[1][2] + rot[2][1])/4)/ y;
		z = ((rot[2][3] + rot[3][2])/4)/ y;
		
		
	}
	else if (maxV >= Vz2){
		z = sqrt(Vz2);

		w = ((rot[2][1]- rot[1][2])/4)/z;
		x  =  ((rot[1][3]+rot[3][1])/4)/z;
		y =  ((rot[2][3] +rot[3][2])/4)/z;


		
	}
	
	
mX =x;
mY =y;
mZ =z;
mW= w;
normalize();
}

}