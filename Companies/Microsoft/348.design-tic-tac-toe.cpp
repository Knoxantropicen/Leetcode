// Time: O(1) for move(), Space: O(n)
class TicTacToe {
public:
    TicTacToe(int n) {
        rowSum.resize(n);
        colSum.resize(n);
        diagSum.resize(2);
        nSize = n;
    }
    int move(int row, int col, int player) {
        int change = 2 * player - 3;    // player1: -1, player2: 1
        rowSum[row] += change;
        if (rowSum[row] == nSize * change) return player;
        colSum[col] += change;
        if (colSum[col] == nSize * change) return player;
        if (row == col) {
            diagSum[0] += change;
            if (diagSum[0] == nSize * change) return player;
        }
        if (row + col == nSize - 1) {
            diagSum[1] += change;
            if (diagSum[1] == nSize * change) return player;
        }
        return 0;
    }
private:
    vector<int> rowSum, colSum, diagSum;
    int nSize;
};