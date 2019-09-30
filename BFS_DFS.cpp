//������ܲ���http://www.cnblogs.com/skywang12345/p/3711483.html
//������ܲ���http://rapheal.iteye.com/blog/1526863
////////////////////////////////////
////�������֮�ڵ����
////1-----5----------9
////|     |          |
////|     |          |  
////2-----4----6-----8
////|          |     |
////|          |     |
////3----------7-----10
//
//
//#include<iostream>
//#include<queue>
//using namespace std;
//
////�ڵ���
//#define M 10
//
////ͼ�ľ����ʾ
//int matrix[M][M] =
//{ 
//0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
//1, 0, 1, 1, 0, 0, 0, 0, 0, 0,
//0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
//0, 1, 0, 0, 1, 1, 0, 0, 0, 0,
//1, 0, 0, 1, 0, 0, 0, 0, 1, 0,
//0, 0, 0, 1, 0, 0, 1, 1, 0, 0,
//0, 0, 1, 0, 0, 1, 0, 0, 0, 1,
//0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
//0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
//0, 0, 0, 0, 0, 0, 1, 1, 0, 0
//
//};
////���ʱ��,��ʼ��Ϊ0,
//int visited[M + 1];
//
//void GT_BFS()
//{
//	visited[1] = 1;
//	queue<int> q;
//	q.push(1);
//	while (!q.empty())
//	{
//		int now = q.front();
//		q.pop();
//		cout << now << " ";
//		for (int i = 1; i <= M; i++)
//		{
//			if (!visited[i] && matrix[now - 1][i - 1] == 1)
//			{
//				q.push(i);
//				visited[i] = 1;
//			}
//		}
//	}
//}
//
//int main()
//{
//	GT_BFS();//������Ϊ1 2 5 3 4 9 7 6 8 10
//	system("pause");
//	return 0;
//}



///////////////////////////////////////////
//�����������֮��Ȩ���·����Dijkstra�㷨
// 1---(1)-->5
// |         |
//(2)       (12)
// |         |
// 2--(13)---4---(2)--6--(2)--8
// |                  |
//(4)                (5)
// |                  |
// 3----(1)-----------7
// 1 2 3 4 5 6 7 8
//1 0 2 0 0 1 0 0 0
//2 2 0 4 7 0 0 0 0
//3 0 4 0 0 0 0 1 0
//4 0 7 0 0 12 2 0 0
//5 1 0 0 12 0 0 0 0
//6 0 0 0 2 0 0 5 2
//7 0 0 1 0 0 5 0 0
//8 0 0 0 0 0 2 0 0

#include<iostream>
#include<queue>
using namespace std;

//�ڵ���
#define M 8

//ͼ�ľ����ʾ
int matrix[M][M] =
{ 0, 2, 0, 0, 1, 0, 0, 0,
2, 0, 4, 13, 0, 0, 0, 0,
0, 4, 0, 0, 0, 0, 1, 0,
0, 13, 0, 0, 12, 2, 0, 0,
1, 0, 0, 12, 0, 0, 0, 0,
0, 0, 0, 2, 0, 0, 5, 2,
0, 0, 1, 0, 0, 5, 0, 0,
0, 0, 0, 0, 0, 2, 0, 0

};

//����ÿ���ڵ�����·��,��ʼ��Ϊ0xFFFF
int dist[M + 1] = { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
//calculate the distance
void Dijkstra_BFS(int startNodeNum)
{
	dist[startNodeNum] = 0;
	queue<int> q;
	q.push(startNodeNum);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		cout<<top<<" ";
		for (int i = 1; i <= M; ++i)
		{
			if (matrix[top - 1][i - 1] != 0 && (dist[top] + matrix[top - 1][i - 1]) < dist[i])
			{
				dist[i] = dist[top] + matrix[top - 1][i - 1];
				q.push(i);
			}
		}
	}
}


int main()
{
	Dijkstra_BFS(1);
	system("pause");
	return 0;
}


