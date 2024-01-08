##### Exercise 1: 
    -Traverse the tree using three algorithms: Preorder traversal, Inorder traversal, Postorder traversal.
    -Write a function to free the memory of a tree: freeTree(TreeNode *r)
    -Write a function to count the total number of nodes in the tree: countNode(Treenode *r)
    -Write a function to count the total number of leafs in the tree: countLeaf(Treenode *r)
    -Write a function to count the total number of nodes with k child in the tree: countNodeWithKchild(Treenode *r)
<img width="286" alt="Screenshot 2023-12-13 202844" src="https://github.com/trandung261o/c-dsa-exercises/assets/114976992/e9d74d3c-ba31-4639-9db6-f6d362c53205">

##### Exercise 2: (Binary tree)
    -Traverse the binary tree using three algorithms: Preorder traversal, Inorder traversal, Postorder traversal.
    -Write a function to free the memory of a binary tree: freeTree(TreeNode *r)
    -Write a function to count the total number of nodes in the binary tree: countNode(Treenode *r)
    -Write a function to count the total number of internal nodes in the binary tree: countInternalNode(Treenode *r)
    -Write a function to count the total number of nodes with k child in the binary tree: countNodeWithKchild(Treenode *r)
<img width="239" alt="Screenshot 2023-12-14 002616" src="https://github.com/trandung261o/c-dsa-exercises/assets/114976992/290a9c8e-93c8-4336-92cb-6b32578a1c02">

##### Exercise 3: (Binary tree)
    Write a C program to run interactively with the following commands:
    -Load <filename>: Load data from file <filename> and construct the tree
    -Print: Print the tree to the screen
    -AddLeftChild <cur_id> <child_id>: Add the left child <child_id> (if not
    already existent) to the node with identifier <cur_id> if <cur_id> exists
    -AddRightChild <cur_id> <child_id>: Add the right child <child_id> (if not
    already existent) to the node with identifier <cur_id> if <cur_id> exists
    -Find <id>: Find the node with identifier <id>
    -Count: Count the number of nodes in the tree
    -FindLeaves: Print to the screen the leaf nodes of the tree
    -Height <id>: Print to the screen the height of the node <id> (if it exists)
    -Store <filename>: Save the tree data to file <filename>
    -Quit: Exit the program

##### Exercise 4: (Normal tree)
##### Exercise 5: Binary tree manipulation 2
    insert node
    delete node
    khi cây rỗng, in ra NONE
##### Exercise 6: 
    Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
    insert k: insert a key k into the BST (do not insert if the key k exists)
    - Input
    Each line contains command under the form: “insert k”
    The input is terminated by a line containing #
    - Output
    Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)
    insert 20
    insert 10
    insert 26
    insert 7
    insert 15
    insert 23
    insert 30
    insert 3
    insert 8
    #
    Output
    20 10 7 3 8 15 26 23 30

