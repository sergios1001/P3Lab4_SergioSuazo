//Clases con conjunto

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string.h> 
#include <stdlib.h>

#ifndef PERSONA_CPP
#define PERSONA_CPP



using namespace std;

class Persona{
	
      private:
      	
              string nombre;
              string apellido;
              string contra;
              int llave;
              vector<string> mensajes;
              
      public:
      	
            Persona(){}
             
			Persona(string nombre, string apellido, string contra){
				this->nombre.assign(nombre);
            	this->apellido.assign(apellido); 
            	this->contra.assign(contra); 
            	llave=rand()% 15 + 1 ; 
            	
			}
             
            void setNombre(string nombre){
                this->nombre.assign(nombre);
            }
             
            string getNombre(){
                return this->nombre;
            }
             
            void setApellido(string apellido){
                this->apellido.assign(apellido);
            }
             
            string getApellido(){
                return this->apellido;
            }
			
			void setContra(string contra){
				this->contra.assign(contra);
			}  
			
			string getContra(){
				return this->contra;
			}
			
			int getLlave()
			{
				return this->llave;
			}
			
			vector<string> getMensajes() {
        		return mensajes;
    		}
    		
    		void setMensaje(string mensaje) {
        		this->mensajes.push_back(mensaje);
			}
    		
            void print(){
                cout<<setw(15)<<nombre;
				cout<<setw(15)<<apellido<<endl;

            } 
             
            ~Persona(){}	     
};
#endif
