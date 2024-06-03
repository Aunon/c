#include <stdio.h>
#include <math.h>

void C2_b() {
	char ch;
	printf("请输入一个字符 ");
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

	// 提示用户输入硬度、碳含量和抗拉强度
	printf("Enter the hardness of the steel: ");
	scanf_s("%f", &hardness);
	printf("Enter the carbon content of the steel: ");
	scanf_s("%f", &carbonContent);
	printf("Enter the tensile strength of the steel: ");
	scanf_s("%f", &tensileStrength);

	// 初始化条件变量
	int condition1 = hardness > 50;
	int condition2 = carbonContent < 0.7;
	int condition3 = tensileStrength > 5600;

	// 根据条件判断钢的等级
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

	// 输出钢的等级
	printf("The grade of the steel is: %d\n", grade);
}

void C2_d() {
	int lateDays;

	// 提示用户输入逾期天数
	printf("Enter the number of days the book is late: ");
	scanf_s("%d", &lateDays);

	// 根据逾期天数判断罚款金额或显示消息
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

	// 使用while循环遍历ASCII值从0到255
	asciiValue = 0;
	while (asciiValue <= 255) {
		character = (char)asciiValue; // 将ASCII值转换为字符
		printf("%d - %c\n", asciiValue, character);
		asciiValue++; // 递增ASCII值
	}
}

int isArmstrong(int number) {
	int originalNumber, remainder, result = 0;
	int n = 0;

	// 计算数字的位数
	originalNumber = number;
	while (originalNumber != 0) {
		++n;
		originalNumber /= 10;
	}

	// 计算各位数字的n次幂之和
	originalNumber = number;
	while (originalNumber != 0) {
		remainder = originalNumber % 10;
		result += remainder * remainder * remainder;
		originalNumber /= 10;
	}

	// 如果结果等于原数，则是一个阿姆斯特朗数
	return result == number;
}

void C3_Be() {
	int number;

	// 打印1到500之间的所有阿姆斯特朗数
	printf("Armstrong numbers between 1 and 500 are:\n");
	for (number = 1; number <= 500; number++) {
		if (isArmstrong(number)) {
			printf("%d\n", number);
		}
	}

}

void C3_Bf() {
	int matchsticks = 21; // 初始火柴数量
	int userChoice; // 用户的选择
	int computerChoice; // 计算机的选择

	printf("Matchsticks Game\n");
	printf("I will always win!\n\n");

	while (matchsticks > 0) {
		// 用户选择拿走1到4根火柴
		printf("You have %d matchsticks. How many do you want to pick (1-4)? ", matchsticks);
		scanf_s("%d", &userChoice);

		// 确保用户输入有效
		while (userChoice < 1 || userChoice > 4) {
			printf("Invalid choice. Please pick 1, 2, 3, or 4 matchsticks.\n");
			printf("How many do you want to pick (1-4)? ");
			scanf_s("%d", &userChoice);
		}

		// 用户拿走火柴
		matchsticks -= userChoice;
		printf("You picked %d matchsticks.\n", userChoice);

		// 检查游戏是否结束
		if (matchsticks == 0) {
			printf("You picked the last matchstick and lost the game!\n");
			break;
		}

		// 计算机拿走火柴，确保剩余火柴是5的倍数
		if (matchsticks % 5 == 0) {
			computerChoice = 0; // 计算机不需要拿火柴
		}
		else if (matchsticks < 5) {
			computerChoice = 0;
		}
		else {
			computerChoice = 5 - matchsticks % 5;
		}
		// 计算机拿走火柴
		matchsticks -= computerChoice;
		printf("I picked %d matchsticks.\n", computerChoice);

		
	}
}

void C3_Bh() {
	int decimalNumber;
	printf("Enter an integer: ");
	scanf_s("%d", &decimalNumber); // 读取整数

	// 打印八进制等价数
	printf("The octal equivalent of the entered integer (%d) is: ", decimalNumber);
	printf("%o\n", decimalNumber); // 使用%o格式化输出八进制数

	return 0;
}


