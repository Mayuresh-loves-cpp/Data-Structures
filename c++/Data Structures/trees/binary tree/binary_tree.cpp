#include <iostream>

// ADT for tree node
class node {
public:
    node *left;
    node *right;
    int data;
    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// checks whether the input for data given by the user is numeric or not
bool isnumeric(std::string input) {
    for (int i = 0; i < input.length(); i++) {
        if (!isdigit(input[i])) return false;
    }
    return true;
}

// this function creates binary tree
node *create_node(node *parent_node, std::string dir) {
    std::string input, parent_data;
    int data;

    if (parent_node == NULL) {
        parent_data = "root node";
    } else {
        parent_data = std::to_string(parent_node -> data);
    }

    node *new_node;
    incorrect_data_for_node : std::cout << "Enter value for" << dir << " of " << parent_data << ": ";
    std::cin >> input;
    if (input == "leave" || input == "l" || input == "null") {
        return NULL;
    } else if (input == "exit") {
        std::cout << std::endl;
        exit(1);
    } else {
        if (!isnumeric(input)) {
            std::cout << "Please enter numerical values only or (leave/l/null) command to make child node emplty or type (exit) command to exit program..." << std::endl;
            goto incorrect_data_for_node;
        }
    }
    data = stoi(input);
    
    new_node = new node(data);
    new_node -> data = data;
    
    // taking left node
    new_node->left = create_node(new_node, " left");
    
    // taking right node
    new_node->right = create_node(new_node, " right");

    return new_node;
}

void inorder_display_tree(node* root_node) {
    if (root_node) {
        inorder_display_tree(root_node -> left);
        std::cout << root_node -> data << " ";
        inorder_display_tree(root_node -> right);
        // std::cout << root_node -> data << " ";
    } else {
        return;
    }
}

void postorder_display_tree(node* root_node) {
    if (root_node) {
        postorder_display_tree(root_node -> left);
        inorder_display_tree(root_node -> right);
        std::cout << root_node -> data << " ";
    } else {
        return;
    }
}

void preorder_display_tree(node *root_node, bool pretty) {
    // std::cout << root_node << std::endl;
    if (root_node == NULL) {
        return;
    }
    if (pretty) {
        std::cout << root_node -> data;
        if (root_node -> left != nullptr || root_node -> right != nullptr) {
            std::cout << " -> [";
        }
        if (root_node -> left != nullptr) {
            std::cout << " at left: ";
        }
        preorder_display_tree(root_node -> left, pretty);
        if (root_node -> right != nullptr) {
            std::cout << " at right: ";
        }
        preorder_display_tree(root_node -> right, pretty);
        std::cout << "], ";
    } else {
        std::cout << root_node -> data << " " ;
        preorder_display_tree(root_node -> left, pretty);
        preorder_display_tree(root_node -> right, pretty);
    }
    
}

// this functions erxtracts the main function's code
void operations() {
    int value;

    std::cout << std::endl << "THE BINARY TREE GENERATOR" << std::endl << std::endl;
    std::cout << "Enter values: -" << std::endl << std::endl;
    node *root_node;
    root_node = create_node(NULL, "");
    // std::cout << root_node << std::endl;
    std::string c, display_method;
    std::cout << std::endl << "In which manner you want the output: -" << std::endl;
    std::cout << " : inorder (in/inorder)" << std::endl << " : preorder (pr/preorder)" << std::endl << " : postorder (po/postorder)" << std::endl;
    wrong_type_display_method : std::cout << std::endl << "Enter (in/inorder/pr/preorder/po/postorder) : ";
    std::cin >> display_method;
    if (display_method == "in" || display_method == "inorder") {
        std::cout << std::endl << "Displaying Binary Tree in inorder traversal: -" << std::endl << std::endl;
        inorder_display_tree(root_node);
    } else if (display_method == "pr" || display_method == "preorder") {
        jump1 : std::cout << std::endl << "Do you want pretty output of the traversal (y or n) : ";
        std::cin >> c;
        if (c == "y") {
            std::cout << std::endl << "Displaying Binary Tree in preorder traversal: -" << std::endl;
            preorder_display_tree(root_node, true);
        } else if (c == "n") {
            std::cout << std::endl << "Displaying Binary Tree in preorder traversal: -" << std::endl << std::endl;
            preorder_display_tree(root_node, false);
        } else {
            goto jump1;
        }
    } else if (display_method == "po" || display_method == "postorder") {
        std::cout << std::endl << "Displaying Binary Tree in postorder traversal: -" << std::endl << std::endl;
        postorder_display_tree(root_node);
    } else {
        goto wrong_type_display_method;
    }
    std::cout << std::endl;
    jump2 : std::cout << std::endl << "want to try any other display method? (y or n) : ";
    std::cin >> c;
    if (c == "y") {
        goto wrong_type_display_method;
    } else if (c == "n") {
        std::cout << std::endl;
    } else {
        goto jump2;
    }
    delete root_node;
}

// the small main function
int main() {
    operations();
    exit(0);
}
