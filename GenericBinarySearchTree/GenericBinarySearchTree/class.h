#include <iostream>

// NAMESPACES
using namespace std;

// TEMPLATED CLASS
template <typename T>
class GenericBinarySearchTree {
	public:
		struct TreeNode {
			T data;
			TreeNode* left;
			TreeNode* right;
			TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
		};

		// MEMBERS
		TreeNode* tree;

		// CONSTRUCTOR AND DESTRUCTOR
		GenericBinarySearchTree() : tree(nullptr) {}
		~GenericBinarySearchTree() {
			tree = nullptr;
		}

		// METHODS
		void AddItem(T item) {
			AddItem(tree, item);
		}

		bool FindItem(T item) {
			return FindItem(tree, item);
		}

		bool RemoveItem(T item) {
			return RemoveItem(tree, item);
		}

		void PreOrder() {
			PreOrder(tree);
			cout << endl;
		}

		void InOrder() {
			InOrder(tree);
			cout << endl;
		}

		void DeletePostOrderNodes() {
			DeletePostOrderNodes(tree);
			tree = nullptr;
		}
	private:
		TreeNode* FindMinimumInTree(TreeNode* node) {
			while (node->left) {
				node = node->left;
			}
			return node;
		}

		// OVERLOADED METHODS (YAY RECURSION, BRINGS ME BACK TO JAVA DAYS)
		void AddItem(TreeNode* &node, T item) {
			if (!node) {
				node = new TreeNode(item);
				return;
			}

			if (item < node->data) {
				AddItem(node->left, item);
			} else {
				AddItem(node->right, item);
			}
		}

		bool FindItem(TreeNode* node, T item) {
			if (!node) {
				return 0;
			}
			return node->data == item ? 1 : (item < node->data ? FindItem(node->left, item) : FindItem(node->right, item));
		}

		bool RemoveItem(TreeNode* &node, T item) {
			if (!node) {
				return false;
			}

			if (item < node->data) {
				return RemoveItem(node->left, item);
			} else if (item > node->data) {
				return RemoveItem(node->right, item);
			} else {
				if (!node->left) {
					TreeNode* temp = node;
					node = node->right;
					delete temp;
				} else if (!node->right) {
					TreeNode* temp = node;
					node = node->left;
					delete temp;
				} else {
					TreeNode* minNode = FindMinimumInTree(node->right);
					node->data = minNode->data;
					RemoveItem(node->right, minNode->data);
				}
				return true;
			}
		}

		void PreOrder(TreeNode* node) {
			if (!node) {
				return;
			}

			cout << node->data << endl;
			PreOrder(node->left);
			PreOrder(node->right);
		}

		void InOrder(TreeNode* node) {
			if (!node) {
				return;
			}

			InOrder(node->left);
			cout << node->data << endl;
			InOrder(node->right);
		}

		void DeletePostOrderNodes(TreeNode* node) {
			if (!node) {
				return;
			}

			DeletePostOrderNodes(node->left);
			DeletePostOrderNodes(node->right);
			cout << "Deleting node with value: " << node->data << endl;
			delete node;
		}
};
