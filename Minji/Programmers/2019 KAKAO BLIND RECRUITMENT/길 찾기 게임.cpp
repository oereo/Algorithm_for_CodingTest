#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y, index;
    Node *left;
    Node *right;
};

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return a[0] < b[0];
    else
        return a[0] > b[0];
}

vector<int> precircuit(const Node *node, vector<int> &pre)  // 현재 노드 - 왼쪽 노드 - 오른쪽 노드
{
    pre.push_back(node->index);
    if (node->left != NULL)
        precircuit(node->left, pre);
    if (node->right != NULL)
        precircuit(node->right, pre);
    return pre;
}

vector<int> postcircuit(const Node *node, vector<int> &post) // 왼쪽 노드 - 오른쪽 노드 - 현재 노드
{
    if (node->left != NULL)
        postcircuit(node->left, post);
    if (node->right != NULL)
        postcircuit(node->right, post);
    post.push_back(node->index);

    return post;
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    // 인덱스 추가
    for (int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i + 1);

    // y값 내림차순, x값 오름차순 정렬
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);


    // 트리 저장
    Node root = { nodeinfo[0][0], nodeinfo[0][1], nodeinfo[0][2], NULL, NULL };
    Node * iter;
    for (int i = 1; i < nodeinfo.size(); i++) {
        iter = &root;
        while (1) {
            if (iter->x > nodeinfo[i][0]) { // 왼쪽 노드
                if (iter->left == NULL) {
                    iter->left = new Node{nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2], NULL, NULL};
                    break;
                }
                else
                    iter = iter->left;
            }
            else{   // 오른쪽 노드
                if (iter->right == NULL)
                {
                    iter->right = new Node{nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2], NULL, NULL};
                    break;
                }
                else
                    iter = iter->right;
            }
        }        
    }

    // 전위 순회, 후위 순회
    vector<vector<int>> answer;
    vector<int> pre;
    vector<int> post;
    answer.push_back(precircuit(&root, pre));
    answer.push_back(postcircuit(&root, post));
    return answer;
}

// 참고 : https://chaibin0.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%EA%B8%B8%EC%B0%BE%EA%B8%B0-%EA%B2%8C%EC%9E%84#recentComments