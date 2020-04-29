#include <iostream>
#include <windows.h>
#include <vector>
#include <queue>

using namespace std;

typedef char KEY_TYPE;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<char>> layerTravel(TreeNode *root){
    vector<vector<char>> ans;
    if (root==NULL){
        return ans;
    }
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        vector<char> temp;
        for (int i = q.size() - 1; i >= 0;i--){
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(temp);
    }
    return ans;
}

TreeNode* consTree(vector<KEY_TYPE> a, int idx){
    if (a[idx]=='#'){
        return NULL;
    }
    TreeNode *root = new TreeNode(a[idx]);
    int l = idx * 2 + 1;
    int r = idx * 2 + 2;
    if (l<a.size()-1){
        root->left = consTree(a, l);
    }
    else{
        root->left = NULL;
    }
    if (r<a.size()){
        root->right = consTree(a, r);
    }
    else{
        root->right = NULL;
    }
    return root;
}

int main(){
    vector<KEY_TYPE> a;
    KEY_TYPE temp;
    while((temp=cin.get())!='\n'){
        if(temp!=' '){
            a.push_back(temp);
        }
    }
    TreeNode *root = consTree(a, 0);
    vector<vector<char>> ans = layerTravel(root);
    for (int i = 0; i < ans.size();i++){
        for (int j = 0; j < ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    system("pause");
    return 0;
}