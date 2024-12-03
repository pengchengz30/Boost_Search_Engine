# Boost Search Engine

A lightweight search engine implemented in C++ using the Boost library. This project is designed to efficiently parse, tokenize, index, and search through documents.

---

## Features

- **Efficient Parsing**: Extract and preprocess HTML content using `Boost::Filesystem` and custom parsing logic.
- **Tokenization**: Break down text into meaningful tokens, with support for stopword filtering and case normalization.
- **Inverted Indexing**: Quickly index documents for fast lookup.
- **Search Functionality**: Perform queries to retrieve relevant documents based on a scoring mechanism.

---

## Project Structure

### **Directories**
- **`Parse/`**:
  - **`GetFileList.h`**: Utilities for traversing directories and listing files.
  - **`HtmlInfo.h`**: Data structure for storing metadata and parsed content.
  - **`Parse.h`**: Parsing logic for extracting HTML content.
  - **`main.cpp`**: Entry point for parsing module.
  
- **`Tokenizer/`**:
  - **`Tokenizer.h`**: Tokenization logic with support for punctuation trimming and word normalization.
  - **`StopWords.h`**: Utility for loading and handling stopwords.
  - **`main.cpp`**: Entry point for tokenization module.

- **`Index/`**:
  - **`Index.h`**: Logic for building and managing inverted indexes.
  - **`main.cpp`**: Entry point for indexing module.

- **`Search_Engine/`**:
  - **`Search_Engine.h`**: Combines all modules to provide query and ranking functionality.
  - **`main.cpp`**: Entry point for the search engine.

---

## Prerequisites

1. **C++ Compiler**: Support for C++17 or newer.
2. **Boost Library**: Ensure Boost is installed on your system.
3. **Jsoncpp Library**: Ensure Jsoncpp is installed on your system.
3. **CMake**: For building the project.

---

## Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/pengchengz30/Boost_Search_Engine.git
   cd Boost_Search_Engine
   
2. Pending...
