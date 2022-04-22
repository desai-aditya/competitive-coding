class Solution {
public:
    long long int counter = 0;
    unordered_map<string,string> m1;
    unordered_map<string,string> m2;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        m1[longUrl]=to_string(counter);
        m2[to_string(counter)]=longUrl;
        counter++;
        return m1[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));