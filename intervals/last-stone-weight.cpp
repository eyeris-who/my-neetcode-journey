// https://neetcode.io/problems/last-stone-weight/question

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        map<int, int, greater<int>> weights;
        for (int i = 0; i < stones.size(); i++) {
            weights[stones[i]]++;
        }

        while(!weights.empty()) {
            int weight = weights.begin()->first;
            int count = weights.begin()->second;
            if (count >= 2) {
                weights[weight] -= 2;
                if (weights[weight] == 0) weights.erase(weight);
            } else {
                auto it = next(weights.begin());
                if (it == weights.end()) return weight;
                int weight2 = it->first;
                weights.erase(weight);
                weights[weight2]--;
                if (weights[weight2] == 0) weights.erase(weight2);
                if (weight - weight2 > 0) weights[weight - weight2]++;
            } 
        }
        return 0;
    }
};
