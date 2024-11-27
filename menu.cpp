
#include <iostream>
#include "UserManager.h"
#include "ContentManager.h"
#include "Graph.h"
#include "RecommendationSystem"
using namespace std;

void displayMenu(){
    int choice;
    do{
        cout << "............ MENU ..........."<<endl;
        cout << "1. Crear amistad" <<endl;
        cout << "2. Agregar contenido" <<endl;
        cout << "3. Agregar interes a un usuario" <<endl;
        cout << "4. Ver recomendaciones" <<endl;
        cout << "5. Agregar usuario" <<endl;
        cout << "6. Salir" <<endl<<endl;

        cout <<"Seleccione una opcion: ";
        cin >> choice;

        switch(choice){
            case 1:
                addFriend();
                break;
            case 2:
                addContent();
                break;
            case 3:
                addInterest();
                break;
            case 4:
                getRecommendations();
                break;
            case 5:
                addUser();
                break;
            case 6:
                cout << "Saliendo del sistema..."<<endl;
                break;
            default:
                cout << "Opcion no valida"<<endl;
                break;
        }
    } 
    while(choice != 5);

    

}
