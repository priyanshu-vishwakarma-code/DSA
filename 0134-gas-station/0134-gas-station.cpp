class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //check if solution exist of not
        int totalcost = 0 , totalgas = 0;
        for(int i : gas) totalgas += i;
        for(int i : cost) totalcost += i;
        if(totalgas<totalcost) return -1;

        //if unique solution exists
        int start = 0 , tank = 0;
        for(int i = 0 ; i<gas.size() ; i++){
            tank += gas[i] - cost[i];
            if(tank<0) start = i+1 , tank = 0;
        }

        return start;
    }
};