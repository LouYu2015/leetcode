class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort all edges
        set<int> edges;
        for (auto interval : intervals) {
            for (int edge : interval) {
                edges.insert(edge);
            }
        }
        
        // Map all edges to a sequencial edge ID
        // Map from edge value to edge ID
        map<int, int> edgeToID;
        // idToEdge[x] is the value of edge ID 'x'
        vector<int> idToEdge;
        int numIDs = 0;
        for (int edge : edges) {
            if (edgeToID.find(edge) == edgeToID.end()) {
                edgeToID[edge] = numIDs;
                numIDs++;
                idToEdge.push_back(edge);
            }
        }
        
        // Count interval edges
        // open[i] is the number of intervals that open at edge ID 'i'
        vector<int> open(numIDs, 0);
        // close[i] is the number of intervals that close at edge ID 'i'
        vector<int> close(numIDs, 0);
        for (auto interval : intervals) {
            open[edgeToID[interval[0]]]++;
            close[edgeToID[interval[1]]]++;
        }
        
        // Slide through all intervals sequencially
        // Store result
        vector<vector<int>> result;
        // The edge id where current interval opens
        int lastEdgeID = 0;
        // How many intervals are still open
        int currentLevel = 0;
        // Are we currently inside an interval
        bool insideInterval = false;
        for (int i = 0; i < open.size(); i++) {
            // Open intervals
            currentLevel += open[i];
            if (currentLevel > 0 && !insideInterval) {
                // We stated a new interval
                lastEdgeID = i;
                
                insideInterval = true;
            }
            
            // Close intervals
            currentLevel -= close[i];
            if (currentLevel == 0 && insideInterval) {
                // All intervals closed, record last interval
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
