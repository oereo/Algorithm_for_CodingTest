#include <iostream>
#include <algorithm>
using namespace std;


struct qq {
	int a=0;
	int trigger = 0;
};
int front = 0;
int rear = 0;
int CNT;
void push_bk(qq que[])
{
	qq temp=que[front];
	que[rear] = temp;
	rear++;
	front++;
	
}
void clear()
{
	front = 0;
	rear = 0;
	CNT = 0;
	
}
void pop()
{
	front++;	
}

int main()
{
	int temp;
	int roo;
	cin >> roo;
	int N, M;
	for (int i = 0; i < roo; i++)
	{
		qq que[10000];
		int ma[100] = { 0, };
		cin >> N >> M;
		
		que[M].trigger = 1;
		
		
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			que[j].a = temp;
			rear++;
			ma[j] = que[j].a;
		}
		sort(ma, ma + N);
	
		int k = front; int j = 0;
		while(1)
		{
		
			if (ma[N-1-j] > que[front].a)
			{
				push_bk(que);
			}
			else if(que[front].trigger==1)
			{	que[front].trigger = 0;
				CNT++;
				cout << CNT << endl;
				clear();
				break;
			}
			else 
			{
				pop();
				j++;
				CNT++;	
			}	
		}
	}
}