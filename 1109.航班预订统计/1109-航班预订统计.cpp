class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n,0);
        for(auto &booking: bookings)
        {
            diff[booking[0]-1]+=booking[2];
            if(booking[1]<n)
            {
                diff[booking[1]]-=booking[2];
            }
        }

        for(int i=1;i<n;++i)
        {
            diff[i]+=+diff[i-1];
        }
        return diff;
    }
};