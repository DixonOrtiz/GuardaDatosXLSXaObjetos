#pragma once
#include <string>

class Docente{
    private:
        std::string codigo_curso;
        int id_docente;
        int bloques_disponibles;
    
    public:
        Docente(std::string, int, int);
        ~Docente();
        void mostrarDatos();

};