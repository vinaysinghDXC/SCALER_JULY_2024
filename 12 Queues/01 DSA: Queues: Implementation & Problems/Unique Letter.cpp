// https://www.scaler.com/academy/mentee-dashboard/class/236124/homework/problems/4365?navref=cl_tt_nv

// Problem Description

// Imagine you're a teacher. You ask students to call out a letter one by one. After each letter, you jot down the very first letter that's only been called out once. If all letters have been repeated, you write "#".

// Here's a scenario:

// A student says "a". It's the first letter. You write "a".
// Next, a student says "b", "a" is still unique, so you add "a". Now it's "aa".
// A student says "a" again. Now, "b" is the unique one. You add "b", making it "aab".
// A student says "b". All letters so far are repeated. You add "#". It becomes "aab#".
// A student says "c". "c" is unique. You add "c". The final is "aab#c".
// Your task? Given the sequence the students call out A, determine the string on the board.





// Problem Constraints

// 1 <= |A| <= 100000



// Input Format

// The only argument given is string A.



// Output Format

// Return a string after processing the stream of lowercase alphabets A.



// Example Input

// Input 1:

//  A = "abadbc"
// Input 2:

//  A = "abcabc"


// Example Output

// Output 1:

// "aabbdd"
// Output 2:

// "aaabc#"


// Example Explanation

// Explanation 1:

// "a"      -   first non repeating character 'a'
// "ab"     -   first non repeating character 'a'
// "aba"    -   first non repeating character 'b'
// "abad"   -   first non repeating character 'b'
// "abadb"  -   first non repeating character 'd'
// "abadbc" -   first non repeating character 'd'
// Explanation 2:

// "a"      -   first non repeating character 'a'
// "ab"     -   first non repeating character 'a'
// "abc"    -   first non repeating character 'a'
// "abca"   -   first non repeating character 'b'
// "abcab"  -   first non repeating character 'c'
// "abcabc" -   no non repeating character so '#'

string Solution::solve(string A) {
    string ans = "";
    queue<char> q;
    vector<int> freq(26, 0);

    for (char ch : A) {
        freq[ch - 'a']++;

        if (freq[ch - 'a'] == 1) {
            q.push(ch);
        }

        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) ans += '#';

        else ans += q.front();
    }

    return ans;
}
