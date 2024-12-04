# User-Item Recommendation System

## Abstract

This document provides an overview of the User-Item Recommendation System project. It includes detailed descriptions of the project's structure, files, setup instructions, usage, and future directions.

## Project Structure

```
.
├── data
│   └── interaction.csv      # CSV file with user-item interaction data
└── src
    ├── main.cpp             # Entry point of the application
    ├── recommendersystem.cpp  # Logic for recommendation system using DFS
    └── recommendersystem.h    # Header file for the recommendation system logic
```

### Explanation of Project Structure

- `data/interaction.csv`: Contains the interaction data between users and items. This file lists which users have interacted with which items (e.g., liked or viewed).
- `src/main.cpp`: The entry point of the program. It loads the interaction data and prompts the user to input a username. It then generates and displays recommendations using the `RecommenderSystem` class.
- `src/recommendersystem.cpp`: Contains the logic for the recommendation system. It constructs a graph from the interaction data and performs DFS-based traversal to recommend items for a given user.
- `src/recommendersystem.h`: The header file that declares the `RecommenderSystem` class and its methods.

## Architecture

The recommendation system is based on a graph-based approach:

### Graph Representation
- Users and items are represented as nodes.
- An edge exists between a user and an item if the user has interacted with that item.

### DFS Algorithm
- The system uses DFS (Depth-First Search) to explore the graph. Starting from the user node, the system traverses through connected users and items, gathering recommendations.

### CSV-Driven Input
- The system dynamically loads user-item interaction data from `interaction.csv`.

## Project Files

### 1. `data/interaction.csv`

This CSV file contains the user-item interaction data. It includes two columns:
- `user`: The username (e.g., `user1`, `user2`).
- `item`: The item that the user has interacted with (e.g., `item1`, `item2`).

**Example Format:**
```
user,item
user1,item1
user1,item2
user2,item1
user2,item3
user3,item2
```

### 2. `src/main.cpp`

The entry point of the program, responsible for:
- Loading user-item interaction data from `interaction.csv`.
- Asking the user to input a username.
- Displaying the recommended items for the user based on the DFS traversal.

### 3. `src/recommendersystem.cpp`

Contains the implementation of the recommendation system:
- Constructs the graph of user-item interactions.
- Implements the DFS algorithm to explore the graph and generate recommendations for the selected user.

### 4. `src/recommendersystem.h`

The header file declaring the functions and the `RecommenderSystem` class used to perform recommendations.

## Setup Instructions

### 1. Prerequisites
Ensure you have a **C++ compiler** (like `g++`) installed on your system.

### 2. Project Directory Structure
Ensure that the project directory is structured as follows:
```
.
├── data
│   └── interaction.csv
└── src
    ├── main.cpp
    ├── recommendersystem.cpp
    └── recommendersystem.h
```

### 3. Compilation
To compile the code, navigate to the `src` directory and run:
```bash
cd src
g++ -std=c++11 main.cpp recommendersystem.cpp -o recommender
```

### 4. Run the Program
After compiling, run the program using:
```bash
./recommender
```

## Usage Instructions

### 1. Start the Program
To start the application, run the following command:
```bash
./recommender
```

### 2. View Usernames
The program will display a list of available usernames:
```
Select a user from the list below:
user1
user2
user3
```

### 3. Enter Username
Enter one of the usernames from the list (e.g., `user1`).

### 4. View Recommendations
After selecting a user, the program will display a list of recommended items:
```
Recommendations for user1:
- item3
- item4
```

## How It Works

### 1. Data Loading
The system reads the `interaction.csv` file, which contains the interaction data between users and items. This data is used to build a graph where users and items are nodes, and interactions are edges.

### 2. Graph Construction
The program constructs a graph where:
- Users are nodes.
- Items are nodes.
- An edge exists between a user and an item if that user has interacted with that item.

### 3. DFS Algorithm
The system starts at the node corresponding to the selected user and uses DFS to explore the graph, collecting items interacted with by connected users. The traversal continues recursively, recommending items from connected users.

### 4. Recommendation Filtering
After collecting the items, the system ensures that no item is recommended more than once.

## Commands Summary

### Compilation
To compile the code, run:
```bash
g++ -std=c++11 src/main.cpp src/recommendersystem.cpp -o recommender
```

### Execution
To run the program, use:
```bash
./recommender
```

## Testing and Validation

### Valid Input
Input one of the usernames displayed in the list (e.g., `user1`). The system will provide item recommendations for the selected user.

### Invalid Input
If an invalid username is entered (e.g., a username not present in `interaction.csv`), the system will output:
```
User not found!
```

### Graph Traversal Test
Ensure that the DFS algorithm correctly explores the graph and provides recommendations from connected users and items.

## Future Improvements

### 1. Enhanced Recommendations
Implement collaborative filtering algorithms, such as item-based or user-based filtering, to improve the quality of recommendations.

### 2. Scalability
For larger datasets, consider optimizing the DFS algorithm or exploring more efficient graph algorithms like BFS or Random Walks.

### 3. Integration of Graph Neural Networks (GNNs)
In the future, integrate Graph Neural Networks (GNNs) to improve recommendations by learning more complex relationships between users and items.

**Future Directions:** Explore libraries such as PyTorch Geometric or DGL to implement GNNs for improved recommendation accuracy.

## License
This project is open-source and available under the MIT License.
