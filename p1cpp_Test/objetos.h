//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>

using namespace std;

const float AXIS_SIZE=5000;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:


	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw_arista_solido(float ra, float ga, float ba,int grosor,float rs, float gs, float bs);
void 	draw_tres_colores(float r1, float g1, float b1, float r2, float g2, float b2,float r3, float g3, float b3,float rp, float gp, float bp,int grosor);
void 	draw_tetraedro_pac(float rp, float gp, float bp, float ra, float ga, float ba,float r1, float g1, float b1,float r2, float g2, float b2, int grosorp, int grosora); //pac : puntos aristas caras

vector<_vertex3i> caras;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam, float al);
};
