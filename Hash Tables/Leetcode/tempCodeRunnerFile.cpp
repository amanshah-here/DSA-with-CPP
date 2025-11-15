unordered_map<int, int> m;  // Store number and its index

    for (int i = 0; i < nums.size(); i++) {
        int tar = target - nums[i];  // Calculate complement

        // Check if complement exists in map
        if (m.count(tar)) {
            return { m[tar], i };  // Return indices of the pair
        }

        m[nums[i]] = i;  // Store current number and index
    }

    return { -1, -1 };  // No pair found