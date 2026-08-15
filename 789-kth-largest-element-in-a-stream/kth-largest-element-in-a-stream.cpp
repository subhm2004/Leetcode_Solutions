class KthLargest {

    // Hume kth largest element find karna hai
    int k;

    // Min Heap use kar rahe hain.
    // Isme sabse chhota element top par hota hai.
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:

    KthLargest(int k, vector<int>& nums) {

        // k ko class variable me store kar liya
        this->k = k;

        // Initial scores ko ek-ek karke heap me daalenge
        for (int score : nums) {

            minHeap.push(score);

            // Hume sirf k largest elements maintain karne hain.
            //
            // Agar heap me k se zyada elements aa gaye,
            // to sabse chhota element remove kar do.
            //
            // Isse heap me hamesha k largest elements rahenge.
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    int add(int score) {

        // Naya score stream me add karo
        minHeap.push(score);

        // Agar k se zyada elements ho gaye,
        // to smallest element hata do.
        //
        // Kyunki hume sirf k largest elements
        // maintain karne hain.
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        // Min Heap me sabse chhota element top par hota hai.
        //
        // Heap me sirf k largest elements hain,
        // isliye in k elements me sabse chhota
        // overall kth largest element hoga.
        return minHeap.top();
    }
};