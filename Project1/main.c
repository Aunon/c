#include <stdio.h>
#include <math.h>

void C2_b() {
	char ch;
	printf("������һ���ַ� ");
	scanf_s(" %c", &ch);
	if (ch >= 'A' && ch <= 'Z') {
		printf("The character '%c' is a capital letter.\n", ch);
	}
	else if (ch >= 'a' && ch <= 'z') {
		printf("The character '%c' is a small case letter.\n", ch);
	}
	else if (ch >= '0' && ch <= '9') {
		printf("The character '%c' is a digit.\n", ch);
	}
	else if (ch >= 0 && ch <= 47 || ch >= 58 && ch <= 64 || ch >= 91 && ch <= 96 || ch >= 123 && ch <= 127) {
		printf("The character '%c' is a special symbol.\n", ch);
	}
	else {
		printf("The character '%c' does not fall into any of the categories.\n", ch);
	}
}

void C2_c() {
	float hardness, carbonContent, tensileStrength;
	int grade;

	// ��ʾ�û�����Ӳ�ȡ�̼�����Ϳ���ǿ��
	printf("Enter the hardness of the steel: ");
	scanf_s("%f", &hardness);
	printf("Enter the carbon content of the steel: ");
	scanf_s("%f", &carbonContent);
	printf("Enter the tensile strength of the steel: ");
	scanf_s("%f", &tensileStrength);

	// ��ʼ����������
	int condition1 = hardness > 50;
	int condition2 = carbonContent < 0.7;
	int condition3 = tensileStrength > 5600;

	// ���������жϸֵĵȼ�
	if (condition1 && condition2 && condition3) {
		grade = 10;
	}
	else if (condition1 && condition2) {
		grade = 9;
	}
	else if (condition1 && condition3) {
		grade = 8;
	}
	else if (condition2 && condition3) {
		grade = 7;
	}
	else if (condition1 || condition2 || condition3) {
		grade = 6;
	}
	else {
		grade = 5;
	}

	// ����ֵĵȼ�
	printf("The grade of the steel is: %d\n", grade);
}

void C2_d() {
	int lateDays;

	// ��ʾ�û�������������
	printf("Enter the number of days the book is late: ");
	scanf_s("%d", &lateDays);

	// �������������жϷ��������ʾ��Ϣ
	if (lateDays > 30) {
		printf("Your membership will be cancelled.\n");
	}
	else if (lateDays > 10) {
		printf("The fine for returning the book late is 5 rupees.\n");
	}
	else if (lateDays > 5) {
		printf("The fine for returning the book late is 1 rupee.\n");
	}
	else if (lateDays > 0) {
		printf("The fine for returning the book late is 50 paise.\n");
	}
	else {
		printf("No fine for returning the book on time.\n");
	}
}

void C3_Bd() {
	int asciiValue;
	char character;

	// ʹ��whileѭ������ASCIIֵ��0��255
	asciiValue = 0;
	while (asciiValue <= 255) {
		character = (char)asciiValue; // ��ASCIIֵת��Ϊ�ַ�
		printf("%d - %c\n", asciiValue, character);
		asciiValue++; // ����ASCIIֵ
	}
}

int isArmstrong(int number) {
	int originalNumber, remainder, result = 0;
	int n = 0;

	// �������ֵ�λ��
	originalNumber = number;
	while (originalNumber != 0) {
		++n;
		originalNumber /= 10;
	}

	// �����λ���ֵ�n����֮��
	originalNumber = number;
	while (originalNumber != 0) {
		remainder = originalNumber % 10;
		result += remainder * remainder * remainder;
		originalNumber /= 10;
	}

	// ����������ԭ��������һ����ķ˹������
	return result == number;
}

void C3_Be() {
	int number;

	// ��ӡ1��500֮������а�ķ˹������
	printf("Armstrong numbers between 1 and 500 are:\n");
	for (number = 1; number <= 500; number++) {
		if (isArmstrong(number)) {
			printf("%d\n", number);
		}
	}

}

