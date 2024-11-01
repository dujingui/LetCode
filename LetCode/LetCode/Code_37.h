#pragma once

#include "Define.h"

using namespace std;

//37. ������
//��дһ������ͨ�����ո�������������⡣
//
//�����Ľⷨ�� ��ѭ���¹���
//
//���� 1 - 9 ��ÿһ��ֻ�ܳ���һ�Ρ�
//���� 1 - 9 ��ÿһ��ֻ�ܳ���һ�Ρ�
//���� 1 - 9 ��ÿһ���Դ�ʵ�߷ָ��� 3x3 ����ֻ�ܳ���һ�Ρ�����ο�ʾ��ͼ��
//�������ֿո��������������֣��հ׸��� '.' ��ʾ��

//ʾ�� 1��
//
//���룺board = [["5", "3", ".", ".", "7", ".", ".", ".", "."], ["6", ".", ".", "1", "9", "5", ".", ".", "."], [".", "9", "8", ".", ".", ".", ".", "6", "."], ["8", ".", ".", ".", "6", ".", ".", ".", "3"], ["4", ".", ".", "8", ".", "3", ".", ".", "1"], ["7", ".", ".", ".", "2", ".", ".", ".", "6"], [".", "6", ".", ".", ".", ".", "2", "8", "."], [".", ".", ".", "4", "1", "9", ".", ".", "5"], [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
//����� [["5", "3", "4", "6", "7", "8", "9", "1", "2"], ["6", "7", "2", "1", "9", "5", "3", "4", "8"], ["1", "9", "8", "3", "4", "2", "5", "6", "7"], ["8", "5", "9", "7", "6", "1", "4", "2", "3"], ["4", "2", "6", "8", "5", "3", "7", "9", "1"], ["7", "1", "3", "9", "2", "4", "8", "5", "6"], ["9", "6", "1", "5", "3", "7", "2", "8", "4"], ["2", "8", "7", "4", "1", "9", "6", "3", "5"], ["3", "4", "5", "2", "8", "6", "1", "7", "9"]]
//���ͣ��������������ͼ��ʾ��Ψһ��Ч�Ľ������������ʾ��

//��ʾ��
//
//board.length == 9
//board[i].length == 9
//board[i][j] ��һλ���ֻ��� '.'
//��Ŀ���� ��֤ ������������һ����

class Solution {
private:
	vector<vector<vector<char>>> mResult;
public:
	Solution(){
		for (int i = 0; i < 9; i++){
			mResult[i].resize(9);
		}
	}

    void solveSudoku(vector<vector<char>>& board) {
		this->updateResult(board);

		this->solveSudokuEx(board, 0, 0);
    }

	bool solveSudokuEx(vector<vector<char>>& board, int i, int j) {
		if (mResult[i][j].size() < 2){
			return this->solveSudokuEx(board, j >= 9 ? i++ : i, j >= 9 ? 0 : j++);
		}

		for (int k = 0; k < mResult[i][j].size(); k++){
			board[i][j] = mResult[i][j][k];
			if (!this->updateResult(board)){
				board[i][j] = '.';
				continue;
			}
			if (!this->solveSudokuEx(board, j >= 9 ? i++ : i, j >= 9 ? 0 : j++)){
				board[i][j] = '.';
				continue;
			}
		}

		return board[i][j] != '.';
	}

	bool updateResult(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				if (board[i][j] == '.'){
					vector<char> result = this->getGridNum(i, j, board);
					if (result.size() <= 0){
						return false;
					}
					else if (result.size() == 1){
						board[i][j] = result[0];
					}
					else{
						mResult[i][j] = result;
					}
				}
			}
		}
		return true;
	}

	vector<char> getGridNum(int row, int col, vector<vector<char>>& board) {
        vector<char> result = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

		for (int j = 0; j < 9; j++){
			for (int k = 0; k < result.size(); k++){
				if (board[row][j] == result[k]){
					result.erase(result.begin() + k);
					break;
				}
			}
		}

		for (int i = 0; i < 9; i++){
			for (int k = 0; k < result.size(); k++){
				if (board[i][col] == result[k]){
					result.erase(result.begin() + k);
					break;
				}
			}
		}

		int startRow = row / 3;
		startRow = startRow * 3;

		int startCol = col / 3;
		startCol = startCol * 3;
		for (int i = startRow; i < startRow + 3; i++){
			for (int j = startCol; j < startCol + 3; j++){
				for (int k = 0; k < result.size(); k++){
					if (board[i][j] == result[k]){
						result.erase(result.begin() + k);
						break;
					}
				}
			}
		}

		return result;
    }
};

void test_37(){
	Solution pSolution;
	vector<vector<char>> board = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
	pSolution.solveSudoku(board);
	PrintVector(board);
}