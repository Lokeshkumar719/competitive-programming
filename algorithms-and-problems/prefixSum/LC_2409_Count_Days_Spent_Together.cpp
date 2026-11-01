class Solution {
public:
    int findDayInTimelime(string &s,vector<int> &cntDays){
        int month = stoi(s.substr(0,2));
        int day = stoi(s.substr(3,2));
        cout << cntDays[month - 1] + day<<endl;
        return cntDays[month - 1] + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> cntDays(13);
        cntDays[1] = daysInMonths[0];
        for(int i=2;i<12;i++){
            cntDays[i] = cntDays[i-1] + daysInMonths[i-1];
        }
        int aliceArrivalDay = findDayInTimelime(arriveAlice,cntDays);
        int aliceLeaveDay = findDayInTimelime(leaveAlice,cntDays);
        int bobArrivalDay = findDayInTimelime(arriveBob,cntDays);
        int bobLeaveDay = findDayInTimelime(leaveBob,cntDays);
        int overLap = min(aliceLeaveDay,bobLeaveDay)-max(aliceArrivalDay,bobArrivalDay) + 1;
        return max(0,overLap);
    }
};