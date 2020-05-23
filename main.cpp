#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>
#include "Persona.cpp"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu(){
	int retValue=0;
	
	while(retValue < 1 || retValue > 5){
		
		cout<<"       Messenger Service"<<endl
			<<"1.- Registrarse"<<endl
			<<"2.- Ingresar"<<endl
			<<"3.- Salir"<<endl
			<<"Ingrese una opcion entre 1 y 3: ";
			
			cin>>retValue;

			
			if(retValue >= 1 && retValue <= 5){
				break;
			}
				
			else{
						
				cout<<endl<<"Opcion incorrecta, elija nuevamente "<<endl;
			}
					
	}//end while
	
	
	return retValue;
}

vector <Persona*>  personas;

string cifrado(int llave, string mensaje, bool encrypt)
{	
	string encriptado;
	char ascii;
	int num_ascii;
	if(llave==0)
	{
		return mensaje;
	}
	else
	{
		if(encrypt)
		{
			if(mensaje.size()<llave)
			{
				return cifrado(llave-1,mensaje,encrypt);
			}
			else
			{
				int track=0;
				bool up=true;
				for(int i=0;i<mensaje.size();i++)
				{
					if(up)
					{
						ascii=mensaje[i];
						num_ascii=ascii;
						num_ascii+=llave;
						ascii=num_ascii;
						encriptado+=ascii;
						track++;
						if(track=llave)
						{
							track=0;
							up=false;
						}
					}
					else
					{
						ascii=mensaje[i];
						num_ascii=ascii;
						num_ascii-=llave;
						ascii=num_ascii;
						encriptado+=ascii;
						track++;
						if(track=llave)
						{
							track=0;
							up=true;
						}
					}
				}
				return cifrado(llave-1,encriptado,encrypt);
			}
		}
		else
		{
			if(mensaje.size()<llave)
			{
				return cifrado(llave-1,mensaje,encrypt);
			}
			else
			{
				int track=0;
				bool up=false;
				for(int i=0;i<mensaje.size();i++)
				{
					if(up)
					{
						ascii=mensaje[i];
						num_ascii=ascii;
						num_ascii+=llave;
						ascii=num_ascii;
						encriptado+=ascii;
						track++;
						if(track=llave)
						{
							track=0;
							up=false;
						}
					}
					else
					{
						ascii=mensaje[i];
						num_ascii=ascii;
						num_ascii-=llave;
						ascii=num_ascii;
						encriptado+=ascii;
						track++;
						if(track=llave)
						{
							track=0;
							up=true;
						}
					}
				}
				return cifrado(llave-1,encriptado,encrypt);
			}
		}
	}
}

int main(int argc, char** argv) {
	int option=0;
	while( option != 3 ) {
		
		switch( option = menu() ){ 
		
			case 1:{
				string nombre,apellido,contra;
				cout<<"Nombre: ";
				cin>>nombre;
				cout<<"Apellido: ";
				cin>>apellido;
				cout<<"Contraseña: ";
				cin>>contra;

				personas.push_back(new Persona(nombre,apellido,contra));
				cout<<"Se registro exitosamente"<<endl;
				
				break;
			}
			case 2:{
				string nombre, contra;
				cout<<"Ingrese su nombre: ";
				cin>>nombre;
				cout<<"Ingrese su contraseña: ";
				cin>>contra;
				bool login;
				for(int i=0;i<personas.size();i++)
				{
					
					if(nombre==personas[i]->getNombre()&&contra==personas[i]->getContra())
					{
						login=true;
						int accion=5;
						while(accion!=0)
						{
							cout<<"       Bienvenido "<< personas[i]->getNombre()<<endl
							<<"1.- Enviar Mensaje"<<endl
							<<"2.- Ver mensajes"<<endl
							<<"3.- Ver llave"<<endl
							<<"0.- Salir"<<endl
							<<"Ingrese su opcion: ";
							cin>>accion;
							
							switch (accion)
							{
								case 1:
									{
										string destino;
										bool sent;
										cout<<"Ingrese el destinatario: ";
										cin>>destino;
										for(int j=0;j<personas.size();j++)
										{
											if(destino==personas[j]->getNombre())
											{
												string mensaje;
												cout<<"Ingrese el mensaje: ";
												cin>>mensaje;
												string encriptado;
												encriptado=cifrado(personas[j]->getLlave(),mensaje,true);
												personas[j]->setMensaje(encriptado);
												sent=true;
														
											}
											
										}
										if(sent)
										{
											cout<<"Mensaje enviado exitosamente"<<endl;
										}
										else
										{
											cout<<"El destinatario no existe"<<endl;
										}
										break;
									}
									
								case 2:
								{
									cout<<"Mis mensajes"<<endl;
									if(personas[i]->getMensajes().size()!=0)
									{
										for(int j=0;j<personas.size()-1;j++)
										{
											cout<<j<<"- "<<personas[i]->getMensajes()[j]<< endl;
										}
										int seleccion;
										cout<<"Seleccione un mensaje para desencriptar: ";
										cin>>seleccion;
										if(seleccion<personas[i]->getMensajes()[seleccion].size())
										{
											string decrypt;
											decrypt=cifrado(personas[i]->getLlave(),personas[i]->getMensajes()[seleccion],false);
											
											cout<<"El mensaje es: "<<decrypt<< endl;
										}
										else
										{
											cout<<"Selecciono un mensaje invalido "<<endl;
										}
										
									}
									else
									{
										cout<<"No tiene mensajes"<<endl;
									}
									
									break;
								}
								
								case 3:
								{
									cout<<"Mi llave: "<<personas[i]->getLlave()<<endl;
									break;
								}
							}
						}
						
					}
					
				}
				if(!login)
				{
					cout<<"Usuario o contraseña incorrectas, intente nuevamente "<<endl;
				}
				
				break;	
			} 
			    
			case 3:{

				//salir
				cout<<"Saliendo del programa..."<<endl;
				break;

			}
						
		}//switch
	
	}//while
	return 0;
}
