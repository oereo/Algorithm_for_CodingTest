#include <string>
#include <vector>

using namespace std;
int ma[500000];
struct q {
	int size;
	int send=-1;	
};
q stack[500000];
void search(int i)
{	
	if (ma[i-1] >= stack[i].size) {
		int j = i - 1;
		while (j >= 0) {
			if (stack[i].size < stack[j].size)
			{
				stack[i].send = j;
				break;
			}
			j--;
		}
	}
	
}

vector<int> solution(vector<int> heights) {
    int len=heights.size();
    ma[0]=heights[0];
    stack[0].size=heights[0];
    for(int i=1;i<len;i++)
    {
        stack[i].size=heights[i];
       if (ma[i-1]<stack[i].size){
			ma[i] = stack[i].size;
		}
		else
		{
			ma[i] = ma[i - 1];
		}
        
    }
    for (int i = len - 1; i >= 1; i--)
	{

		search(i);
	}
    vector<int> answer;
    for (int i = 0; i < len; i++)
	{
		
			stack[i].send++;
		
		 answer.push_back(stack[i].send);

		
	}
    
   
    return answer;
}