class Solution {
public:
    bool empty(unordered_map<char,int> m)
    {
        for(auto el : m)
        {
            if(el.second!=0)return false;
        }
        return true;
    }        
    
    vector< unordered_map<char,int> > vm;
    string originalDigits(string s) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        //vm.push_back({{'z',1},{'e',1},{'r',1},{'o',1}});
        vm.push_back({});
        vm.push_back({{'o',1},{'n',1},{'e',1}});
        
        //vm.push_back({{'t',1},{'w',1},{'o',1}});
        vm.push_back({});
        
        vm.push_back({{'t',1},{'h',1},{'r',1},{'e',2}});
        //vm.push_back({{'f',1},{'o',1},{'u',1},{'r',1}});
        vm.push_back({});
        //vm.push_back({{'f',1},{'i',1},{'v',1},{'e',1}});
        vm.push_back({});
        //vm.push_back({{'s',1},{'i',1},{'x',1}});
        vm.push_back({});
        vm.push_back({{'s',1},{'e',2},{'v',1},{'n',1}});
        //vm.push_back({{'e',1},{'i',1},{'g',1},{'h',1},{'t',1}});
        vm.push_back({});
        vm.push_back({{'n',2},{'i',1},{'e',1}});
        
        unordered_map<char,int> bigm={{'z',0},{'e',0},{'r',0},{'o',0},{'n',0},{'t',0},{'w',0},{'h',0},{'f',0},{'u',0},{'i',0},{'v',0},{'x',0},{'s',0},{'g',0}};
        for(auto c : s)bigm[c]++;
        string ans;                
        
        for(int i = 0; i < bigm['z']; i++)
        {
            ans+='0';
        }
        bigm['e']-=bigm['z'];
        bigm['r']-=bigm['z'];
        bigm['o']-=bigm['z'];
        bigm['z']-=bigm['z'];
        
        for(int i = 0; i < bigm['w']; i++)
        {
            ans+='2';
        }
        bigm['t']-=bigm['w'];
        bigm['o']-=bigm['w'];
        bigm['w']-=bigm['w'];
        
        for(int i = 0; i < bigm['u']; i++)
        {
            ans+='4';
        }
        bigm['f']-=bigm['u'];
        bigm['o']-=bigm['u'];
        bigm['r']-=bigm['u'];
        bigm['u']-=bigm['u'];
        
        for(int i = 0; i < bigm['x']; i++)
        {
            ans+='6';
        }
        bigm['i']-=bigm['x'];
        bigm['s']-=bigm['x'];
        bigm['x']-=bigm['x'];                
        
        for(int i = 0; i < bigm['g']; i++)
        {
            ans+='8';
        }
        
        bigm['e']-=bigm['g'];
        bigm['t']-=bigm['g'];
        bigm['h']-=bigm['g'];
        bigm['i']-=bigm['g'];
        bigm['g']-=bigm['g'];
        
        int i;
        for(i = 0; i < bigm['f'] && i < bigm['v']; i++)
        {
            ans+='5';
        }
        
        bigm['f']-=i;
        bigm['i']-=i;
        bigm['v']-=i;
        bigm['e']-=i;                                                            
       
        while(!empty(bigm))
        {
            for(int i = 0 ;i < vm.size(); i++)
            {
                if(vm[i].size()==0)continue;
                int flag = 1;
                for(auto el: vm[i])
                {
                    if(bigm[el.first]<el.second)
                    {
                        flag=0;
                        break;
                    }
                }
                if(flag)
                {
                    for(auto el: vm[i])
                    {                        
                        bigm[el.first]-=el.second;                     
                    }   
                    ans+=to_string(i);
                    //i--;
                }
                
            }
        }
        
    
        sort(ans.begin(),ans.end());
        return ans;        
    }
};