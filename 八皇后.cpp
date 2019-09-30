//-------------------- -
//���ߣ�changyuanchn
//��Դ��CSDN
//ԭ�ģ�https ://blog.csdn.net/changyuanchn/article/details/17354461 
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
#include <stdio.h>
#include <windows.h>

#define N 8
#define abs(x) (((x)>=0)?(x):-(x)) 
int col[N + 1];
int count = 0;

void Output();
void Queen(int i, int n);

void main()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		col[1] = i;
		Queen(2, N);
	}
	printf("%d\n", count);
	system("pause");
}

void Queen(int i, int n)
{
	if (i>n)
		Output();
	else
	{
		int j;
		for (j = 1; j <= N; j++)
		{
			col[i] = j;
			int k = 1; //�Ѿ�������λ�õĻʺ���α�ָʾ
			while (k<i)//�Ƚ����ڵĻʺ���֮ǰ�Ļʺ���û�г�ͻ
			{
				if ((col[k] - col[i])*(abs(col[k] - col[i]) - abs(k - i)) != 0)//��ͻ����
				{
					k++;
					if (k == i)
						Queen(i + 1, n);
				}
				else
					break;
			}
		}
	}
}
void Output()
{
	int i;
	count++;
	for (i = 1; i <= N; i++)
	{
		printf("(%d,%d)\n", i, col[i]);
	}
	printf("\n");
}
