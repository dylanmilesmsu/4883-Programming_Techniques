## P673
### Dylan Miles
### Description:
Solution code to https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=614
Simply added all open brackets to a stack, and then once encountered a closing bracket, if the last thing on the stack was an opening bracket, pop it
If the last condition isn't true, or if theres still brackets left on the stack, print No. Otherwise, print Yes.

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [Main.java](./Main.java)         | Main driver of my project, contains all logic      |
|   2   | [input](./in)         | the input file used from uDebug to test the program      |
|   3   | [out](./out)         | another input file used from uDebug to test the program      |
|   4   | [p673.pdf](./p673.pdf)         | the instructions file from onlinejudge      |
|   5   | [Main.jar](./Main.jar)         | a binary for the program      |

### Instructions

- Example run command:
    - `java -jar main.jar < in > out`
