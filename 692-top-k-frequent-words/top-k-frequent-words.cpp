class Solution {
 public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freqMap;
    for (const string& word : words) {
      freqMap[word]++;
    }
   

    vector<string> uniqueWords;
    for (const auto& [word, _] : freqMap) {
      uniqueWords.push_back(word);
    }

    sort(uniqueWords.begin(), uniqueWords.end(), [&](const string& a, const string& b) {
      return freqMap[a] == freqMap[b] ? a < b : freqMap[a] > freqMap[b];
    });

    vector<string> result;
    for (int i = 0; i < k; ++i) {
      result.push_back(uniqueWords[i]);
    }

    return result;
  }
};
