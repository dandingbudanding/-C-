//#include<iostream>
//#include<algorithm>
//using namespace std;
//#define MAXN 100
//#define MAXM 1000
//int m, n;
//int v[MAXN] = { 0 }, w[MAXN] = { 0 };
//int f[MAXM] = { 0 };
//int main()
//{
//	int sum = 0;//��
//	cin >> sum;
//
//	int m = 0;
//	int n = 0;
//	int temp; char c;
//
//	cin >> w[m++]; //��ȡ�����еĵ�һ���ַ�(2)
//	while ((c = getchar()) != '\n') //��ȡ�����еĵڶ����ַ�(�� ��)
//	{
//		cin >> temp;//��ȡ�����еĵ������ַ�(3)
//		w[m++] = temp;
//	}
//
//	cin >> v[n++]; //��ȡ�����еĵ�һ���ַ�(2)
//	while ((c = getchar()) != '\n') //��ȡ�����еĵڶ����ַ�(�� ��)
//	{
//		cin >> temp;//��ȡ�����еĵ������ַ�(3)
//		v[n++] = temp;
//	}
//	for (int i = 0; i <= n; i++)             //��f(v)��ʾ����������v���������ֵ
//		for (int j = sum; j >= w[i]; j--)  //ע��������
//			f[j] = max(f[j - w[i]] + v[i], f[j]);
//	printf("%d\n", f[MAXM]);                      // f(m)Ϊ���Ž�
//	return 0;
//}



#include<stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


const int N = 15;

bool onetwobag(int m[N][N], int w[], int v[], int n, int c)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (j >= w[i])
				m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i]);
			else
				m[i][j] = m[i - 1][j];
		}
	}
	return 1;
}

int main()
{
	int v[N] = { 0,8,10,6,3,7,2 };
	int w[N] = { 0,4,6,2,2,5,1 };

	/*int *aaa = new int[10];
	aaa[0] = 1; 
	aaa[1] = 2;
	aaa[100] = 3;

	cout << aaa[100] << endl;*/


	int m[N][N];
	int n = 6, c = 12;
	memset(m, 0, sizeof(m));
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (j >= w[i])
				m[i][j] = max(m[i - 1][j], m[i - 1][j - w[i]] + v[i]);


			else
				m[i][j] = m[i - 1][j];
		}
	}*/
	onetwobag(m, w, v, n, c);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << m[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}


