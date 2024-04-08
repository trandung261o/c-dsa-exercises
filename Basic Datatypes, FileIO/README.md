### Exercise 1: 
Display the array in reverse order
### Exercise 2: Find the Special Element in the Array
Extend the above example program to display the array element 
that is closest to the average value of all array elements.
### Exercise 3:
Write a program that takes an input string and displays the number of occurrences of each character in the string. 
The output should be displayed for the input string "hello, world!":

    The letter 'd' appears 1 time(s).
    The letter 'e' appears 1 time(s).
    The letter 'h' appears 1 time(s).
    The letter 'l' appears 3 time(s).
    The letter 'o' appears 2 time(s).
    The letter 'r' appears 1 time(s).
    The letter 'w' appears 1 time(s).
### Exercise 4:
Write a function that takes two integer arrays as arguments, both having the same number of elements. 
The function returns 1 if the two arrays have identical content and 0 for all other cases.
### Exercise 5:
Write a function:
- With parameters as a string and two characters.
- The function will traverse the string and replace all occurrences 
of the first character in the string with the second character.

Write a program to test the above function:
- Read a string that does not contain whitespace and two characters, 
then call the function with the specified arguments and print the result.
Example:
- Input: "papa", 'p', 'm'
- Result: "mama"
### Exercise 6: Word Separation
Write a program that reads a character string representing a sentence from the user. 
Then the program displays each word in the sentence on a separate line. 
A word is a sequence of consecutive characters that does not contain whitespace.
Example:
- Input: "The house next door is very old."
- Result:

    The
    
    house
    
    ….
### Exercise 7: 
Write a function that takes a real number (double) as an argument and returns its integer and fractional parts.
### Exercise 8:
Write a program that takes two real numbers as command line arguments, 
representing the length and width of a rectangle.
The program calculates and prints the area and perimeter of the rectangle based on these inputs.
### Exercise 9:
Write a program that allows the user to enter a sentence as command line arguments 
(each word in the sentence is a command line argument). 
The program displays the reversed content of the entered sentence.
Example: 

    ./inverse I love HUST
Result:

    HUST love I
##### Exercise 10:
    Write a program to calculate the exponential function of a natural base, e, raised to the power of x. 
    Users can run the program with two syntaxes:
    <Program_Name> <exponential_value>, for example: e 50
    Or
    <Program_Name> <exponential_value> <permissible_error>. For example: e 50 0.0003
##### Exercise 11:
    Write a program named 'sde' that takes command line arguments as the coefficients of a quadratic 
    equation ax^2 + bx + c = 0 and solves the equation, printing the solutions on the screen.
    - Syntax using 'sde a b c'
    - Example: ./sde 1 2 1 yields the result: x1 = x2 = -1
##### Exercise 12: Copying File Content
    Create a text file named 'lab1.txt' with any content, 
    saved in the same directory as the program.
    Write a program to read from the above file character by character, 
    then write them to a new file named 'lab1w.txt'.
##### Exercise 13:
    Re-implement the file content copying programming exercise, 
    but instead of using the fgetc and fputc function pair, 
    use the fgets and fputs function pair to read from the file and write to the file, 
    processing one line of text content at a time.
##### Exercise 14:
    Modify the file copying program so that the program only displays the file content on the screen, 
    then shows the number of lines of text.
    Illustration of the program interface:
        Reading file Haiku.txt…. done!
        Haiku haiku
        Tokyo
        Hanoi
        This file has 3 lines
##### Exercise 15: 
    Write a command-line program as follows:
    merge <file1> <file2> <file3>
    The program writes to file 3 by reading and
    merging each line sequentially from file 1 and file 2.
    The program reads a line from file 1, writes it to
    file 3, then reads a line from file 2 and writes it to
    file 3. Note: File 1 and File 2 may have a different
    number of lines; when one file's content is fully
    read, the program copies the remaining lines from
    the other file to file 3
### Exercise 16:
Create a text file named product.txt, where each line contains information about a product: 

ID (integer), Product Name (a string without whitespaces), Price (double). 

The data fields are separated by a space or tab character. For example:

    1 Samsung_Television_4K 20000000
    2 Apple_MacBook_2020 18560000
Write a program to read the above file into an array of structure elements and 
then display the content of the array on the screen in the following format:

    No     Product Name             Price
    1      Samsung_Television_4K    20000000
        ...
### Exercise 17: 
Implement the function my_strcat:
- Takes two input strings, s1 and s2.
- Returns a pointer pointing to the dynamically allocated memory containing the concatenated string of s1 and s2.

Example: Concatenating "hello_" and "world!" results in "hello_world!"
- Utilize dynamic memory allocation techniques.
- Test your function






