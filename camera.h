///Function to convert degrees to radian value
#define DEG2RAD(a) (a * 0.0174532925)
#include "vectors.h"
///The main Camera Class
class Camera
{
public:
	///Eye vector is where the camera will look at and is usually in negetive Z direction
	Vector3f eye;
	///Reference point(origin) is the centre of the scene.
	Vector3f center;
	///UP vector points towards positive Y axix.
	Vector3f up;
	///Constructor for the camera Class
	Camera(float eyeX = 1.0f, float eyeY = 1.0f, float eyeZ = 1.0f, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f, float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f)
	{
		eye = Vector3f(eyeX, eyeY, eyeZ);
		center = Vector3f(centerX, centerY, centerZ);
		up = Vector3f(upX, upY, upZ);
		Vector3f view = (center - eye).Normalize();
		eye = eye + view * -0.7;
		center = center + view * -0.7;
	}
	///Translate along x axis
	///@param d units
	void moveX(float d)
	{
		Vector3f right = up.CrossProduct(center - eye).Normalize();
		eye = eye + right * d;
		center = center + right * d;
	}
	///Translate along y axis
	///@param d units
	void moveY(float d)
	{
		eye = eye + up.Normalize() * d;
		center = center + up.Normalize() * d;
	}
	///Translate along Z axis (Zooming In and Out)
	///@param d units
	void moveZ(float d)
	{
		Vector3f view = (center - eye).Normalize();
		eye = eye + view * d;
		center = center + view * d;
	}
	///Rotate about X axis
	///@param a angle
	void rotateX(float a)
	{
		Vector3f view = (center - eye).Normalize();
		Vector3f right = up.CrossProduct(view).Normalize();
		view = view * cos(DEG2RAD(a)) + up * sin(DEG2RAD(a));
		up = view.CrossProduct(right);
		center = eye + view;
	}
	///Rotate about Y axis
	///@param a angle
	void rotateY(float a)
	{
		Vector3f view = (center - eye).Normalize();
		Vector3f right = up.CrossProduct(view).Normalize();
		view = view * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
		right = view.CrossProduct(up);
		center = eye + view;
	}
	///Uses gluLookAt function to Generate View Matrix
	///@param eye: Position of eye
	///@param centre: Reference point(center of scene)
	///@param up: Specifies the UP vector
	void look()
	{
		gluLookAt(eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);
	}
} camera; ///< Object of type Camera declared Globally
///Sets up the perspective Vision
///Initializes the camera
void setupCamera()
{ ///Specify the current matrix
	glMatrixMode(GL_PROJECTION);
	///Replace current matrix with identity matrix
	glLoadIdentity();
	///FOV angle,Aspect Ratio,FrontPlane,BackPlane
	gluPerspective(100, 1280 / 720, 0.001, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.look();
}
///Sets camera to show Left View of Scene
void setLeftView()
{
	camera.up.x = -0.00405836;
	camera.up.y = 0.999989;
	camera.up.z = 0.00230124;

	camera.center.x = -0.713009;
	camera.center.y = 0.448415;
	camera.center.z = 0.426624;

	camera.eye.x = -1.71246;
	camera.eye.y = 0.444435;
	camera.eye.z = 0.393797;
}
///Sets camera to show Top View of Scene
void setTopView()
{
	camera.up.x = 0.0226687;
	camera.up.y = -0.0143616;
	camera.up.z = -0.99964;

	camera.center.x = -0.00778855;
	camera.center.y = 1.79373;
	camera.center.z = 0.516674;

	camera.eye.x = -0.00758377;
	camera.eye.y = 2.79363;
	camera.eye.z = 0.502314;
}
///Sets camera to show Right View of Scene
void setRightView()
{
	camera.up.x = -0.108454;
	camera.up.y = 0.994058;
	camera.up.z = -0.00928754;

	camera.center.x = 0.952321;
	camera.center.y = 0.526236;
	camera.center.z = 0.454693;

	camera.eye.x = 1.94623;
	camera.eye.y = 0.634482;
	camera.eye.z = 0.434158;
}
///Sets camera to show Front View of Scene
void setFrontView()
{
	camera.up.x = -0.00171101;
	camera.up.y = 0.995962;
	camera.up.z = -0.0897583;

	camera.center.x = 0.0095462;
	camera.center.y = 0.491564;
	camera.center.z = 1.5339;

	camera.eye.x = 0.0304264;
	camera.eye.y = 0.590316;
	camera.eye.z = 2.62926;
}
