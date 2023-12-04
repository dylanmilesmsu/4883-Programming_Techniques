## A11
### Dylan Miles
### Description:
Solution code to https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927

This one was a bit more challenging than most for me. I had a lot of difficulty getting dijkstras to work. Everything written in main was done quite quickly of course, and then several attempts at me implementing dijkstras went poorly. I even tried some brute force approaches, with mild success, but was still having issues.
Eventually, I asked chatgpt to help. At first, its help was unhelpful and had worse issues than my own code. Eventually I asked it a more generic problem: "just give me a dijkstras example on a weighted graph in c++". The output of that can be seen in [chatgpt.cpp](./chatgpt.cpp) After manually inputting everything into it, I found that it worked, and then adapted parts of it for my use, such as only paying attention to the end node, even though the function gets weights for all nodes, and fixing an edge-case when the starting and ending nodes were the same (the code chatgpt wrote for me would return integer max value)
tl;dr I guess ill study up on dijkstras algorithm because this was a struggle

### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [Main.cpp](./Main.cpp)         | Main driver of my project, contains all logic      |
|   2   | [10986.pdf](./10986.pdf)         | the instructions file from onlinejudge      |
|   3   | [Main](./Main)         | a binary for the program      |
|   4   | [in](./in)         | an example input       |
|   5   | [out](./out)         | the ouput of said example input       |

### Instructions

- Example run command:
    - `./main < in`

- Example compile command:
    - `g++ Main.cpp -o Main`

