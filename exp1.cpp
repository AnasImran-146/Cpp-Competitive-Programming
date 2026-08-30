#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

// Global variable to store the maximum sum found across all BST subtrees
int max_bst_sum = 0; 

// --- Node Class and Tree Building Functions (omitted for brevity, they remain the same) ---

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

vector<Node*> nodes;

void insertOne(int val){
    int index = nodes.size();
    nodes.push_back(NULL);

    if(val == -1)
        return;

    Node* newNode = new Node(val);
    nodes[index] = newNode;

    if(index != 0){
        int parent = (index - 1) / 2;

        if(nodes[parent] != NULL){
            if(index == 2*parent + 1)
                nodes[parent]->left = newNode;
            else
                nodes[parent]->right = newNode;
        }
    }
}

Node* buildTree(int arr[], int n){
    nodes.clear();
    for(int i = 0; i < n; i++){
        insertOne(arr[i]);
    }
    return nodes[0];
}

void levelorder(Node* node){
    if(!node) return;

    queue<Node*> q;
    q.push(node);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout << endl;
            if(!q.empty()) q.push(NULL);
            continue;
        }

        cout << curr->data << " ";

        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
// ---------------------------------------------------------------------------------------


class Info {
public:
    int max_val;
    int min_val;
    bool is_bst;
    int sum;

    Info(int mx, int mn, bool b, int s) : max_val(mx), min_val(mn), is_bst(b), sum(s) {}
};

Info findBSTSubtreeInfo(Node* root) {
    if (root == NULL) {
        return Info(INT_MIN, INT_MAX, true, 0); 
    }

    Info left_info = findBSTSubtreeInfo(root->left);
    Info right_info = findBSTSubtreeInfo(root->right);

    int current_sum = root->data + left_info.sum + right_info.sum;

    bool is_current_bst = 
        left_info.is_bst &&
        right_info.is_bst &&
        (root->data > left_info.max_val) &&
        (root->data < right_info.min_val);

    int current_min = min({root->data, left_info.min_val, right_info.min_val});
    int current_max = max({root->data, left_info.max_val, right_info.max_val});

    // 💡 The NEW Logic: Update the global maximum sum if this subtree is a BST
    if (is_current_bst) {
        cout << "Subtree rooted at " << root->data << " IS a BST. Sum: " << current_sum << endl;
        // Update the maximum sum found so far
        max_bst_sum = max(max_bst_sum, current_sum); 
    } else {
        cout << "Subtree rooted at " << root->data << " is NOT a BST." << endl;
    }

    return Info(current_max, current_min, is_current_bst, current_sum);
}

int main() {
    // Input array for the tree structure from the image
    int arr[] = {1, 7, 9, 2, 6, 9, -1, -1, -1, 5, 11, 5, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildTree(arr, n);

    cout << "Tree Structure (Level-Order Traversal):" << endl;
    levelorder(root); 

    cout << "\nChecking all subtrees for BST property and calculating sum:" << endl;
    
    // Reset max_bst_sum before starting the search
    max_bst_sum = 0; 
    findBSTSubtreeInfo(root);

    // 🏆 Final Print: The result you were looking for!
    cout << "\n--- Final Result ---" << endl;
    cout << "The **maximum sum** of any valid BST subtree is: **" << max_bst_sum << "**" << endl;

    return 0;
}