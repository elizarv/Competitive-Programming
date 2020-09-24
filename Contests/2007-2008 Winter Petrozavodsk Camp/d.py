inpt = open("dinner.in","r")
out = open("dinner.out","w")

k = 0
N = 105

dp = [[-1 for i in range (N)] for j in range (N)]
fact = []

def f(i, n):
    if(i == k):
        return n == 0
    if(dp[i][n] != -1):
        return dp[i][n]
    dp[i][n] = 0
    ans = 0
    for j in range (1, n+1):
        ans = ans + f(i+1, n-j) * (fact[n]/(fact[j]*fact[n-j]))
    dp[i][n] = ans
    return dp[i][n]


k, n = map(int, inpt.read().split(' '))


fact.append(1)
for i in range (1, n+1):
    fact.append(fact[i-1]*i)

out.write("{}\n".format(int(f(0, n))))


    