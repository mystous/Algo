package Algospot;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static int InputWords(ArrayList<String> wordList, BufferedReader br) {
		int wordNum = 0;
		try {
			wordNum = Integer.parseInt(br.readLine());
			for (int i = 0; i < wordNum; i++) {
				wordList.add(i, br.readLine());
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
		return wordNum;
	}

	public static boolean detect(char[][] matrix, int[] letters, String str) { // PRETTY
		for (int i = 0; i < str.length(); i++) {
			// no this letters of the word in matrix
			// only search one word
			if (letters[str.charAt(i)] <= 0) {
				return false;
			}
		}

		// if every letters of word is existed
		int idx = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (matrix[i][j] == str.charAt(idx)) { // first find
					if (nextDetect(matrix, i, j, str, ++idx)) {
						return true;
					}
					idx = 0;
				}
			}
		}
		return false;
	}

	public static boolean nextDetect(char[][] matrix, int row, int col,
			String str, int idx) {

		if (idx == str.length()) {
			return true;
		}
		if (detectRC(row - 1, col - 1)) {
			if (matrix[row - 1][col - 1] == str.charAt(idx)) {
				if (nextDetect(matrix, row - 1, col - 1, str, ++idx)) {
					return true;
				}
			}
		}
		if (detectRC(row - 1, col)) {
			if (matrix[row - 1][col] == str.charAt(idx)) {
				if (nextDetect(matrix, row - 1, col, str, ++idx)) {
					return true;
				}
			}
		}
		if (detectRC(row - 1, col + 1)) {
			if (matrix[row - 1][col + 1] == str.charAt(idx)) {
				if (nextDetect(matrix, row - 1, col + 1, str, ++idx))
					return true;
			}
		}
		if (detectRC(row, col - 1)) {
			if (matrix[row][col - 1] == str.charAt(idx)) {
				if (nextDetect(matrix, row, col - 1, str, ++idx))
					return true;
			}
		}
		if (detectRC(row, col + 1)) {
			if (matrix[row][col + 1] == str.charAt(idx)) {
				if (nextDetect(matrix, row, col + 1, str, ++idx))
					return true;
			}
		}
		if (detectRC(row + 1, col - 1)) {
			if (matrix[row + 1][col - 1] == str.charAt(idx)) {
				if (nextDetect(matrix, row + 1, col - 1, str, ++idx))
					return true;
			}
		}
		if (detectRC(row + 1, col)) {
			if (matrix[row + 1][col] == str.charAt(idx)) {
				if (nextDetect(matrix, row + 1, col, str, ++idx))
					return true;
			}
		}
		if (detectRC(row + 1, col + 1)) {
			if (matrix[row + 1][col + 1] == str.charAt(idx)) {
				if (nextDetect(matrix, row + 1, col + 1, str, ++idx))
					return true;
			}
		}
		return false;
	}

	public static boolean detectRC(int row, int col) {
		if (row >= 5 || row < 0 || col >= 5 || col < 0) {
			return false;
		}
		return true;
	}

	public static void main(String[] args) {
		int[] letters = new int[256];
		char[][] matrix = new char[5][5];
		BufferedReader br = null;
		int testcaseNum = 0;
		try {
			br = new BufferedReader(new InputStreamReader(System.in));

			// testcase number
			testcaseNum = Integer.parseInt(br.readLine());	//테이스 케이스 개수

			// counting number of each word on array 2 0 0 1 0 3 0 ....
			StringBuilder str = new StringBuilder();
			for (int i = 0; i < 5; i++) {	//1줄씩 읽기
				str.replace(0, 5, br.readLine());	//stringbuilder에 담기
				for (int j = 0; j < 5; j++) {	//하나씩 점검
					matrix[i][j] = str.charAt(j); // save on the matrix,	메트릭스에 저장
					letters[str.charAt(j)]++; // save on the letters array, letter에 해당 단어++  
				}
			}
			// execute depanding testcase number
			ArrayList<String> wordList = new ArrayList<String>();
			int wordNum = 0;
			System.out.println();
			for (int i = 0; i < testcaseNum; i++) {	//테스트 케이스 만큼 실행
				wordNum = InputWords(wordList, br); // input words on the
													// arraylist
				for (int j = 0; j < wordNum; j++) { // PRETTY -> GIRL -> ...
					if (detect(matrix, letters, wordList.get(j))) { // true
						System.out.println(wordList.get(j) + " YES");
					} else { // false
						System.out.println(wordList.get(j) + " NO");
					}
				}
			}

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
