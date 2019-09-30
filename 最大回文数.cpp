# include <iostream>
# include<string>
# include<algorithm>
using namespace std;


//����
int Init();
int Manacher();

char str[100];
char s_new[200];
int p[200];

//��ʼ��
int Init()
{
	s_new[0] = '$';
	s_new[1] = '#';
	int j = 2;
	int len = (int)strlen(str);
	for (int i = 0; i < len; i++)
	{
		s_new[j++] = str[i];
		s_new[j++] = '#';
	}
	s_new[j] = '\0';
	return j;
}
//����p����
int Manacher()
{
	int len = Init();
	int max_len = -1;
	int id;
	int right = 0;
	for (int i = 1; i < len; i++)
	{
		if (i < right)
		{
			p[i] = min(p[2 * id - i], right - i);
		}
		else
		{
			p[i] = 1;
		}
		while (s_new[i - p[i]] == s_new[i + p[i]])
		{
			p[i]++;
		}
		//cout << p[i] << endl;
		if (i > right)
		{
			right = p[i] + i;
			id = i;
		}
		max_len = max(p[i] - 1, max_len);
	}
	return max_len;
}
//������
int main()
{
	cout << "�������ַ�����" << endl;
	cin >> str;
	int max_len = Manacher();
	cout << "�����ĳ��ȣ�" << max_len << endl;
	return 0;
}