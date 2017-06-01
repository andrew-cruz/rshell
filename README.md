# CS100 - Assn3: RSHELL

## Test Command
* Added the test command and the [] equivalent where it checks if the file or directory exists, if the path given is a file, and if the path given is a directory. It returns 0 (True) if the test worked properly and returns 1 (False) if the test failed.
## The Precedence Operators
* Added a parentheses class where commands and arguments have precedence.

## Known bugs
* When manually inputting our test cases, our program doesn't output extra lines which is fine
* But, when we use the shell test cases, our program outputs extra lines and no endl's are evident
* When inputting a single command in parentheses the program segfaults
* When inputting multiple commands the order in which the commands are executed is reversed due to the way we push and pop into our stack 

### Rubric
* 5 points for well commented
* 5 points for following style guidelines
* 20 points for sufficient test cases
* 40 points for test operator (including integration with precedence and past requirements)
* 30 points for precedence operators (including integration with test and past requirements)


## Authors

* **Andrew Cruz**
* **Jonathan Kaneshiro**

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE.md](https://github.com/andrew-cruz/rshell/blob/exec/LICENSE) file for details
