#include <iostream>
#include<Windows.h>

int main()
{
	//λ�����ж��Ƿ�Ϊ����
	int a = 1000000000;
	int b = 2312321;
	double t = GetTickCount();
	while (a--)
	{
		if (b % 2 == 1); //std::cout << a << std::endl;
	}
	t = (GetTickCount() - t);
	std::cout << t << "ms" << std::endl;


	
	a = 1000000000;
	t = GetTickCount();
	while (a--)
	{
		if (b & 1 == 1); //std::cout << a << std::endl;
	}
	t = (GetTickCount() - t);
	std::cout << t << "ms" << std::endl;


	//λ(������㽻����������
	int x = 21321312;
	int y = 534654;

	a = 1000000000;
	t = GetTickCount();
	while (a--)
	{
		int z = x;
		x = y;
		y = z;
	}
	t = (GetTickCount() - t);
	std::cout << t << "ms" << std::endl;

	x = 21321312;
	y = 534654;
	a = 1000000000;
	t = GetTickCount();
	while (a--)
	{
		x = x^y;
		y = x^y;
		x = x^y;
	}
	t = (GetTickCount() - t);
	std::cout << t << "ms" << std::endl;


	//�����в��ظ����Ǹ���
	int array[] = { 1, 2, 3, 4, 5, 6, 8, 8, 6, 4, 3, 2, 1 };
	int result = 0;
	t = GetTickCount();
	for (int i = 0; i < sizeof(array) / sizeof(int); i++)
	{
		result ^= array[i];
	}
	std::cout << result << std::endl;
	t = (GetTickCount() - t);
	std::cout << t << "ms" << std::endl;
	system("pause");
	return 1;
	
}