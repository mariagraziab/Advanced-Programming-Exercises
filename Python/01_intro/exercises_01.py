import numpy as np

def is_palindrome(string_var):     
    '''
    returns True if string_var is palindrome, False otherwise
    '''
    ret = string_var[::-1]
   
    return ret == string_var

def histogram_letters(string_var):     
    '''
    count how many times a letter is present in the string_var
    and returns a dict

    '''
    letters = {}
    for c in string_var:
        letters[c] = 0
        
    for c in string_var:
        letters[c]+=1
    return letters

def get_most_frequent(list_var):
    '''
    returns a tuple with the most frequent object in the list with the 
    corresponing number
    '''
    dic = histogram_letters(list_var)
    most_frequent = None
    max = 0
    for i in dic: 
        if dic[i]>max:
            max= dic[i]
            most_frequent = i

    return (most_frequent,max)

def which_duplicates(list_var):
    '''
    return a dict with containing the repeted object and the number of repetitions
    '''
    ret = histogram_letters(list_var)
    for i in list_var: 
        if ret[i] < 2:
            del ret[i]

    return ret


def compute_factorial(int_val):
    '''
    returns factorial of a number
    '''
    if(int_val) <=1:
        ret = 1
    else: 
        ret = int_val*(compute_factorial(int_val-1))
    return ret


def is_prime(int_val):
    '''
    returns True if int_val is prime, False otherwise
    '''
    ret = True
    for n in range(2,int_val):
        if np.any(not(int_val%n)):
            ret = False
            
    return ret





        
        

