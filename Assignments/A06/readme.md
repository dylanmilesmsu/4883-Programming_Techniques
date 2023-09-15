## P161
### Dylan Miles
### Description:
Solution code to https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1167

I first attempted to solve this problem in Java, but found that uvaonline runs Java too slowly to complete under the runtime. No clue how the other 6612 managed to get it to run fast enough in java, and I'm even more impressed by the 847 people who got it working in Python. On my machine (3900X) I can run it on a whole 5MB dictionary file and complete it in around 900ms, but onlinejudge's persumably 25 year old CPU takes over 3 seconds. Oh well, C++ it is. 

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [Main.java](./Main.java)         | NOT the driver of my project, contains all logic but is too slow.     |
|   2   | [input](./input)         | the input file used from uDebug to test the program      |
|   3   | [10226.pdf](./10226.pdf)         | the instructions file from onlinejudge      |
|   4   | [main.jar](./main.jar)         | a binary for the Java program      |

### Instructions

Compiled with GCC

- Example run command:
    - `./java -jar Main.jar < input`
