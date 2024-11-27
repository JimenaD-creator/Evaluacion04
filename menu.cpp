
#include <iostream>
#include "UserManager.h"
#include "ContentManager.h"
#include "RecommendationSystem.h"
#include "menu.h"
#include "Graph.h"
#include <vector>
#include <algorithm>
using namespace std;

void displayMenu(){

    ContentManager content;
    Graph graph;
    UserManager user;
    RecommendationSystem recommendations;

    int choiceM,choice;
    int index;
    string category,newContent, interest, user2,usuario,contrasenia;
    vector<string> contrasenias;
    vector<string> usuarios;
    vector<string> recomendaciones;
    vector<string> contenidoCat;
    vector<string> interesesUser;
    choiceM = 0;
    while(choiceM!=3){
        cout << "............ BIENVENIDO A AMIGOS.COM ..........."<<endl;
        cout << "1. Iniciar Sesion" <<endl;
        cout << "2. Crear cuenta (Agregar usuario)" <<endl;
        cout << "3. Salir" <<endl<<endl;
        cout << "Seleccione una opcion: "<<endl;
        cin>>choiceM;

        if(choiceM==1){
            cout << endl;
            cout << "Ingrese su usuario" <<endl;
            cin>>usuario;
            cout << "Ingrese su contraseña" <<endl;
            cin>>contrasenia;
            auto it = find(usuarios.begin(),usuarios.end(),usuario);

            if (it != usuarios.end()) {
            int index = distance(usuarios.begin(), it);
            if(contrasenia == contrasenias[index]){
                    choice = 0;
                    while(choice != 7){
                        cout << "............ MENU ..........."<<endl;
                        cout << "1. Crear amistad" <<endl;
                        cout << "2. Agregar interes a mi perfil" <<endl;
                        cout << "3. Agregar contenido" <<endl;
                        cout<<  "4. Ver contenido por categoria"<<endl;
                        cout << "5. Ver mis intereses" <<endl;
                        cout<<  "6. Ver recomendaciones"<<endl;
                        cout << "7. Salir" <<endl<<endl;

                        cout <<"Seleccione una opcion: ";
                        cin >> choice;

                        switch(choice){
                            case 1:
                                cout<<"Ingrese el usuario a agregar"<<endl;
                                cin>>user2;
                                graph.addEdge(usuario,user2);
                                break;
                            case 2:
                                cout<<"Ingrese el interes que deseas agregar"<<endl;
                                cin>>interest;
                                user.addInterest(usuario,interest);
                                break;
                            case 3:
                                cout<<"Ingrese el contenido que deseas agregar"<<endl;
                                cin>>newContent;
                                cout<<"Ingrese su categoria (belleza, deportes, educativo, etc)"<<endl;
                                cin>>category;
                                content.addContent(category,newContent);
                                break;
                            case 4:
                                cout<<"Ingrese la categoria de tu interes (belleza, deportes, educativo, etc)"<<endl;
                                cin>>category;
                                contenidoCat = content.getContentByCategory(category);
                                cout<<"Por categoria encontramos:"<<endl;
                                for(int i = 0;i<contenidoCat.size();i++){
                                    cout<<contenidoCat[i]<<endl;
                                }

                                break;
                            case 5:
                                interesesUser=user.getInterests(usuario);
                                cout<<"Tus intereses:"<<endl;
                                for(int i = 0;i<interesesUser.size();i++){
                                    cout<<interesesUser[i]<<endl;
                                }
                                break;
                            case 6:
                                recomendaciones = recommendations.recommendContent(usuario);
                                cout<<"Recomendaciones segun tus amigos:"<<endl;
                                for(int i = 0;i<interesesUser.size();i++){
                                   cout<<interesesUser[i]<<endl;
                                }
                                break;
                            case 7:
                                cout << "Saliendo del sistema..."<<endl;
                                break;
                            default:
                                cout << "Opcion no valida"<<endl;
                                break;
                        }

                    }




        }
        }
         if(it == usuarios.end()){
                cout<<"Los datos no coinciden"<<endl;

            }
        }


         if(choiceM==2){
            cout << "Ingrese su usuario" <<endl;
            cin>>usuario;
            cout << "Ingrese su contraseña" <<endl;
            cin>>contrasenia;
            auto it = find(usuarios.begin(),usuarios.end(),usuario);

            if(it == usuarios.end()){
                usuarios.push_back(usuario);
                contrasenias.push_back(contrasenia);
                user.addUser(usuario);
            }
                else{

                cout << "El usuario esta en uso" <<endl;
            }


            }else{
                if(choiceM==3){
                    cout<<endl;
                    cout<< "Saliendo del sistema..."<<endl;
                }
            }


}
}
