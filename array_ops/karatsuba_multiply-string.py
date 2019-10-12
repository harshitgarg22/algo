# This implementation uses strings to multiply two numbers and can, therefore, handle exceedingly large numbers.

# Test Case:
# x = 3141592653589793238462643383279502884197169399375105820974944592
# y = 2718281828459045235360287471352662497757247093699959574966967627
# x*y = 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184

import sys

def karatsuba_multiply(x, y):

    n = len(x)

    if(n==1):
        return multiply(x, y)

    b = x[n//2:]
    a = x[:n//2]
    d = y[n//2:]
    c = y[:n//2]

    print(a + ' ' + b + ' ' + c + ' ' + d)

    ac = karatsuba_multiply(a, c)
    bd = karatsuba_multiply(b, d)
    k = karatsuba_multiply(add(a,b), add(c,d))

    print("sums " + ac + ' ' + bd + ' ' + k)

    term1 = bd

    term2 = subtract(k, add(ac, bd))
    term2 = multiply(term2, power(10, n-n//2))

    term3 = ac
    term3 = multiply(term3, power(10, n))

    print(term1 + ' ' + term2 + ' ' + term3)

    return add(add(term1, term2), term3)


def power(x, y):
    # Outputs x**y
    mul = "1"
    for i in range(int(y)):
        mul = multiply(mul, x)

    return mul


def add(x, y):

    cin=0  # carry-in for addition
    output = ""  # stores the output string

    # So that we can accommodate cases like 3 + 3333333 = 3333336 by making it 0000003
    if(len(x)>len(y)):
        for i in range(len(x)-len(y)):
            y = '0' + y
    else:
        for i in range(len(y)-len(x)):
            x = '0' + x

    # Loop adds the number digit by digit
    if((x[0]!='-') and (y[0]!='-')):
        print(x + ' ' + y)
        for j in range(len(x)):
            i = len(x)-j-1 # So that it iterates from the unit's place, which is not x[0]

            print(x[i] + ' ' + y[i])
            z = int(x[i])+int(y[i])+cin
            if(z>9):
                cin=int(z/10)
            else:
                cin=0
            output = str(int(z%10)) + output

        # To add the carry over from the x[0] position
        if(cin!=0):
           output = str(cin) + output
    elif(x[0]=='-'):
        return subtract(x[1:], y)
    elif(y[0]=='-'):
        return subtract(x, y[1:])


    return output


def subtract(x, y):
    cin=0  # carry-in for subtraction
    output = ""  # stores the output string

    # So that we can accommodate cases like 3 + 3333333 = 3333336 by making it 0000003
    if(len(x)>len(y)):
        for i in range(len(x)-len(y)):
            y = '0' + y
    else:
        for i in range(len(y)-len(x)):
            x = '0' + x

    # Loop adds the number digit by digit
    for j in range(len(x)):
       i = len(x)-j-1 # So that it iterates from the unit's place, which is not x[0]

       z = int(x[i])-int(y[i])-cin
       if(z<0):
           z = 10+z
           cin=1
       else:
           cin=0
       output = str(int(z%10)) + output

    # To add the carry over from the x[0] position
    if(cin==1):
         output = ""
         cin = 0
         j=0
         for j in range(len(x)):
             i = len(x)-j-1 # So that it iterates from the unit's place, which is not x[0]
             z = int(y[i])-int(x[i])-cin
             if(z<0):
                 z = 10+z
                 cin=1
             else:
                 cin=0
             output = str(int(z%10)) + output


         # temp = str(10 - int(output[0]))
         # output = output[1:]
         output = '-' + output

    return output


def multiply(x, y):

    output = ""  # stores the output string

    if(x!='' and y!=''):
        output = str(int(x)*int(y))
    else:
        output = '0'
    return output


def main():

    if(sys.argv[1]=='1'):
        x = 3141592653589793238462643383279502884197169399375105820974944592
        y = 2718281828459045235360287471352662497757247093699959574966967627

    elif(sys.argv[1]=='2'):
        print("Enter the two numbers: ")
        x = input()
        y = input()

    print(karatsuba_multiply(str(x),str(y)))

    # print(multiply(str(x), power(10, 232)))

main()
