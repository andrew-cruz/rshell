# CS100 - Assn4: RSHELL

## Redirection and Piping
* Using the UNIX functions dup and pipe to extend our rshell program so that it properly handles input redirection <, output redirection > and >>, and piping |

## Known bugs
* Can't handle multiple redirections
* Can't handle multiple piping
* 1 input and 1 output works for piping, but does not completely exit out of the execute function for the leaf node
* Sometimes multiple files are created when executing redirection
* Precedence works now!
* Doesn't exit out of redirection

## Authors

* **Andrew Cruz**
* **Jonathan Kaneshiro**

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE.md](https://github.com/andrew-cruz/rshell/blob/exec/LICENSE) file for details
