#include <iostream>
#include <vector>
using namespace std;
#include <random>
#include <fstream>

int main() {
	std::random_device rd;
	std::mt19937 eng(rd()); 
	std::uniform_int_distribution<> distr(1, 15); 
	int contenidos = distr(eng);  
	vector<string> contenidoss (contenidos);
	cout << "(define (problem test-01) (:domain planificador)" << endl;
	cout << "		(:objects ";	
	for(int i = 0; i < contenidos; ++i) {
    	string aux = "";	
    	string contenido = "c";
    	aux.append(contenido);
    	contenidoss[i] = aux.append(to_string(i));
    	cout <<	contenidoss[i] << " ";	
	}	
	cout << "- contenido" << endl;
	std::uniform_int_distribution<> distrr(contenidos, contenidos*2); 
	int diass = distrr(eng);  
	vector<string> dias(diass);
	cout << "		         ";
	for(int i = 0; i < diass; ++i) {
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
	while(i < contenidoss.size() and contenidos_ != 0) {
		std::uniform_int_distribution<> dista(1, contenidos_); 
		std::uniform_int_distribution<> rand(1, dista(eng));
		int series = dista(eng);
		contenidos_ = contenidos_ - series;
		int j = 0;
		if(series == 1 and i == 0) break;
		else if(series == 2 and i == 0) {
			cout << "(predecesor " << contenidoss[i] << " " << contenidoss[i+1] << ")" << endl;
			++i;
			j = j + 2;
		}
		while(j+1 != series and series != 1 and series != 2) {
			if(i == rand(eng) or j == rand(eng)) {
			++i; ++j;
			}
			else{
				cout << "(predecesor " << contenidoss[i] << " " << contenidoss[i+1] << ")" << endl;
				++j;
				++i;
			}
			
		} 
	}
	/*std::uniform_int_distribution<> dista(1, contenidoss.size()); 
	int series = dista(eng);
	vector<string> cont = contenidoss;
	while(i < series and series !=1) {
		if(series == 2 and i == 0) {
			std::uniform_int_distribution<> dista(1, cont.size()); 
			int pos1 = dista(eng);
			string pre1 = cont[pos1];
			//cont.erase(cont.begin()+pos1);

			std::uniform_int_distribution<> dist(1, cont.size()); 
			int pos2 = dist(eng);
			string pre2 = cont[pos2];
			//cont.erase(pos2);
			cout << "(predecesor " << pre1 << " " << pre2 << ")" << endl;
			break;
		}
		else {
			std::uniform_int_distribution<> dista(1, cont.size()); 
			int pos1 = dista(eng);
			string pre1 = cont[pos1];
			//cont.erase(pos1);

			std::uniform_int_distribution<> dist(1, cont.size()); 
			int pos2 = dist(eng);
			string pre2 = cont[pos2];
			//cont.erase(pos2);
			cout << "(predecesor " << pre1 << " " << pre2 << ")" << endl;
			++i;
		}
	} 	*/
	std::uniform_int_distribution<> dist(1, contenidos); 
	int visto_ = dist(eng); 
	vector<string> visto (visto_);
	for(i = 0; i < visto_; ++i){
		std::random_device rd;
		std::mt19937 eng(rd()); 
		std::uniform_int_distribution<> distr(1, visto_);
		int vistoo = distr(eng) - 1; 
		cout << "(visto " << contenidoss[vistoo] << ")" << endl;
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
		cout << "(ver " << contenidoss[verr] << ")" << endl;
		ver[i] = contenidoss[verr];
	}
	for(i = 0; i < dias.size(); ++i){
		cout << "(dia " << dias[i] << ")" << endl;
	}
	cout << ")" << endl;
	cout << endl;
	cout << " (:goal (and (forall (?x - contenido) (not (ver ?x))) (forall (?n - dia) (dia ?n)))))" << endl;
}
