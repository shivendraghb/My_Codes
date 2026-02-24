#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a new value into a Binary Search Tree (BST)
TreeNode* insertNode(TreeNode* root, int value) {
    // If the tree is empty, create the first node (root)
    if (root == nullptr) {
        return new TreeNode(value);
    }

    // Otherwise, recurse down the tree
    if (value < root->val) {
        root->left = insertNode(root->left, value);
    } else if (value > root->val) {
        root->right = insertNode(root->right, value);
    }
    // Handle duplicate values as per specific tree rules (here we ignore them)

    return root;
}

int heightDFS(TreeNode* root) {
    // Base case: an empty tree has a height of 0.
    if (!root) {
        return 0;
    }
    
    // Recursively find the height of the left and right subtrees.
    int leftHeight = heightDFS(root->left);
    int rightHeight = heightDFS(root->right);
    
    // The height of the current node is 1 plus the maximum of the two heights.
    return 1 + max(leftHeight, rightHeight);
}

int heightBFS(TreeNode* root) {
    if (!root) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int height = 0;

    while (!q.empty()) {
        // Get the number of nodes at the current level.
        int levelSize = q.size();
        
        // Process all nodes at the current level.
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = q.front();
            q.pop();

            // Add children to the queue for the next level.
            if (currentNode->left) {
                q.push(currentNode->left);
            }
            if (currentNode->right) {
                q.push(currentNode->right);
            }
        }
        // After processing a level, increment the height.
        height++;
    }

    return height;
}

int maxElementdfs(TreeNode* root) {
    if (root == nullptr)
        return INT_MIN;

    int leftmax = maxElementdfs(root->left);
    int rightmax = maxElementdfs(root->right);

    return max(root->val, max(leftmax, rightmax));
}

int maxElementbfs(TreeNode* root) {
    if (root == nullptr)
        return INT_MIN;

    int mv = INT_MIN;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        mv = max(mv, curr->val);

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }

    return mv;
}

int countNode(TreeNode* root) {
    if (root == nullptr)
        return INT_MIN;

    return 1 + countNode(root->left) + countNode(root->right);
}

TreeNode* findMin(TreeNode* root) {
    TreeNode* curr = root;

    while (curr && curr->left != nullptr)
        curr = curr->left;

    return curr;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
        return root;

    // Step 1: Search for the node to delete
    if (key < rooot->val)
        // The key is smaller, go to the left subtree
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        // The key is larger 
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->left;

        }
    }
}

int main() {
    TreeNode* root = nullptr; // Start with an empty tree
    int value;
    char choice;

    cout << "--- Binary Tree Initialization via User Input ---" << endl;

    do {
        cout << "Input a value to insert into the tree: ";
        // Use cin to get the integer value from the user
        if (!(cin >> value)) {
            cout << "Invalid input. Exiting." << endl;
            break;
        }

        // Insert the value into the tree
        root = insertNode(root, value);

        cout << "Want to insert another node? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Tree creation complete." << endl;
    // You can add tree traversal functions here to verify the structure

    // Remember to free allocated memory in a real application
    // (requires a separate function to deallocate the entire tree)

    int hd =heightDFS(root);
    cout << "height through dfs: " << hd << '\n';

    int hb = heightBFS(root);
    cout << "height through dfs: " << hb << '\n';

    int md = maxElementdfs(root);
    cout << "max element through dfs: " << md << '\n';
    
    int mb = maxElementbfs(root);
    cout << "max element through bfs: " << mb << '\n';

    int cnt = countNode(root);
    cout << "number of nodes: " << cnt << '\n';

    return 0;
}

