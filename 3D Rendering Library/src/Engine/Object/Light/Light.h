
#include "../Sphere/Sphere.h"
#include "LightSource.h"

class Light : public Sphere
{
public:

	Light();

public:

	LightSource source;
};