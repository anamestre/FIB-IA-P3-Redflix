#include <iostream>
#include <vector>
using namespace std;
#include <random>
#include <fstream>

int main() {
	//ofstream cout;
	//cout.open("init.pddl");

	std::random_device rd;
	std::mt19937 eng(rd()); 
	std::uniform_int_distribution<> distr(1, 15); 
	int contenidos = distr(eng);  
	vector<string> contenidoss (contenidos);
	cout << "(define (problem extensio4) (:domain planificador)" << endl;
	cout << "		(:objects ";	
	for(int i = 0; i < contenidos; ++i) {
    	string aux = "";	
    	string contenido = "c";
    	aux.append(contenido);
    	contenidoss[i] = aux.append(to_string(i));
    	cout <<	contenidoss[i] << " ";	
	}	
	cout << "- contenido" << endl;
	cout << "		         ";
	vector<string> dias (contenidoss.size()+1);
	for(int i = 0; i < contenidoss.size()+1; ++i) {
    	string aux = "";	
    	string diass = "d";
    	aux.append(diass);
    	dias[i] = aux.append(to_string(i));
    	cout <<	dias[i] << " ";	
	}
	cout << "- dia)" << endl;
	cout << "(:init" << endl;
	int contenidos_ = contenidos;
	int i = 0;
	int m = 0;
	while(i < contenidoss.size() and contenidos_ != 0) {
		m = 0;
		std::uniform_int_distribution<> dista(1, contenidos_); 
		std::uniform_int_distribution<> rand(1, dista(eng));
		int series = dista(eng);
		contenidos_ = contenidos_ - series;
		int j = 0;
		if(series == 1 and i == 0) {
			cout << "(= (predecesores " << contenidoss[i] << ") " << 0 << ")" << endl;
			break;
		}
		else if(series == 2 and i == 0) {
			cout << "(predecesor " << contenidoss[i] << " " << contenidoss[i+1] << ")" << endl;
			cout << "(= (predecesores " << contenidoss[i] << ") " << 0 << ")" << endl;
			cout << "(= (predecesores " << contenidoss[i+1] << ") " << 1 << ")" << endl;
			++i;
			j = j + 2;
		}
		while(j+1 != series and series != 1 and series != 2) {
			if(i == rand(eng) or j == rand(eng) and j < 1) {
			++i; ++j;
			m = 0;
			}
			else{
				cout << "(predecesor " << contenidoss[i] << " " << contenidoss[i+1] << ")" << endl;
				cout << "(= (predecesores " << contenidoss[i] << ") " << m << ")" << endl;
				++m;
				cout << "(= (predecesores " << contenidoss[i+1] << ") " << m << ")" << endl;
				++j;
				++i;
			}
			
		} 
	}
	std::uniform_int_distribution<> dist(1, contenidos); 
	int visto_ = dist(eng); 
	/*vector<string> visto (visto_);
	for(i = 0; i < visto_; ++i){
		std::random_device rd;
		std::mt19937 eng(rd()); 
		std::uniform_int_distribution<> distr(1, visto_);
		int vistoo = distr(eng) - 1; 
		cout << "(visto " << contenidoss[vistoo] << ")" << endl;
		visto[i] = contenidoss[vistoo];
	}*/
	std::uniform_int_distribution<> dis(1, contenidos); 
	int ver_ = dis(eng); 
	vector<string> ver (ver_);
	for(i = 0; i < ver_; ++i){
		std::random_device rd;
		std::mt19937 eng(rd()); 
		std::uniform_int_distribution<> distr(1, visto_);
		int verr = distr(eng) - 1; 
		cout << "(ver " << contenidoss[verr] << ")" << endl;
		ver[i] = contenidoss[verr];
	}
	for(i = 0; i < dias.size(); ++i){
		cout << "(= (ordenDia " << dias[i] << ") " << i<< ")" << endl;
	}
	for(i = 0; i < contenidoss.size(); ++i){
		cout << "(= (ultimoDia " << contenidoss[i] << ") " << 0 << ")" << endl;
	}
	for(i = 0; i < contenidoss.size(); ++i){
		std::uniform_int_distribution<> dist(1, 200); 
		int conn = dist(eng); 
		cout << "(= (minutosContenido " << contenidoss[i] << ") " << conn << ")" << endl;
	}
	for(i = 0; i < dias.size(); ++i){
		cout << "(= (minutosDia " << dias[i] << ") " << 0 << ")" << endl;
	}

	for(i = 0; i < contenidoss.size(); ++i){
		cout << "(= (predecesoresAsignados " << contenidoss[i] << ") " << 0 << ")" << endl;
	}
	/*for(i = 0; i < contenidoss.size(); ++i){
		cout << "(= (predecesores " << contenidoss[i] << ") " << 0 << ")" << endl;
	}*/

	cout << ")" << endl;
	cout << endl;
	cout << " (:goal (and (forall (?x - contenido) (imply (ver ?x) (contenidoAsignado ?x)))))" << endl;
}