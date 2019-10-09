/*ȫ��������C++����
���룺ȫ����Ԫ������ n
n����Ҫ���е��ַ�
�������n���ַ���ȫ��������
*/
#include <iostream>
using namespace std;
void swap(int &a, int &b) {      //����
	int temp = a;
	a = b;
	b = temp;
}

void perm(char list[], int low, int high) {      //�ݹ麯��
	if (low == high) {      //��ִ����һ�˵ݹ����б�������н��
		for (int i = 0; i <= low; i++)
			cout << list[i];
		cout << endl;
	}
	else {
		for (int i = low; i <= high; i++) {
			swap(list[i], list[low]);      //�ѵ�low��Ԫ�غ͵�i��Ԫ�ؽ���
			perm(list, low + 1, high);       //��������list[low+1]~list[high]ִ�еݹ����в���
			swap(list[i], list[low]);      //��֮ǰ����������Ԫ�ػ�����
		}
	}
}

int main()
{
	int n;
	char list[100];
	cout << "Number of elements for Full Permutation: ";
	cin >> n;      //���������ַ�������
	cout << "\nInput: ";
	for (int i = 0; i < n; i++)
		cin >> list[i];      //����n����Ҫ���е��ַ�
	cout << "\nOutput:" << endl;
	perm(list, 0, n - 1);
	cout << endl;
	system("pause");
	return 0;
}

///*
//* ��n����ͬ���ַ�����ȫ����
//* �㷨˼�룺
//*     ������ 1234 ��ȫ����
//*     �� �� 1 �̶���234 ��ȫ�ţ����еݹ����У�ֱ��Ϊһ��Ԫ�أ���ӡ����Ԫ�أ����ָ����������
//*     �� �� 1 �� 2 ���н������� 2 �̶���134 ��ȫ���У�ֱ��Ϊһ��Ԫ�أ���ӡ����Ԫ�أ����ָ����������
//*     �� ͬ����ʾ��ֱ���� 4 ��Ϊ��һ��Ϊֹ��
//*/
//#include <iostream>
//using namespace std;
//
//void FullArray(char *str, int m, int n)
//{
//	int i, tmp;
//
//	if (n == m)
//	{
//		for (i = 0; i < n; i++)
//			cout << str[i];
//		cout << endl;
//	}
//	else
//	{
//		for (i = m; i < n; i++)
//		{
//			tmp = str[i];
//			str[i] = str[m];
//			str[m] = tmp;
//
//			FullArray(str, m + 1, n);
//
//			tmp = str[i];
//			str[i] = str[m];
//			str[m] = tmp;
//		}
//	}
//}
//
//int main(void)
//{
//	char str[100] = "1234";
//	FullArray(str, 0, strlen(str));
//
//	system("pause");
//	return 0;
//}