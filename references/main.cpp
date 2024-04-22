#include <iostream>


template <typename T>
void pswap(T* pointer1, T* pointer2) {
	T tmp = *pointer1;
	*pointer1 = *pointer2;
	*pointer2 = tmp;
}

template <typename T>
void rswap(T& ref1, T& ref2) {
	T tmp = ref1;
	ref1 = ref2;
	ref2 = tmp;
}
//Задача 1.
void foo(int& var1, int& var2);


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	//Нейтральные указатели
	int* p1 = 0;
	if (p1 != 0)
		std::cout << p1 << std::endl;
	else
		std::cout << "Указатель не инициализирован!\n";

	int* p2 = NULL; // NULL - замена внешнего вида значений (0) обычный ноль.
	if (p2 != NULL)
		std::cout << p2 << std::endl;
	else
		std::cout << "Указатель не инициализирован!\n";

	// использовать нужно только этот способ.
	int* p3 = nullptr;//ptr значение адресного типа
	if (p3 != nullptr)
		std::cout << p3 << std::endl;
	else
		std::cout << "Указатель не инициализирован!\n";
	
	//Указатели констант
	n = 7; m = 15;


	//Указатель на константу. Может быть обьявлен без инициализации 
	// и может менять свое значение в любой момент работы программы,
	//  но с его помощью не получится поменять его значение памяти 
	// на которую он направлен.
	const int* pointer1;
	pointer1 = &n;
	//*pointer1 = 5; ошибка!
	std::cout << *pointer1 << std::endl;
	
	//Константный указатель или указатель-константа.
	// не может быть обьявлен без инициализации 
	// и не может менять своего значения, но с его помощью можно поменять значение памяти
	//  на которую он направлен.
	int* const pointer2 = &n; // другой тип константы
	//pointer2 = &m; //ОШИБКА!
	*pointer2 = 5;
	std::cout << *pointer2 << std::endl;

	// Константный указатель на константу.
	const int* const pointer3 = &m;
	// pointer3 = &m; ОШИБКА!
	// *pointer3 = 42;ОШИБКА!
	std::cout << *pointer3 << std::endl;

	//Ссылки на переменные
	n = 7;
	int& refn = n; // Ссылка, асcоциированная с переменной n
	std::cout << "n = " << n << std::endl;
	std::cout << "refn = " << refn << std::endl;

	n = 15;
	std::cout << "refn = " << refn << std::endl; 

	//Ссылки и функции
	n = 7; m = 15;
	std::cout << n << ' ' << m << std::endl;
	// pswap(&n, &m); //Передаем с амперсантом/ функция работает не удобно
	rswap(n, m); // работает с ссылками.
	std::cout << n << ' ' << m << std::endl;

	//Задача 1. Ссылочная функция.
	std::cout << "Задача 1.\n Введите 2 числа -> ";
	std::cin >> n >> m;
	foo(n, m);
	std::cout << "n = " << n << "; m = " << m << "\n\n"; 


	return 0;
}

void foo(int& var1, int& var2) {
	if (var1 > var2) {
		var1 *= var1;
		var2 *= var2;
		return;
	}
	var1 = 0;
	var2 = 0;
}