str = input();
str1, str2 = str.split(' ')
n = int(str1)
a = int(str2)

def factorial(n):
    mul = 1;
    while(n > 0):
        mul = mul*n;
        n = n-1;
    return mul

n_mul = factorial(n)
m = -1
for k in range(1000):
    if a**k > n_mul:
        break
    if n_mul%(a**k)==0 and n_mul%(a**(k+1))> 0:
        if k > m:
            m = k
print(m)