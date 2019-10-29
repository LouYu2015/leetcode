class Solution {
public:
    int find_next(string &path, int i) {
        while (i < path.length() && path[i] != '/') {
            i++;
        }
        return i;
    }
    
    string simplifyPath(string path) {
        int current = 0;
        vector<string> names;
        while (current < path.length()) {
            if (path[current] == '/') {
                current++;
            }
            if (current >= path.length()) {
                break;
            }
            int end = find_next(path, current);
            string name = path.substr(current, end - current);
            if (name == "" || name == ".") {
                continue;
            }
            if (name == "..") {
                if (names.size() > 0) {
                    names.pop_back();
                }
            } else {
                names.push_back(name);
            }
            current = end;
        }
        string result;
        if (path.length() > 0 && path[0] == '/') {
            result += '/';
        }
        for (int i = 0; i < names.size(); i++) {
            result += names[i];
            if (i != names.size() - 1) {
                result += '/';
            }
        }
        return result;
    }
};
