#include <algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 0, right = piles[piles.size()-1];
        while(left <= right)
        {
            int mid = left+(right-left)/2;
            if(mid<1) return 1;
            if(totalEatingTime(piles, mid) == h)
            {
                right = mid-1;
            }
            else if(totalEatingTime(piles, mid) > h)
            {
                left = mid+1;
            }
            else if(totalEatingTime(piles, mid) < h)
            {
                right = mid-1;
            }
        }

        return left;
    }

    int totalEatingTime(vector<int> &piles, long int speed) {
        cout<<"speed: "<<speed<<endl;
        int time = 0;
        for(auto &i: piles)
        {
            if(i%speed == 0)
            {
                time+=(i/speed);
            }
            else
            {
                time+=((i/speed)+1);
            }
        }

        cout<<"time: "<<time<<endl;
        return time;
    }
};