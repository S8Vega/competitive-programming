class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        for (const int &x : batteryPercentages){
            if (x - ans > 0) ans++;
        }
        return ans;
    }
};