# Huffman Coding Implementation in C++

This project implements the Huffman coding algorithm in C++. Huffman coding is a data compression technique that assigns variable-length codes to characters based on their frequency of occurrence. More frequent characters are assigned shorter codes, resulting in overall compression of the data.

## Features

- Build Huffman tree based on character frequencies
- Encode text using Huffman codes
- Decode Huffman-encoded text back to original form
- Simple command-line interface for demonstration

## Requirements

- C++ compiler with C++11 support (e.g., GCC, Clang)
- Standard C++ libraries

## Compilation

To compile the program, use the following command:

```
g++ -std=c++11 huffman_coding.cpp -o huffman_coding
```

This will create an executable named `huffman_coding`.

## Usage

After compilation, run the program using:

```
./huffman_coding
```

The program will encode a sample text, display the encoded version, and then decode it back to the original text.

## Modifying the Input

To encode and decode different text, modify the `text` variable in the `main()` function of `huffman_coding.cpp`:

```cpp
string text = "Your text here";
```

Then recompile and run the program.

## How It Works

1. The program builds a frequency table for each character in the input text.
2. It creates a priority queue of Huffman nodes based on these frequencies.
3. The Huffman tree is built by repeatedly combining the two nodes with the lowest frequencies.
4. Huffman codes are generated by traversing the tree, assigning '0' for left branches and '1' for right branches.
5. The text is encoded using these Huffman codes.
6. For decoding, the program traverses the Huffman tree based on the encoded bits to recover the original text.

## Class Structure

- `HuffmanNode`: Represents a node in the Huffman tree.
- `Compare`: A comparator for the priority queue.
- `Huffman`: The main class containing methods for building the tree, encoding, and decoding.

## Performance

Huffman coding provides optimal prefix-free encoding and can lead to significant compression for texts with highly skewed character frequencies. The time complexity for building the Huffman tree is O(n log n), where n is the number of unique characters.

## Future Improvements

- Implement file I/O to read from and write to files.
- Add command-line arguments for specifying input text or files.
- Optimize memory usage for very large inputs.

## License

This project is open-source and available under the MIT License.

## Contributing

Contributions, issues, and feature requests are welcome. Feel free to check issues page if you want to contribute.

## Author

Naman Jhanwar

---

For more information on Huffman coding, visit [Huffman Coding on Wikipedia](https://en.wikipedia.org/wiki/Huffman_coding).
```