void C3_Bf() {
	int matchsticks = 21; // ��ʼ�������
	int userChoice; // �û���ѡ��
	int computerChoice; // �������ѡ��

	printf("Matchsticks Game\n");
	printf("I will always win!\n\n");

	while (matchsticks > 0) {
		// �û�ѡ������1��4�����
		printf("You have %d matchsticks. How many do you want to pick (1-4)? ", matchsticks);
		scanf_s("%d", &userChoice);

		// ȷ���û�������Ч
		while (userChoice < 1 || userChoice > 4) {
			printf("Invalid choice. Please pick 1, 2, 3, or 4 matchsticks.\n");
			printf("How many do you want to pick (1-4)? ");
			scanf_s("%d", &userChoice);
		}

		// �û����߻��
		matchsticks -= userChoice;
		printf("You picked %d matchsticks.\n", userChoice);

		// �����Ϸ�Ƿ����
		if (matchsticks == 0) {
			printf("You picked the last matchstick and lost the game!\n");
			break;
		}

		// ��������߻��ȷ��ʣ������5�ı���
		if (matchsticks % 5 == 0) {
			computerChoice = 0; // ���������Ҫ�û��
		}
		else if (matchsticks < 5) {
			computerChoice = 0;
		}
		else {
			computerChoice = 5 - matchsticks % 5;
		}
		// ��������߻��
		matchsticks -= computerChoice;
		printf("I picked %d matchsticks.\n", computerChoice);

		
	}
}

void C3_Bh() {
	int decimalNumber;
	printf("Enter an integer: ");
	scanf_s("%d", &decimalNumber); // ��ȡ����

	// ��ӡ�˽��Ƶȼ���
	printf("The octal equivalent of the entered integer (%d) is: ", decimalNumber);
	printf("%o\n", decimalNumber); // ʹ��%o��ʽ������˽�����

	return 0;
}


void C3_Ec(){
	int sum = 0;
	int a = 1;
	for (int i = 1; i <= 7; i++) {
		a *= i;
		sum += i / a;
	}
	printf("ǰ����ĺ�Ϊ%d\n", &sum);
}

void C3_Ed() {
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			for (int k = 1; k <= 3 ; k++) {
				if (i == k || j == k || i==j) {
					continue;
				}
				printf("%d,%d,%d\n", i, j, k);
			}
		}
	}
}

void C3_Ee() {
	for (int j = 0; j < 7; j++) {
		for (int i = 0; i <= 6; i++) {
			if (i +j > 6  ) {
				printf("  ");
				continue;
			}
			char c = 'A' + i;
			printf("%c ", c);
		}
		for (int i = 5; i >= 0; i--) {
			if (i + j > 5) {
				printf("  ");
				continue;
			}
			char c = 'A' + i;
			printf("%c ", c);
		}
		printf("\n");
	}
	
}

int C3_Ef() {
	char ch;

	// ��ӡ�� 'A' �� 'G'
	for (ch = 'A'; ch <= 'G'; ch++) {
		printf("%c\n", ch);
	}

	// �����ӡ�� 'F' �� 'A'
	for (ch = 'F'; ch >= 'A'; ch--) {
		printf("%c\n", ch);
	}

	// �ظ����Σ���ӡ�� 'A' �� 'E'��Ȼ�������ӡ�� 'E' �� 'A'
	for (int i = 0; i < 2; i++) {
		for (ch = 'A'; ch <= 'E'; ch++) {
			printf("%c\n", ch);
		}
		for (ch = 'E'; ch >= 'A'; ch--) {
			printf("%c\n", ch);
		}
	}

	// ��ӡ�� 'A' �� 'A' ���ַ�
	for (int i = 0; i < 4; i++) {
		for (ch = 'A'; ch <= 'A'; ch++) {
			printf("%c\n", ch);
		}
	}

	return 0;
}

