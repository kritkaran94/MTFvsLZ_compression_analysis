''' 

   Author : Krit Karan
   Roll : IS201311018
  Indian Instiute Of Information Technology, Sri City

'''

def compress(uncompressed):
    
 
    
    dict_size = 256
    dictionary = dict((chr(i), chr(i)) for i in xrange(dict_size))
  
 
    w = ""
    result = []
    for c in uncompressed:
        wc = w + c
        if wc in dictionary:
            w = wc
        else:
            result.append(dictionary[w])
            
            dictionary[wc] = dict_size
            dict_size += 1
            w = c
 
    
    if w:
        result.append(dictionary[w])
    return result

compressed = compress('TOBEORNOTTOBEORTOBEORNOT')
print (compressed)
