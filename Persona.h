#ifndef PERSONA_H
#define PERSONA_H
#include <vector>
#include <string>
using namespace std;

class Persona
{
	public:
		Persona();
		
		
		Persona(string,string,string);
		
		
		
		
		~Persona();
	protected:
		int llave;
		vector<string> registro;
		string nombre,apellido,contra;
		
};

#endif
