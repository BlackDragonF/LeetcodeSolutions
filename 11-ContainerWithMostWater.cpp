class Solution {
public:
    int maxArea(vector<int>& height) {
        // height should at least have 2 elements
        int left = 0, right = height.size() - 1;
        int area = 0;
        while (right >= left) {
            int tempArea = min(height[left], height[right]) * (right - left);
            if (tempArea > area) {
                area = tempArea;
            }
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return area;
    }
};