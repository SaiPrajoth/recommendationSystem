#include <iostream>
#include <string>
#include "recommendersystem.h"

int main() {
    RecommenderSystem recommender;
    recommender.loadData("../data/interactions.csv");

    std::cout << "Available users:" << std::endl;
    std::vector<std::string> users = recommender.getUsers();
    for (const auto& user : users) {
        std::cout << user << std::endl;
    }

    std::string selectedUser;
    std::cout << "\nEnter a user to get recommendations: ";
    std::cin >> selectedUser;

    int numRecommendations = 5;
    std::vector<std::string> recommendations = recommender.getRecommendations(selectedUser, numRecommendations);

    std::cout << "\nRecommendations for " << selectedUser << ":" << std::endl;
    for (const auto& item : recommendations) {
        std::cout << item << std::endl;
    }

    return 0;
}
