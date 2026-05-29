//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//typedef struct {
//	int x;
//	int y;
//}vector2D;
//
//float distanceBetweenTwoPoint(vector2D *v1, vector2D *v2) {
//	int xByx = v2->x - v1->x;
//	int yByy = v2->y - v1->y;
//
//	xByx *= xByx;
//	yByy *= yByy;
//
//	return (float)sqrt(xByx + yByy);
//}
//void initVector(vector2D* v, int a, int b)
//{
//	v->x = a;
//	v->y = b;
//}
//
//int main(void)
//{
//	vector2D v1;
//	vector2D v2;
//	
//	initVector(&v1, -6, -6);
//	initVector(&v2, 6, 6);
//
//	printf("%0.2f\n", distanceBetweenTwoPoint(&v1, &v2));
//	return 0;
//
//}