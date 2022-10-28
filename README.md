# Morse-Code-Translator
This program takes two text files, a Morse Code text file and a Conversion text file, and converts the Conversion text file into morse code, outputing the result to the console. It creates a Binary Search Tree with the Morse Code text file to preform the conversion. The Binary Search Tree and its nodes are template classes, meaning that it could make a BST from any text file.

---

# Structure
```
+-----------------------+     +---------------------------+     +----------------------+
|                       |     |            Main           |     |                      |
| Morse Table Text File +----->                           <-----+ Conversion Text File |
|                       |     | BST<MorseCode> SearchTree |     |                      |
+-----------------------+     +------^-------------^------+     +----------------------+
                                     |             |
                            +--------+----+   +~~~~+~~~~~~~~+
                            |  MorseCode  |   \    BST<T>   /
                            |             |   /             \
                            | char letter |   \ BSTNde<T> h /
                            | std::str mc |   +~~~~~~^~~~~~~+
                            +-------------+          |
                                            +~~~~~~~~+~~~~~~~~~+
                                            \    BSTNode<T>    /
                                            /                  \
                                            \      T Data      /
                                            /  BSTNde<T>* lPtr \
                                            \  BSTNde<T>* rPtr /
                                            +~~~~~~~~~~~~~~~~~~+
```
