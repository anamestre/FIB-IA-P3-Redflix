#include <iostream>
#include <vector>
using namespace std;
#include <random>

//http://stackoverflow.com/questions/5008804/generating-random-integer-from-a-range
//http://www.cplusplus.com/reference/string/string/append/
//Inicialitzacions ja fetes
#include <fstream>
//#include <string> 

ofstream fichero_salida;
fichero_salida.open("inicializacion.txt");
//fichero_salida << ""


int main() {
	vector<pair<string,string>> visto;
	vector<pair<string,string>> para_ver;
	struct serie {
		string nombre;
  		vector<string> capitulos;
  		vector<string> peliculas;
	};
	int i = 0;
    string aux;
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 15); // define the range
    int nseries = distr(eng);  
    vector <serie> ser(nseries);
	cout << "- Las series son: " << endl;
	for(i = 0; i < nseries; ++i){
		aux = "";
		string seriee = "serie";
		aux.append(seriee);
		ser[i].nombre = aux.append(to_string(i));
		cout << ser[i].nombre << " ";
	}
	cout << endl;
	cout << endl;
    int j = 0;   
    while(j < ser.size()) {
    	std::uniform_int_distribution<> distruu(0, 50);
    	int ncapitulos = distruu(eng);  
    	cout << "Los capitulos de la serie " << ser[j].nombre << " son: " << endl;
    	for(i = 0; i < ncapitulos; ++i){
    		aux = "";
			string seriee = "capitulo";
			aux.append(seriee);	
			aux.append(to_string(i));
			ser[j].capitulos.push_back(aux.append(ser[j].nombre));
			cout << ser[j].capitulos[i] << " ";
			aux.erase(0,aux.length()-1);
		}
		cout << endl;
		cout << endl;
    	std::uniform_int_distribution<> distru(0, 10);   
    	int npeliculas = distru(eng);  
    	cout << "Las peliculas de la serie " << ser[j].nombre << " son: " << endl;
		for(i = 0; i < npeliculas; ++i){
			aux = "";
			string seriee = "pelicula";
			aux.append(seriee);
			aux.append(to_string(i));
			ser[j].peliculas.push_back(aux.append(ser[j].nombre));
			cout << ser[j].peliculas[i] << " ";
			aux.erase(0,aux.length()-1);
		}
		cout << endl;
		cout << endl;
		++j;
	}

	cout << "Añadidas capitulos y peliculas" << endl;
    
   j = 0;
   while(j < ser.size()) {
   		int n_capitulos = ser[j].capitulos.size();
   		int n_peliculas = ser[j].peliculas.size();
   		std::uniform_int_distribution<> vist(0, n_capitulos);
   		int ncap = vist(eng);
   		for(i = 0; i < ncap; ++i){
   			cout << "Capítulos vistos de la serie -> " << ser[j].nombre << endl;
   			int ncapp = vist(eng);
   			aux = "";
   			string seri = "capitulo";
   			aux.append(seri);	
   			aux.append(to_string(ncapp));
   			aux.append(ser[j].nombre);
			visto.push_back(make_pair(ser[j].nombre,aux));
			cout << aux << endl;
			cout << j << endl;
   		}
   		std::uniform_int_distribution<> vistt(0, n_peliculas);
   		int npel = vistt(eng);
   		for( i = 0; i < npel; ++i){
   			cout << "Películas vistas de la serie -> " << ser[j].nombre << endl;
   			int npell = vistt(eng);
   			aux = "";
   			string seri_ = "pelicula";
			aux.append(seri_);	
			aux.append(to_string(npell));	
			aux.append(ser[j].nombre);
			visto.push_back(make_pair(ser[j].nombre,aux));
			cout << aux << endl;
   		}	
   		++j;
  }
  j = 0;
  while(j < ser.size()) {
   		int n_capitulos = ser[j].capitulos.size();
   		int n_peliculas = ser[j].peliculas.size();
   		std::uniform_int_distribution<> vist(0, n_capitulos);
   		int ncap = vist(eng);
   		for(i = 0; i < ncap; ++i){
   			cout << "Capítulos que quiere ver de la serie -> " << ser[j].nombre << endl;
   			int ncapp = vist(eng);
   			aux = "";
   			string seri = "capitulo";
   			aux.append(seri);	
   			aux.append(to_string(ncapp));
   			aux.append(ser[j].nombre);
			para_ver.push_back(make_pair(ser[j].nombre,aux));
			cout << aux << endl;
   		}
   		std::uniform_int_distribution<> vistt(0, n_peliculas);
   		int npel = vistt(eng);
   		for( i = 0; i < npel; ++i){
   			cout << "Películas que quiere ver de la serie -> " << ser[j].nombre << endl;
   			int npell = vistt(eng);
   			aux = "";
   			string seri_ = "pelicula";
			aux.append(seri_);	
			aux.append(to_string(npell));	
			aux.append(ser[j].nombre);
			para_ver.push_back(make_pair(ser[j].nombre,aux));
			cout << aux << endl;
   		}	
   		++j;
  }


  cout << "Añadidas las que ha visto y que quiere ver" << endl;

  /////////////////////////////////////////////////////////////////////////////////////// SACAMOS EL COUT DEL MODELO DE INICIALIZACIÓN

    cout << "Definimos los objetos ..." << endl;

    fichero_salida << "(define (problem planifiacion1)" << endl;
    fichero_salida << "	(:domain planificador)" << endl;
    fichero_salida << "(:objects ";
    for (int i = 0; i < ser.size(); ++i){
    	fichero_salida << ser[i].nombre << " ";
    }
    fichero_salida << " - serie" << endl;
    j = 0;
    for (int i = 0; i < ser.size(); ++i){
    	while(j < ser[i].capitulos.size()){
    		fichero_salida << ser[i].capitulos[j] << " ";
    		++j;
    	}
    	j = 0; 	
    }
    fichero_salida << " - capitulo" << endl;
    for (int i = 0; i < ser.size(); ++i){
    	while(j < ser[i].peliculas.size()){
    		fichero_salida << ser[i].peliculas[j] << " ";
    		++j;
    	}
    	j = 0; 	
    }
    fichero_salida << " - pelicula)" << endl;

    cout << "Definimos la inicialización ..." << endl;

    fichero_salida << "(:init" << endl;
    
    for (i = 0; i < ser.size(); ++i){
            fichero_salida << "(serie " << ser[i].nombre << ")" << endl;
    }

    for (i = 0; i < ser.size(); ++i){
            j = 0;
            while (j < ser[i].capitulos.size()){
                    fichero_salida << "(capitulo " << ser[i].capitulos[j] << ")" << endl;
                    ++j;
            }
    }

    for (i = 0; i < ser.size(); ++i){
            j = 0;
            while (j < ser[i].peliculas.size()){
                    fichero_salida << "(pelicula " << ser[i].peliculas[j] << ")" << endl;
                    ++j;
            }
    }

    for (i = 0; i < ser.size(); ++i){
            j = 0;
            while(j < ser[i].capitulos.size()){
                    fichero_salida << "(pertenece " << ser[i].capitulos[j] << " " << ser[i].nombre << ")" << endl;
                    ++j;
            }
            j = 0;
            while (j < ser[i].peliculas.size()){
                    fichero_salida << "(pertenece " << ser[i].peliculas[j] << " " << ser[i].nombre << ")" << endl;
                    ++j;
            }
    }

    for (i = 0; i < ser.size(); ++i){
            cout << "el vector de capitulos es de tamaño: " << ser[i].capitulos.size() << endl;
             if(ser[i].capitulos.size() > 1) {
             	j = 0;
                    while (j < ser[i].capitulos.size()-1) {
                    	cout << j << endl;
                            fichero_salida << "(predecesor " << ser[i].capitulos[j] << " " << ser[i].capitulos[j+1] << ")" << endl;
                            ++j;

                    }
                }
                    cout << "TATATATAT" << endl;
                    bool ppp = true;
                    j = 0;
                     while (j < ser[i].peliculas.size()-1 and ser[i].peliculas.size() > 0) {
                     		cout << "el vector de peliculas es de tamaño" << ser[i].peliculas.size() << endl;
                            if(ser[i].capitulos.size() > 0 and ppp) {
                            		int tam = ser[i].capitulos.size()-1;
                                    fichero_salida << "(predecesor " << ser[i].capitulos[tam] << " " << ser[i].peliculas[j] << ")" << endl;
                                    ppp = false;
                                    cout << j << endl;
                            }
                            else{
                            		cout << j << endl;
                                    fichero_salida << "(predecesor " << ser[i].peliculas[j] << " " << ser[i].peliculas[j+1] << ")" << endl;
                                    ++j;
                            }
                    } 
    }
    for (i = 0; i < visto.size(); ++i){
            fichero_salida << "(visto " <<  visto[i].second << " " << visto[i].first << ")" << endl;
    }

    for (i = 0; i < para_ver.size(); ++i){
            fichero_salida << "(quiere " << para_ver[i].second << " " << para_ver[i].first << ")" << endl;
    }

    cout << "Calculando la meta..." << endl;
    fichero_salida << "(:goal" << endl;
    if(para_ver.size() == 1) fichero_salida << "(visto " << para_ver[1].first << " " << para_ver[2].second << ")" << endl;
    else{
            cout << "(and ";
            for(i = 0; i < para_ver.size(); ++i){
                    fichero_salida << "(visto " << para_ver[i].second << " " << para_ver[i].first << ") ";
            }
            fichero_salida << ")";
    }
    fichero_salida << ")" << endl;
}

fichero_salida.close();



