##### Exercise 1 (singly linked list): 
    Build a program to perform the following tasks:
    - Generate a random list with integer elements. After that:
    - From the generated list, create two separate lists: 
    one containing all positive numbers, and the other containing all negative numbers from the original list.

##### Exercise 2 (singly linked list): Student Record Management Exercise
    A student record includes:
      -name: the student's name
      -email: the student's email address
    Write a command-line interactive program to perform basic operations in student record management.
    Perform the following tasks:
      -Read data from a text file into a list
      -Print the list of students
      -Add a record to the end of the list
      -Delete a record
      -Search for a record
      -Save the records to a text file.

##### Exercise 3 (doubly linked list): Student Record Management Exercise
    A student record includes:
      -name: the student's name
      -email: the student's email address
    Write a command-line interactive program to perform basic operations in student record management.
    Perform the following tasks:
      -Read data from a text file into a list
      -Print the list of students
      -Add a record to the end of the list
      -Delete a record
      -Search for a record
      -Save the records to a text file.

##### Exercise 4 (Stack): manipulations with stack
    - createStack
    - isEmpty
    - push
    - pop
    - destroyStack        

##### Exercise 5 (Stack): Base Conversion Problem
    Input:
        Decimal number n, base b (b<10)
    Output:
        Corresponding number in base b

##### Exercise 6 (Stack):
    Every '(', '{', or '[' must be paired with ')', '}', or ']'
    - Examples:
    Correct: ( )(( )){([( )])}
    Correct: ((( )(( )){([( )])}))
    Incorrect: )(( )){([( )])}
    Incorrect: ({[ ])}
    Incorrect: (

##### Exercise 7 (Queue): Escape the Matrix
    A maze is represented by a binary matrix A of size M x N, where A[i][j] equals 1 if the cell (i, j) is a brick wall, 
    and A[i][j] equals 0 if the cell (i, j) is an empty cell that can be entered.
    From an empty cell, you can move to any of its 4 adjacent cells (up, down, left, right) if that cell is also an empty cell.
    Compute the minimum number of moves required to exit the maze starting from a given empty cell (i_0, j_0).
    Note: The solution should be calculated such that it uses the fewest possible moves.

##### Exercise 8: Maze
    Một mê cung hình chữ nhật được biểu diễn bởi 0-1 ma trận NxM trong đó 
    A[i,j] = 1 thể hiện ô (i,j) là tường gạch và A[i,j] = 0 thể hiện ô (i,j) là ô trống, có thể di chuyển vào. 
    Từ 1 ô trống, ta có thể di chuyển sang 1 trong 4 ô lân cận 
    (lên trên, xuống dưới, sang trái, sang phải) nếu ô đó là ô trống.
    Xuất phát từ 1 ô trống trong mê cung, hãy tìm đường ngắn nhất thoát ra khỏi mê cung.
    - Input: 
        Dòng 1: ghi 4 số nguyên dương n, m, r, c trong đó 
                n và m tương ứng là số hàng và cột của ma trận A (1 <= n,m <= 999) 
                và r, c tương ứng là chỉ số hàng, cột của ô xuất phát.
        Dòng i+1 (i=1,...,n): ghi dòng thứ i của ma trận A
        
    - Output:
        Ghi giá số bước cần di chuyển ngắn nhất để thoát ra khỏi mê cung, 
        hoặc ghi giá trị -1 nếu không tìm thấy đường đi nào thoát ra khỏi mê cung.
   
    Ví dụ:
    
        Input
        8 12 5 6
        1 1 0 0 0 0 1 0 0 0 0 1
        1 0 0 0 1 1 0 1 0 0 1 1
        0 0 1 0 0 0 0 0 0 0 0 0
        1 0 0 0 0 0 1 0 0 1 0 1
        1 0 0 1 0 0 0 0 0 1 0 0
        1 0 1 0 1 0 0 0 1 0 1 0
        0 0 0 0 1 0 1 0 0 0 0 0
        1 0 1 1 0 1 1 1 0 1 0 1
        
        Output
        7
