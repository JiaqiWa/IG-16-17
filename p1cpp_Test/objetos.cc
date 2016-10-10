//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos.h"
#include <cmath>

//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{

}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
        glColor3f(r,g,b);
        glPointSize(grosor);
        glBegin(GL_POINTS);
                for(int i = 0; i< vertices.size(); i++){
                        glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
                }
        glEnd();

}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
        glColor3f(r,g,b);
        glLineWidth(grosor);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_TRIANGLES);
                for(int i = 0; i < caras.size(); i++){
                        glVertex3f(vertices[caras[i]._0].x,vertices[caras[i]._0].y,vertices[caras[i]._0].z);
                        glVertex3f(vertices[caras[i]._1].x,vertices[caras[i]._1].y,vertices[caras[i]._1].z);
                        glVertex3f(vertices[caras[i]._2].x,vertices[caras[i]._2].y,vertices[caras[i]._2].z);
                }
        glEnd();
}

//*************************************************************************
// dibujar en modo sólido
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
        glColor3f(r,g,b);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_TRIANGLES);
                for(int i = 0; i< caras.size(); i++){
                       glVertex3f(vertices[caras[i]._0]._0,vertices[caras[i]._0]._1,vertices[caras[i]._0]._2);
                       glVertex3f(vertices[caras[i]._1]._0,vertices[caras[i]._1]._1,vertices[caras[i]._1]._2);
                       glVertex3f(vertices[caras[i]._2]._0,vertices[caras[i]._2]._1,vertices[caras[i]._2]._2);
               }
        glEnd();
}

//*************************************************************************
// dibujar en modo sólido con apariencia de ajedrez
//*************************************************************************

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2)
{
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_TRIANGLES);
                for(int i = 0; i< caras.size(); i++){
                        if(i&1){
                                glColor3f(r1,g1,b1);
                        }else{
                                glColor3f(r2,g2,b2);
                        }
                        glVertex3f(vertices[caras[i]._0]._0,vertices[caras[i]._0]._1,vertices[caras[i]._0]._2);
                        glVertex3f(vertices[caras[i]._1]._0,vertices[caras[i]._1]._1,vertices[caras[i]._1]._2);
                        glVertex3f(vertices[caras[i]._2]._0,vertices[caras[i]._2]._1,vertices[caras[i]._2]._2);
                }
        glEnd();
}


//*************************************************************************
// TEST
//*************************************************************************
void _triangulos3D::draw_arista_solido(float ra, float ga, float ba,int grosor,float rs, float gs, float bs)
{

        glColor3f(ra,ga,ba);
        glLineWidth(grosor);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_TRIANGLES);
                for(int i = 0; i < caras.size()-2; i++){
                        glVertex3f(vertices[caras[i]._0].x,vertices[caras[i]._0].y,vertices[caras[i]._0].z);
                        glVertex3f(vertices[caras[i]._1].x,vertices[caras[i]._1].y,vertices[caras[i]._1].z);
                        glVertex3f(vertices[caras[i]._2].x,vertices[caras[i]._2].y,vertices[caras[i]._2].z);
                }
        glEnd();

        glColor3f(rs,gs,bs);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_TRIANGLES);
                for(int i = 0; i< caras.size()-2; i++){
                       glVertex3f(vertices[caras[i]._0]._0,vertices[caras[i]._0]._1,vertices[caras[i]._0]._2);
                       glVertex3f(vertices[caras[i]._1]._0,vertices[caras[i]._1]._1,vertices[caras[i]._1]._2);
                       glVertex3f(vertices[caras[i]._2]._0,vertices[caras[i]._2]._1,vertices[caras[i]._2]._2);
               }
        glEnd();
}

void _triangulos3D::draw_tres_colores(float r1, float g1, float b1, float r2, float g2, float b2,float r3, float g3, float b3,float rp, float gp, float bp, int grosor)
{
        glColor3f(rp,gp,bp);
        glPointSize(grosor);
        glBegin(GL_POINTS);
                for(int i = 0; i< vertices.size(); i++){
                        glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
                }
        glEnd();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_TRIANGLES);
                for(int i = 0; i< caras.size(); i++){
                        if(i%3==1){
                                glColor3f(r1,g1,b1);
                        }else if(i%3==2){
                                glColor3f(r2,g2,b2);
                        }else{
                                glColor3f(r3,g3,b3);
                        }
                        glVertex3f(vertices[caras[i]._0]._0,vertices[caras[i]._0]._1,vertices[caras[i]._0]._2);
                        glVertex3f(vertices[caras[i]._1]._0,vertices[caras[i]._1]._1,vertices[caras[i]._1]._2);
                        glVertex3f(vertices[caras[i]._2]._0,vertices[caras[i]._2]._1,vertices[caras[i]._2]._2);
                }
        glEnd();
}

