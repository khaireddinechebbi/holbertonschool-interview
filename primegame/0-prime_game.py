#!/usr/bin/python3
"""
Prime Game: Maria and Ben
"""


def sieve_primes(n):
    """Return list of prime counts up to n using sieve."""
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    prime_count = [0] * (n + 1)
    count = 0
    for i in range(2, n + 1):
        if is_prime[i]:
            count += 1
        prime_count[i] = count

    return prime_count


def isWinner(x, nums):
    """
    Determines the winner of the Prime Game.

    Args:
        x (int): number of rounds
        nums (list of int): each round's n

    Returns:
        str: "Maria" or "Ben", or None if tie
    """
    if x < 1 or not nums:
        return None

    max_n = max(nums)
    prime_count = sieve_primes(max_n)

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
