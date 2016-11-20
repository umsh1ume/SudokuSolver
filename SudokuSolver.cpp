#include<bits/stdc++.h>
using namespace std;
int rowhash[9][9], colhash[9][9], blockhash[3][3][9];
  bool solve(vector<vector<char> > &A, int position) {
            if (position >= 9*9) {
                return true;
            }
            int row = position / 9, col = position % 9;
            if (A[row][col] != '.') {
                return solve(A, position + 1);
            }
            for (int num = 0; num < 9; num++) {
                if (rowhash[row][num] != 1 && colhash[col][num] != 1 && blockhash[row / 3][col / 3][num] != 1) {

                    A[row][col] = '1' + num;
                    rowhash[row][num] = 1;
                    colhash[col][num] = 1;
                    blockhash[row / 3][col / 3][num] = 1;
                    if (solve(A, position + 1)) return true;

                    A[row][col] = '.';
                    rowhash[row][num] = 0;
                    colhash[col][num] = 0;
                    blockhash[row / 3][col / 3][num] = 0;
                }
            }
            return false;
    }

int main()
{
    cout<<"Enter sudoku numbers row by row, '.' for unknown places and enter for new row"<<endl;

    vector<vector<char> > A;
    A.resize(9);


      memset(rowhash, 0, sizeof(rowhash));
            memset(colhash, 0, sizeof(colhash));
            memset(blockhash, 0, sizeof(blockhash));

            for(int i=0;i<9;i++)
            {
                A[i].resize(9);
                string s;
                cin>>s;

                for(int j=0;j<9;j++)
            {
            A[i][j]=s[j];

            }
            }


            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (A[i][j] != '.') {
                        int num = A[i][j] - '1';
                        rowhash[i][num] = 1;
                        colhash[j][num] = 1;
                        blockhash[i / 3][j / 3][num] = 1;
                    }
                }
            }
            solve(A, 0);
            cout<<"Sudoku solution is"<<endl;
            for(int i=0;i<9;i++)
            {

                for(int j=0;j<9;j++)
                {
                    cout<<A[i][j];
            }
            cout<<endl;
            }

}
/*
.......7.
5...9..38
6.7.1324.
4.97.1.86
..3.64..9
.....8...
1.837...4
9.5..2.6.
2.4.5.8.7

*/
