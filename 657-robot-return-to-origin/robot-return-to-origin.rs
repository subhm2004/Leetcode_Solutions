impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        let mut x = 0;
        let mut y = 0;

        for move_char in moves.chars() {
            match move_char {
                'R' => x += 1,
                'L' => x -= 1,
                'U' => y += 1,
                'D' => y -= 1,
                _ => {}
            }
        }

        x == 0 && y == 0
    }
}
