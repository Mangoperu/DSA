class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;  // 30° per hour, 0.5° per minute
        double minuteAngle = minutes * 6.0;                   // 6° per minute
        double diff = abs(hourAngle - minuteAngle);
        return min(diff, 360 - diff);
    }
};