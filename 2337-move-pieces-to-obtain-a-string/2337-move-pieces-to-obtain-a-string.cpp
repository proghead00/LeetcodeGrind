
class Solution {
public:
	bool canChange(string start, string target) {
		// L's idx in target should be less than (or equal) to that in start
		// opposite for R

		// i => for start; j => for target

		int i = 0, j = 0, n = start.size();

		// or => since there can be multiple '_' disrupting
		while (i < n or j < n) {

			// skip 'em
			while (i < n and start[i] == '_') i++;
			while (j < n and target[j] == '_') j++;

			// base case
			if (i == n or j == n) return (i == n and j == n);

			// can't cross over kek
			if (start[i] != target[j]) return false;


			if (start[i] == 'L') if (i < j) return false;
			if (start[i] == 'R') if (i > j) return false;
			i++; j++;
		}

		// start = "_L__R__RR", target = "L______RR"
		// target will get exhausted, but i will remain, hence false
		return i == n and j == n;
	}
};

