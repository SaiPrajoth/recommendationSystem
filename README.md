# **User-Item Recommendation System**

This project is a **User-Item Recommendation System** that leverages a **graph-based DFS (Depth-First Search) algorithm** to provide personalized recommendations. The system dynamically loads data from an `interaction.csv` file that contains user-item interaction data. Based on the graph traversal, users can get recommendations for items (movies or any type of items they have interacted with).

---

## **Architecture**

The system uses a **graph-based approach** for recommendations:

1. **Graph Representation**:
   - **Users** and **Items** are represented as nodes.
   - An **edge** exists between a user and an item if the user has interacted with (or liked) the item.
   
2. **DFS Traversal**:
   - The recommendation system uses **DFS** to explore the graph.
   - DFS explores the connections (edges) between users and items, identifying items liked by other users who are similar or connected to the starting user.

3. **CSV-Driven Input**:
   - The interaction data is read from a CSV file, `interaction.csv`, which defines user-item interactions.

---

## **Project Files**

### **1. `main.cpp`**
- **Description**:  
  The entry point of the application that manages user input and displays the movie recommendations.

- **Key Functions**:
  - **`loadInteractions()`**: Reads user-item interaction data from `interaction.csv`.
  - **`main()`**:
    - Displays the list of usernames from the `interaction.csv` file.
    - Prompts the user to input their username.
    - Fetches and displays movie recommendations based on the DFS algorithm using the `RecommenderSystem`.

---

### **2. `RecommenderSystem.cpp`**
- **Description**:  
  Implements the recommendation logic using a **DFS-based traversal** on the user-item interaction graph.

- **Key Functions**:
  - **`addEdge()`**:
    - Adds an edge between a user and an item in the graph, establishing a connection based on interactions.
  - **`recommendItemsDFS()`**:
    - Implements the DFS algorithm to explore all connected users and gather recommendations.
  - **`getRecommendations()`**:
    - Fetches the recommendations for a given user by invoking the DFS-based recommendation algorithm.

---

### **3. `interaction.csv`**
- **Description**:  
  This file defines user-item interactions. Each line represents a user-item interaction (e.g., a user liking an item or movie).

- **Format**:
  ```csv
  user,item
  user1,item1
  user1,item2
  user2,item1
  user2,item3
  user3,item2

- **Columns**
- **user**: The username of the user (e.g., `user1`).
- **item**: The item (e.g., `item1`, `item2`, etc.) that the user has interacted with.

---

## **Setup Instructions**

### 1. **Prerequisites**
- **Compiler**: Ensure you have `g++` installed.
- **CSV File**: Prepare an `interaction.csv` file with user-item interaction data.

### 2. **Directory Structure**
Ensure the project directory structure is as follows:

```plaintext
.
├── interaction.csv
├── main.cpp
└── RecommenderSystem.cpp