void C4_c() {
	int a = 0;
	int num = 0;
	while (1) {
		printf("������һ����\n");
		scanf_s("%d", &num);
		printf("��ѡ���ţ�1-4��\n");
		scanf_s("%d", &a);
		int sum = 1;
		int flag = 0;
		int tmp = 0;
		switch (a) {
			case 1 :
				for (int i = 1; i <= num; i++) {
					sum *= i;
				}
				printf("%d�Ľ׳�Ϊ%d\n",num,sum);
				break;
			case 2:
				if (num < 2) {
					printf("%d��������\n",num);
					break;
				}
				for (int i = 2; i * i <= num; i++) {
					if (num % i == 0) {
						printf("%d��������\n", num);
						tmp = 1;
						break;
					}
				}
				if (tmp == 0) {
					printf("%d������\n", num);
				}
				break;
			case 3:
				if (num % 2 == 0) {
					printf("%d��ż��\n", num);
				}
				else {
					printf("%d������\n", num);
				}
				break;
			case 4:
				flag = 1;
				break;
			default:
				break;
		}
		if (flag == 1) {
			break;
		}
	}
}

void C4_d() {
	int grade = 0;
	int num = 0;
	printf("�������õ�����\n");
	scanf_s("%d", &grade);
	printf("�����벻�����Ŀ����Ŀ\n");
	scanf_s("%d", &num);
	switch (grade) {
		case 1:
			if (num > 3) {
				printf("û���κο���\n");
			}
			else {
				printf("ÿ�ƿ���5��\n");
			}
			break;
		case 2:
			if (num > 2) {
				printf("û���κο���\n");
			}
			else {
				printf("ÿ�ƿ���4��\n");
			}
			break;
		case 3:
			if (num > 1) {
				printf("û���κο���\n");
			}
			else {
				printf("ÿ�ƿ���5��\n");
			}
			break;
		default:
			break;
	}
}

void C5_Da(){
	printf("������һ������\n");
	int num = 0;
	scanf_s("%d", &num);
	int sum = 1;
	for (int i = 1; i <= num; i++) {
		sum *= i;
	}
	printf("%d�Ľ׳�Ϊ%d\n", num, sum);
}

void convertToRoman(int year, char* roman) {
	// �����������ֶ�Ӧ������ֵ
	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	char* romanNumerals[] = { "m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i" };
	int i = 0;

	// ȷ������ַ������㹻�Ŀռ�
	roman[0] = '\0';

	// �����ĵ�λ��ʼ���𲽹������������ַ���
	while (year > 0) {
		while (year >= values[i]) {
			year -= values[i];
			strcat(roman, romanNumerals[i]);
		}
		i++;
	}
}

int C5_Dc() {
	int year;
	char roman[50]; // �������ת�����������ֲ��ᳬ��50���ַ�

	printf("Enter a year: ");
	scanf_s("%d", &year); // ��ȡ���

	// ת������ӡ��������
	convertToRoman(year, roman);
	printf("The Roman equivalent of the year %d is: %s\n", year, roman);

	return 0;
}


// �������壺�ҳ�����ӡһ����������������
void findPrimeFactors(int number) {
	int factor;

	// ����С��������ʼ
	for (factor = 2; number > 1; factor++) {
		// ��鵱ǰ�����Ƿ�Ϊ������
		while (number % factor == 0) {
			printf("%d ", factor);
			number /= factor; // �������������������
		}
	}
	printf("\n"); // ��������ӡ��Ϻ���
}

void C5_De() {
	int number;

	// ��ʾ�û�����һ��������
	printf("Enter a positive integer: ");
	scanf_s("%d", &number);

	// ��������Ƿ�Ϊ������
	if (number <= 0) {
		printf("The number must be a positive integer.\n");
	}
	else {
		// ��ȡ����ӡ������
		findPrimeFactors(number);
	}
}

void C5_Fb() {
	int numbers[5]; // �洢5������
	double sum, average, stdDev; // �洢�͡�ƽ��ֵ�ͱ�׼��
	sum = 0;
	// ��ʾ�û�����5������
	printf("Enter 5 integers:\n");
	for (int i = 0; i < 5; i++) {
		printf("Number %d: ", i + 1);
		scanf_s("%d", &numbers[i]);
	}

	for (int i = 0; i < 5; i++) {
		sum += numbers[i];
	}
	printf("Sum: %.2f\n", sum);

	average = sum / 5;
	printf("Average: %.2f\n", average);

	double variance = 0.0;
	double meanDifference = 0.0;

	for (int i = 0; i < 5; i++) {
		meanDifference = numbers[i] - average;
		variance += meanDifference * meanDifference;
	}
	variance /= 5;

	// �����׼��
	stdDev = sqrt(variance);


	// ��ӡ���
	
	
	printf("Standard Deviation: %.2f\n", stdDev);
}

