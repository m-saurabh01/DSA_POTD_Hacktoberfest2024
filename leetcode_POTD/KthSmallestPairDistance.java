
class KthSmallestPairDistance{
    public int smallestDistancePair(int[] nums, int k) {
        int max = Arrays.stream(nums).max().getAsInt();

        int diff[] = new int[max + 1];
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = Math.abs(nums[i] - nums[j]);
                diff[d]++;
            }
        }

        for (int i = 0; i < max + 1; i++) {
            k -= diff[i];
            if (k <= 0)
                return i;
        }

        return 0;
    }
}