#include <iostream>
#include <queue>
typedef struct node
{
    int data;
    struct node *left, *right;
} Node;
void dfs(Node *root)
{
    if (root)
    {
        dfs(root->left);
        std::cout << root->data << " ";
        dfs(root->right);
    }
}

void sfs(Node *root)
{
    std::queue<Node *> q;
    Node *cur;
    q.push(root);

    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        std::cout << cur->data << " ";

        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }
}

int main()
{
    Node m[7];
    for (int i = 0; i < 7; i++)
    {
        m[i].data = i;
        m[i].left = m[i].right = nullptr;
    }

    m[0].left = &m[1];
    m[0].right = &m[2];
    m[1].left = &m[3];
    m[1].right = &m[4];
    m[2].left = &m[5];
    m[2].right = &m[6];

    for (int i = 0; i < 7; i++)
    {
        std::cout << m[i].data << " ";
    }
    std::cout << "\n";

    std::cout << "dfs: ";
    dfs(&m[0]);
    std::cout << "\n";

    std::cout << "sfs: ";
    sfs(&m[0]);
    std::cout << "\n";

    return 0;
}
