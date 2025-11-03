unordered_map<string, int> memo;

// Check if array is already increasing
bool isIncreasing(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i)
        if (arr[i] <= arr[i - 1]) return false;
    return true;
}

// Convert array to string key for memoization
string toKey(const vector<int>& arr) {
    string key;
    for (int x : arr) key += to_string(x) + ",";
    return key;
}

// Compute Grundy number
int grundy(vector<int>& arr) {
    if (isIncreasing(arr)) return 0;

    string key = toKey(arr);
    if (memo.count(key)) return memo[key];

    unordered_set<int> nextStates;

    for (int i = 0; i < arr.size(); ++i) {
        vector<int> next = arr;
        next.erase(next.begin() + i);
        nextStates.insert(grundy(next));
    }

    // mex (minimum excluded value)
    int g = 0;
    while (nextStates.count(g)) ++g;

    return memo[key] = g;
}

string permutationGame(vector<int> arr) {
    return grundy(arr) ? "Alice" : "Bob";
}