#ifndef RECOMMENDERSYSTEM_H
#define RECOMMENDERSYSTEM_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

class RecommenderSystem {
private:
    std::unordered_map<std::string, std::unordered_set<std::string> > userItemGraph;
    std::unordered_map<std::string, std::unordered_set<std::string> > itemUserGraph;

public:
    void loadData(const std::string& filename);
    std::vector<std::string> getRecommendations(const std::string& user, int numRecommendations);
    std::vector<std::string> getUsers() const;
};

#endif // RECOMMENDERSYSTEM_H
