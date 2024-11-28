
#include <iostream>
#include "UserManager.h"
#include "ContentManager.h"
#include "RecommendationSystem.h"
#include "Graph.h"
#include <vector>
#include <algorithm>
using namespace std;

void displayMenu(){

    ContentManager content;
    Graph graph;
    UserManager user;
    //RecommendationSystem recommendations;

    int choiceM,choice;
    int index;

    string category,newContent, interest, user2,usuario,contrasenia;
    vector<string> contrasenias;
    vector<string> usuarios;
    //vector<string> recomendaciones;
    vector<string> contenidoCat;
    vector<string> interesesUser;
    vector<string> friends;
    choiceM = 0;
    while(choiceM!=3){
        cout<<endl;
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
            cout << "Ingrese su contrasena" <<endl;
            cin>>contrasenia;
            auto it = find(usuarios.begin(),usuarios.end(),usuario);
            auto it_1 = find(contrasenias.begin(), contrasenias.end(), contrasenia);

            if (it != usuarios.end() || it_1 != contrasenias.end()) {
            int index = distance(usuarios.begin(), it);
            if(contrasenia == contrasenias[index]){
                    choice = 0;
                    while(choice != 7){
                        cout<<endl;
                        cout << "............ MENU ..........."<<endl;
                        cout << "1. Crear amistad" <<endl;
                        cout << "2. Agregar interes a mi perfil" <<endl;
                        cout << "3. Agregar contenido" <<endl;
                        cout<<  "4. Ver contenido por categoria"<<endl;
                        cout << "5. Ver mis intereses" <<endl;
                        //cout<<  "6. Ver recomendaciones"<<endl;
                        cout<<  "6. Ver amigos"<<endl;
                        cout << "7. Salir" <<endl<<endl;

                        cout <<"Seleccione una opcion: ";
                        cin >> choice;

                        switch(choice){
                            case 1: {
                                cout << "Ingrese el usuario a agregar" << endl;
                                string user2; // Declare `user2` inside this case
                                cin >> user2;
                                auto it = find(usuarios.begin(), usuarios.end(), user2); // Declare `it` inside this case
                                if (it != usuarios.end()) {
                                    graph.addEdge(usuario, user2); // Add edge if the user exists
                                    cout << "Usuario agregado como amigo." << endl;
                                } else {
                                    cout << "Usuario no encontrado." << endl;
                                }
                                break;
                            }
                            case 2:
                                cout<<"Ingrese el interes que deseas agregar"<<endl;
                                cin>>interest;
                                user.addInterest(usuario,interest);
                                break;
                            case 3:
                                cout<<"Ingrese su categoria (belleza, deportes, educativo, etc)"<<endl;
                                cin>>category;
                                cout<<"Ingrese el contenido que deseas agregar"<<endl;
                                cin>>newContent;
                                content.addContent(category,newContent);
                                break;
                            case 4:
                                cout<<"Ingrese la categoria de su interes (belleza, deportes, educativo, etc)"<<endl;
                                cin>>category;
                                contenidoCat = content.getContentByCategory(category);

                                if (contenidoCat.empty()) {
                                    cout << "No se encontro contenido para la categoria '" << category << "'." << endl;
                                } else {
                                    cout << "Por categoria encontramos:" << endl;
                                    for (int i = 0; i < contenidoCat.size(); i++) {
                                        cout << contenidoCat[i] << endl;
                                    }
                                }

                                break;
                            case 5:
                                interesesUser=user.getInterests(usuario);
                                cout<<"Tus intereses:"<<endl;
                                for(int i = 0;i<interesesUser.size();i++){
                                    cout<<interesesUser[i]<<endl;
                                }
                                break;
                            //case 6:
                                /*friends = graph.BFS(usuario);
                                cout<<"friends "<< friends.size()<<endl;
                                recomendaciones = recommendations.recommendContent(friends); //ESTA SECCION NO FUNCIONA, NO ENCUENTRA LOS USUARIOS EN USERS
                                cout<<"Recomendaciones segun tus amigos:"<<endl;
                                for(int i = 0;i<recomendaciones.size();i++){
                                   cout<<recomendaciones[i]<<endl;
                                }*/
                                //break;
                            case 6:
                                graph.BFS(usuario);
                                break;

                            default:
                                cout << "Saliendo del sistema..."<<endl;
                                break;
                        }

                    }




        }
        }else{
            if(it == usuarios.end() || it_1 == contrasenias.end()){
                cout<<"Los datos no coinciden"<<endl;

            }
        }
         
        }


         if(choiceM==2){
            cout<<endl;
            cout << "Ingrese su usuario" <<endl;
            cin>>usuario;
            cout << "Ingrese su contrasena" <<endl;
            cin>>contrasenia;
            auto it = find(usuarios.begin(),usuarios.end(),usuario);

            if(it == usuarios.end()){
                usuarios.push_back(usuario);
                contrasenias.push_back(contrasenia);
                user.addUser(usuario);
            }
                else{

                cout << "El usuario esta en uso" <<endl<<endl;
            }


            }else{
                if(choiceM==3){
                    cout<<endl;
                    cout<< "Saliendo del sistema..."<<endl<<endl;
                }
            }


}
}
