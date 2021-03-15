#include "tools.h"
#include <math.h>
#include <stdbool.h>
#define PI 3.1415


		//coordenadas de composicion de un rectangulo

double getDistanceBetweenPoints(Point p1, Point p2)			//distancia euclidiana entre dos puntos
{
	//h^2 = c^2+c^2. ¿Habra que hacer alguna validacion?
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}

double getAngleBetweenPoints(Point p1, Point p2)//angulo del segmento entre dos puntos.
{
	//siempre tomo a p1 como eje de rotación, al "norte"/eje cartesiano "y" como referencia del angulo
	if (isPointEqual(p1, p2))
		return 0;
	double angle = atan((p2.x - p1.x)/ (p2.y - p1.y)) * (180 / PI);//angulo entre -180 to 180
	return(angle >= 0 ? angle : angle + 360);//si es negativo le sumo una vuelta
}

Point translatePoint(Point p, double distance, double angle)//translada el punto p la distancia y angulo especificados
{
	//x = r.cos(a)
	//y = r.sin(a)
	p.x += distance * cos(angle);
	p.y += distance * sin(angle);
	return p;
}
bool isPointEqual(Point p1, Point p2)//son iguales con error = 0.0000001
{
	if (getDistanceBetweenPoints(p1, p2) < 0.0000001)
		return true;
	else
		return false;
}
double getRectArea(Rect r)//calcula el area de un rectangulo, solo puede recibir valores positivos de puntos
{
	return ((r.SupDer.x - r.InfIzq.x) * (r.SupDer.y - r.InfIzq.y));
}
bool isPointInRect(Point p, Rect r)//determina si el punto p esta en el rectangulo r
{
	if ((p.x <= r.SupDer.x && p.x >= r.InfIzq.x) && (p.y <= r.SupDer.y && p.y >= r.InfIzq.y))
		return true;
	else
		return false;
}