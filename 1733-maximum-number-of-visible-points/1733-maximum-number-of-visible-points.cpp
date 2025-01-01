class Solution {
public:
    double getAngle(int x,int y,vector<int> &location){
        int opposite=y-location[1];
        int perp=x-location[0];
        double angle=atan2(opposite,perp)*180/M_PI;
        if(angle<0) angle+=360;
        return angle;
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int center=0;
        for(auto i:points){
            if(i[0]==location[0] && i[1]==location[1]){
                center++;
                continue;
            }
            double a=getAngle(i[0],i[1],location);
            angles.push_back(a);
        }
        if(angles.size()==0) return center;
        sort(angles.begin(),angles.end());
        double largestAngle=angles[angles.size()-1];
        int n=angles.size();
        for(int i=0;i<n;i++){
            if(angles[i]+360-largestAngle>angle) break;
            angles.push_back(angles[i]+360);
        }
        int ans=0;
        for(int start=0,end=0;end<angles.size();end++){
            if(angles[end]-angles[start]>angle){
                start++;
                continue;
            }
            ans=max(ans,end-start+1);
        }
        return ans+center;
    }
};