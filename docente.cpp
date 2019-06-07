#include "docente.h"
#include <iostream>

using namespace std;

Docente::Docente(string codigo_curso, int id_docente, int bloques_disponibles){
    this->codigo_curso = codigo_curso;
    this->id_docente = id_docente;
    this->bloques_disponibles = bloques_disponibles;
}

Docente::~Docente(){
}

void Docente::mostrarDatos(){
    cout << "Código curso: " << this->codigo_curso << endl;
    cout << "Id docente: " << this->id_docente << endl;
    cout << "Bloques disponiles: " << this->bloques_disponibles << endl;
}