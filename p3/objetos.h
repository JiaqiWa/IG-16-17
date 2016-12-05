//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include <math.h>
#define X 0
#define Y 1
#define Z 2
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
void 	draw_polygon(float r, float g, float b, int grosor);

vector<_vertex3i> caras;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=5);
	_cubo &operator=(const _cubo & obj) ;
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam, float al);
};




//*************************************************************************
// clase objeto
//*************************************************************************

class _objeto: public _triangulos3D
{
private:
	const char * filename;
public:
	_objeto();
	_objeto(const char* filename);
	_objeto &operator=(const _objeto & obj) ;
};


//*************************************************************************
// clase revolucion
//*************************************************************************

class _revolucion : public _triangulos3D
{
private:
	_matrix4<float> matrizObj;
	int numVerticesPerfil;
	float numPerfil;

public:
	_revolucion();
	_revolucion(_objeto &objetoPly, int eje, float numPasos);
	_revolucion &operator=(const _revolucion & obj) ;
	void getPerfilVertices();
	void getPerfilCaras();
	void getTapas(int eje);
	void rotarX(float angulo);
	void rotarY(float angulo);
	void rotarZ(float angulo);


};


//*************************************************************************
// clase barrido
//*************************************************************************

class _barrido : public _triangulos3D
{
private:
	_matrix4<float> matrizObj;
	float distancia;
	int numTraslados;
	int numVertices;

public:
	_barrido(_objeto &objetoPly, int numTras, float dist, int eje);
	void traslado(int eje,float distancia);
	void getPerfilVertices();
	void getPerfilCaras();
	void getTapas();


};

//*************************************************************************
// clase Grua
//*************************************************************************

class _grua : public _triangulos3D
{
private:
	_cubo cubo;
	_revolucion cilindro;
	float alfa,beta, grado1, grado2, grado3, angulo;
	string modo;


public:
	_grua(_cubo &cubo, _revolucion &cilindro, float a, float b, float ang, float g1, float g2, float g3);
	void dibuja(string m);
	void parteSuperior();
	void parteInferior();
	void brazosCuerdaCaja();
	void brazoHcuerdaCaja();
	void cuerdaCaja();
	void ruedas();
        void luces();
        void prismaRectInferior();
        void prismaRectSuperior();
	void ruedasTraseras();
        void ruedasDelanteras();
	void rueda();
	void luz();



};
