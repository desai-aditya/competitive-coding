class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> s(wordList.begin(),wordList.end());
                     
          int path=INT_MAX;           
       

        
              
            

        
                    
                     
                             
             
          




        vector<vector<string> > ans={};
        queue< vector<string> > q={};
        q.push({beginWord});
                     s.erase(beginWord);
        while(q.size())
            {
            auto tp = q.front(); q.pop();
            if(tp.size()>path)continue;
                string prev = tp.back();
            s.erase(prev);
                if(prev == endWord) 
                    {
                   
                    if(tp.size()<path ) ans.clear();
                    ans.push_back(tp);
                    path=tp.size();
                    continue;}
                for(int i= 0; i<prev.size(); i++)
                    {
                    
                    for(char c= 'a'; c<= 'z';c++){
                        string cur=prev;
                        cur[i]=c;
                        
                        if(c!=prev[i] && s.count(cur))
                            {
                            tp.push_back(cur);
                            q.push(tp);
                            tp.pop_back();
                            }
                        }
                    
                   }
                
            }
        return ans;
    }
};