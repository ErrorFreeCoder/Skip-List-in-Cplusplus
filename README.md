# Skip List Implementation in C++

This repository contains a robust and efficient implementation of a Skip List data structure in C++. The Skip List is a probabilistic data structure that allows for fast search, insertion, and deletion operations, providing an average time complexity of O(log n) for these operations.

## Features

- **Dynamic Level Generation**: Utilizes a probabilistic approach to generate levels for each node, ensuring balanced performance.
- **Customizable Maximum Level**: The maximum level of the Skip List is configurable (default set to 7).
- **Comprehensive Operations**: Supports insertion, deletion, search, and display functionalities.
- **User-Friendly Interface**: Includes a simple console-based interface for interacting with the Skip List.

## Structure

The implementation consists of two main classes:

1. `Node`: Represents individual elements in the Skip List.
2. `SkipList`: Manages the Skip List structure and operations.

### Key Components

- **Node Creation**: Efficiently creates nodes with random levels.
- **Insertion**: Inserts new elements while maintaining the Skip List properties.
- **Deletion**: Removes elements and adjusts the Skip List structure accordingly.
- **Search**: Performs fast lookups utilizing the multi-level structure.
- **Display**: Visualizes the current state of the Skip List across all levels.

## Usage

The `main()` function provides a simple interface to interact with the Skip List. Users can:

1. Insert data
2. Delete data
3. Search for data
4. Display the entire Skip List
5. Exit the program

## Performance

This implementation aims to provide:

- O(log n) average time complexity for search, insert, and delete operations
- O(n) space complexity

## Future Improvements

- Implement iterators for more flexible traversal
- Add serialization and deserialization capabilities
- Extend to support generic data types using templates

## Contributing

Contributions to improve the implementation or extend its functionality are welcome. Please feel free to submit pull requests or open issues for discussion.

## License

SOHAIB-RASHED

---
