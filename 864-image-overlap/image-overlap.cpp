class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>A,B;
        int n = img1.size();
        int m = img1[0].size();
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(img1[i][j]==1)A.push_back({i,j});
                if(img2[i][j]==1)B.push_back({i,j});
            }
        }
        map<pair<int,int>,int>mp;
        int maxi =0;
        for(auto& it1:A){
            for(auto& it2:B){
                int dr = it1.first-it2.first;
                int dc = it1.second-it2.second;
                mp[{dr,dc}]++;
                maxi = max(maxi,mp[{dr,dc}]);
            }

        }
        return maxi;
    }
};