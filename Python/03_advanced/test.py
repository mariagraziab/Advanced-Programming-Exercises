__all__=['myrange','MyRange']


def control(func): 
    def controlled(*args):
        param_numb = len(args)
        if param_numb not in [2,3,4]:
            raise TypeError("Wrong number of parameters")
        if param_numb == 2: 
            result = func(args[0],0,args[1])
            return result 
        if param_numb == 3: 
            result = func(args[0],args[1],args[2])
            return result
        if param_numb == 4: 
            result = func(args[0],args[1],args[2],args[3])
            return result 
    return controlled

class MyRange(): 
    @control
    def __init__(self, start, stop, step=1):
    	l = []
        i = start
        while(i<stop):
            l.append(i)
            i+=step
        self.range = tuple(l)

    def __call__(self):
        return self.range


def myrange(*args):
    a = MyRange(*args)
    return a()



import unittest

class TestRange(unittest.TestCase):
    def test_minimum_value(self):
        self.assertEqual(min([i for i in range(20)]),min([i for i in myrange(20)]))
        #self.assertEqual(0,)
         

    def test_maximum_value(self):
        self.assertEqual(max([i for i in range(22)]),max([i for i in myrange(22)]))

    def test_range_len(self):

        self.assertEqual(len([i for i in range(3,27,3)]),len([i for i in myrange(3,27,3)]))

    def test_equivalence(self):
        
        self.assertEqual([i for i in range(13,57,3)],[i for i in myrange(13,57,3)])
   
    def test_exceptions(self):
        with self.assertRaises(TypeError):
            myrange(0,1,4,1)

        with self.assertRaises(TypeError):
            myrange()



if __name__ == '__main__':
    unittest.main()
