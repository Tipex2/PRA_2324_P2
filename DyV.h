#include <vector>

template <typename T>
int BusquedaBinaria(const T& x, const std::vector<T>& v, int ini, int fin){
	if (ini > fin) {
		return -1;
	}

	int mid = ini + (fin - ini) / 2;

	if (v[mid] == x) {
		return mid;
	}else if (v[mid] > x) {
		return BusquedaBinaria(x, v, ini, mid-1); //mitad izq
	}else{
		return BusquedaBinaria(x, v, mid+1, fin);
	}
}

template <typename T>
int Partition(std::vector<T>& v, int ini, int fin) {
	T pivot = v[fin];
	int i = ini;

	for (int j = ini; j < fin; j++) {
		if (v[j] <= pivot) {
			T aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			++i;
		}
	}

	T aux = v[i];
	v[i] = v[fin];
	v[fin] = aux;
	
	return i;
}

template <typename T>
void QuickSort(std::vector<T>& v, int ini, int fin){
	if (ini < fin) {
		int pivot = Partition(v, ini, fin);
		QuickSort(v, ini, pivot-1);
		QuickSort(v, pivot+1, fin);
	}
}
