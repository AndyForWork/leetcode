#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dop = head;
        Node* res = nullptr;
        Node* res_start = nullptr;
        map<Node*,Node*> nodes;
        while (dop != nullptr)
        {
            if (res == nullptr)
            {
                res = new Node(dop->val);
                res_start = res;
                nodes[dop] = res;
            }
            else
            {
                Node* newNode = new Node(dop->val);
                res->next = newNode;
                nodes[dop] = newNode;
                res = res->next;
            }
            dop = dop->next;
        }
        res = res_start;
        while (head != nullptr)
        {
            if (head->random == nullptr)
                res->random = nullptr;
            else
                res->random = nodes[head->random];
            head = head->next;
            res = res->next;
        }
        return res_start;

    }
};


int main()
{
    Solution s;
    int n;
    cin >> n;
    vector<Node*> vec;
    vector<int>poses;
    for (int i = 0; i < n; i++)
    {
        int m, n;
        cin >> m >> n;
        vec.push_back(new Node(m));
        if (i != 0)
            vec[i - 1]->next = vec[i];
        poses.push_back(n);
    }
    for (int i = 0; i < n; i++)
    {
        if (poses[i] == -1)
            vec[i]->random = nullptr;
        else
            vec[i]->random = vec[poses[i]];
    }
    cout << s.copyRandomList(vec[0]);
}