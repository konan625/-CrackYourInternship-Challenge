You are given a 0-indexed integer array buses of length n, where buses[i] represents the departure time of the ith bus. You are also given a 0-indexed integer array passengers of length m, where passengers[j] represents the arrival time of the jth passenger. All bus departure times are unique. All passenger arrival times are unique.

You are given an integer capacity, which represents the maximum number of passengers that can get on each bus.

The passengers will get on the next available bus. You can get on a bus that will depart at x minutes if you arrive at y minutes where y <= x, and the bus is not full. Passengers with the earliest arrival times get on the bus first.

Return the latest time you may arrive at the bus station to catch a bus. You cannot arrive at the same time as another passenger.

Note: The arrays buses and passengers are not necessarily sorted.
Input: buses = [10,20], passengers = [2,17,18,19], capacity = 2
Output: 16
Explanation: 
The 1st bus departs with the 1st passenger. 
The 2nd bus departs with you and the 2nd passenger.
Note that you must not arrive at the same time as the passengers, which is why you must arrive before the 2nd passenger to catch the bus.
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        queue<int> q;
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int n=buses.size();
        int m=passengers.size();
        set<int> st;
        for(auto p:passengers)
        {
            q.push(p);
            st.insert(p);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int currbus=buses[i]; // curr bus depature time.
            int count=0; //number of people in curr bus
            int x;
            //CASE1
            while(!q.empty() && count<capacity && q.front()<=currbus)
            {
                x=q.front();
                q.pop();
                if(st.find(x-1)==st.end()) //checking if person timing-1 doesnt exist and update the answer.
                    ans=x-1; 
                count++;
            }
            //CASE2
            if(count<capacity)
            {
                while(st.find(currbus)!=st.end()) //starting from dept time find a time which does not exist int the set already.
                {
                    currbus--;
                }
                ans=max(ans,currbus);
            }
            
        }
        return ans;
    }
};