int sumOfDigits(int number) {
	int sum = 0;
	while (number > 0) {
		sum += number % 10; // ȡ�����һλ���ֲ��ӵ�sum��
		number /= 10;       // �Ƴ����һλ����
	}
	return sum;
}

void C5_Ja() {
	int number;
	printf("Enter a 5-digit number: ");
	scanf_s("%d", &number);

	// ȷ��������һ��5λ��
	if (number < 10000 || number > 99999) {
		printf("The number is not a 5-digit number.\n");
		return 1;
	}

	int sum = sumOfDigits(number);
	printf("The sum of the digits is: %d\n", sum);
}

int sumOfDigitsRecursive(int number) {
	if (number == 0) {
		return 0; // �ݹ���ֹ����
	}
	return number % 10 + sumOfDigitsRecursive(number / 10); // �ݹ����
}

void C5_Jar() {
	int number;
	printf("Enter a 5-digit number: ");
	scanf_s("%d", &number);

	// ȷ��������һ��5λ��
	if (number < 10000 || number > 99999) {
		printf("The number is not a 5-digit number.\n");
		return 1;
	}

	int sum = sumOfDigitsRecursive(number);
	printf("The sum of the digits is: %d\n", sum);
}

void printPrimeFactorsRecursive(int number, int divisor) {
	if (number <= 1) {
		return; // �ݹ���ֹ����
	}

	if (number % divisor == 0) {
		printf("%d ", divisor);
		printPrimeFactorsRecursive(number / divisor, divisor); // �ݹ����
	}
	else {
		printPrimeFactorsRecursive(number, divisor + 1); // �ݹ���ã����ӳ���
	}
}

void C5_Jb() {
	int number;
	printf("Enter a positive integer: ");
	scanf_s("%d", &number);
	if (number <= 0) {
		printf("The number must be positive.\n");
		return 1;
	}
	printf("Prime factors of %d: ", number);
	printPrimeFactorsRecursive(number,2);
	printf("\n");
}

int fibonacci(int n) {
	if (n == 0) {
		return 0; // 쳲��������еĵ�һ��������0
	}
	else if (n == 1) {
		return 1; // 쳲��������еĵڶ���������1
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2); // �ݹ����
	}
}

int C5_Jc() {
	int i;
	printf("The first 25 numbers of the Fibonacci sequence are:\n");
	for (i = 0; i < 25; i++) {
		printf("%d ", fibonacci(i));
	}
	printf("\n");
	return 0;
}

void printBinaryRecursive(int n) {
	if (n > 0) {
		printBinaryRecursive(n / 2); // �ݹ���ã�����һλ
		printf("%d", n % 2); // ��ӡ��ǰλ�Ķ�����ֵ
	}
}

int C5_Jd() {
	int number;
	printf("Enter a positive integer: ");
	scanf_s("%d", &number);

	if (number < 0) {
		printf("The number must be positive.\n");
		return 1;
	}

	printf("Binary equivalent of %d using recursion: ", number);
	printBinaryRecursive(number);

	printf("\n");
	return 0;
}

int recurSum(int a) {
	if (a == 25) {
		return a;
	}
	return recurSum(a+1)+a;
}

void C5_Je() {
	printf("ǰ25λ��Ȼ���ĺ�Ϊ%d\n", recurSum(1));
}

double factorial(int n) {
	double result = 1.0;
	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	return result;
}

// �������Ҽ����ĺ���
double sinSeries(double x) {
	double sum = 0.0;
	int sign = 1; // ������
	int k = 1;    // ����

	// ���㼶��ֱ��������
	for (int term = 1; term <= 5; ++term) {
		sum += sign * (x / factorial(2 * k + 1));
		sign *= -1; // ����������
		++k;
	}

	return sum;
}

void C5_Jf() {
	double x;
	printf("Enter the value of x: ");
	scanf_s("%lf", &x);

	double result = sinSeries(x);
	printf("The value of sin(x) to five significant digits is: %.5lf\n", result);

}

