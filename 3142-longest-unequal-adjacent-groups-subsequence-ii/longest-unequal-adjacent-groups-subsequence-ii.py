from typing import List

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        def is_one_letter_diff(s: str, t: str) -> bool:
            return len(s) == len(t) and sum(a != b for a, b in zip(s, t)) == 1

        n = len(words)
        lengths = [1] * n
        previous_index = [-1] * n
        max_length = 1

        for i, current_group in enumerate(groups):
            for j, previous_group in enumerate(groups[:i]):
                if (current_group != previous_group and 
                    lengths[i] < lengths[j] + 1 and 
                    is_one_letter_diff(words[i], words[j])):
                    lengths[i] = lengths[j] + 1
                    previous_index[i] = j
                    max_length = max(max_length, lengths[i])

        longest_subsequence = []

        for i in range(n):
            if lengths[i] == max_length:
                j = i
                while j >= 0:
                    longest_subsequence.append(words[j])
                    j = previous_index[j]
                break

        return longest_subsequence[::-1]
