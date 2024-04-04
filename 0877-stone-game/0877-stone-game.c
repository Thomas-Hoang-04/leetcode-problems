bool stoneGame(int* piles, int pilesSize) {
    return true;
    /* Alice goes first, so she can always choose all of the odd piles or the even piles
    If Alice choose all odd piles, and sum(piles[odd]) > sum(piles[even]) -> Win
    If Alice choose all even piles, and sum(piles[even]) > sum(piles[odd]) -> Win
    => Alice always win */
}
