\documentclass[12pt]{article}
\usepackage{graphicx}
\usepackage{hyperref}

\title{User-Item Recommendation System}
\author{}
\date{}

\begin{document}

\maketitle

\begin{abstract}
This document provides an overview of the User-Item Recommendation System project. It includes detailed descriptions of the project's structure, files, setup instructions, usage, and future directions.
\end{abstract}

\tableofcontents
\newpage

\section{Project Structure}

\begin{verbatim}
.
├── data
│   └── interaction.csv      # CSV file with user-item interaction data
└── src
    ├── main.cpp             # Entry point of the application
    ├── RecommenderSystem.cpp  # Logic for recommendation system using DFS
    └── RecommenderSystem.h    # Header file for the recommendation system logic
\end{verbatim}

\subsection{Explanation of Project Structure}
\begin{itemize}
    \item \texttt{data/interaction.csv}: Contains the interaction data between users and items. This file lists which users have interacted with which items (e.g., liked or viewed).
    \item \texttt{src/main.cpp}: The entry point of the program. It loads the interaction data and prompts the user to input a username. It then generates and displays recommendations using the \texttt{RecommenderSystem} class.
    \item \texttt{src/RecommenderSystem.cpp}: Contains the logic for the recommendation system. It constructs a graph from the interaction data and performs DFS-based traversal to recommend items for a given user.
    \item \texttt{src/RecommenderSystem.h}: The header file that declares the \texttt{RecommenderSystem} class and its methods.
\end{itemize}

\section{Architecture}

The recommendation system is based on a graph-based approach:

\begin{itemize}
    \item \textbf{Graph Representation:}
    \begin{itemize}
        \item Users and items are represented as nodes.
        \item An edge exists between a user and an item if the user has interacted with that item.
    \end{itemize}
    
    \item \textbf{DFS Algorithm:}
    \begin{itemize}
        \item The system uses DFS (Depth-First Search) to explore the graph. Starting from the user node, the system traverses through connected users and items, gathering recommendations.
    \end{itemize}
    
    \item \textbf{CSV-Driven Input:}
    \begin{itemize}
        \item The system dynamically loads user-item interaction data from \texttt{interaction.csv}.
    \end{itemize}
\end{itemize}

\section{Project Files}

\subsection{1. \texttt{data/interaction.csv}}
This CSV file contains the user-item interaction data. It includes two columns:
\begin{itemize}
    \item \texttt{user}: The username (e.g., \texttt{user1}, \texttt{user2}).
    \item \texttt{item}: The item that the user has interacted with (e.g., \texttt{item1}, \texttt{item2}).
\end{itemize}

\textbf{Example Format:}
\begin{verbatim}
user,item
user1,item1
user1,item2
user2,item1
user2,item3
user3,item2
\end{verbatim}

\subsection{2. \texttt{src/main.cpp}}
The entry point of the program, responsible for:
\begin{itemize}
    \item Loading user-item interaction data from \texttt{interaction.csv}.
    \item Asking the user to input a username.
    \item Displaying the recommended items for the user based on the DFS traversal.
\end{itemize}

\subsection{3. \texttt{src/RecommenderSystem.cpp}}
Contains the implementation of the recommendation system:
\begin{itemize}
    \item Constructs the graph of user-item interactions.
    \item Implements the DFS algorithm to explore the graph and generate recommendations for the selected user.
\end{itemize}

\subsection{4. \texttt{src/RecommenderSystem.h}}
The header file declaring the functions and the \texttt{RecommenderSystem} class used to perform recommendations.

\section{Setup Instructions}

\subsection{1. Prerequisites}
Ensure you have a \textbf{C++ compiler} (like \texttt{g++}) installed on your system.

\subsection{2. Project Directory Structure}
Ensure that the project directory is structured as follows:
\begin{verbatim}
.
├── data
│   └── interaction.csv
└── src
    ├── main.cpp
    ├── RecommenderSystem.cpp
    └── RecommenderSystem.h
\end{verbatim}

\subsection{3. Compilation}
To compile the code, navigate to the \texttt{src} directory and run:
\begin{verbatim}
g++ -std=c++11 src/main.cpp src/RecommenderSystem.cpp -o movie_recommender
\end{verbatim}

\subsection{4. Run the Program}
After compiling, run the program using:
\begin{verbatim}
./movie_recommender
\end{verbatim}

\section{Usage Instructions}

\subsection{1. Start the Program}
To start the application, run the following command:
\begin{verbatim}
./movie_recommender
\end{verbatim}

\subsection{2. View Usernames}
The program will display a list of available usernames:
\begin{verbatim}
Select a user from the list below:
user1
user2
user3
\end{verbatim}

\subsection{3. Enter Username}
Enter one of the usernames from the list (e.g., \texttt{user1}).

\subsection{4. View Recommendations}
After selecting a user, the program will display a list of recommended items:
\begin{verbatim}
Recommendations for user1:
- item3
- item4
\end{verbatim}

\section{How It Works}

\subsection{1. Data Loading}
The system reads the \texttt{interaction.csv} file, which contains the interaction data between users and items. This data is used to build a graph where users and items are nodes, and interactions are edges.

\subsection{2. Graph Construction}
The program constructs a graph where:
\begin{itemize}
    \item Users are nodes.
    \item Items are nodes.
    \item An edge exists between a user and an item if that user has interacted with that item.
\end{itemize}

\subsection{3. DFS Algorithm}
The system starts at the node corresponding to the selected user and uses DFS to explore the graph, collecting items interacted with by connected users. The traversal continues recursively, recommending items from connected users.

\subsection{4. Recommendation Filtering}
After collecting the items, the system ensures that no item is recommended more than once.

\section{Commands Summary}

\subsection{Compilation}
To compile the code, run:
\begin{verbatim}
g++ -std=c++11 src/main.cpp src/RecommenderSystem.cpp -o movie_recommender
\end{verbatim}

\subsection{Execution}
To run the program, use:
\begin{verbatim}
./movie_recommender
\end{verbatim}

\section{Testing and Validation}

\subsection{Valid Input}
Input one of the usernames displayed in the list (e.g., \texttt{user1}). The system will provide item recommendations for the selected user.

\subsection{Invalid Input}
If an invalid username is entered (e.g., a username not present in \texttt{interaction.csv}), the system will output:
\begin{verbatim}
User not found!
\end{verbatim}

\subsection{Graph Traversal Test}
Ensure that the DFS algorithm correctly explores the graph and provides recommendations from connected users and items.

\section{Future Improvements}

\subsection{1. Enhanced Recommendations}
Implement collaborative filtering algorithms, such as item-based or user-based filtering, to improve the quality of recommendations.

\subsection{2. Scalability}
For larger datasets, consider optimizing the DFS algorithm or exploring more efficient graph algorithms like BFS or Random Walks.

\subsection{3. Integration of Graph Neural Networks (GNNs)}
In the future, integrate Graph Neural Networks (GNNs) to improve recommendations by learning more complex relationships between users and items.
\begin{itemize}
    \item \textbf{Future Directions:} Explore libraries such as PyTorch Geometric or DGL to implement GNNs for improved recommendation accuracy.
\end{itemize}

\section{License}
This project is open-source and available under the MIT License.

\end{document}
