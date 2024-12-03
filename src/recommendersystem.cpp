#include "recommendersystem.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>

struct CompareRecommendations {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) const {
        return a.second > b.second;
    }
};

void RecommenderSystem::loadData(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string user, item;
        if (std::getline(iss, user, ',') && std::getline(iss, item)) {
            userItemGraph[user].insert(item);
            itemUserGraph[item].insert(user);
        }
    }
}

std::vector<std::string> RecommenderSystem::getRecommendations(const std::string& user, int numRecommendations) {
    std::unordered_set<std::string> visited;
    std::unordered_map<std::string, int> itemScores;

    std::queue<std::string> queue;
    queue.push(user);
    visited.insert(user);

    while (!queue.empty()) {
        std::string currentUser = queue.front();
        queue.pop();

        for (const auto& item : userItemGraph[currentUser]) {
            itemScores[item]++;
            for (const auto& otherUser : itemUserGraph[item]) {
                if (visited.find(otherUser) == visited.end()) {
                    visited.insert(otherUser);
                    queue.push(otherUser);
                }
            }
        }
    }

    std::vector<std::pair<std::string, int> > recommendations;
    for (const auto& pair : itemScores) {
        if (userItemGraph[user].find(pair.first) == userItemGraph[user].end()) {
            recommendations.push_back(pair);
        }
    }

    std::sort(recommendations.begin(), recommendations.end(), CompareRecommendations());

    std::vector<std::string> result;
    for (int i = 0; i < numRecommendations && i < static_cast<int>(recommendations.size()); i++) {
        result.push_back(recommendations[i].first);
    }

    return result;
}

std::vector<std::string> RecommenderSystem::getUsers() const {
    std::vector<std::string> users;
    for (const auto& pair : userItemGraph) {
        users.push_back(pair.first);
    }
    return users;
}
