class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        int maxi = max({a, b, c});
        return min(sum / 2, sum - maxi);
    }
};

// class Solution {
// public:
//     int maximumScore(int a, int b, int c) {
//         priority_queue<int> pq;
//         pq.push(a);
//         pq.push(b);
//         pq.push(c);

//         int score = 0;

//         while (pq.size() > 1) {
//             int x = pq.top();
//             pq.pop();
//             int y = pq.top();
//             pq.pop();

//             x--;
//             y--; // ek stone dono piles se hata do or store bada do 1 unit se or
//                  // agar piles se stone hatane k baad bhi value > 0 hai to fir
//                  // se khelte rho jab tak 2 piles ka score 0 na ho jaye
//             score++;

//             if (x > 0)
//                 pq.push(x);
//             if (y > 0)
//                 pq.push(y);
//         }

//         return score;
//     }
// };