void C3_Ec(){
	int sum = 0;
	int a = 1;
	for (int i = 1; i <= 7; i++) {
		a *= i;
		sum += i / a;
	}
	printf("前七项的和为%d\n", &sum);
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

	// 打印从 'A' 到 'G'
	for (ch = 'A'; ch <= 'G'; ch++) {
		printf("%c\n", ch);
	}

	// 逆序打印从 'F' 到 'A'
	for (ch = 'F'; ch >= 'A'; ch--) {
		printf("%c\n", ch);
	}

	// 重复两次，打印从 'A' 到 'E'，然后逆序打印从 'E' 到 'A'
	for (int i = 0; i < 2; i++) {
		for (ch = 'A'; ch <= 'E'; ch++) {
			printf("%c\n", ch);
		}
		for (ch = 'E'; ch >= 'A'; ch--) {
			printf("%c\n", ch);
		}
	}

	// 打印从 'A' 到 'A' 的字符
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
		printf("请输入一个数\n");
		scanf_s("%d", &num);
		printf("请选择编号（1-4）\n");
		scanf_s("%d", &a);
		int sum = 1;
		int flag = 0;
		int tmp = 0;
		switch (a) {
			case 1 :
				for (int i = 1; i <= num; i++) {
					sum *= i;
				}
				printf("%d的阶乘为%d\n",num,sum);
				break;
			case 2:
				if (num < 2) {
					printf("%d不是质数\n",num);
					break;
				}
				for (int i = 2; i * i <= num; i++) {
					if (num % i == 0) {
						printf("%d不是质数\n", num);
						tmp = 1;
						break;
					}
				}
				if (tmp == 0) {
					printf("%d是质数\n", num);
				}
				break;
			case 3:
				if (num % 2 == 0) {
					printf("%d是偶数\n", num);
				}
				else {
					printf("%d是奇数\n", num);
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
	printf("请输入获得的名次\n");
	scanf_s("%d", &grade);
	printf("请输入不及格科目的数目\n");
	scanf_s("%d", &num);
	switch (grade) {
		case 1:
			if (num > 3) {
				printf("没有任何宽限\n");
			}
			else {
				printf("每科宽限5分\n");
			}
			break;
		case 2:
			if (num > 2) {
				printf("没有任何宽限\n");
			}
			else {
				printf("每科宽限4分\n");
			}
			break;
		case 3:
			if (num > 1) {
				printf("没有任何宽限\n");
			}
			else {
				printf("每科宽限5分\n");
			}
			break;
		default:
			break;
	}
}

void C5_Da(){
	printf("请输入一个整数\n");
	int num = 0;
	scanf_s("%d", &num);
	int sum = 1;
	for (int i = 1; i <= num; i++) {
		sum *= i;
	}
	printf("%d的阶乘为%d\n", num, sum);
}

void convertToRoman(int year, char* roman) {
	// 定义罗马数字对应的整数值
	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	char* romanNumerals[] = { "m", "cm", "d", "cd", "c", "xc", "l", "xl", "x", "ix", "v", "iv", "i" };
	int i = 0;

	// 确保输出字符串有足够的空间
	roman[0] = '\0';

	// 从最大的单位开始，逐步构建罗马数字字符串
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
	char roman[50]; // 假设年份转换的罗马数字不会超过50个字符

	printf("Enter a year: ");
	scanf_s("%d", &year); // 读取年份

	// 转换并打印罗马数字
	convertToRoman(year, roman);
	printf("The Roman equivalent of the year %d is: %s\n", year, roman);

	return 0;
}


// 函数定义：找出并打印一个数的所有质因数
void findPrimeFactors(int number) {
	int factor;

	// 从最小的质数开始
	for (factor = 2; number > 1; factor++) {
		// 检查当前因子是否为质因数
		while (number % factor == 0) {
			printf("%d ", factor);
			number /= factor; // 除以质因数，继续检查
		}
	}
	printf("\n"); // 质因数打印完毕后换行
}

void C5_De() {
	int number;

	// 提示用户输入一个正整数
	printf("Enter a positive integer: ");
	scanf_s("%d", &number);

	// 检查输入是否为正整数
	if (number <= 0) {
		printf("The number must be a positive integer.\n");
	}
	else {
		// 获取并打印质因数
		findPrimeFactors(number);
	}
}

void C5_Fb() {
	int numbers[5]; // 存储5个整数
	double sum, average, stdDev; // 存储和、平均值和标准差
	sum = 0;
	// 提示用户输入5个整数
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

	// 计算标准差
	stdDev = sqrt(variance);


	// 打印结果
	
	
	printf("Standard Deviation: %.2f\n", stdDev);
}

int sumOfDigits(int number) {
	int sum = 0;
	while (number > 0) {
		sum += number % 10; // 取出最后一位数字并加到sum上
		number /= 10;       // 移除最后一位数字
	}
	return sum;
}

void C5_Ja() {
	int number;
	printf("Enter a 5-digit number: ");
	scanf_s("%d", &number);

	// 确保输入是一个5位数
	if (number < 10000 || number > 99999) {
		printf("The number is not a 5-digit number.\n");
		return 1;
	}

	int sum = sumOfDigits(number);
	printf("The sum of the digits is: %d\n", sum);
}

int sumOfDigitsRecursive(int number) {
	if (number == 0) {
		return 0; // 递归终止条件
	}
	return number % 10 + sumOfDigitsRecursive(number / 10); // 递归调用
}

void C5_Jar() {
	int number;
	printf("Enter a 5-digit number: ");
	scanf_s("%d", &number);

	// 确保输入是一个5位数
	if (number < 10000 || number > 99999) {
		printf("The number is not a 5-digit number.\n");
		return 1;
	}

	int sum = sumOfDigitsRecursive(number);
	printf("The sum of the digits is: %d\n", sum);
}

void printPrimeFactorsRecursive(int number, int divisor) {
	if (number <= 1) {
		return; // 递归终止条件
	}

	if (number % divisor == 0) {
		printf("%d ", divisor);
		printPrimeFactorsRecursive(number / divisor, divisor); // 递归调用
	}
	else {
		printPrimeFactorsRecursive(number, divisor + 1); // 递归调用，增加除数
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
		return 0; // 斐波那契数列的第一个数字是0
	}
	else if (n == 1) {
		return 1; // 斐波那契数列的第二个数字是1
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2); // 递归计算
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
		printBinaryRecursive(n / 2); // 递归调用，右移一位
		printf("%d", n % 2); // 打印当前位的二进制值
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
	printf("前25位自然数的和为%d\n", recurSum(1));
}

double factorial(int n) {
	double result = 1.0;
	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	return result;
}

// 计算正弦级数的函数
double sinSeries(double x) {
	double sum = 0.0;
	int sign = 1; // 正负号
	int k = 1;    // 阶数

	// 计算级数直到第五项
	for (int term = 1; term <= 5; ++term) {
		sum += sign * (x / factorial(2 * k + 1));
		sign *= -1; // 交替正负号
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
	int temp = *x; // 保存x的值
	*x = *z;       // 将z的值赋给x
	*z = *y;       // 将y的值赋给z
	*y = temp;     // 将x原来的值赋给y
}

void C5_Jg() {
	int a, b, c;

	// 初始化变量
	a = 5;
	b = 8;
	c = 10;

	printf("Before circular shift: a = %d, b = %d, c = %d\n", a, b, c);

	// 调用函数进行循环右移
	circularShift(&a, &b, &c);

	printf("After circular shift: a = %d, b = %d, c = %d\n", a, b, c);

	return 0;
}

void printBinaryEquivalent(unsigned int decimal) {
	// 用于存储二进制数的数组，假设32位整数足以存储所有位
	char binary[33];
	int index = 0;

	// 计算二进制等价数
	while (decimal > 0) {
		binary[index++] = (decimal & 1) + '0'; // 获取最低位并转换为字符
		decimal >>= 1; // 右移一位
	}

	// 打印二进制数，从数组的末尾向前打印
	while (index > 0) {
		printf("%c", binary[--index]);
	}
	printf("\n");
}

void C5_Jh() {
	unsigned int decimalNumber;
	printf("Enter a decimal integer: ");
	scanf_s("%u", &decimalNumber); // 使用无符号整数以避免负数输入

	printf("Binary equivalent: ");
	printBinaryEquivalent(decimalNumber); // 调用函数显示二进制等价数
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void C5_Jk() {
	printf("请输入两个整数\n");
	int a = 0;
	int b = 0;
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	int c = gcd(a, b);
	printf("%d\n",c);
}

void C8_Da() {
	int arr[25];
	printf("请输入25个数字\n");
	for (int i = 0; i < 25; i++) {
		scanf_s("%d", &arr[i]);
	}
	printf("请输入要查找的号码\n");
	int a = 0;
	scanf_s("%d", &a);
	int sum = 0;
	for (int i = 0; i < 25; i++) {
		if (a == arr[i]) {
			sum++;
		}
	}
	if (sum == 0) {
		printf("没有此号码\n");
	}else{
		printf("该号码出现了%d次\n", sum);
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
	printf("原数组为：");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubblesort(&arr);
	printf("冒泡排序后：");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("原数组为：");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	selectsort(&arr2);
	printf("选择排序后：");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr2[i]);
	}
	printf("\n");
	printf("原数组为：");
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr3[i]);
	}
	printf("\n");
	insertsort(&arr3);
	printf("插入排序后：");
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
	printf("100以内的质数有：");
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
	printf("请输入25个数\n");
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
	printf("正数有：%d个\n", pos);
	printf("负数有：%d个\n", neg);
	printf("偶数有：%d个\n", even);
	printf("奇数有：%d个\n", odd);
}

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void interchangeOddEven(int arr[], int size) {
	int i;
	for (i = 0; i < size - 1; i += 2) {
		// 如果当前元素是奇数，并且下一个元素是偶数
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
		printf("请输入要查看的章节（2-9）,若要退出请选择0\n");
		scanf_s("%d", &chapter);
		char ch = ' ';
		if (chapter == 0) {
			break;
		}
		else if (chapter == 2) {
			while (1) {
				printf("已选择第二章，请选择题号（b,c,d),退出请输入0\n");
				scanf_s(" %c", &ch);
				if (ch == '0') {
					break;
				}
				else if (ch == 'b') {
					printf("已选择题b\n");
					C2_b();
				}
				else if (ch == 'c') {
					printf("已选择题c\n");
					C2_c();
				}
				else if (ch == 'd') {
					printf("已选择题d\n");
					C2_d();
				}
				else {
					printf("非法输入，请重试\n");
				}
			}
		}
		else if (chapter == 3) {
			while (1) {
				char big = ' ';
				printf("已选择第三章，请选择大题号（B,E),退出请输入0\n");
				scanf_s(" %c", &big);
				if (big == '0') {
					break;
				}else if (big == 'B') {
					while (1) {
						printf("已选择第三章大题号B，请选择题号（d,e,f,h),退出请输入0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'd') {
							printf("已选择题d\n");
							C3_Bd();
						}
						else if (ch == 'e') {
							printf("已选择题e\n");
							C3_Be();
						}
						else if (ch == 'f') {
							printf("已选择题f\n");
							C3_Bf();
						}
						else if (ch == 'h') {
							printf("已选择题h\n");
							C3_Bh();
						}
						else {
							printf("非法输入，请重试\n");
						}
					}
				}
				else if (big == 'E') {
					while (1) {
						printf("已选择第三章大题号E，请选择题号（c,d,e,f),退出请输入0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'c') {
							printf("已选择题c\n");
							C3_Ec();
						}
						else if (ch == 'd') {
							printf("已选择题d\n");
							C3_Ed();
						}
						else if (ch == 'e') {
							printf("已选择题e\n");
							C3_Ee();
						}
						else if (ch == 'f') {
							printf("已选择题f\n");
							C3_Ef();
						}
						else {
							printf("非法输入，请重试\n");
						}
					}
				}
				else {
					printf("非法输入，请重新输入");
				}
			}
		}
		else if (chapter == 4) {
			while (1) {
				printf("已选择第四章，请选择题号（c,d),退出请输入0\n");
				scanf_s(" %c", &ch);
				if (ch == '0') {
					break;
				}
				else if (ch == 'c') {
					printf("已选择题c\n");
					C4_c();
				}
				else if (ch == 'd') {
					printf("已选择题d\n");
					C4_d();
				}
				else {
					printf("非法输入，请重试\n");
				}
			}
		}
		else if (chapter == 5) {
			while (1) {
				char big = ' ';
				printf("已选择第三章，请选择大题号（D,F,J),退出请输入0\n");
				scanf_s(" %c", &big);
				if (big == '0') {
					break;
				}
				else if (big == 'D') {
					while (1) {
						printf("已选择第五章大题号D，请选择题号（a,c,e),退出请输入0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'a') {
							printf("已选择题a\n");
							C5_Da();
						}
						else if (ch == 'c') {
							printf("已选择题c\n");
							C5_Dc();
						}
						else if (ch == 'e') {
							printf("已选择题e\n");
							C5_De();
						}
						else {
							printf("非法输入，请重试\n");
						}
					}
				}
				else if (big == 'F') {
					while (1) {
						printf("已选择第五章大题号F，请选择题号（b),退出请输入0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'b') {
							printf("已选择题b\n");
							C5_Fb();
						}
						else {
							printf("非法输入，请重试\n");
						}
					}
				}
				else if (big == 'J') {
					while (1) {
						printf("已选择第五章大题号J，请选择题号（a,b,c,d,e,f,g,h,k),退出请输入0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'a') {
							int t = 0;
							printf("已选择题a，请选择是否使用递归（0不使用1使用）\n");
							scanf_s("%d", &t);
							if (t == 0) {
								C5_Ja();
							}else {
								C5_Jar();
							}
						}
						else if (ch == 'b') {
							printf("已选择题b\n");
							C5_Jb();
						}
						else if (ch == 'c') {
							printf("已选择题c\n");
							C5_Jc();
						}
						else if (ch == 'd') {
							printf("已选择题d\n");
							C5_Jd();
						}
						else if (ch == 'e') {
							printf("已选择题e\n");
							C5_Je();
						}
						else if (ch == 'f') {
							printf("已选择题f\n");
							C5_Jf();
						}
						else if (ch == 'g') {
							printf("已选择题g\n");
							C5_Jg();
						}
						else if (ch == 'h') {
							printf("已选择题h\n");
							C5_Jh();
						}
						else if (ch == 'k') {
							printf("已选择题k\n");
							C5_Jk();
						}
						else {
							printf("非法输入，请重试\n");
						}
					}
				}
			}
			
		}
		else if (chapter == 8) {
			while (1) {
				char big = ' ';
				printf("已选择第八章，请选择大题号（D,L),退出请输入0\n");
				scanf_s(" %c", &big);
				if (big == '0') {
					break;
				}
				else if (big == 'D') {
					while (1) {
						printf("已选择第八章大题号D，请选择题号（a,b,c,d,e),退出请输入0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'a') {
							printf("已选择题a\n");
							C8_Da();
						}
						else if (ch == 'b') {
							printf("已选择题b\n");
							C8_Db();
						}
						else if (ch == 'c') {
							printf("已选择题c\n");
							C8_Dc();
						}
						else if (ch == 'd') {
							printf("已选择题d\n");
							C8_Dd();
						}
						else if (ch == 'e') {
							printf("已选择题e\n");
							C8_De();
						}
						else {
							printf("非法输入，请重试\n");
						}
					}
				}
				else if (big == 'L') {
					while (1) {
						printf("已选择第八章大题号D，请选择题号（b,c,d),退出请输入0\n");
						scanf_s(" %c", &ch);
						if (ch == '0') {
							break;
						}
						else if (ch == 'b') {
							printf("已选择题b\n");
							C8_Lb();
						}
						else if (ch == 'c') {
							printf("已选择题c\n");
							C8_Lc();
						}
						else if (ch == 'd') {
							printf("已选择题d\n");
							C8_Ld();
						}
						else {
							printf("非法输入，请重试\n");
						}
					}
				}
			}

			
		}
		else if (chapter == 9) {

		}
		else {
			printf("非法输入，请重试\n");
		}
	}
	
	
}