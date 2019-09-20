import math


def karatsuba_multiply(x,y):
    n = min(len(str(x)), len(str(y)))

    n = int(n)

    if(n==1):
        return int(x)*int(y)
    if(n%2==1):
        ++n

    a = str(x)[n//2:]
    b = str(x)[:n//2]
    c = str(y)[n//2:]
    d = str(y)[:n//2]

    sum1 = karatsuba_multiply(a, c)
    sum2 = karatsuba_multiply(b, d)

    sum3 = karatsuba_multiply(str(int(a)+int(b)), str(int(c)+int(d)))

    term1 = str(sum1)
    term2 = str((int(sum3)-int(sum2)-int(sum1)))
    term3 = str(sum2)

    if(term1[0]=='-'):
        term1 = term[1:]

    if(term2[0]=='-'):
        term2 = term2[1:]

    if(term3[0]=='-'):
        term3 = term3[1:]

    print(n)

    for i in range(0, n//2):
        term2 = str(term2) + ('0')

    for j in range(0, n):
        term3 = str(term3) + ('0')

    return str(int(term1) + int(term2) + int(term3))

def main():

    print("Enter the two numbers: ")
    x = input()
    y = input()

    print("Product is: " + str(karatsuba_multiply(str(x), str(y))))


main()
