class Solution {
public:
    int getH(string s) {
        int first = s[0] - '0';
        int second = s[1] - '0';
        return first*10 + second;
    }
    int getM(string s) {
        int first = s[3] - '0';
        int second = s[4] - '0';
        return first*10 + second;
    }
    int getS(string s) {
        int first = s[6] - '0';
        int second = s[7] - '0';
        return first*10 + second;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        int hour = getH(endTime) - getH(startTime);
        int min = getM(endTime) - getM(startTime);
        int sec = getS(endTime) - getS(startTime);
        return hour * 3600 + min * 60 + sec;
    }
};