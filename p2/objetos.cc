//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos.h"
#include "file_ply_stl.h"

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
// dibujar en modo poligono
//*************************************************************************

void _triangulos3D::draw_polygon(float r, float g, float b, int grosor)
{
        glColor3f(r,g,b);
        glLineWidth(grosor);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glBegin(GL_POLYGON);
                for(int i = 0; i < vertices.size(); i++){
                        glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
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

//*************************************************************************
// clase objeto
//*************************************************************************

_objeto::_objeto(){}
_objeto::_objeto(const char* filename)
{
        cout << filename<<endl;
        //Vectores que guardan las vértices y las caras leídas del fichero .ply
        vector<float> Vertices;
        vector<int> Caras;

        //Abrir, leer y cerrar el fichero .ply
        _file_ply file = _file_ply();
        file.open((char *)filename);
        file.read(Vertices,Caras);
        file.close();

        //pasar los puntos de vector<float> Vertices a vector<_vertex3f> vertices
        _vertex3f v = _vertex3f(0.0,0.0,0.0);
        for (int i = 0; i < Vertices.size(); i=i+3)
        {
                v.x=Vertices[i];
                v.y=Vertices[i+1];
                v.z=Vertices[i+2];
                vertices.push_back(v);
        }

        //pasar los puntos de vector<int> Caras a vector<_vertex3i> caras
        _vertex3i c;
        for (int i = 0; i < Caras.size(); i=i+3)
        {
                c._0=Caras[i];
                c._1=Caras[i+1];
                c._2=Caras[i+2];
                caras.push_back(c);
        }


}

_objeto& _objeto::operator=(const _objeto &obj)
{
        vertices=obj.vertices;
        caras=obj.caras;
}
//*************************************************************************
// Clase revolucion
//*************************************************************************

_revolucion::_revolucion(_objeto &objetoPly, int eje, float numPasos)
{

        vertices = objetoPly.vertices;
        caras = objetoPly.caras;
        numPerfil=numPasos;
        float angulo = (2 * M_PI )/numPerfil;
        numVerticesPerfil = vertices.size();

        if (eje == X)
                rotarX(angulo);
        else if (eje == Y)
                rotarY(angulo);
        else if (eje == Z)
                rotarZ(angulo);

        getPerfilVertices();
        getPerfilCaras();
        getTapas(eje);

}


void _revolucion::getPerfilVertices()
{
        // numPerfil -1 porque no hay que generar nuevo perfil para el ultimo perfil
        for (int i = 0; i < numPerfil-1; i++)
        {
                for (int j = 0; j < numVerticesPerfil; j++)
                {
                        _vertex3f verticeActual = vertices[i*numVerticesPerfil+j];
                        _vertex3f nuevoVertice;

                        nuevoVertice = verticeActual * matrizObj;

                        vertices.push_back(nuevoVertice);


                }
        }

}

void _revolucion::getPerfilCaras()
{
        caras.clear();
        int verticesTotal = vertices.size();
        int verticeAux1 , verticeAux2;
        for (int i = 0; i < numPerfil; i++)
        {
                for (int j = 0; j < numVerticesPerfil -1; j++)
                {
                        verticeAux1 = i*numVerticesPerfil+j;
                        verticeAux2 = i*numVerticesPerfil+j+1;
                        _vertex3i caraAux;

                        //cara 1
                        caraAux._0 = verticeAux1; //1er vertice del triangulo(perfil actual)
                        caraAux._1 = verticeAux2; //2o vertice del triangulo (perfil actual)
                        caraAux._2 = (verticeAux1 + numVerticesPerfil)%verticesTotal; //3er vertice del triangulo (perfil siguente)

                        caras.push_back(caraAux);


                        //cara2
                        caraAux._0 = verticeAux2; //1er vertice del triangulo(perfil actual)
                        caraAux._1 = (verticeAux2 + numVerticesPerfil)%verticesTotal; //2o vertice del triangulo (perfil siguiente)
                        caraAux._2 = (verticeAux1 + numVerticesPerfil)%verticesTotal; //3er vertice del triangulo (perfil siguente)

                        caras.push_back(caraAux);

                }
        }

}

void _revolucion::getTapas(int eje)
{
        int numVertices=vertices.size();//numeros de vertice antes de añadir los vertices de las tapas
        //obtener vertice centrar del eje
        _vertex3f verticeTapaArriba = _vertex3f(0.0,0.0,0.0);
        _vertex3f verticeTapaAbajo = _vertex3f(0.0,0.0,0.0);
        if(eje == X){
                verticeTapaAbajo.x = vertices[0].x;
                verticeTapaArriba.x = vertices[numVerticesPerfil-1].x;
        }
        else if(eje == Y){
                verticeTapaAbajo.y = vertices[0].y;
                verticeTapaArriba.y = vertices[numVerticesPerfil-1].y;
        }
        else{
                verticeTapaAbajo.z = vertices[0].z;
                verticeTapaArriba.z = vertices[numVerticesPerfil-1].z;
        }

        vertices.push_back(verticeTapaAbajo);
        vertices.push_back(verticeTapaArriba);



        //contruir caras de la tapar
        int verticePerfilActualAbajo, verticePerfilSiguienteAbajo, verticeCentralAbajo;
        int verticePerfilActualArriba, verticePerfilSiguienteArriba, verticeCentralArriba;
        verticeCentralAbajo=vertices.size()-2;
        verticeCentralArriba=vertices.size()-1;
        for (int i =0; i < numPerfil; i++ )
        {
                //tapa abajo
                verticePerfilActualAbajo=i*numVerticesPerfil;
                verticePerfilSiguienteAbajo=((i+1)*numVerticesPerfil)%numVertices;
                _vertex3i caraTapaAbajo = _vertex3i(verticePerfilActualAbajo,verticeCentralAbajo, verticePerfilSiguienteAbajo );
                caras.push_back(caraTapaAbajo);
        }
        for (int i =0; i < numPerfil; i++ )
        {
                //tapa arriba
                verticePerfilActualArriba=(i*numVerticesPerfil)+numVerticesPerfil-1;
                verticePerfilSiguienteArriba=(((i+1)*numVerticesPerfil)%numVertices)+numVerticesPerfil-1;

                _vertex3i caraTapaArriba = _vertex3i(verticePerfilActualArriba, verticePerfilSiguienteArriba, verticeCentralArriba);
                caras.push_back(caraTapaArriba);
        }
}


void _revolucion::rotarX(float angulo){

	matrizObj.matrizIdentidad();

	// Casos especiales en la matriz de rotación
	matrizObj.set(1,1,cos(angulo));
	matrizObj.set(1,2,-sin(angulo));
	matrizObj.set(2,1, sin(angulo));
	matrizObj.set(2,2, cos(angulo));
}

void  _revolucion::rotarY(float angulo){

	matrizObj.matrizIdentidad();

	// Casos especiales en la matriz de rotación
	matrizObj.set(0,0,cos(angulo));
	matrizObj.set(0,2, -sin(angulo));
	matrizObj.set(2,0, sin(angulo));
	matrizObj.set(2,2,cos(angulo));
}

void  _revolucion::rotarZ(float angulo){

	matrizObj.matrizIdentidad();

	// Casos especiales en la matriz de rotación
	matrizObj.set(0,0, cos(angulo));
	matrizObj.set(0,1, -sin(angulo));
	matrizObj.set(1,0,sin(angulo));
	matrizObj.set(1,1, cos(angulo));
}


//*************************************************************************
// Clase barrido
//*************************************************************************

_barrido::_barrido(_objeto &objetoPly, int numTras, float dist, int eje)
{
        vertices=objetoPly.vertices;
        numTraslados=numTras;
        distancia=dist;
        numVertices=vertices.size();
        traslado(eje,distancia);
        getPerfilVertices();
        getPerfilCaras();
        getTapas();


}

void  _barrido::traslado(int eje, float distancia){

	matrizObj.matrizIdentidad();

	// Casos especiales en la matriz de rotación
        if(eje == X)
	       matrizObj.set(3,0,distancia);
        else if(eje==Y)
	       matrizObj.set(3,1, distancia);
        else if(eje == Z)
	       matrizObj.set(3,2,distancia);
}



void _barrido::getPerfilVertices()
{
        // numPerfil -1 porque no hay que generar nuevo perfil para el ultimo perfil
        for (int i = 0; i < numTraslados; i++)
        {
                for (int j = 0; j < numVertices; j++)
                {
                        _vertex3f verticeActual = vertices[i*numVertices+j];
                        _vertex3f nuevoVertice;

                        nuevoVertice = verticeActual * matrizObj;

                        vertices.push_back(nuevoVertice);


                }
        }

}

void _barrido::getPerfilCaras()
{
        caras.clear();
        int verticesTotal = vertices.size();
        int verticeAux1 , verticeAux2;
        for (int i = 0; i < numTraslados; i++)
        {
                for (int j = 0; j < numVertices  ; j++)
                {
                        verticeAux1 = i*numVertices+j;
                        verticeAux2 = i*numVertices+j+1;
                        _vertex3i caraAux;

                        //cara 1
                        caraAux._0 = verticeAux1;
                        caraAux._1 = verticeAux2;
                        caraAux._2 = (verticeAux1 + numVertices)%verticesTotal;

                        caras.push_back(caraAux);


                        //cara2
                        caraAux._0 = verticeAux2;
                        caraAux._1 = (verticeAux2 + numVertices)%verticesTotal;
                        caraAux._2 = (verticeAux1 + numVertices)%verticesTotal;

                        caras.push_back(caraAux);

                }
        }
        caras.pop_back();
        _vertex3i caraAux;

        //cara 1
        caraAux._0 = numVertices;
        caraAux._1 = numVertices -1;
        caraAux._2 = 0;
        caras.push_back(caraAux);

}

void _barrido::getTapas()
{
        int last=vertices.size()-1;
        float maxX,maxY,maxZ;
        float minX,minY,minZ;

        maxX=vertices[0].x;
        minX=vertices[0].x;

        maxY=vertices[0].y;
        minY=vertices[0].y;

        maxZ=vertices[0].z;
        minZ=vertices[0].z;

        float x,y,z;
        for (int i = 1; i < numVertices; i++)
        {
                x = vertices[i].x;
                y = vertices[i].y;
                z = vertices[i].z;

                if (x > maxX)
                        maxX=x;
                else if(x < minX)
                        minX=x;

                if (y > maxY)
                        maxY=y;
                else if(y < minY)
                        minY=y;

                if (z > maxZ)
                        maxZ=z;
                else if(z < minZ)
                        minZ=z;

        }

        _vertex3f verticeCentro = _vertex3f((maxX+minX)/2,(maxY+minY)/2,(maxZ+minZ)/2);
        vertices.push_back(verticeCentro);

        maxX=vertices[last].x;
        minX=vertices[last].x;

        maxY=vertices[last].y;
        minY=vertices[last].y;

        maxZ=vertices[last].z;
        minZ=vertices[last].z;


        for (int i = 1; i < numVertices; i++)
        {
                x = vertices[last-i].x;
                y = vertices[last-i].y;
                z = vertices[last-i].z;

                if (x > maxX)
                        maxX=x;
                else if(x < minX)
                        minX=x;

                if (y > maxY)
                        maxY=y;
                else if(y < minY)
                        minY=y;


                if (z > maxZ)
                        maxZ=z;
                else if(z < minZ)
                        minZ=z;

        }

         verticeCentro = _vertex3f((maxX+minX)/2,(maxY+minY)/2,(maxZ+minZ)/2);
        vertices.push_back(verticeCentro);

        int actual, siguiente, centro;
        centro = last+1;
        for (int i = 0; i < numVertices; i++)
        {
                actual = i;
                siguiente = (i+1)%numVertices;
                _vertex3i caraAux = _vertex3i(actual, siguiente, centro);
                caras.push_back(caraAux);

        }

        centro =last+2;
        for (int i = 0; i < numVertices -1; i++)
        {
                actual = last - i -1;
                siguiente = last -i ;
                _vertex3i caraAux = _vertex3i(actual,siguiente,centro);
                caras.push_back(caraAux);

        }

        actual = last;
        siguiente = last-numVertices +1;
        _vertex3i caraAux = _vertex3i(actual,siguiente,centro);
        caras.push_back(caraAux);


}
