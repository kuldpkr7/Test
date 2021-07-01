bool cmp(pair<double,double>a,pair<double,double>b){
        return a.first>b.first;
    }
class Solution {
public:
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==0)return 0;
        int n=position.size();
        vector<pair<double,double>>temp;
        for(int i=0;i<n;i++){
            temp.push_back(make_pair((double)position[i],(double)(target-position[i])/speed[i]));
        }
        sort(temp.begin(),temp.end(),cmp);
        stack<pair<double,double>>s;
        s.push(temp[0]);
        for(int i=1;i<n;i++){
            if(temp[i].second>s.top().second){
                s.push(temp[i]);
            }
        }
        return s.size();
    }
};