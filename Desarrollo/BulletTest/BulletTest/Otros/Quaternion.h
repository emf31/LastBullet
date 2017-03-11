#pragma once
// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h


//Version reducida de la clase quaternion de irrlitch. 


#include <vec3.hpp>
#include <Util.h>



//! Constant for 64bit PI.
const double PI64 = 3.1415926535897932384626433832795028841971693993751;

		//! Quaternion class for representing rotations.
		/** It provides cheap combinations and avoids gimbal locks.
		Also useful for interpolations. */
		class quaternion
		{
		public:

			//! Default Constructor
			quaternion() : X(0.0f), Y(0.0f), Z(0.0f), W(1.0f) {}

			//! Constructor
			quaternion(float x, float y, float z, float w) : X(x), Y(y), Z(z), W(w) { }


			//! Equalilty operator
			bool operator==(const quaternion& other) const;

			//! inequality operator
			bool operator!=(const quaternion& other) const;

			//! Assignment operator
			inline quaternion& operator=(const quaternion& other);

			//! Add operator
			quaternion operator+(const quaternion& other) const;

			//! Multiplication operator
			quaternion operator*(const quaternion& other) const;

			//! Multiplication operator with scalar
			quaternion operator*(float s) const;

			//! Multiplication operator with scalar
			quaternion& operator*=(float s);

			//! Multiplication operator
			quaternion& operator*=(const quaternion& other);

			//! Calculates the dot product
			inline float dotProduct(const quaternion& other) const;

			//! Sets new quaternion
			inline quaternion& set(float x, float y, float z, float w);

			//! Sets new quaternion based on euler angles (radians)
			inline quaternion& set(float x, float y, float z);

			//! Sets new quaternion based on euler angles (radians)
			inline quaternion& set(const Vec3<float>& vec);

			//! Sets new quaternion from other quaternion
			inline quaternion& set(const quaternion& quat);



			//! Normalizes the quaternion
			inline quaternion& normalize();



			//! Inverts this quaternion
			quaternion& makeInverse();

			//! Set this quaternion to the linear interpolation between two quaternions
			/** \param q1 First quaternion to be interpolated.
			\param q2 Second quaternion to be interpolated.
			\param time Progress of interpolation. For time=0 the result is
			q1, for time=1 the result is q2. Otherwise interpolation
			between q1 and q2.
			*/
			quaternion& lerp(quaternion q1, quaternion q2, float time);



			//! Create quaternion from rotation angle and rotation axis.
			/** Axis must be unit length.
			The quaternion representing the rotation is
			q = cos(A/2)+sin(A/2)*(x*i+y*j+z*k).
			\param angle Rotation Angle in radians.
			\param axis Rotation axis. */
			quaternion& fromAngleAxis(float angle, const Vec3<float>& axis);


			//! Output this quaternion to an euler angle (radians)
			void toEuler(Vec3<float>& euler) const;

			//! Set quaternion to identity
			quaternion& makeIdentity();


			//! Quaternion elements.
			float X; // vectorial (imaginary) part
			float Y;
			float Z;
			float W; // real part
		};





		// equal operator
		inline bool quaternion::operator==(const quaternion& other) const
		{
			return ((X == other.X) &&
				(Y == other.Y) &&
				(Z == other.Z) &&
				(W == other.W));
		}

		// inequality operator
		inline bool quaternion::operator!=(const quaternion& other) const
		{
			return !(*this == other);
		}

		// assignment operator
		inline quaternion& quaternion::operator=(const quaternion& other)
		{
			X = other.X;
			Y = other.Y;
			Z = other.Z;
			W = other.W;
			return *this;
		}




		// multiplication operator
		inline quaternion quaternion::operator*(const quaternion& other) const
		{
			quaternion tmp;

			tmp.W = (other.W * W) - (other.X * X) - (other.Y * Y) - (other.Z * Z);
			tmp.X = (other.W * X) + (other.X * W) + (other.Y * Z) - (other.Z * Y);
			tmp.Y = (other.W * Y) + (other.Y * W) + (other.Z * X) - (other.X * Z);
			tmp.Z = (other.W * Z) + (other.Z * W) + (other.X * Y) - (other.Y * X);

			return tmp;
		}


		// multiplication operator
		inline quaternion quaternion::operator*(float s) const
		{
			return quaternion(s*X, s*Y, s*Z, s*W);
		}


		// multiplication operator
		inline quaternion& quaternion::operator*=(float s)
		{
			X *= s;
			Y *= s;
			Z *= s;
			W *= s;
			return *this;
		}

		// multiplication operator
		inline quaternion& quaternion::operator*=(const quaternion& other)
		{
			return (*this = other * (*this));
		}

		// add operator
		inline quaternion quaternion::operator+(const quaternion& b) const
		{
			return quaternion(X + b.X, Y + b.Y, Z + b.Z, W + b.W);
		}

		// Inverts this quaternion
		inline quaternion& quaternion::makeInverse()
		{
			X = -X; Y = -Y; Z = -Z;
			return *this;
		}


		// sets new quaternion
		inline quaternion& quaternion::set(float x, float y, float z, float w)
		{
			X = x;
			Y = y;
			Z = z;
			W = w;
			return *this;
		}


		// sets new quaternion based on euler angles
		inline quaternion& quaternion::set(float x, float y, float z)
		{
			double angle;

			angle = x * 0.5;
			const double sr = sin(angle);
			const double cr = cos(angle);

			angle = y * 0.5;
			const double sp = sin(angle);
			const double cp = cos(angle);

			angle = z * 0.5;
			const double sy = sin(angle);
			const double cy = cos(angle);

			const double cpcy = cp * cy;
			const double spcy = sp * cy;
			const double cpsy = cp * sy;
			const double spsy = sp * sy;

			X = (float)(sr * cpcy - cr * spsy);
			Y = (float)(cr * spcy + sr * cpsy);
			Z = (float)(cr * cpsy - sr * spcy);
			W = (float)(cr * cpcy + sr * spsy);

			return normalize();
		}

		// sets new quaternion based on euler angles
		inline quaternion& quaternion::set(const Vec3<float>& vec)
		{
			return set(vec.getX(), vec.getY(), vec.getZ());
		}

		// sets new quaternion based on other quaternion
		inline quaternion& quaternion::set(const quaternion& quat)
		{
			return (*this = quat);
		}



		// set this quaternion to the result of the linear interpolation between two quaternions
		inline quaternion& quaternion::lerp(quaternion q1, quaternion q2, float time)
		{
			const float scale = 1.0f - time;
			return (*this = (q1*scale) + (q2*time));
		}



		// calculates the dot product
		inline float quaternion::dotProduct(const quaternion& q2) const
		{
			return (X * q2.X) + (Y * q2.Y) + (Z * q2.Z) + (W * q2.W);
		}


		//! axis must be unit length, angle in radians
		inline quaternion& quaternion::fromAngleAxis(float angle, const Vec3<float>& axis)
		{
			const float fHalfAngle = 0.5f*angle;
			const float fSin = sinf(fHalfAngle);
			W = cosf(fHalfAngle);
			X = fSin*axis.getX();
			Y = fSin*axis.getY();
			Z = fSin*axis.getZ();
			return *this;
		}


		inline bool equals(const float a, const float b, const float tolerance = 0.00000001)
		{
			return (a + tolerance >= b) && (a - tolerance <= b);
		}

		inline void quaternion::toEuler(Vec3<float>& euler) const
		{
			const float sqw = W*W;
			const float sqx = X*X;
			const float sqy = Y*Y;
			const float sqz = Z*Z;
			float test = 2.f * (Y*W - X*Z);

			if (equals(test, 1.f, 0.000001f))
			{
				// heading = rotation about z-axis
				euler.setZ((float)(-2.0*atan2(X, W)));
				// bank = rotation about x-axis
				euler.setX(0);
				// attitude = rotation about y-axis
				euler.setY((float)(PI64 / 2.0));
			}
			else if (equals(test, -1.f, 0.000001f))
			{
				// heading = rotation about z-axis
				euler.setZ((float)(2.0*atan2(X, W)));
				// bank = rotation about x-axis
				euler.setX(0);
				// attitude = rotation about y-axis
				euler.setY((float)(PI64 / -2.0));
			}
			else
			{
				// heading = rotation about z-axis
				euler.setZ((float)atan2(2.0 * (X*Y + Z*W), (sqx - sqy - sqz + sqw)));
				// bank = rotation about x-axis
				euler.setX((float)atan2(2.0 * (Y*Z + X*W), (-sqx - sqy + sqz + sqw)));
				// attitude = rotation about y-axix
				euler.setY((float)asin(clip(test, -1.0, 1.0)));
			}
		}

