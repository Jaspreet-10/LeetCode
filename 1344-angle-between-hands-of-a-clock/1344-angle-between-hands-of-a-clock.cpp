class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = hour*30 + minutes*0.5;//360/12 = 30 degee for hour and each hour has 60 minutes, so minute angle would be 30/60 which will be 0.5
        double minuteAngle = 6*minutes;
        double ans = abs(hourAngle - minuteAngle);
        return min(ans, 360-ans);
    }
};