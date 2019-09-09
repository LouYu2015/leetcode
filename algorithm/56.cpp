class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        set<int> edges;
        for (auto interval : intervals) {
            for (int edge : interval) {
                edges.insert(edge);
            }
        }
        
        map<int, int> edgeToID;
        vector<int> idToEdge;
        int numIDs = 0;
        for (int edge : edges) {
            if (edgeToID.find(edge) == edgeToID.end()) {
                edgeToID[edge] = numIDs;
                numIDs++;
                idToEdge.push_back(edge);
            }
        }
        
        vector<int> open(0, numIDs);
        vector<int> close(0, numIDs);
        for (auto interval : intervals) {
            open[edgeToID[interval[0]]]++;
            close[edgeToID[interval[1]]]++;
        }
        
        vector<vector<int>> result;
        int lastEdgeID = 0;
        int currentLevel = 0;
        bool insideInterval = false;
        for (int i = 0; i < open.size(); i++) {
            currentLevel += open[i];
            if (currentLevel > 0 && !insideInterval) {
                lastEdgeID = i;
                insideInterval = true;
            }
            
            currentLevel -= close[i];
            if (currentLevel == 0 && insideInterval) {
                vector<int> interval;
                interval.push_back(idToEdge[lastEdgeID]);
                interval.push_back(idToEdge[i]);
                result.push_back(interval);
                insideInterval = false;
            }
        }
        return result;
    }
};
