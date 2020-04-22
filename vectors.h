///A Class to enable use of vectors in the program
///All needed operations on vectors are defined here
///
///Took help from :http://pages.cs.wisc.edu/~byrne/p3/Vector3f.cpp*/
class Vector3f
{
public:
	///X component of the vector
	float x;
	///Y component of the vector
	float y;
	///Z component of the vector
	float z;
	///Constructor to set x,y,z to given value(0 by default)
	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f)
	{
		x = _x;
		y = _y;
		z = _z;
	}
	///Vector addition
	///@param v: a vector
	Vector3f operator+(Vector3f const &v)
	{
		return Vector3f(x + v.x, y + v.y, z + v.z);
	}
	///Vector subtraction
	///@param v: a vector
	Vector3f operator-(Vector3f &v)
	{
		return Vector3f(x - v.x, y - v.y, z - v.z);
	}
	///Vector multiplication by scalar
	///@param n: a scalar
	Vector3f operator*(float n)
	{
		return Vector3f(x * n, y * n, z * n);
	}
	///Cector division by scalar
	///@param n: a scalar
	Vector3f operator/(float n)
	{
		return Vector3f(x / n, y / n, z / n);
	}
	///Convert vector to unit vector
	Vector3f Normalize()
	{
		return *this / sqrt(x * x + y * y + z * z);
	}
	///Calculate cross product with given vector
	///@param v: a vector
	Vector3f CrossProduct(Vector3f v)
	{
		return Vector3f(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}
};

