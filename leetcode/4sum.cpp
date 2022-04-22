class Solution {
public:
    bool notequal(int a, int b, int c, int d)
    {
        return (a!=c&&b!=c&&a!=d&&b!=d);
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, vector<pair<int,int> > > m  = {};
        for(int i = 0 ;i < n-1; i++)
        {                           
                for(int j = i+1 ;j < n; j++)
                {
                    //if(m.find(nums[i]+nums[j])==m.end())m[nums[i]+nums[j]]={};
                    m[nums[i]+nums[j]].push_back({i,j});
                }   
        }
        set<vector<int> > ans = {};
        // for(int i = 0 ;i < n-1; i++)
        // {                           
        //         for(int j = i+1 ;j < n; j++)
        //         {   
        for(auto mitr = m.begin(); mitr!=m.end(); mitr++)
        {                    
            //cout<<"sum = "<<mitr->first<<endl;
                    auto s = m[target-(mitr->first)];
                    for(auto itr = s.begin(); itr!=s.end(); itr++)
                    {
                        
                        for(auto itr2 = mitr->second.begin(); itr2!= mitr->second.end(); itr2++)
                        {
                            //cout<<"values"<<endl;
                            //cout<<(*itr).second<<" val "<<nums[(*itr).second]<<endl;;
                            //cout<<(*itr).second<<" val "<<nums[(*itr).second]<<endl;;
                            //cout<<"keys"<<endl;
                            //cout<<(*itr2).first<<" val "<<nums[(*itr2).first]<<endl;;
                            //cout<<(*itr2).first<<" val "<<nums[(*itr2).first]<<endl;;
                            
                            
                            if(notequal((*itr).first,(*itr).second,(*itr2).first,(*itr2).second))
                            {
                                vector<int> v = {nums[(*itr2).first],nums[(*itr2).second],nums[(*itr).first],nums[(*itr).second]};
                                sort(v.begin(),v.end());
                                ans.insert(v);
                            }
                        }
                    }                                            
        //         }   
        // }
        }
        
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};