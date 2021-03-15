#ifndef TOOLS_H
#define TOOLS_H
#include <stdbool.h>
typedef struct {
	double x;
	double y;
} Point;		//cada punto tendra una estructura de este tipo

typedef struct {
	Point InfIzq;
	Point SupDer;
} Rect;

double getDistanceBetweenPoints(Point p1, Point p2);//distancia euclidiana entre dos puntos
double getAngleBetweenPoints(Point p1, Point p2);//angulo del segmento entre dos puntos
Point translatePoint(Point p, double distance, double angle);//translada el punto p la distancia y angulo especificados
bool isPointEqual(Point p1, Point p2);//son iguales con error = 0.0000001
double getRectArea(Rect r);//calcula el area de un rectangulo
bool isPointInRect(Point p, Rect r);//determina si el punto p esta en el rectangulo r

#endif