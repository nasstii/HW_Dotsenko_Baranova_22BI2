#include <iostream>
#include <string>
#include <ctime>
#include <cmath>

void fillArray(int** myArray, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			myArray[i][j] = rand() % 41 + 10;
		}
	}
}
void fullarray(int* array, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << "Enter the element " << i + 1 << " - ";
		std::cin >> array[i];
	}
}
int sortarray(int* arr, int size)
{
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] < arr[j + 1]) {
				// ќбмен элементов
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return 0;
}

int Add(int a, int b)
{
	return a + b;
}

int Min(int a, int b)
{
	return a - b;
}

int Multiply(int a, int b)
{
	return a * b;
}

int Divide(int a, int b)
{
	return a / b;
}


int fullarray2(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << "Ёлемент " << i + 1 << ": ";
		std::cin >> arr[i];
	}
	return 0;
}
void printArray(int** myArray, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << myArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int main() {
	/*task 4*/
	srand(static_cast<unsigned int>(time(0)));
	int rows, cols;
	std::cout << "Enter the rows: ";
	std::cin >> rows;
	std::cout << "Enter the cols: ";
	std::cin >> cols;
	int** myArray = new int* [rows];
	for (int i = 0; i < rows; i++) {
		myArray[i] = new int[cols];
	}
	fillArray(myArray, rows, cols);
	std::cout << "My array:" << std::endl;
	printArray(myArray, rows, cols);
	for (int i = 0; i < rows; i++) {
		delete[] myArray[i];
	}
	delete[] myArray;

	/*task 5*/

	int a = 0;
	int b = 0;
	char operation;

	int (*PtrFnc)(int, int) = nullptr;


	do {
		std::cout << "Enter the a ";
		std::cin >> a;
		std::cout << "Enter the b ";
		std::cin >> b;
		std::cout << "Enter the operation ";
		std::cin >> operation;

		switch (operation) {
		case '+':
			PtrFnc = Add;
			break;
		case '-':
			PtrFnc = Min;
			break;
		case '*':
			PtrFnc = Multiply;
			break;
		case '/':
			if (b != 0) {
				PtrFnc = Divide;
			}
			else {
				std::cout << "division by zero. mistake" << std::endl;
			}
			break;
		default:
			if (operation != ' ') {
				std::cout << "Error: incorrect operation!" << std::endl;
			}
			break;
		}
		std::cout << PtrFnc(a, b);

	} while (operation != ' ');

	/*task 6*/

	int k = 0;
	std::cout << "¬ведите количество k:\n";
	std::cin >> k;
	std::cout << "¬ведите количество элементов массива:\n";
	int size;
	std::cin >> size;
	int* arr = new int[size];
	fullarray2(arr, size);
	sortarray(arr, size);

	int n = size, i = 0, ans = INT_MAX, winSize = 0;
	for (int j = 0; j < n; j++) {
		winSize++;
		if (winSize < k) continue;
		ans = std::min(ans, arr[i] - arr[j]);
		i++;
	}
	std::cout << ans << std::endl;

	/*task 7*/

	int n7;
	std::cout << "Enter the length: "; //длина массива
	std::cin >> n7;

	if (n7 < 1) {
		std::cout << "Error\n";
		return 1;
	}

	int* nums7 = new int[n];
	fullarray(nums7, n7); //заполнение массива

	int lucky7 = 0; //инициализаци€ нужного элемента
	int count7 = 0; // счетчик
	int majorityElement7 = -1;
	for (int i = 0; i < n; i++) { //перебор основных элементов
		count7 = 0;
		for (int j = 0; j < n; j++) { //перебор элементов с которыми сравниваем
			for (int k = 0; k < n; k++) { //перебор дл€ нового массива
				if ((nums7[i] == nums7[j]) && (nums7[k] != nums7[i])) {
					count7 = count7 + 1;
				}
			}
		}
		if (count7 == nums7[i]) {
			lucky7 = nums7[i];
		}
		if (lucky7 > majorityElement7) {
			majorityElement7 = nums7[i];
		}

	}

	if (majorityElement7 != -1) { //вывод результата на экран
		std::cout << "The largest lucky number: " << majorityElement7 << std::endl;
	}
	else {
		std::cout << "The largest lucky number not found." << std::endl;
	}

	delete[] nums7; //освобождение пам€ти

	/*task 8*/

	int n8; //инициализаци€ длины
	int element8 = 0; //инициализаци€ нужного элемента
	std::cout << "Enter the length: ";
	std::cin >> n8;
	if (n8 < 1) {
		std::cout << "Error\n";
		return 1;
	}
	int* nums8 = new int[n];
	fullarray(nums8, n8); //заполнение массива
	sortarray(nums8, n8); //сортировка массивоа
	int key8 = nums8[0], c8 = 0;
	for (int i = 0; i < n8; i++) //нахождение наибольшего элемента
	{
		if (c8 == 0)
			key8 = nums8[i];
		if (nums8[i] == key8)
			c8++;
		else c8--;
	}
	std::cout << "the majority element: " << key8 << std::endl;

	delete[] nums8; //освобождение пам€ти

	return 0;
}