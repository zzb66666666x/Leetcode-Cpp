class Solution {
public:
    bool winnerOfGame(string colors) {
        vector<int> moves = {0, 0};
        char cur = 'A';
        int cnt = 0;
        int n = colors.size();
        for (int i=0; i<n; i++){
            char c = colors[i];
            if (cur != c){
                if (cnt >= 3){
                    moves[cur != 'A'] += (cnt - 2);
                }
                cur = c;
                cnt = 1;
            }else{
                cnt ++;
            }
        }
        if (cnt >= 3){
            moves[cur != 'A'] += (cnt - 2);
        }
        return moves[0] > moves[1] ? true : false;
    }
};
