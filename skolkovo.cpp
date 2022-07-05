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
        map<Node*, Node*> mn;
        Node* dop = head;
        while (dop != nullptr)
        {
            mn[dop] = new Node(dop->val);
            dop = dop->next;
        }
        dop = head;
        while (dop != nullptr)
        {
            mn[dop]->next = mn[dop->next];
            mn[dop]->random = mn[dop->random];
        }
        return mn[head];
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