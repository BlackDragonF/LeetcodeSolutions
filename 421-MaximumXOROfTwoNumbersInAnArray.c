#define MASK (0x40000000)

typedef struct BitTrieNode {
    struct BitTrieNode * bit[2];
}BitTrieNode;

typedef struct BitTrie {
    BitTrieNode * root;
}BitTrie;

int findMaximumXOR(int* nums, int numsSize) {
    BitTrie * tree = malloc(sizeof(BitTrie));
    tree->root = malloc(sizeof(BitTrieNode));
    tree->root->bit[0] = NULL;
    tree->root->bit[1] = NULL;
    int result = 0;
    int xor;
    int mask;
    int index;
    for (index = 0 ; index < numsSize ; ++index) {
        BitTrieNode * node = tree->root;
        BitTrieNode * mirr = node;
        int bit;
        xor = 0;
        mask = MASK;
        while (mask > 0) {
            bit = ((mask & nums[index]) > 0) ? 1 : 0;
            if ((node->bit)[bit] == NULL) {
                (node->bit)[bit] = malloc(sizeof(BitTrieNode));
                (((node->bit)[bit])->bit)[0] = NULL;
                (((node->bit)[bit])->bit)[1] = NULL;
            }
            node = (node->bit)[bit];
            if ((mirr->bit)[1-bit] != NULL) {
                xor += mask;
                mirr = (mirr->bit)[1-bit];
            } else {
                mirr = (mirr->bit)[bit];
            }
            mask >>= 1;
        }
        if (xor > result) {
            result = xor;
        }
    }
    return result;
}
