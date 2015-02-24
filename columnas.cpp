#include <iostream>
#include <cstring>
#include <array>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]){
	string continuar;
	do{
		int tamA, tamB;
		cout << "Ingrese el tamano de la columna A: ";
		cin >> tamA;
		cout << endl;
		cout << "Ingrese el tamano de la columna B: ";
		cin >> tamB;
		cout << endl;
		char* columnasA[tamA];
		char* columnasB[tamB];
		char palabra[80];
		cout << "Palabras columnas A:" << endl;
		for (int i = 0; i < tamA; ++i){
			cout << "\tcolumnasA " << i+1 << ": ";
			cin >>palabra;
			cout << endl;
			columnasA[i] = new char[strlen(palabra)+1];
			strcpy(columnasA[i], palabra);
		}
		cout << "Palabras columnas B:" << endl;
		for (int i = 0; i < tamB; ++i){
			cout << "\tcolumnasB " << i+1 << ": ";
			cin >>palabra;
			cout << endl;
			columnasB[i] = new char[strlen(palabra)+1];
			strcpy(columnasB[i], palabra);
		}
		char s;
		int a, b, cont = 1;
		vector< vector<int> > respuestas;
		vector<int> numero;
		cout << endl << endl << "Respuestas: " << endl;
		for (int i = 0; i < cont; ++i){
			cout << "columnaA: ";
			cin >> a ;
			cout << endl << "columnaB: ";
			cin >> b;
			cout << endl;
			vector<int> numero;
			numero.push_back(b);
			respuestas.push_back(numero);
			respuestas[i][0] = a;
			respuestas[i][1] = b;
			cout << "s/n: ";
			cin >> s;
			if(s == 's')
				cont++;
		}
		for (int i = 0; i < respuestas.size(); ++i){
			for (int j = 0; j < respuestas[i].size(); ++j){
				cout << respuestas[i][j] << " ";
			}
			cout << endl;
		}
		

		int res1, res2;
		vector< vector<int> > ingresados;
		do{
			cout << "columnasA: " << endl;
			for (int i = 0; i < tamA; ++i){
				cout << "\t" << i+1 << ". " <<columnasA[i] << endl;
			}
			cout << endl << "columnasB: " << endl;
			for (int i = 0; i < tamB; ++i){
				cout << "\t" << i+1 << ". " <<columnasB[i] << endl;
			}
			cout << "Ingrese su respuesta: " << endl;
			cout << "A-";
			cin >> res1;
			cout << "B-";
			cin >> res2;
			cout << "s/n: ";
			vector<int> numero;
			numero.push_back(res2);
			ingresados.push_back(numero);
			ingresados[ingresados.size() - 1][0] = res1;
			ingresados[ingresados.size() - 1][1] = res2;
			cin >> s;
		}while(s == 's');
		int aciertos = 0, palbras = 0;
		for (int m = 0; m < respuestas.size(); ++m){
			for (int n = 0; n < respuestas[m].size(); ++n){
				palbras++;
			}
		}
		for (int i = 0; i < ingresados.size(); ++i){
			for (int j = 0; j < ingresados[i].size(); ++j){
				if(ingresados[i][0] == respuestas[j][0]){
					cout << "i es verdadero" << endl;
					if(ingresados[i][1] == respuestas[j][1]){
						cout << "j es verdadero" << endl;
						aciertos++;
					}
				}
			}
		}
		double por = ((double)aciertos/(double)palbras) * 100;
		cout << "Aciertos: " << aciertos << endl << "Numero total de respuestas: " << palbras << endl << "Porcentaje de buenas: " << por << endl;
		cout << "Seguir jugando? [si/no]";
		cin >> continuar;
	}while(continuar == "si");
	return 0;
}