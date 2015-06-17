var inseed: UInt64 = 987234904
var seed: UInt64 = 0

java_random_setseed(&seed, seed)
var result = java_random_nextint_n(&seed, 10)
print(result)
