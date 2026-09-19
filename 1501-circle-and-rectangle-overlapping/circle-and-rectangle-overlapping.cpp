#include <cmath>

class Solution {
public:
    // 1. Fixed your typo (yCenter <= x2 is now xCenter <= x2)
    bool inside(int xCenter, int yCenter, int x1, int y1, int x2, int y2){
        if(yCenter >= y1 && yCenter <= y2 && xCenter >= x1 && xCenter <= x2){
            return true;
        }
        return false;
    }
    
    // Helper to check if a specific corner point is inside the circle
    bool cornerInside(int x, int y, int xCenter, int yCenter, int radius) {
        int dx = x - xCenter;
        int dy = y - yCenter;
        return (dx * dx + dy * dy) <= (radius * radius);
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Condition A: Center of circle is inside the rectangle
        if (inside(xCenter, yCenter, x1, y1, x2, y2)) {
            return true;
        }
        
        // Condition B: Circle intersects one of the flat edges
        // Check horizontal edges (top and bottom)
        if (xCenter >= x1 && xCenter <= x2) {
            if (abs(yCenter - y1) <= radius || abs(yCenter - y2) <= radius) return true;
        }
        // Check vertical edges (left and right)
        if (yCenter >= y1 && yCenter <= y2) {
            if (abs(xCenter - x1) <= radius || abs(xCenter - x2) <= radius) return true;
        }
        
        // Condition C: Circle touches or overlaps one of the four corners
        if (cornerInside(x1, y1, xCenter, yCenter, radius)) return true; // Bottom-left
        if (cornerInside(x1, y2, xCenter, yCenter, radius)) return true; // Top-left
        if (cornerInside(x2, y1, xCenter, yCenter, radius)) return true; // Bottom-right
        if (cornerInside(x2, y2, xCenter, yCenter, radius)) return true; // Top-right
        
        // If it's not inside, not hitting an edge, and not hitting a corner, it doesn't overlap
        return false;
    }
};