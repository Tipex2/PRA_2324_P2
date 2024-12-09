#include "DyV.h"
#include <iostream>
#include <vector>

int main(){
	std::vector<int> vector = {1, 3, 9, 12, 4, 5, 8, 7};
	/*int x = 5;
	int resultado = BusquedaBinaria(x, vector, 0, vector.size() - 1);

	if (resultado != -1) {
		std::cout << "Valor encontrado en la posición: " << resultado << std::endl; } else {
		std::cout << "Valor no encontrado\n";
		}
*/
	std::cout << "Vector original: ";
	for (int val : vector) {
		std::cout << val << " ";
	}
	std::cout << "\n";

	QuickSort(vector, 0, vector.size() - 1);

	std::cout << "Vector ordenado: ";
	for (int val : vector) {
		std::cout << val << " ";
	}
	std::cout << "\n";

	return 0;
}
