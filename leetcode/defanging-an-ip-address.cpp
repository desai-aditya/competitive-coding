class Solution {
public:
    string defangIPaddr(string address) {
        string t{""};
        for(auto el : address)
        {
            if (el=='.')
            {
                t+="[.]";
                continue;
            }
            t+=el;
        }
        return t;
    }
};