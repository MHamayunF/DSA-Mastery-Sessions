#include <iostream>
#include <cctype>
using namespace std;

struct TreeElement {
    char value;
    TreeElement* left;
    TreeElement* right;

    TreeElement(char val)
	{
		value=val;
		left=NULL;
		right=NULL;
	}
};

class CustomBinaryTree {
private:
    TreeElement* root;

    TreeElement* add(TreeElement* element, char val) 
	{
        if (element == NULL) 
		{
            return new TreeElement(val);
        }
        if (tolower(val) < tolower(element->value)) 
		{
            element->left = add(element->left, val);
        } 
		else if (tolower(val) > tolower(element->value)) 
		{
            element->right = add(element->right, val);
        }

        return element;
    }

    TreeElement* find(TreeElement* element, char val) 
	{
        if (element == NULL || tolower(element->value) == tolower(val)) 
		{
            return element;
        }

        if (tolower(val) < tolower(element->value)) 
		{
            return find(element->left, val);
        } 
		else 
		{
            return find(element->right, val);
        }
    }

    TreeElement* getMin(TreeElement* element) 
	{
        while (element->left != NULL) 
		{
            element = element->left;
        }
        return element;
    }

    TreeElement* erase(TreeElement* element, char val) 
	{
        if (element == NULL) 
		{
            return NULL;
        }

        if (tolower(val) < tolower(element->value)) 
		{
            element->left = erase(element->left, val);
        } else if (tolower(val) > tolower(element->value)) 
		{
            element->right = erase(element->right, val);
        } else {
            if (element->left == NULL) 
			{
                TreeElement* temp = element->right;
                delete element;
                return temp;
            } else if (element->right == NULL) 
			{
                TreeElement* temp = element->left;
                delete element;
                return temp;
            }

            TreeElement* temp = getMin(element->right);
            element->value = temp->value;
            element->right = erase(element->right, temp->value);
        }

        return element;
    }

    void postOrderTraversal(TreeElement* element)
	{
        if (element == NULL) 
		{
            return;
        }

        postOrderTraversal(element->left);
        postOrderTraversal(element->right);
        cout << element->value << " ";
    }

    void preOrderTraversal(TreeElement* element) 
	{
        if (element == NULL) 
		{
            return;
        }

        cout << element->value << " ";
        preOrderTraversal(element->left);
        preOrderTraversal(element->right);
    }

    void inOrderTraversal(TreeElement* element) {
        if (element == NULL) {
            return;
        }

        inOrderTraversal(element->left);
        cout << element->value << " ";
        inOrderTraversal(element->right);
    }

public:
    CustomBinaryTree() : root(NULL) {}

    void add(char val) {
        root = add(root, val);
    }

    bool find(char val) 
	{
        return find(root, val) != NULL;
    }

    void erase(char val) 
	{
        root = erase(root, val);
    }

    void postOrderTraversal() 
	{
        postOrderTraversal(root);
        cout << endl;
    }

    void preOrderTraversal() 
	{
        preOrderTraversal(root);
        cout << endl;
    }

    void inOrderTraversal() 
	{
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    CustomBinaryTree customTree;
	cout<<"Name: Hamayun, RegId: 225158"<<endl;
	cout<<"-----------------------------------"<<endl;
    customTree.add('b');
    customTree.add('a');
    customTree.add('C');
    customTree.add('d');
    customTree.add('A');
    customTree.add('B');
    cout << "In-order traversal: ";
    customTree.inOrderTraversal();
    cout << "Pre-order traversal: ";
    customTree.preOrderTraversal();
    cout << "Post-order traversal: ";
    customTree.postOrderTraversal();
    cout << "Search for 'c': " << (customTree.find('c') ? "Found" : "Not Found") << endl;
    cout << "Search for 'D': " << (customTree.find('D') ? "Found" : "Not Found") << endl;
    customTree.erase('A');
    cout << "After removing 'A', In-order traversal: ";
    customTree.inOrderTraversal();

    return 0;
}

