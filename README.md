## CS-530, Spring 2019 Assignment 1
### Developed by Zach Selchau(cssc0418) and Darpan Beri(cssc0429)

#### The Program:
    The program is a hexadecimal file dump program named xbd.
    The program opens a regular type file, reads every file and has the ability to write either ASCII or hex value for that byte as well as it's printable character.

#### Files Included:
**README.d**:

    A README file describing the program and detailing it.

**xbd.cpp**:

    Add description here.

**HEADER FILE HERE**:

    Add description here.

**Makefile**:

    Creates a compiled version of xbd.cpp.

#### Compilation Instructions:
    make all
    	compiles the xbd file
    make clear
    	deletes the xbd file
    **Running the Program**
    	xbd <filename>
    	xbd -b <filename>
**NOTE:** <> are not part of the command.

#### Operating Instructions:
**Command Line Options**:

    -b: The "binary" option. Outputs in binary and human readable characters instead of hex and human readable characters.

**Required Input**:

    The program can only work with regular file type(binary or text/ASCII content). Unwanted behavior will occur otherwise.

#### Significant Design Decisions:
    We stored the file in strings for binary, hex, and ASCII content and edited the strings.

#### Extra features:
**Binary to Decimal:**

    We decided to convert Binary -> Decimal -> Hex/ASCII instead of Binary -> Hex/Ascii. The reason for this was that converting through Decimal made it simpler and intuitive. Also, we had a hard time figuring out how to convert from Binary -> Ascii (Human readable).

**Decimal to Hex:**

    Thanks to our previous feature, we also implemented a Decimal to Hex converter.

**Decimal to Binary:**

    We needed this to convert from ASCII to binary as we would get the ASCII value first and then convert to binary.

**Decimal to Human readable:**

    We needed this to convert from binary to human readable. We only wanted printable characters so we had to make sure that we did not convert ASCII values > 127 and < 31.

#### Known Deficiencies and Bugs:
**None i guess**

#### Lessons Learned:
* An algorithm takes 1 hour to figured out. Its implementation takes 1 week.

* Commenting code helps to prevent bugs.

* Testing is difficult if one doesnt have access to the right system.

* Its easier to use WebIDE of gitlab than to figure out how to push to someone's else repo.

* One must verify any assumption made during coding (in our case was the way to determine whether an input file was binary or text).

* Starting early feels nice.

* Zach is really good with C++

* DB is really good with Algorithms.