void _triangulos3D::draw_tetraedro_pac(float rp, float gp, float bp, float ra, float ga, float ba,float r1, float g1, float b1,float r2, float g2, float b2, int grosorp, int grosora)
{
        //puntos
        glColor3f(rp,gp,bp);
        glPointSize(grosorp);
        glBegin(GL_POINTS);
                for(int i = 0; i< vertices.size(); i++){
                        glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
                }
        glEnd();

        //aristas
        glColor3f(ra,ga,ba);
        glLineWidth(grosora);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_TRIANGLES);
                for(int i = 0; i < caras.size(); i++){
                        glVertex3f(vertices[caras[i]._0].x,vertices[caras[i]._0].y,vertices[caras[i]._0].z);
                        glVertex3f(vertices[caras[i]._1].x,vertices[caras[i]._1].y,vertices[caras[i]._1].z);
                        glVertex3f(vertices[caras[i]._2].x,vertices[caras[i]._2].y,vertices[caras[i]._2].z);
                }
        glEnd();

        //caras
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glBegin(GL_TRIANGLES);
                for(int i = 0; i< caras.size(); i++){
                        if(i%2==0){
                                glColor3f(r1,g1,b1);
                        }else if(i%2==1){
                                glColor3f(r2,g2,b2);
                        }
                        glVertex3f(vertices[caras[i]._0]._0,vertices[caras[i]._0]._1,vertices[caras[i]._0]._2);
                        glVertex3f(vertices[caras[i]._1]._0,vertices[caras[i]._1]._1,vertices[caras[i]._1]._2);
                        glVertex3f(vertices[caras[i]._2]._0,vertices[caras[i]._2]._1,vertices[caras[i]._2]._2);
                }
        glEnd();
}
//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
        //Vértices inferiores
        //0-izqierda trasera
        _vertex3f v = _vertex3f(0,0,0);
        vertices.push_back(v);

        //1-izquierda delantera
        v = _vertex3f(0,0,tam);
        vertices.push_back(v);

        //2-derecha delantera
        v = _vertex3f(tam,0,tam);
        vertices.push_back(v);

        //3-derecha trasera
        v = _vertex3f(tam,0,0);
        vertices.push_back(v);

        //4-Vértices superiores
        //izqierda trasera
        v = _vertex3f(0,tam,0);
        vertices.push_back(v);

        //5-izquierda delantera
        v = _vertex3f(0,tam,tam);
        vertices.push_back(v);

        //6-derecha delantera
        v = _vertex3f(tam,tam,tam);
        vertices.push_back(v);

        //7-derecha trasera
        v = _vertex3f(tam,tam,0);
        vertices.push_back(v);

        //Caras
        //0-inferior
        _vertex3i c1 = _vertex3i(0,2,1);
        _vertex3i c2 = _vertex3i(0,3,2);
        caras.push_back(c1);
        caras.push_back(c2);

        //1-frontal
        c1 = _vertex3i(1,6,5);
        c2 = _vertex3i(1,2,6);
        caras.push_back(c1);
        caras.push_back(c2);

        //3-derecha
        c1 = _vertex3i(2,7,6);
        c2 = _vertex3i(2,3,7);
        caras.push_back(c1);
        caras.push_back(c2);

        //4-trasera
        c1 = _vertex3i(3,4,7);
        c2 = _vertex3i(3,0,4);
        caras.push_back(c1);
        caras.push_back(c2);

        //izquierdad
        c1 = _vertex3i(0,5,4);
        c2 = _vertex3i(0,1,5);
        caras.push_back(c1);
        caras.push_back(c2);

        //superior
        c1 = _vertex3i(5,7,4);
        c2 = _vertex3i(7,5,6);
        caras.push_back(c1);
        caras.push_back(c2);
}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

        //No es un tetraedro regular
        //0-izqierda trasera
        _vertex3f v = _vertex3f(0.0,0.0,0.0);
        vertices.push_back(v);

        //1-derecha trasera
        v = _vertex3f(tam,0.0,0.0);
        vertices.push_back(v);

        //2-delantera
        v = _vertex3f(tam/2,0.0,tam/2);
        vertices.push_back(v);

        //3-superior
        v = _vertex3f(tam/2,al,tam/2);
        vertices.push_back(v);

        //Caras
        //0-inferior
        _vertex3i c1 = _vertex3i(0,1,2);
        caras.push_back(c1);

        //1-izquierda
        c1 = _vertex3i(0,2,3);
        caras.push_back(c1);

        //2-derecha
        c1 = _vertex3i(1,3,2);
        caras.push_back(c1);

        //3-trasera
        c1 = _vertex3i(1,0,3);
        caras.push_back(c1);



}