void circularShift(int* x, int* y, int* z) {
	int temp = *x; // ����x��ֵ
	*x = *z;       // ��z��ֵ����x
	*z = *y;       // ��y��ֵ����z
	*y = temp;     // ��xԭ����ֵ����y
}

void C5_Jg() {
	int a, b, c;

	// ��ʼ������
	a = 5;
	b = 8;
	c = 10;

	printf("Before circular shift: a = %d, b = %d, c = %d\n", a, b, c);

	// ���ú�������ѭ������
	circularShift(&a, &b, &c);

	printf("After circular shift: a = %d, b = %d, c = %d\n", a, b, c);

	return 0;
}

void printBinaryEquivalent(unsigned int decimal) {
	// ���ڴ洢�������������飬����32λ�������Դ洢����λ
	char binary[33];
	int index = 0;

	// ��������Ƶȼ���
	while (decimal > 0) {
		binary[index++] = (decimal & 1) + '0'; // ��ȡ���λ��ת��Ϊ�ַ�
		decimal >>= 1; // ����һλ
	}

	// ��ӡ�����������������ĩβ��ǰ��ӡ
	while (index > 0) {
		printf("%c", binary[--index]);
	}
	printf("\n");
}

void C5_Jh() {
	unsigned int decimalNumber;
	printf("Enter a decimal integer: ");
	scanf_s("%u", &decimalNumber); // ʹ���޷��������Ա��⸺������

	printf("Binary equivalent: ");
	printBinaryEquivalent(decimalNumber); // ���ú�����ʾ�����Ƶȼ���
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void C5_Jk() {
	printf("��������������\n");
	int a = 0;
	int b = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	int c = gcd(a, b);
	printf("%d\n",c);
}

void C8_Da() {
	int arr[25];
	printf("������25������\n");
	for (int i = 0; i < 25; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("������Ҫ���ҵĺ���\n");
	int a = 0;
	scanf_s("%d", &a);
	int sum = 0;
	for (int i = 0; i < 25; i++) {
		if (a == arr[i]) {
			sum++;
		}
	}
	if (sum == 0) {
		printf("û�д˺���\n");
	}else{
		printf("�ú��������%d��\n", sum);
	}
}

void bubblesort(int* arr) {
	for (int i = 24; i >=0 ; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int a = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = a;
			}
		}
	}
}

void selectsort(int* arr) {
	for (int i = 0; i < 25; i++) {
		for (int j = i; j < 25; j++) {
			if (arr[j] < arr[i]) {
				int a = arr[j];
				arr[j] = arr[i];
				arr[i] = a;
			}
		}
	}
}

void insertsort(int* arr) {
	for (int i = 1; i < 25; i++) {
		int k = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] < arr[j]) {
				k = j;
			}
			else {
				break;
			}
		}
		if (k != -1) {
			int tmp = arr[i];
			for (int j = i; j > k; j--) {
				arr[j] = arr[j - 1];
			}
			arr[k] = tmp;
		}

	}
}

void C8_Db() {
	int arr[25] = {4,3,2,6,7,25,24,23,1,5,8,9,22,21,20,19,11,16,12,18,17,14,15,10,3};
	int arr2[25] = {4,3,2,6,7,25,24,23,1,5,8,9,22,21,20,19,11,16,12,18,17,14,15,10,3};
	int arr3[25] = {4,3,2,6,7,25,24,23,1,5,8,9,22,21,20,19,11,16,12,18,17,14,15,10,3};
	printf("ԭ����Ϊ��");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubblesort(&arr);
	printf("ð�������");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("ԭ����Ϊ��");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	selectsort(&arr2);
	printf("ѡ�������");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	printf("ԭ����Ϊ��");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr3[i]);
	}
	printf("\n");
	insertsort(&arr3);
	printf("���������");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr3[i]);
	}
	printf("\n");
}

