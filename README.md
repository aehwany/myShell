# myShell
Name: Ahmed Elehwany

## OS
Mac OS X

## Instructions
`gcc -c shell.c interpreter.c shellmemory.c`

`gcc -o mysh shell.o interpreter.o shellmemory.o`

`./mysh`

## Operations
| Command (case sensitive)    |      Description                          |
|:----------------------------|:------------------------------------------|
| help 			                  | 	Displays all the commands               |
| quit 			                  |  Exits / terminates the shell with "Bye!" |
|	set VAR STRING 		        	|   Assigns a value to VAR in shell memory  |
|	print VAR 				          | Displays the STRING assigned to VAR       |
|	run SCRIPT.TXT 		         	|	Executes the file SCRIPT.TXT              |

## Assumptions
1. Running script recursively beyond a limit will cause at some point an error opening the script file, therefore terminating the recursion.
2. Running quit inside a script will exit the script, not the shell.
3. The command "set bobbie Montreal Canadians", is computed as bobbie=Montreal
4. $ sign only shows when using the command line prompt to enter a command.
5. If running a script of commands, only output of the script will be printed with no $ signs.
6. program supports manually entering commands, piping commands from a script file and running a script file.
