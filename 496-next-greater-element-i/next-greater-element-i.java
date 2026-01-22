class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> d = new ArrayDeque<>();
        Map<Integer, Integer> m = new HashMap<>();
        for(int i = nums2.length - 1; i >= 0; i--){
            while(!d.isEmpty() && d.peek() < nums2[i]){
                d.pop();
            }
            if(d.isEmpty()){
                m.put(nums2[i], -1);
            }
            else{
                m.put(nums2[i], d.peek());
            }
            d.push(nums2[i]);
        }
        for(int i = 0; i < nums1.length; i++){
            nums1[i] = m.get(nums1[i]);
        }
        return nums1;
    }
}