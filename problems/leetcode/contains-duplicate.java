class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> reps = new HashSet<>();
        for (int n : nums) {
            if (reps.contains(n)) return true;
            reps.add(n);
        }
        return false;
    }
}