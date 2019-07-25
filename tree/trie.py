class TrieNode:
    def __init__(self):
        self.path = 0
        self.end = 0
        self.maps = [None] * 26


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        if not word:
            return 

        node = self.root
        for c in word:
            index = ord(c) - ord('a')
            if not node.maps[index]:
                node.maps[index] = TrieNode()
                node.path += 1
            node = node.maps[index]
        node.end += 1

    def search(self, word):
        if not word:
            return False

        node = self.root
        for c in word:
            index = ord(c) - ord('a')
            if not node.maps[index]:
                return False
            node = node.maps[index]
        return node.end != 0

    def has_prefix(self, prefix):
        if not prefix:
            return False

        node = self.root
        for i, c in enumerate(prefix):
            index = ord(c) - ord('a')
            if not node.maps[index]:
                return False
            node = node.maps[index]
        return i == len(prefix) - 1


if __name__ == "__main__":
    trie = Trie()
    trie.insert('hello')
    assert trie.search('hello') == True
    assert trie.search('hell') == False
    assert trie.search('world') == False

    assert trie.has_prefix('h') == True
    assert trie.has_prefix('he') == True
    assert trie.has_prefix('hel') == True
    assert trie.has_prefix('hell') == True
    