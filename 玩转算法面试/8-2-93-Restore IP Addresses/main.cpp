class Solution {
public:
	/**
	*»ØËÝ·¨ 
	*/
    vector<string> restoreIpAddresses(string s) {

        vector<string> res;
        vector<int> ip;
        dfs(s, 0, ip, res);
        return res;
    }

private:
    void dfs(const string& s, int index, vector<int>& ip, vector<string>& res){

        if(index == s.size()){
            if(ip.size() == 4)
                res.push_back(get_string(ip));
            return;
        }

        if(index == 0){
            ip.push_back(s[0] - '0');
            dfs(s, index + 1, ip, res);
        }
        else{
            int next = ip.back() * 10 + (s[index] - '0');
            if(next <= 255 && ip.back() != 0){
                ip.back() = next;
                dfs(s, index + 1, ip, res);
                ip.back() /= 10;
            }
            if(ip.size() < 4){
                ip.push_back(s[index] - '0');
                dfs(s, index + 1, ip, res);
                ip.pop_back();
            }
        }
    }

    string get_string(const vector<int>& ip){
        string res = to_string(ip[0]);
        for(int i = 1; i < ip.size(); i ++)
            res += "." + to_string(ip[i]);
        return res;
    }
};