void C8_Dc() {
	int arr[100];
	for (int i = 0; i < 100; i++) {
		arr[i] = i + 1;
	}
	arr[0] = 0;
	for (int i = 0; i < 100; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = arr[i] * 2; j <= 100; j += arr[i]) {
			arr[j-1] = 0;
		}
	}
	printf("100���ڵ������У�");
	for (int i = 0; i < 100; i++) {
		if (arr[i] == 0) {
			continue;
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void C8_Dd() {
	int arr[25];
	printf("������25����\n");
	for (int i = 0; i < 25; i++) {
		scanf_s("%d", &arr[i]);
	}
	int neg = 0;
	int pos = 0;
	int even = 0;
	int odd = 0;
	for (int i = 0; i < 25; i++) {
		if (arr[i] > 0) {
			pos++;
		}
		if (arr[i] < 0) {
			neg++;
		}
		if (arr[i] % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}
	printf("�����У�%d��\n", pos);
	printf("�����У�%d��\n", neg);
	printf("ż���У�%d��\n", even);
	printf("�����У�%d��\n", odd);
}

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void interchangeOddEven(int arr[], int size) {
	int i;
	for (i = 0; i < size - 1; i += 2) {
		// �����ǰԪ����������������һ��Ԫ����ż��
		if ((arr[i] % 2 != 0) && (arr[i + 1] % 2 == 0)) {
			swap(&arr[i], &arr[i + 1]);
		}
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void C8_De() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("Original array: ");
	printArray(arr, size);

	interchangeOddEven(arr, size);

	printf("Array after interchanging odd and even elements: ");
	printArray(arr, size);
}

void C8_Lb() {

}

void C8_Ld() {

}

void C8_Ld() {

}

void main(){
	int chapter = 0;
	while (1) {
		printf("������Ҫ�鿴���½ڣ�2-9��,��Ҫ�˳���ѡ��0\n");
		scanf_s("%d", &chapter);
		char ch = ' ';
		if (chapter == 0) {
			break;
		}
		else if (chapter == 2) {
			while (1) {
				printf("��ѡ��ڶ��£���ѡ����ţ�b,c,d),�˳�������0\n");
				scanf_s(" %c", &ch);
				if (ch == '0') {
					break;
				}
				else if (ch == 'b') {
					printf("��ѡ����b\n");
					C2_b();
				}
				else if (ch == 'c') {
					printf("��ѡ����c\n");
					C2_c();
				}
				else if (ch == 'd') {
					printf("��ѡ����d\n");
					C2_d();
				}
				else {
					printf("�Ƿ����룬������\n");
				}
			}
		}
		else if (chapter == 3) {
			while (1) {
				char big = ' ';
				printf("��ѡ������£���ѡ�����ţ�B,E),�˳�������0\n");
				scanf_s(" %c", &big);
				if (big == '0') {
					break;
				}else if (big == 'B') {
					while (1) {
						printf("��ѡ������´����B����ѡ����ţ�d,e,f,h),�˳�������0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'd') {
							printf("��ѡ����d\n");
							C3_Bd();
						}
						else if (ch == 'e') {
							printf("��ѡ����e\n");
							C3_Be();
						}
						else if (ch == 'f') {
							printf("��ѡ����f\n");
							C3_Bf();
						}
						else if (ch == 'h') {
							printf("��ѡ����h\n");
							C3_Bh();
						}
						else {
							printf("�Ƿ����룬������\n");
						}
					}
				}
				else if (big == 'E') {
					while (1) {
						printf("��ѡ������´����E����ѡ����ţ�c,d,e,f),�˳�������0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'c') {
							printf("��ѡ����c\n");
							C3_Ec();
						}
						else if (ch == 'd') {
							printf("��ѡ����d\n");
							C3_Ed();
						}
						else if (ch == 'e') {
							printf("��ѡ����e\n");
							C3_Ee();
						}
						else if (ch == 'f') {
							printf("��ѡ����f\n");
							C3_Ef();
						}
						else {
							printf("�Ƿ����룬������\n");
						}
					}
				}
				else {
					printf("�Ƿ����룬����������");
				}
			}
		}
		else if (chapter == 4) {
			while (1) {
				printf("��ѡ������£���ѡ����ţ�c,d),�˳�������0\n");
				scanf_s(" %c", &ch);
				if (ch == '0') {
					break;
				}
				else if (ch == 'c') {
					printf("��ѡ����c\n");
					C4_c();
				}
				else if (ch == 'd') {
					printf("��ѡ����d\n");
					C4_d();
				}
				else {
					printf("�Ƿ����룬������\n");
				}
			}
		}
		else if (chapter == 5) {
			while (1) {
				char big = ' ';
				printf("��ѡ������£���ѡ�����ţ�D,F,J),�˳�������0\n");
				scanf_s(" %c", &big);
				if (big == '0') {
					break;
				}
				else if (big == 'D') {
					while (1) {
						printf("��ѡ������´����D����ѡ����ţ�a,c,e),�˳�������0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'a') {
							printf("��ѡ����a\n");
							C5_Da();
						}
						else if (ch == 'c') {
							printf("��ѡ����c\n");
							C5_Dc();
						}
						else if (ch == 'e') {
							printf("��ѡ����e\n");
							C5_De();
						}
						else {
							printf("�Ƿ����룬������\n");
						}
					}
				}
				else if (big == 'F') {
					while (1) {
						printf("��ѡ������´����F����ѡ����ţ�b),�˳�������0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'b') {
							printf("��ѡ����b\n");
							C5_Fb();
						}
						else {
							printf("�Ƿ����룬������\n");
						}
					}
				}
				else if (big == 'J') {
					while (1) {
						printf("��ѡ������´����J����ѡ����ţ�a,b,c,d,e,f,g,h,k),�˳�������0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'a') {
							int t = 0;
							printf("��ѡ����a����ѡ���Ƿ�ʹ�õݹ飨0��ʹ��1ʹ�ã�\n");
							scanf_s("%d", &t);
							if (t == 0) {
								C5_Ja();
							}else {
								C5_Jar();
							}
						}
						else if (ch == 'b') {
							printf("��ѡ����b\n");
							C5_Jb();
						}
						else if (ch == 'c') {
							printf("��ѡ����c\n");
							C5_Jc();
						}
						else if (ch == 'd') {
							printf("��ѡ����d\n");
							C5_Jd();
						}
						else if (ch == 'e') {
							printf("��ѡ����e\n");
							C5_Je();
						}
						else if (ch == 'f') {
							printf("��ѡ����f\n");
							C5_Jf();
						}
						else if (ch == 'g') {
							printf("��ѡ����g\n");
							C5_Jg();
						}
						else if (ch == 'h') {
							printf("��ѡ����h\n");
							C5_Jh();
						}
						else if (ch == 'k') {
							printf("��ѡ����k\n");
							C5_Jk();
						}
						else {
							printf("�Ƿ����룬������\n");
						}
					}
				}
			}
			
		}
		else if (chapter == 8) {
			while (1) {
				char big = ' ';
				printf("��ѡ��ڰ��£���ѡ�����ţ�D,L),�˳�������0\n");
				scanf_s(" %c", &big);
				if (big == '0') {
					break;
				}
				else if (big == 'D') {
					while (1) {
						printf("��ѡ��ڰ��´����D����ѡ����ţ�a,b,c,d,e),�˳�������0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'a') {
							printf("��ѡ����a\n");
							C8_Da();
						}
						else if (ch == 'b') {
							printf("��ѡ����b\n");
							C8_Db();
						}
						else if (ch == 'c') {
							printf("��ѡ����c\n");
							C8_Dc();
						}
						else if (ch == 'd') {
							printf("��ѡ����d\n");
							C8_Dd();
						}
						else if (ch == 'e') {
							printf("��ѡ����e\n");
							C8_De();
						}
						else {
							printf("�Ƿ����룬������\n");
						}
					}
				}
				else if (big == 'L') {
					while (1) {
						printf("��ѡ��ڰ��´����D����ѡ����ţ�b,c,d),�˳�������0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'b') {
							printf("��ѡ����b\n");
							C8_Lb();
						}
						else if (ch == 'c') {
							printf("��ѡ����c\n");
							C8_Lc();
						}
						else if (ch == 'd') {
							printf("��ѡ����d\n");
							C8_Ld();
						}
						else {
							printf("�Ƿ����룬������\n");
						}
					}
				}
			}

			
		}
		else if (chapter == 9) {

		}
		else {
			printf("�Ƿ����룬������\n");
		}
	}
	
	
}