class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0,pickG = 0, pickM = 0;
        int travelP = 0 , travelG = 0 , travelM = 0;
        int lastP= 0 , lastG= 0 , lastM=0;

        // calculate pick time & travel time
        for(int i=0;i<garbage.size();i++){
            string curr = garbage[i];
            for(auto ch :curr){
                if(ch == 'P'){
                        pickP++;
                         lastP = i;
                }
                else if(ch == 'M'){
                    pickM++;
                    lastM = i;
                }
                else{
                    // ch == 'G'
                    pickG++;
                    lastG = i;
                }
            }
        }

        // calcute travel time

        for(int i=0;i<lastG;i++){
            travelG += travel[i];
        }
        for(int i=0;i<lastP;i++){
            travelP += travel[i];
        }
        for(int i=0;i<lastM;i++){
            travelM += travel[i];
        }

        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
        return ans;
    }
};