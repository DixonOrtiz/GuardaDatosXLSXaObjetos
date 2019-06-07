#include <iostream>
#include <string>
#include <string.h>
#include "docente.h"
#include <xlsxio_read.h>
#include <vector>

using namespace std;

int main(){
    cout << endl;

    //Se declara el vector donde se almacenan los objetos "Docente"
    vector<Docente> vectorDocentes;
    //Docente que se crea tras cada iteración
    Docente *docenteAuxiliar = NULL;

    xlsxioreader archivoCursos;

    if((archivoCursos = xlsxioread_open("Cursos.xlsx")) == NULL){
        cout << "No se ha podido abrir el archivo." << endl;
        return 1;
    }

    else{    
        char* celda;
        xlsxioreadersheet hoja;
    
        hoja = xlsxioread_sheet_open(archivoCursos, "Secciones", XLSXIOREAD_SKIP_EMPTY_ROWS);
        int numColumna;
        int numFila = 1;
        string codigo_curso_auxiliar;
        int id_docente_auxiliar;
        int bloques_disponibles_auxiliar;
        string char_a_string;

        while(xlsxioread_sheet_next_row(hoja)){
            numColumna = 1;

            while((celda = xlsxioread_sheet_next_cell(hoja)) != NULL){
                if(numFila != 1){
                    //Se obtiene el código del curso
                    if(numColumna == 1){
                        codigo_curso_auxiliar = celda;  
                        free(celda);    
                    }

                    //Se obtiene el id docente
                    if(numColumna == 3){
                        char_a_string = celda;
                        id_docente_auxiliar = stoi(char_a_string);
                        free(celda);    
                    }

                    //Se obtiene los bloques del profesor
                    if(numColumna == 6){
                        char_a_string = celda;
                        bloques_disponibles_auxiliar = stoi(char_a_string);
                        free(celda);    
                    } 
                }    
                numColumna++;
            }

            if(numFila != 1){
                Docente *docenteAuxiliar = new Docente(codigo_curso_auxiliar, id_docente_auxiliar, bloques_disponibles_auxiliar);
                vectorDocentes.push_back(*docenteAuxiliar);
            }            
            numFila++;
        }
        xlsxioread_sheet_close(hoja);
    }

    for(int i = 0; i < vectorDocentes.size(); i++){
        vectorDocentes[i].mostrarDatos();
    }

    cout << vectorDocentes.size() << endl;
    

    cout << endl;
    return 0;
}