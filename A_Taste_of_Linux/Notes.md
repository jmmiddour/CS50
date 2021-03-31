# CS50' s New Year's Seminars 2021

# [A Taste of Linux](https://youtu.be/AG4A5C_k4Xo)

## File System Configuration:
![File Tree Image](https://raw.githubusercontent.com/jmmiddour/CS50/main/A_Taste_of_Linux/images/file_tree.jpg)
- Always starts with the "root" (`/`) directory (folder)

- File Paths:
    - Absolute Path:
        - Starts with the root directory (folder) `/`
        - Does not matter where you are in the tree.
        - The absolute path for `mario.c` in the above image would be: `/home/ubuntu/pset1/mario.c`

    - Relative Path:
        - Relative to where you are currently at (the current directory you are in only)
        - The relative path for `mario.c` if you are currently in the `ubuntu` directory in the above image would be: `pset1/mario.c` or `./pset1/mario.c` (`.` stands for the current directory). Either one of these will work though.
        - The relative path for `mario.c` if you are currently in the `pset0` directory in the above image would be: `../pset1/mario.c` (`..` takes you back to the parent directory first, then goes down the relative path from that parent folder)
    
- Linux does not care as much about file extensions like Windows does. Without adding an extension to a file name, Linux makes it a txt type of file.

## Main Directories (folders):
- `root` (`/`) = Base directory
- `home` = user files and folders (this is the where the all user "home" folders are stored)
- `usr` = some programs and/or libraries used by the programs 
- `etc` = system wide configuration files
- `opt` = 3rd party programs / software installed
- `tmp` = temporary files
- `run` = 
- `sys` = 


## Commands (using BASH shell):

- `cd` - change directory

- `cd /` - takes back to the root `/` directory no matter where you are in the file system

- `cd ..` - takes you to the prior directory or "parent" directory

- `ls` - list the contents of the current directory

- `ls <directory or path to directory>` - list the contents of the directory specified

- `~/` - the user's path when at the top user folder, the `~` represents the user's home folder.

- `pwd` - shows your "present working directory" (the directory you are currently in from the root directory)

- `touch <file name>` - Creates a new file in the current directory.

- `mkdir <folder name or path to folder and name>` - Creates a new directory in the current directory, or the directory you specify.

- `mv <file to move> <location to move to>` - moves a file to another directory. If you want to move multiple files into the same directory you can do so by just adding a space between, just make sure the destination directory is always the last parameter.

- `ls <directory> > <file name>` - will output to the file specified instead of the terminal. It the file does not already exist, it will create a new file with that name. This is called "output redirection"

- `cat` - when you hit enter the terminal will wait on you to input something and will repeat what you input when you hit enter. To exit out, push `ctrl + d` and the terminal will return you to the prompt.
    
    - `cat <file name>` - shows the contents in the file specified in the terminal.

    - `cat > <file name>` - allows you to input data into the file directly from the terminal. To exit out, just hit `ctrl + d`. If the file already exists, whatever you input here will overwrite the original data in the specified file.

        - The `>` is "output redirection" command. Can use it to redirect any output to what you chose to output to.

    - `cat >> <file name>` - allows you to append to an existing file and will not overwrite it.

        - The `>>` is "output redirection" command that allows you to append instead of overwrite or create.

    - `cat` is also used if you want to concatenate files together. This can be done like this: `cat <file 1> <file 2>` and it will output the contents of `file 1` then `file 2` in the terminal. 

    - You can also use `cat` to add the concatenated files into another file using the "redirect" command like this:  
        `cat <file 1> <file 2> > <new file>`

    - `cat < <file>` will input data from the file specified.

        - `<` is "input redirection" command.

    - `cat < <input file> > <output file>` - will write the input file to a new output file.
    
