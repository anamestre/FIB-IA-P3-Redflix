#include <iostream>
#include <vector>
using namespace std;
#include <random>
#include <fstream>

int main() {
	ofstream fichero_salida;
	fichero_salida.open("init.pddl");

	std::random_device rd;
	std::mt19937 eng(rd()); 
	std::uniform_int_distribution<> distr(1, 15); 
	int contenidos = distr(eng);  
	vector<string> contenidoss (contenidos);
	fichero_salida << "(define (problem extensio4) (:domain planificador)" << endl;
	fichero_salida << "		(:objects ";	
	for(int i = 0; i < contenidos; ++i) {
    	string aux = "";	
    	string contenido = "c";
    	aux.append(contenido);
    	contenidoss[i] = aux.append(to_string(i));
    	fichero_salida <<	contenidoss[i] << " ";	
	}	
	fichero_salida << "- contenido" << endl;
	fichero_salida << "		         ";
	vector<string> dias (contenidoss.size());
	for(int i = 0; i < contenidoss.size(); ++i) {
    	string aux = "";	
    	string diass = "d";
    	aux.append(diass);
    	dias[i] = aux.append(to_string(i));
    	fichero_salida <<	dias[i] << " ";	
	}
	fichero_salida << "- dia)" << endl;
	fichero_salida << "(:init" << endl;
	int contenidos_ = contenidos;
	int i = 0;
	while(i < contenidoss.size() and contenidos_ != 0) {
		std::uniform_int_distribution<> dista(1, contenidos_); 
		std::uniform_int_distribution<> rand(1, dista(eng));
		int series = dista(eng);
		contenidos_ = contenidos_ - series;
		int j = 0;
		if(series == 1 and i == 0) break;
		else if(series == 2 and i == 0) {
			fichero_salida << "(predecesores " << contenidoss[i] << " " << contenidoss[i+1] << ")" << endl;
			++i;
			j = j + 2;
		}
		while(j+1 != series and series != 1 and series != 2) {
			if(i == rand(eng) or j == rand(eng)) {
			++i; ++j;
			}
			else{
				fichero_salida << "(predecesores " << contenidoss[i] << " " << contenidoss[i+1] << ")" << endl;
				++j;
				++i;
			}
			
		} 
	}
	std::uniform_int_distribution<> dist(1, contenidos); 
	int visto_ = dist(eng); 
	vector<string> visto (visto_);
	for(i = 0; i < visto_; ++i){
		std::random_device rd;
		std::mt19937 eng(rd()); 
		std::uniform_int_distribution<> distr(1, visto_);
		int vistoo = distr(eng) - 1; 
		fichero_salida << "(visto " << contenidoss[vistoo] << ")" << endl;
		visto[i] = contenidoss[vistoo];
	}
	std::uniform_int_distribution<> dis(1, contenidos); 
	int ver_ = dis(eng); 
	vector<string> ver (ver_);
	for(i = 0; i < ver_; ++i){
		std::random_device rd;
		std::mt19937 eng(rd()); 
		std::uniform_int_distribution<> distr(1, visto_);
		int verr = distr(eng) - 1; 
		fichero_salida << "(ver " << contenidoss[verr] << ")" << endl;
		ver[i] = contenidoss[verr];
	}
	for(i = 0; i < dias.size(); ++i){
		fichero_salida << "(= (ordenDia " << dias[i] << ") " << i<< ")" << endl;
	}
	for(i = 0; i < contenidoss.size(); ++i){
		fichero_salida << "(= (ultimoDia " << contenidoss[i] << ") " << 0 << ")" << endl;
	}
	for(i = 0; i < contenidoss.size(); ++i){
		std::uniform_int_distribution<> dist(1, 200); 
		int conn = dist(eng); 
		fichero_salida << "(= (minutosContenido" << contenidoss[i] << ") " << conn << ")" << endl;
	}
	for(i = 0; i < contenidoss.size(); ++i){
		fichero_salida << "(= (minutosDia " << contenidoss[i] << ") " << 0 << ")" << endl;
	}

	for(i = 0; i < contenidoss.size(); ++i){
		fichero_salida << "(= (predecesoresAsignados " << contenidoss[i] << ") " << 0 << ")" << endl;
	}

	fichero_salida << ")" << endl;
	fichero_salida << endl;
	fichero_salida << " (:goal (and (forall (?x - contenido) (not (ver ?x))))))" << endl;
}
