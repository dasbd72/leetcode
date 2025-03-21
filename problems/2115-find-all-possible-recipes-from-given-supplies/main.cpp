#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    vector<Node*> children;
    bool is_valid;
    bool is_recipe;
    bool visited;
    Node() {
        is_valid = false;
        is_recipe = false;
        visited = false;
    }
};

class Solution {
   public:
    unordered_map<string, Node*> nodes;

    Node* findOrAddNode(string& recipe) {
        auto it = nodes.find(recipe);
        Node* node;
        if (it == nodes.end()) {
            node = nodes[recipe] = new Node;
        } else {
            node = it->second;
        }
        return node;
    }

    bool dfs(Node* node) {
        if (node->visited) {
            return node->is_valid;
        }
        node->visited = true;
        if (node->children.size() == 0 && !node->is_recipe) {
            return node->is_valid = false;
        }
        for (auto& child : node->children) {
            if (!dfs(child)) {
                return node->is_valid = false;
            }
        }
        // All children are valid
        return node->is_valid = true;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // Record all supplies
        unordered_set<string> supplies_set(supplies.begin(), supplies.end());
        // Build graph
        for (int i = 0; i < recipes.size(); i++) {
            Node* out = findOrAddNode(recipes[i]);
            out->is_recipe = true;
            for (auto& ingredient : ingredients[i]) {
                if (supplies_set.find(ingredient) != supplies_set.end()) {
                    continue;
                }
                Node* in = findOrAddNode(ingredient);
                out->children.emplace_back(in);
            }
        }
        // Check each recipe
        vector<string> valid_recipes;
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            if (dfs(nodes[recipe])) {
                valid_recipes.emplace_back(recipe);
            }
        }
        return valid_recipes;
    }
};