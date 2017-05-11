# CS100 - Assn2: RSHELL

We will be implementing a command shell using C++ called rshell which reads in a
single command line at a time of with n number of arguments. It then executes the commands and arguments using C++ syscalls in the order that it was written. The program is exited once the user types in “exit” into the command line.

## Known bugs
* Realized until the last day of the deadline that this assignment should be about design patterns. We were too focused on creating only the Command and Shell classes
* If we had a redo, we would have classes for the commands (e.g ls, echo), arguments(-a, hello world), connector commands (&&, ||) and implement a Composite pattern from that
* Not executing multiple commands with && and ||

### Rubric
* 5 points for well commented code
* 5 points for following style guidelines
* 20 points for sufficient test cases
* 20 points for executing single commands
* 20 points for executing commands with ;, &&, and ||
* 20 points for executing commands with comments
* 10 points for exit commands


## Authors

* **Andrew Cruz**
* **Jonathan Kaneshiro**

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE.md](https://github.com/andrew-cruz/rshell/blob/exec/LICENSE) file for details
