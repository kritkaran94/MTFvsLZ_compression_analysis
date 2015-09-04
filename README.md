# MTFvsLZ_compression_analysis
As a part of Information Theory and Coding course


Comparison with Lempel-Ziv Encoding :

 6.1.  Theoretical Difference :

       Lempel Ziv encoding is an example of class of algorithms called      
       dictionary-based encoding. The idea is to create a dictionary of   
       strings and based on index value we encode the sequence. In case   
       both the sender and receiver have a copy of the dictionary, then     
       previously-encountered strings can be substituted by their index in 
       the dictionary to reduce the amount of information transmitted.

       In MTF encoding is done as alphabets appear in the   
       symbol table and there is no concept of substitution in case of  
       previously-encountered string. We just move the current char to front of
       the symbol table as discussed earlier.


6.2.   Algorithmic Analysis :

      Code for Lempel-Ziv below would make things much easier :

    
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



Clearly the complexity of above algorithm is O(n) where is the length of the string.

Now for MTF the complexity is O(nk) where n is the length of the string and k is total no of values.


6.3. Run Time for the same input :

<table style="width:100%">
  <tr>
    <th>Time</th>
    <th>Lempel Ziv</th> 
    <th>MTF</th>
  </tr>
  <tr>
    <td>Real</td>
    <td>0m0.032s</td> 
    <td>0m0.045s</td>
  </tr>
  <tr>
    <td>User</td>
    <td>0m0.018s</td> 
    <td>0m0.016s</td>
  </tr>
  <tr>
    <td>Sys</td>
    <td>0m0.011s</td> 
    <td>0m0.055s</td>
  </tr>
</table>

 Note : ** Although the above is a rough estimate. Several tests  
                        have proved that Lempel Ziv is faster than MTF.

